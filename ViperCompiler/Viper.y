%{
using namespace std;
#include "ctype.h"
#include "string.h"
#include "iostream"
#include "fstream"
#include "math.h"
const int SIZE = 4096;
const int DIAGNOSE = 0;
class Token {
public:
	int lineno;
	int type;
	int layer;
	int availability;
	union {
		double D;
		int I;
		char * S;
		char C;
	} value;
	Token(){
		layer = 0;
		availability = 0;
		lineno = 0;
		type = 0;
		value.D = 0;
		value.C = 0;
		value.S = 0;
		value.I = 0;
	};
};
class TokenTable {
public:
	int Pointer;
	int Size;
	Token * t;
	TokenTable() {
		Size = 0;
		t = new Token[SIZE];
		Pointer = 0;
	}
};
int yylex();
int ReadTokens(ifstream &f, TokenTable * T);
void DispTokens(TokenTable * T);
void yyerror(char *s);
TokenTable * T = new TokenTable;
class function {
public:
	char * name;
	union {
		int ret_int;
		int ret_double;
		int ret_void;
	} Return;
	function() {
		name = 0;
		Return.ret_int = 0;
		Return.ret_double = 0;
		Return.ret_void = 1;
	}
};
union YYSTYPE{
	int Int;
	double Double;
	char * String;
	char * Name;
	char Char;
	bool Bool;
	function * Function;
};
%}

%define api.value.type {union YYSTYPE}
%token	<Double>		NUMBER
%token	<Char>			CHAR
%token	<Name>			NAME
%token	<String>		STRING
%token	INDENT
%token	DEDENT
%token	ENDMARKER
%token	ELLIPSIS		"..."
%token	CBRACE			"}"
%token	OBRACE			"{"
%token	COLON			":"
%token	ASSIGN			"="
%token	AT				"@"
%token	SEMICOLON		";"
%token	NEWLINE			"\n"
%token	FROM			"from"
%token	EXEC			"exec"
%token	WITH			"with"
%token	RAISE			"raise"
%token	TRY				"try"
%token	DEL				"del"
%token	AS				"as"
%token	ASSERT			"assert"
%token	IS				"is"
%token	EXCEPT			"except"
%token	FINALLY			"finally"
%token	LAMBDA			"lambda"
%token	YIELD			"yield"
%token	IMPORT			"import"
%token	PRINT			"print"
%token	WHILE			"while"
%token	BREAK			"break"
%token	CONTINUE		"continue"
%token	GLOBAL			"global"
%token	ELIF			"elif"
%token	ELSE			"else"
%token	PASS			"pass"
%token	RETURN			"return"
%token	IN				"in"
%token	FOR				"for"
%token	CLASS			"class"
%token	NOT				"not"
%token	AND				"and"
%token	OR				"or"
%token	IF				"if"
%token	DEF				"def"
%token	POWER			"**"
%token	FLOOR_DIVISION	"//"
%token	LESS_THAN		"<" 
%token	LT_OR_EQUAL		"<="
%token	EQUAL			"=="
%token	UNEQUAL			"!="
%token	MT_OR_EQUAL		">="
%token	MORE_THAN		">"
%token	PLUS			"+"
%token	MINUS			"-"
%token	MULTIPLY		"*"
%token	DIVIDE			"/"
%token	MOD				"%"
%token	COMMA			","
%token	PERIOD			"."
%token	OPARENT			"("
%token	CPARENT			")"
%token	OBRACK			"["
%token	CBRACK			"]"
%token	PLUS_EQUAL		"+="
%token	MINUS_EQUAL		"-="
%token	MULTIPLY_EQUAL	"*="
%token	DIVIDE_EQUAL	"/="
%token	FD_EQUAL		"//="
%token	MOD_EQUAL		"%="
%token	POWER_EQUAL		"**="
%token	NONLOCAL		"nonlocal"


%precedence "="
%left "-" "+"
%left "*" "/"
%precedence NEG /* negation--unary minus */
%right "**" /* exponentiation */

%%
input			: %empty
				| input file_input					{ if (DIAGNOSE) cout << "input : input file_input" << endl; }
				;
file_input		: NEWLINE ENDMARKER					{ if (DIAGNOSE) cout << "file_input : NEWLINE ENDMARKER" << endl; }
				| stmt ENDMARKER					{ if (DIAGNOSE) cout << "file_input : stmt ENDMARKER" << endl; }
				| NEWLINE file_input				{ if (DIAGNOSE) cout << "file_input : NEWLINE file_input" << endl; }
				| stmt file_input					{ if (DIAGNOSE) cout << "file_input : NEWLINE stmt FILE_INPUT" << endl; }
				;
stmt			: NEWLINE							{ if (DIAGNOSE) cout << "stmt : NEWLINE" << endl;} 	
				| print								{ if (DIAGNOSE) cout << "stmt : print" << endl;}
				| error	NEWLINE						{ if (DIAGNOSE) cout << "stmt : error NEWLINE" << endl; yyerrok; }
				;
