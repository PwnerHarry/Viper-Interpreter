%{
#include "stdio.h" /* For printf, etc. */
#include "math.h" /* For pow, used in the grammar. */
#include "calc.h" /* Contains definition of 'symrec'. */
int yylex(void);
void yyerror(char const *);
static void init_table(void);
%}

%define api.value.type union
%token <double> NUM
%token <symrec*> VAR FNCT
%type <double> exp

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
		| exp '\n' { printf ("%.10g\n", $1); }
		| error '\n' { yyerrok; }
		;
exp:
		NUM					{ $$ = $1; }
		| VAR				{ $$ = $1->value.var_double;}
		| VAR '=' exp		{ $$ = $3; $1->value.var_double = $3; }
		| FNCT '(' exp ')'	{ $$ = (*($1->value.fnctptr))($3); }
		| exp '+' exp		{ $$ = $1 + $3; }
		| exp '-' exp		{ $$ = $1 - $3; }
		| exp '*' exp		{ $$ = $1 * $3; }
		| exp '/' exp		{ $$ = $1 / $3; }
		| '-' exp %prec NEG	{ $$ = -$2; }
		| exp '^' exp		{ $$ = pow ($1, $3); }
		| '(' exp ')'		{ $$ = $2; }
		;
%%


int main (int argc, char const* argv[]) {
	init_table();
	return yyparse();
}
int yylex(void) {
	int c;
	//Ignore white space, get first nonwhite character
	while ((c = getchar ()) == ' ' || c == '\t')
		continue;
	if (c == EOF)
		return 0;
	//Char starts a number => parse the number
	if (c == '.' || isdigit (c)) {
		ungetc(c, stdin);
		scanf("%lf", &yylval.NUM);
		return NUM;
	}
	//Char starts an identifier => read the name
	if (isalpha (c)) {
		//Initially make the buffer long enough for a 40-character symbol name
		static size_t length = 40;
		static char *symbuf = 0;
		symrec *s;
		int i;
		if (!symbuf)
			symbuf = (char *) malloc(length + 1);
		i = 0;
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
		s = getsym(symbuf);
		if (s == 0) {
			char d;
			if ((d = getchar()) != '=')
				printf("Variable not defined\nNow make it 0\n");
			ungetc(d, stdin);
			s = putsym(symbuf, VAR);
		}
		*((symrec**) &yylval) = s;
		return s->type;
	}
	//Any other character is a token by itself
	return c;
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