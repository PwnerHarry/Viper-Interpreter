%{
#include <stdlib.h>
#include <ctype.h>
#include "stdio.h" //For printf, etc
#include "iostream" //For printf, etc
#include "fstream" //For printf, etc
#include "string.h"
#include "math.h"
using namespace std;
ifstream fin;
ofstream fout;
int Script_Mode = 0;
int yylex(void);
void Instruction();
void yyerror(char const *);
static void init_table(void);
typedef double (*func_t) (double);
class symrec {
public:
	char *name; /* name of symbol */
	int type; /* type of symbol: either VAR or FNCT */
	union {
		double var_double; /* value of a VAR as a double*/
		int var_int; /* value of a VAR as as integer*/
		func_t fnctptr; /* value of a FNCT */
	} value;
	struct symrec *next; /* link field */
};
/* The symbol table: a chain of 'struct symrec'. */
extern symrec *sym_table;
symrec *putsym(char const *, int);
symrec *getsym(char const *);
void table();
class init {
public:
	char const *fname;
	double (*fnct) (double);
};
class cons {
public:
	char const *cname;
	double value;	
};
init const arith_fncts[] = {
	{"sin", sin},
	{"arcsin", asin},
	{"cos", cos},
	{"arccos", acos},
	{"tan", tan},
	{"arctan", atan},
	{"exp", exp},
	{"ln", log},
	{"sqrt", sqrt},
	{0, 0},
};
cons const arith_consts[] = {
	{"pi", 3.14159},
	{0, 0},
};
symrec *sym_table;
%}

%define api.value.type union
%token <double> NUM
%token <symrec*> VAR FNCT
%type <double> exp
%token EXIT "exit"
%token TABLE "table"
%token CLEAR "clear"
%token IF "if"

%precedence '='
%left '-' '+'
%left '*' '/'
%precedence NEG /* negation--unary minus */
%right '^' /* exponentiation */

%%
input:
		%empty
		| input line
		;
line:
		'\n'
		| exp '\n'						{ cout << $1 << endl; }
		| "exit" '\n'					{ system("CLS"); exit(1); }
		| "table" '\n'					{ table(); }
		| "clear" '\n'					{ Instruction();}
		| error '\n'					{ yyerrok; }
		;
exp:
		NUM						{ $$ = $1; }
		| VAR					{ $$ = $1->value.var_double;}
		| VAR '=' exp			{ $$ = $3; $1->value.var_double = $3; }
		| FNCT '(' exp ')'		{ $$ = (*($1->value.fnctptr))($3); }
		| exp '+' exp			{ $$ = $1 + $3; }
		| exp '-' exp			{ $$ = $1 - $3; }
		| exp '*' exp			{ $$ = $1 * $3; }
		| exp '/' exp			{ $$ = $1 / $3; }
		| '-' exp %prec NEG		{ $$ = -$2; }
		| exp '^' exp			{ $$ = pow($1, $3); }
		| '(' exp ')'			{ $$ = $2; }
		;
%%


int main (int argc, char const* argv[]) {
	Instruction();
	init_table();
	if (argc == 3 && strcmp(argv[1], "-s")){
		Script_Mode = 1;
		fin.open(argv[2], ios::in);
		if (fin.bad() || fin.fail()) {
			fprintf(stderr, "Error opening file!\n");
			exit(1);
		}
	}
	return yyparse();
}
int yylex(void) {
	int c;
	if (Script_Mode) {
		fprintf(stderr, "Feature not developed!\n");
		exit(1);
	}
	else {
		while ((c = getchar ()) == ' ' || c == '\t')
			continue;
		if (c == EOF)
			return 0;
		//Char starts a number => parse the number
		if (c == '.' || isdigit (c)) {
			ungetc(c, stdin);
			cin >> yylval.NUM;
			return NUM;
		}
		//Char starts an identifier => read the name
		if (isalpha (c)) {
			//Initially make the buffer long enough for a 40-character symbol name
			static size_t length = 40;
			static char *symbuf = 0;
			symrec *s;
			int i = 0;
			if (!symbuf)
				symbuf = (char *) malloc(length + 1);
			do {
				//If buffer is full, make it bigger
				if (i == length) {
					length *= 2;
					symbuf = (char *) realloc(symbuf, length + 1);
				}
				//Add this character to the buffer
				symbuf[i++] = c;
				//Get another character
				c = getchar();
			} while (isalnum(c));
			ungetc(c, stdin);
			symbuf[i] = '\0';
			if (!strcmp(symbuf, "exit"))
				return EXIT;
			if (!strcmp(symbuf, "table"))
				return TABLE;
			if (!strcmp(symbuf, "clear"))
				return CLEAR;
			if (!strcmp(symbuf, "if"))
				return IF;
			s = getsym(symbuf);
			if (s == 0) {
				char d;
				while ((d = getchar ()) == ' ' || c == '\t')
					continue;
				if (d != '=')
					cout << "Variable not defined" << endl << "Now make it 0" << endl;
				ungetc(d, stdin);
				s = putsym(symbuf, VAR);
			}
			*((symrec**) &yylval) = s;
			return s->type;
		}
		//Any other character is a token by itself
		return c;
	}
}
void yyerror(char const *s) {
	fprintf(stderr, "%s\n", s);
}
symrec * putsym(char const *sym_name, int sym_type) {
	symrec *ptr = (symrec *) malloc(sizeof(symrec));
	ptr->name = (char *) malloc(strlen(sym_name) + 1);
	strcpy(ptr->name, sym_name);
	ptr->type = sym_type;
	ptr->value.var_double = 0; //Set value to 0 even if fctn
	ptr->value.var_int = 0; //Set value to 0 even if fctn
	ptr->next = (struct symrec *)sym_table;
	sym_table = ptr;
	return ptr;
}
symrec * getsym(char const *sym_name) {
	symrec *ptr;
	for (ptr = sym_table; ptr != (symrec *) 0; ptr = (symrec *)ptr->next)
		if (strcmp(ptr->name, sym_name) == 0)
			return ptr;
	return 0;
}
static void init_table(void) {
	int i;
	for (i = 0; arith_fncts[i].fname != 0; i++)	{
		symrec *ptr = putsym(arith_fncts[i].fname, FNCT);
		ptr->value.fnctptr = arith_fncts[i].fnct;
	}
	for (i = 0; arith_consts[i].cname != 0; i++){
		symrec *ptr = putsym(arith_consts[i].cname, VAR);
		ptr->value.var_double = arith_consts[i].value;
	}
}
void table() {
	symrec *ptr;
	cout << "#############################################" << endl;
	cout << "VARIABLE TABLE" << endl;
	for (ptr = sym_table; ptr != (symrec *) 0; ptr = (symrec *)ptr->next) {
		cout << ptr->name << "\t";
		if (ptr->type == VAR)
			cout << ptr->value.var_double << endl;
		if (ptr->type == FNCT)
			cout << "FUNCTION" << endl;
	}
	cout << "#############################################" << endl;
}
void Instruction() {
	system("CLS");
	cout << "Easy Calculator" << endl;
	cout << "\'table\' for displaying the variable table" << endl;
	cout << "\'clear\' for clear screen" << endl;
	cout << "\'exit\' for exit" << endl;
	cout << "===========================================================" << endl;
	
}