print			: "print" "(" STRING ")" 			{ if (DIAGNOSE) cout << "print : \"print\" \"(\" STRING \")\"" << endl; cout << $3 << endl;}	
				| "print" "(" NUMBER ")" 			{ if (DIAGNOSE) cout << "print : \"print\" \"(\" NUMBER \")\"" << endl; cout << $3 << endl;}	
				| "print" "(" CHAR ")" 				{ if (DIAGNOSE) cout << "print : \"print\" \"(\" CHAR \")\"" << endl; cout << $3 << endl;}
				;
global_stmt		: "global" NAME
				| global_stmt "," NAME
				;
nonlocal_stmt	: "nonlocal" NAME
				| global_stmt "," NAME
				;
dotted_name		: NAME
				| dotted_name "," NAME
				;
vfpdef			: NAME ;
encoding_decl	: NAME ;
continue_stmt	: "continue" ;
break_stmt		: "break" ;
pass_stmt		: "pass" ;
import_as_name	: NAME
				| NAME "as" NAME
				;
dotted_as_name	: dotted_name
				| dotted_name "as" NAME
				;
import_as_names	: import_as_name
				| import_as_name ","
				| import_as_name "," import_as_names
				;
dotted_as_names	: dotted_as_name
				| dotted_as_names "," dotted_as_name
				;
%%

int main(int argc, char * argv[]) {
	ofstream fout;
	if (argc != 2) {
		fprintf(stderr, "1 argument required!");
		exit(1);
	}
	ifstream fin(argv[1], ios::in);
	if (fin.fail() || fin.bad()) {
		fprintf(stderr, "Destination Error");
		exit(1);
	}
	ReadTokens(fin, T);
	DispTokens(T);
	return yyparse();
};
void DispTokens(TokenTable * T) {
	system("CLS");
	for (int i = 0; i < SIZE && T->t[i].availability != 0; i++) {
		cout << T->t[i].lineno << "\t" << T->t[i].layer << "\t" << T->t[i].type << "\t";
		switch (T->t[i].type) {
			case STRING:{
				cout << T->t[i].value.S;
				break;
			}
			case NUMBER:{
				cout << T->t[i].value.D;
				break;
			}
			case CHAR:{
				cout << T->t[i].value.C;
				break;
			}
			case NAME:{
				cout << T->t[i].value.S;
				break;
			}
			case INDENT:{
				cout << T->t[i].value.S;
				break;
			}
			case DEDENT:{
				cout << T->t[i].value.S;
				break;
			}
			default:{
				cout << T->t[i].value.S;
				break;
			}
		}
		cout << endl;
	}
	cout << endl;
};
int ReadTokens(ifstream &f, TokenTable * T) {
	int layer = 0;
	int Break = 0;
	int i = 0;
	for (; i < SIZE; i++) {
		if (f.eof()){
			cout << "EOF" << endl;
			break;
		}
		f >> T->t[i].lineno;
		f >> T->t[i].type;
		T->t[i].layer = layer;
		switch (T->t[i].type) {
			case STRING:{
				cout << "STRING" << endl;
				char temp;
				f.get(temp);
				f.get(temp);
				T->t[i].value.S = new char[1024];
				f.getline(T->t[i].value.S, 1024);
				for (int j = 0; j < 1024; j++)
					if (T->t[i].value.S[j] == '\0')
						T->t[i].value.S[j - 1] = '\0';
				break;
			}
			case NUMBER:{
				f >> T->t[i].value.D;
				break;
			}
			case CHAR:{
				char temp;
				f.get(temp);
				f.get(temp);
				f.get(T->t[i].value.C);
				f.get(temp);
				break;
			}
			case NAME:{
				T->t[i].value.S = new char[1024];
				f >> T->t[i].value.S;
				break;
			}
			case INDENT:{
				layer++;
				T->t[i].value.S = new char[1024];
				f >> T->t[i].value.S;
				break;
			}
			case DEDENT:{
				T->t[i].layer = --layer;
				T->t[i].value.S = new char[1024];
				f >> T->t[i].value.S;
				break;
			}
			case ENDMARKER:{
				Break = 1;
				T->t[i].value.S = new char[1024];
				f >> T->t[i].value.S;
				break;
			}
			default:{
				T->t[i].value.S = new char[1024];
				f >> T->t[i].value.S;
				break;
			}
		}
		if (!f.eof()){
			T->t[i].availability = 1;
		}
		if (Break)
			break;
	}
	T->Size = i;
	f.close();
	return 0;
};
int yylex() {
	int i = T->Pointer;
	if (T->t[i].availability == 0)
		return 0;
	switch (T->t[i].type) {
		case STRING:{
			yylval.String = T->t[i].value.S;
			break;
		}
		case NUMBER:{
			yylval.Double = T->t[i].value.D;
			break;
		}
		case CHAR:{
			yylval.Char = T->t[i].value.C;
			break;
		}
		case NAME:{
			yylval.Name = T->t[i].value.S;
			break;
		}
		case INDENT:{
			break;
		}
		case DEDENT:{
			break;
		}
		default:{
			yylval.Name = T->t[i].value.S;
			break;
		}
	}
	T->Pointer++;
	return T->t[i].type;
}
void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}