%{
#include "iostream"
#include "ctype.h"
#include "malloc.h"
#include "fstream"
#include "math.h"
#include "string.h"

using namespace std;
ofstream fout_diag("PARSER.log", ios::out);
const int TOKEN_TABLE_SIZE = 4096;

typedef union {
	double Number;
	char * String;
	char * Name;
	char Char;
	bool Bool;
} SValue;

class _Object {
public:
	union {
	double Number;
	char * String;
	char Char;
	} Value;
	_Object(){
		Value.Number = 0;
		Value.String = 0;
		Value.Char = 0;
	};
};
class Token {
public:
	int lineno;
	int type;
	int layer;
	int availability;
	_Object Object;
	Token(){
		layer = 0;
		availability = 0;
		lineno = 0;
		type = 0;
	};
};
class TokenTable {
public:
	int Pointer;
	int Size;
	Token * t;
	TokenTable() {
		Size = 0;
		t = new Token[TOKEN_TABLE_SIZE];
		Pointer = 0;
	}
};
TokenTable * T = new TokenTable;
#include "ast.h"
#include "symtable.h"
union YYSTYPE{
	ast AST;
	double Number;
	char * String;
	char * Name;
	char Char;
	bool Bool;
};
int yylex();
int ReadTokens(ifstream &f, TokenTable * T);
void PrintTokens(TokenTable * T);
void yyerror(char *s);
char * inttype(int type);
ast newnode(char * symbol, int nodetype, int valuetype = 0);
SymTable addEntry(char * SYMNAME, int BEGIN, int END, int TYPE, SValue VALUE);//Definitions after main
void disptable();
SymTable searchTable(char * NAME);
SymTable initTable();
void interpret_input();
void interpret_stmt(ast N);
void interpret_expr_stmt(ast N);
void interpret_expr(ast N);
void interpret_xor_expr(ast N);
void interpret_and_expr(ast N);
void interpret_shift_expr(ast N);
void interpret_arith_expr(ast N);
void interpret_term(ast N);
void interpret_factor(ast N);
void interpret_power(ast N);
void interpret_atom_expr(ast N);
#include "stack.h"
%}
%define api.value.type		{union YYSTYPE}
%token	<Number>			NUMBER
%token	<String>			STRING
%token	<Name>				NAME
%token	<Char>				CHAR
%token	<Bool>				BOOL
%token	INDENT
%token	DEDENT
%token	ENDMARKER
%token	UNKNOWN
%token	TRUE				"True"
%token	FALSE				"False"
%token	ELLIPSIS			"..."
%token	LBRACE				"}"
%token	RBRACE				"{"
%token	COLON				":"
%token	EQUAL				"="
%token	AT					"@"
%token	SEMI				";"
%token	NEWLINE				"\n"
%token	FROM				"from"
%token	AS					"as"
%token	IS					"is"
%token	WHILE				"while"
%token	BREAK				"break"
%token	CONTINUE			"continue"
%token	ELIF				"elif"
%token	ELSE				"else"
%token	PASS				"pass"
%token	RETURN				"return"
%token	CLASS				"class"
%token	NOT					"not"
%token	AND					"and"
%token	OR					"or"
%token	IF					"if"
%token	DEF					"def"
%token	DOUBLESTAR			"**"
%token	DOUBLESLASH			"//"
%token	LESS				"<" 
%token	LESSEQUAL			"<="
%token	EQEQUAL				"=="
%token	NOTEQUAL			"!="
%token	GREATEREQUAL		">="
%token	GREATER				">"
%token	PLUS				"+"
%token	MINUS				"-"
%token	STAR				"*"
%token	SLASH				"/"
%token	PERCENT				"%"
%token	COMMA				","
%token	DOT					"."
%token	LPAR				"("
%token	RPAR				")"
%token	LSQB				"["
%token	RSQB				"]"
%token	PLUSEQUAL			"+="
%token	MINEQUAL			"-="
%token	STAREQUAL			"*="
%token	SLASHEQUAL			"/="
%token	VBAREQUAL			"|="
%token	AMPEREQUAL			"&="
%token	CIRCUMFLEXEQUAL		"^="
%token	ATEQUAL				"@="
%token	DOUBLESLASHEQUAL	"//="
%token	PERCENTEQUAL		"%="
%token	DOUBLESTAREQUAL		"**="
%token	VBAR				"|"
%token	AMPER				"&"
%token	CIRCUMFLEX			"^"
%token	TILDE				"~"
%token	LEFTSHIFT			"<<"
%token	LEFTSHIFTEQUAL		"<<="
%token	RIGHTSHIFT			">>"
%token	RIGHTSHIFTEQUAL		">>="
%token	RARROW				"->"
%precedence "="
%right "**" /* exponentiation */
%left "-" "+"
%left "*" "/"

%%
input:
	file_input ENDMARKER {
		$<AST>$ = newnode("input", 1, 0);
		$<AST>$->l = $<AST>1;
		ROOT = $<AST>$;
		fout_diag << "BISON\tinput : file_input ENDMARKER\n";
	};

and_expr:
	shift_expr {
		$<AST>$ = newnode("and_expr", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON\tand_expr : shift_expr\n";
	}|
	and_expr "&" shift_expr {
		$<AST>$ = newnode("and_expr", 2);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON\tand_expr : and_expr \"&\" shift_expr\n";
	};

and_test:
	not_test {
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\tand_test : not_test\n";
	}|
	and_test "and" not_test {
		$<AST>$ = newnode("and_test", 2);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
	};

arglist					: arglist_sub
						| arglist_sub ","
						;
arglist_sub				: argument
						| arglist_sub "," argument
						;
argument:
	test {
		fout_diag << "BISON\targument : test\n";
	}|
	test "=" test
	|
	"**" test
	|
	"*" test 
	;

arith_expr:
	term {
		$<AST>$ = newnode("arith_expr", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON\tarith_expr : term\n";
	}|
	arith_expr "+" term {
		$<AST>$ = newnode("arith_expr", 2);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON\tarith_expr : arith_expr \"+\" term\n";
	}|
	arith_expr "-" term {
		$<AST>$ = newnode("arith_expr", 3);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON\tarith_expr : arith_expr \"-\" term\n";
	};

atom:
	"True" {
		$<AST>$ = newnode("atom", 1, BOOL);
		$<AST>$->Value.Bool = true;
	}|
	"False" {
		$<AST>$ = newnode("atom", 2, BOOL);
		$<AST>$->Value.Bool = false;
	}|
	NAME {
		$<AST>$ = newnode("atom", 3, NAME);
		$<AST>$->Value.Name = $<Name>1;
		fout_diag << "BISON\tatom : NAME\n";
	}|
	STRING {
		$<AST>$ = newnode("atom", 4, STRING);
		$<AST>$->Value.String = $<String>1;
		fout_diag << "BISON\tatom : STRING\n";
	}|
	CHAR {
		$<AST>$ = newnode("atom", 5, CHAR);
		$<AST>$->Value.Char = $<Char>1;
		fout_diag << "BISON\tatom : NUMBER\n";
	}|
	NUMBER {
		$<AST>$ = newnode("atom", 6, NUMBER);
		$<AST>$->Value.Number = $<Number>1;
		fout_diag << "BISON\tatom : NUMBER\n";
	};

atom_expr:
	atom {
		$<AST>$ = newnode("atom_expr", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON\tatom_expr : atom\n";
	}|
	"(" expr ")" {
		$<AST>$ = newnode("atom_expr", 2);
		$<AST>$->l = $<AST>2;
		fout_diag << "BISON\tatom_expr : \"(\" expr \")\"\n";
	}|
	atom trailer_plus {
		fout_diag << "BISON\tatom_expr : atom trailer_plus\n";		
	};

break_stmt:
	"break" {
		$<AST>$ = newnode("break_stmt", BREAK);
	};

classdef:
	"class" NAME ":" suite {
		fout_diag << "BISON\tclassdef : \"class\" NAME : suite\n";
	}|
	"class" NAME "(" ")" ":" suite
	|
	"class" NAME "(" arglist ")" ":" suite
	;

comparison:
	expr {
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\tcomparison : expr\n";
	}|
	comparison comp_op expr {
		$<AST>$ = newnode("comparison", 2);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON\tcomparison : comparison comp_op expr\n";
	};

compound_stmt:
	if_stmt {
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\tcompound_stmt : if_stmt\n";
	}|
	while_stmt{
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\tcompound_stmt : while_stmt\n";
	}|
	funcdef {
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\tcompound_stmt : funcdef\n";
	}|
	classdef{
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\tcompound_stmt : classdef\n";
	};

comp_op:
	"<" {
		$<AST>$ = newnode("comp_op", NUMBER);
		$<AST>$->Value.Number = LESS;
		fout_diag << "BISON\tcomp_op : \"<\"\n";
	}|
	">" {
		$<AST>$ = newnode("comp_op", NUMBER);
		$<AST>$->Value.Number = GREATER;
		fout_diag << "BISON\tcomp_op : \">\"\n";
	}|
	"==" {
		$<AST>$ = newnode("comp_op", NUMBER);
		$<AST>$->Value.Number = EQEQUAL;
		fout_diag << "BISON\tcomp_op : \"==\"\n";
	}|
	">=" {
		$<AST>$ = newnode("comp_op", NUMBER);
		$<AST>$->Value.Number = GREATEREQUAL;
		fout_diag << "BISON\tcomp_op : \">=\"\n";
	}|
	"<=" {
		$<AST>$ = newnode("comp_op", NUMBER);
		$<AST>$->Value.Number = LESSEQUAL;
		fout_diag << "BISON\tcomp_op : \"<=\"\n";
	}|
	"<>" {
		$<AST>$ = newnode("comp_op", NUMBER);
		$<AST>$->Value.Number = NOTEQUAL;
		fout_diag << "BISON\tcomp_op : \"<>\"\n";
	}|
	"!=" {
		$<AST>$ = newnode("comp_op", NUMBER);
		$<AST>$->Value.Number = NOTEQUAL;
		fout_diag << "BISON\tcomp_op : \"!=\"\n";
	}|
	"is" {
		$<AST>$ = newnode("comp_op", NUMBER);
		$<AST>$->Value.Number = IS;
		fout_diag << "BISON\tcomp_op : \"is\"\n";
	}|
	"is" "not" {
		$<AST>$ = newnode("comp_op", NUMBER);
		$<AST>$->Value.Number = -2;
		fout_diag << "BISON\tcomp_op : \"is\" \"not\"\n";
	};

continue_stmt			: "continue"
						;

expr:
	xor_expr {
		$<AST>$ = newnode("expr", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON\texpr : xor_expr\n";
	}|
	expr "|" xor_expr {
		$<AST>$ = newnode("expr", 2);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON\texpr : expr \"|\" xor_expr\n";
	};

expr_stmt:
	NAME "=" expr {
		$<AST>$ = newnode("expr_stmt", 1);
		$<AST>$->l = newnode("NAME", NAME);//???????
		$<AST>$->l->Value.Name = $<Name>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON\texpr_stmt : NAME \'=' expr\n";
	};

factor:
	power {
		$<AST>$ = newnode("factor", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON\tfactor : power\n";
	}|
	"+" factor {
		$<AST>$ = newnode("factor", 2);
		$<AST>$->l = $<AST>2;
		fout_diag << "BISON\tfactor : \"+\" factor\n";
	}|
	"-" factor{
		$<AST>$ = newnode("factor", 3);
		$<AST>$->l = $<AST>2;
		fout_diag << "BISON\tfactor : \"-\" factor\n";
	};

file_input:
	NEWLINE {
		$<AST>$ = newnode("file_input", 1);
		$<AST>$->r = newnode("NEWLINE", NEWLINE);
		fout_diag << "BISON\tfile_input : NEWLINE\n";
		
	}|
	stmt {
		$<AST>$ = newnode("file_input", 2);
		$<AST>$->r = $<AST>1;
		fout_diag << "BISON\tfile_input : stmt\n";
	}|
	file_input NEWLINE {
		$<AST>$ = newnode("file_input", 3);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = newnode("NEWLINE", NEWLINE);
		fout_diag << "BISON\tfile_input : file_input_sub NEWLINE\n";
	}|
	file_input stmt {
		$<AST>$ = newnode("file_input", 4);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>2;
		fout_diag << "BISON\tfile_input : file_input_sub stmt\n";
	};

flow_stmt:
	break_stmt {
		fout_diag << "BISON\tflow_stmt : break_stmt\n";
	}|
	continue_stmt {
		fout_diag << "BISON\tflow_stmt : continue_stmt\n";
	}|
	return_stmt {
		fout_diag << "BISON\tflow_stmt : return_stmt\n";
	};

funcdef:
	"def" NAME parameters ":" suite {
		fout_diag << "BISON\tfuncdef : \"def\" NAME parameters \":\" suite\n";
		//To be fulfilled, yet not right now!
	};

if_stmt:
	"if" test ":" suite if_stmt_sub {
	}|
	"if" test ":" suite if_stmt_sub "else" ":" suite {
	};

if_stmt_sub:
	%empty {
		$<AST>$ = newnode("NULL", 0);
	}|
	if_stmt_sub "elif" test ":" suite {
	};

not_test:
	"not" not_test {
		$<AST>$ = newnode("not_test", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON\tnot_test : \"not\" not_test\n";
	}|
	comparison {
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\tnot_test : comparison\n";
	};

or_test:
	and_test {
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\tor_test : and_test\n";
	}|
	or_test "or" and_test {
		$<AST>$ = newnode("or_test", 2);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON\tor_test : or_test \"or\" and_test\n";
	};

parameters				: "(" ")"																{fout_diag << "BISON\tparameters : \"(\" \")\"\n";}
						| "(" typedargslist ")"													{fout_diag << "BISON\tparameters : \"(\" typedargslist \")\"\n";}
						;
pass_stmt:
	"pass" {
		fout_diag << "BISON\tflow_stmt : return_stmt\n";
	};

power:
	atom_expr {
		$<AST>$ = newnode("power", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON\tpower : atom_expr" << "\n";
	}|
	atom_expr "**" factor {
		$<AST>$ = newnode("power", 2);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON\tpower : atom_expr \"**\" factor" << "\n";
	};

return_stmt:
	"return" {
		fout_diag << "BISON\treturn_stmt : \"return\"\n";
	}|
	"return" testlist {
		fout_diag << "BISON\treturn_stmt : \"return\" testlist\n";
	};

shift_expr:
	arith_expr {
		$<AST>$ = newnode("shift_expr", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON\tshift_expr : arith_expr\n";
	}|
	shift_expr "<<" arith_expr {
		$<AST>$ = newnode("shift_expr", 2);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON\tshift_expr : shift_expr \"<<\" arith_expr\n";
	}|
	shift_expr ">>" arith_expr {
		$<AST>$ = newnode("shift_expr", 3);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON\tshift_expr : shift_expr \">>\" arith_expr\n";
	};

simple_stmt:
	small_stmt NEWLINE {
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\tsimple_stmt : small_stmt NEWLINE\n";
	};

sliceop					: ":"
						| ":" test
						;
small_stmt:
	expr_stmt {
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\tsmall_stmt : expr_stmt\n";
	}|
	pass_stmt {
		fout_diag << "BISON\tsmall_stmt : pass_stmt\n";
	}|
	flow_stmt {
		fout_diag << "BISON\tsmall_stmt : flow_stmt\n";
	};

stmt:
	simple_stmt {
		$<AST>$ = newnode("stmt", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON\tstmt : simple_stmt\n";
	}|
	compound_stmt {
		$<AST>$ = newnode("stmt", 2);
		$<AST>$->r = $<AST>1;
		fout_diag << "BISON\tstmt : compound_stmt\n";
	};

subscript				: test
						| ":"
						| ":" sliceop
						| ":" test
						| ":" test sliceop
						| test ":"
						| test ":" sliceop
						| test ":" test
						| test ":" test sliceop
						;
subscriptlist			: subscriptlist_sub
						| subscriptlist_sub ","
						;
subscriptlist_sub		: subscript
						| subscriptlist_sub "," subscript 
						;

suite:
	simple_stmt {
		fout_diag << "BISON\tsuite : simple_stmt\n";
	}|
	NEWLINE INDENT suite_sub DEDENT {
		fout_diag << "BISON\tsuite : NEWLINE INDENT suite_sub DEDENT\n";
	};

suite_sub:
	stmt {
		fout_diag << "BISON\tsuite_sub : stmt\n";
	}|
	suite_sub stmt {
		fout_diag << "BISON\tsuite_sub : suite_sub stmt\n";
	};

term:
	factor {
		$<AST>$ = newnode("term", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON\tterm : factor\n";
	}|
	term "*" factor {
		$<AST>$ = newnode("term", 2);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON\tterm : term \"*\" factor\n";
	}|
	term "/" factor {
		$<AST>$ = newnode("term", 3);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON\tterm : term \"/\" factor\n";
	}|
	term "%" factor {
		$<AST>$ = newnode("term", 4);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON\tterm : term \"%\" factor\n";
	}|
	term "//" factor {
		$<AST>$ = newnode("term", 5);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON\tterm : term \"//\" factor\n";
	};

test:
	or_test {
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\ttest : or_test\n";
	}|
	or_test "if" or_test "else" test
	;

testlist:
	testlist_sub {
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\ttestlist : test testlist_sub\n";
	}|
	testlist_sub ","
	;

testlist_sub:
	test {
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\ttestlist_sub : \n";
	}|
	testlist_sub "," test
	;

tfpdef: NAME;

trailer					: "(" ")"																{fout_diag << "BISON\ttrailer : \"(\" \")\"\n";}
						| "(" arglist ")"														{fout_diag << "BISON\ttrailer : \"(\" arglist \")\"\n"; /*$$ = $2*/}
						| "[" subscriptlist "]"													{fout_diag << "BISON\ttrailer : \"[\" subscriptlist \"]\"\n"; /*$$ = $2*/}
						| "." NAME																{fout_diag << "BISON\ttrailer : \".\" NAME\n";}
						;

trailer_plus:
	trailer
	|
	trailer_plus trailer {
		fout_diag << "BISON\ttrailer_star : trailer_star trailer\n";
	};

typedargslist			: tfpdef
						| typedargslist_sub
						;

typedargslist_sub		: "," tfpdef
						| typedargslist_sub "," tfpdef
						;
						
while_stmt:
"while" test ":" suite
|
"while" test ":" suite "else" ":" suite
;

xor_expr:
	and_expr {
		$<AST>$ = newnode("xor_expr", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON\txor_expr : and_expr\n";
	}|
	xor_expr "^" and_expr {
		$<AST>$ = newnode("xor_expr", 2);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON\txor_expr : xor_expr \"^\" and_expr\n";
	};
%%

int main(int argc, char * argv[]) {
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
	PrintTokens(T);
	initTable();
	yyparse();
	fout_diag << "\n" << "PARSING PROCESS SUCCESS" << "\n";
	fout_diag.close();
	fout_diag.open("INTERPRETER.log", ios::out);
	interpret_input();
	disptable();
	fout_diag << "\n" << "INTERPRETING PROCESS SUCCESS" << "\n";
	fout_diag.close();
	return 0;
};
void PrintTokens(TokenTable * T) {
	system("CLS");
	for (int i = 0; i < TOKEN_TABLE_SIZE && T->t[i].availability != 0; i++) {
		fout_diag << T->t[i].lineno << "\t" << T->t[i].layer << "\t";
		switch (T->t[i].type) {
			case STRING:{
				fout_diag << "STRING" << "\t" << T->t[i].Object.Value.String;
				break;
			}
			case NUMBER:{
				fout_diag << "NUMBER" << "\t" << T->t[i].Object.Value.Number;
				break;
			}
			case CHAR:{
				fout_diag << "CHAR" << "\t" << T->t[i].Object.Value.Char;
				break;
			}
			case NAME:{
				fout_diag << "NAME" << "\t" << T->t[i].Object.Value.String;
				break;
			}
			case INDENT:{
				fout_diag << "INDENT";
				break;
			}
			case DEDENT:{
				fout_diag << "DEDENT";
				break;
			}
			case ENDMARKER:{
				fout_diag << "ENDMARKER";
				break;
			}
			default:{
				fout_diag << T->t[i].Object.Value.String;
				break;
			}
		}
		fout_diag << endl;
	}
	fout_diag << endl;
};
int ReadTokens(ifstream &f, TokenTable * T) {
	int layer = 0;
	int Break = 0;
	int i = 0;
	for (; i < TOKEN_TABLE_SIZE; i++) {
		if (f.eof()){
			cout << "EOF" << endl;
			break;
		}
		f >> T->t[i].lineno;
		f >> T->t[i].type;
		T->t[i].layer = layer;
		switch (T->t[i].type) {
			case STRING:{
				char temp;
				f.get(temp);
				f.get(temp);
				T->t[i].Object.Value.String = new char[1024];
				f.getline(T->t[i].Object.Value.String, 1024);
				for (int j = 0; j < 1024; j++)
					if (T->t[i].Object.Value.String[j] == '\0')
						T->t[i].Object.Value.String[j - 1] = '\0';
				break;
			}
			case NUMBER:{
				f >> T->t[i].Object.Value.Number;
				break;
			}
			case CHAR:{
				char temp;
				f.get(temp);
				f.get(temp);
				f.get(T->t[i].Object.Value.Char);
				f.get(temp);
				break;
			}
			case NAME:{
				T->t[i].Object.Value.String = new char[1024];
				f >> T->t[i].Object.Value.String;
				break;
			}
			case INDENT:{
				layer++;
				T->t[i].Object.Value.String = new char[1024];
				f >> T->t[i].Object.Value.String;
				free(T->t[i].Object.Value.String);
				break;
			}
			case DEDENT:{
				T->t[i].layer = --layer;
				T->t[i].Object.Value.String = new char[1024];
				f >> T->t[i].Object.Value.String;
				free(T->t[i].Object.Value.String);
				break;
			}
			case ENDMARKER:{
				Break = 1;
				T->t[i].Object.Value.String = new char[1024];
				f >> T->t[i].Object.Value.String;
				free(T->t[i].Object.Value.String);
				break;
			}
			default:{
				T->t[i].Object.Value.String = new char[1024];
				f >> T->t[i].Object.Value.String;
				break;
			}
		}
		if (!f.eof()){
			T->t[i].availability = 1;
		}
		if (Break)
			break;
		if (T->t[i].type == UNKNOWN) {
			i = (i == 0)? 0: i - 1;
			continue;
		}
	}
	T->Size = i;
	f.close();
	return 0;
};
int yylex() {
	int i = T->Pointer;
	if (i == TOKEN_TABLE_SIZE)
		return -1;
	if (T->t[i].availability == 0)
		return 0;
	switch (T->t[i].type) {
		case STRING:{
			yylval.String = T->t[i].Object.Value.String;
			fout_diag << "FLEX\tSTRING\t" << yylval.String << endl;
			break;
		}
		case NUMBER:{
			yylval.Number = T->t[i].Object.Value.Number;
			fout_diag << "FLEX\tNUMBER\t" << yylval.Number << endl;
			break;
		}
		case CHAR:{
			yylval.Char = T->t[i].Object.Value.Char;
			fout_diag << "FLEX\tCHAR\t" << yylval.Char << endl;
			break;
		}
		case NAME:{
			yylval.Name = T->t[i].Object.Value.String;
			fout_diag << "FLEX\tNAME\t" << yylval.Name << endl;
			break;
		}
		case INDENT:{
			fout_diag << "FLEX\tINDENT" << endl;
			break;
		}
		case DEDENT:{
			fout_diag << "FLEX\tDEDENT" << endl;
			break;
		}
		case NEWLINE:{
			fout_diag << "FLEX\tNEWLINE" << endl;
			break;
		}
		case ENDMARKER:{
			fout_diag << "FLEX\tENDMARKER" << endl;
			break;
		}
		default:{
			yylval.Name = T->t[i].Object.Value.String;
			fout_diag << "FLEX\t" << yylval.Name << endl;
			break;
		}
	}
	T->Pointer++;
	return T->t[i].type;
}
void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
};
ast newnode(char * symbol, int nodetype, int valuetype) {
	ast N = new asn;
	N->nodetype = nodetype;
	N->valuetype = valuetype;
	N->symbol = new char[128];
	strcpy(N->symbol, symbol);
	if (nodetype == NUMBER || nodetype == BOOL || nodetype == NAME || nodetype == CHAR || nodetype == STRING)
		N->valuenode = true;
	return N;
};
SymTable addEntry(char * SYMNAME, int BEGIN, int END, int TYPE) {
	SymTable T = new symentry;
	T->NAME = SYMNAME;
	T->LIMITS[0] = BEGIN;
	T->LIMITS[1] = END;
	T->TYPE = TYPE;
	T->NEXT = SYMTABLE;
	SYMTABLE = T;
	return T;
};
void interpret_input() {
	ast N = ROOT;
	if (strcmp(N->symbol, "input")){
		fout_diag << "this is not a input node" << "\n";
		return;
	}
	while (N){
		if (N->r && !strcmp(N->r->symbol, "stmt")){
			fout_diag << "FOUND A stmt NODE AND PUSHED IT INTO THE STACK" << "\n";
			STACK.PushStack(N->r);
		}
		if (N->l){
			if (!strcmp(N->l->symbol, "file_input")){//如果是file_input
				fout_diag << "WENT INTO A file_input NODE" << "\n";
				N = N->l;
			}
			else {
				if (!strcmp(N->r->symbol, "stmt")){
					fout_diag << "FOUND A stmt NODE AND PUSHED IT INTO THE STACK" << "\n";
					STACK.PushStack(N->r);
				}
				fout_diag << "NO file_input NODES ANYMORE" << "\n";
				break;
			}
		}
		else 
			break;
	}
	STACK.ClearStack();
}
char * inttype(int type){
	switch (type) {
		case EQUAL:{
			char * R = new char[32];
			strcpy(R, "EQUAL");
			return R;
			break;
		}
		case NUMBER:{
			char * R = new char[32];
			strcpy(R, "NUMBER");
			return R;
			break;
		}
		case STRING:{
			char * R = new char[32];
			strcpy(R, "STRING");
			return R;
			break;
		}
		case CHAR:{
			char * R = new char[32];
			strcpy(R, "CHAR");
			return R;
			break;
		}
		case NAME:{
			char * R = new char[32];
			strcpy(R, "NAME");
			return R;
			break;
		}
		case BOOL:{
			char * R = new char[32];
			strcpy(R, "BOOL");
			return R;
			break;
		}
		case 0:{
			char * R = new char[32];
			strcpy(R, "NULL");
			return R;
			break;
		}
		default:{
			char * R = new char[32];
			strcpy(R, "UNKNOWN");
			return R;
			break;
		}
	}
}
void disptable(){
	SymTable S = SYMTABLE;
	fout_diag << "SYMBOL TABLE" << "\n";
	fout_diag << "NAME" << "\t" << "LBTM" << "\t" << "LTOP" << "\t" << "TYPE" << "\t" << "VALUE" << "\n";
	while (S) {
		if (S->TYPE){
			fout_diag << S->NAME << "\t" << S->LIMITS[0] << "\t" << S->LIMITS[1] << "\t" << inttype(S->TYPE) << "\t";
			switch (S->TYPE) {
				case NUMBER:{
					fout_diag << S->VALUE.Number << "\n";
					break;
				}
				case STRING:{
					fout_diag << S->VALUE.String << "\n";
					break;
				}
				case CHAR:{
					fout_diag << S->VALUE.Char << "\n";
					break;
				}
				case BOOL:{
					fout_diag << S->VALUE.Bool << "\n";
					break;
				}
			}
		}
		S = S->NEXT;
	}
};
void interpret_stmt(ast N){
	if (strcmp(N->symbol, "stmt")){
		fout_diag << "interpret_stmt:\tthis is not a stmt node" << "\n";
		fout_diag << "interpret_stmt:\tthis is a " << N->symbol << " node" << "\n";
		return;
	}
	fout_diag << "pretending to interpret a stmt" << "\n";
	if (N->l && !N->r){//simple_stmt
		fout_diag << "pretending to interpret a simple_stmt" << "\n";
		N = N->l;
		fout_diag << "entered a node with type" << "\t" << inttype(N->nodetype) << "\n";
		if (!strcmp(N->symbol, "expr_stmt")){
			fout_diag << "interpret_stmt:\tfound a expr_stmt" << "\n";
			interpret_expr_stmt(N);
		};
	}
	if (N->r && !N->l){//compound_stmt
		fout_diag << "pretending to interpret a compound_stmt" << "\n";
	}
};
void interpret_expr_stmt(ast N){
	fout_diag << "interpret_expr_stmt" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "expr_stmt")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A expr_stmt NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	interpret_expr(N->r);
	SymTable S = searchTable(N->l->Value.Name);
	if (S){
		fout_diag << "\t" << "EXISTING SYMBOL FOUND" << "\n";
		if (S->TYPE && S->TYPE != N->r->valuetype){
			fout_diag << "\t" << "INCOMPATIBLE VALUE TYPE" << "\n";
			return;
		}
	}
	else {
		fout_diag << "\t" << "TIS A NEW SYMBOL" << "\n";
		S = addEntry(N->l->Value.Name, -1, -1, N->r->valuetype);
	}
	S->VALUE = N->r->Value;
};
void interpret_expr(ast N) {
	fout_diag << "interpret_expr" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "expr")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A expr NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//expr: xor_expr
		interpret_xor_expr(N->l);
		N->valuetype = N->l->valuetype;
		N->Value = N->l->Value;
	}
	if (N->nodetype == 2) {//expr : expr "|" xor_expr
		interpret_expr(N->l);
		interpret_xor_expr(N->r);
		double buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "logical xor IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Number;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "logical xor IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Number;
		}
		if (N->l->valuetype == NUMBER)
			buff1 = N->l->Value.Number;
		if (N->r->valuetype == NUMBER)
			buff2 = N->r->Value.Number;
		if (N->l->valuetype != NUMBER && N->l->valuetype != NAME|| N->r->valuetype != NUMBER && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << "logical xor IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		if (int(buff1) != buff1 || int(buff2) != buff2) {
			fout_diag << "\t" << "ERROR" << "\t" << "logical xor CAN ONLY PROCEED WITH INTEGERS" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = int(buff1) | int(buff2);
	}
};
void interpret_xor_expr(ast N) {
	fout_diag << "interpret_xor_expr" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "xor_expr")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A xor_expr NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//xor_expr : and_expr
		interpret_and_expr(N->l);
		N->valuetype = N->l->valuetype;
		N->Value = N->l->Value;
	}
	if (N->nodetype == 2) {//xor_expr : xor_expr "^" and_expr
		interpret_xor_expr(N->l);
		interpret_and_expr(N->r);
		double buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "logical xor IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Number;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "logical xor IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Number;
		}
		if (N->l->valuetype == NUMBER)
			buff1 = N->l->Value.Number;
		if (N->r->valuetype == NUMBER)
			buff2 = N->r->Value.Number;
		if (N->l->valuetype != NUMBER && N->l->valuetype != NAME|| N->r->valuetype != NUMBER && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << "logical xor IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		if (int(buff1) != buff1 || int(buff2) != buff2) {
			fout_diag << "\t" << "ERROR" << "\t" << "logical xor CAN ONLY PROCEED WITH INTEGERS" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = int(buff1) ^ int(buff2);
	}
};
void interpret_and_expr(ast N) {
	fout_diag << "interpret_and_expr" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "and_expr")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A and_expr NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//and_expr : shift_expr
		interpret_shift_expr(N->l);
		N->valuetype = N->l->valuetype;
		N->Value = N->l->Value;
	}
	if (N->nodetype == 2) {//and_expr : and_expr "&" shift_expr
		interpret_and_expr(N->l);
		interpret_shift_expr(N->r);
		double buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "logical and IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Number;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "logical and IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Number;
		}
		if (N->l->valuetype == NUMBER)
			buff1 = N->l->Value.Number;
		if (N->r->valuetype == NUMBER)
			buff2 = N->r->Value.Number;
		if (N->l->valuetype != NUMBER && N->l->valuetype != NAME|| N->r->valuetype != NUMBER && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << "logical and IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		if (int(buff1) != buff1 || int(buff2) != buff2) {
			fout_diag << "\t" << "ERROR" << "\t" << "logical and CAN ONLY PROCEED WITH INTEGERS" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = int(buff1) & int(buff2);
	}
};
void interpret_shift_expr(ast N) {
	fout_diag << "interpret_shift_expr" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "shift_expr")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A shift_expr NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//shift_expr : arith_expr
		interpret_arith_expr(N->l);
		N->valuetype = N->l->valuetype;
		N->Value = N->l->Value;
	}
	if (N->nodetype == 2) {//shift_expr : shift_expr "<<" arith_expr
		interpret_shift_expr(N->l);
		interpret_arith_expr(N->r);
		double buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "<< IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Number;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "<< IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Number;
		}
		if (N->l->valuetype == NUMBER)
			buff1 = N->l->Value.Number;
		if (N->r->valuetype == NUMBER)
			buff2 = N->r->Value.Number;
		if (N->l->valuetype != NUMBER && N->l->valuetype != NAME|| N->r->valuetype != NUMBER && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << "<< IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		if (int(buff1) != buff1 || int(buff2) != buff2) {
			fout_diag << "\t" << "ERROR" << "\t" << "DIGITS MOVE CAN ONLY PROCEED WITH INTEGERS" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = buff1 * pow(2, int(buff2));
	}
	if (N->nodetype == 3) {//shift_expr : shift_expr ">>" arith_expr
		interpret_shift_expr(N->l);
		interpret_arith_expr(N->r);
		double buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << ">> IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Number;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << ">> IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Number;
		}
		if (N->l->valuetype == NUMBER)
			buff1 = N->l->Value.Number;
		if (N->r->valuetype == NUMBER)
			buff2 = N->r->Value.Number;
		if (N->l->valuetype != NUMBER && N->l->valuetype != NAME|| N->r->valuetype != NUMBER && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << ">> IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		if (int(buff1) != buff1 || int(buff2) != buff2) {
			fout_diag << "\t" << "ERROR" << "\t" << "DIGITS MOVE CAN ONLY PROCEED WITH INTEGERS" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = buff1 / pow(2, int(buff2));
	}
};
void interpret_arith_expr(ast N) {
	fout_diag << "interpret_arith_expr" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "arith_expr")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A arith_expr NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//arith_expr : term
		interpret_term(N->l);
		N->valuetype = N->l->valuetype;
		N->Value = N->l->Value;
	}
	if (N->nodetype == 2) {//arith_expr : arith_expr "+" term
		interpret_arith_expr(N->l);
		interpret_term(N->r);
		double buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "plus IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Number;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "plus IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Number;
		}
		if (N->l->valuetype == NUMBER)
			buff1 = N->l->Value.Number;
		if (N->r->valuetype == NUMBER)
			buff2 = N->r->Value.Number;
		if (N->l->valuetype != NUMBER && N->l->valuetype != NAME|| N->r->valuetype != NUMBER && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << "plus IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = buff1 + buff2;
	}
	if (N->nodetype == 3) {//arith_expr : arith_expr "-" term
		interpret_arith_expr(N->l);
		interpret_term(N->r);
		double buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "minus IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Number;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "minus IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Number;
		}
		if (N->l->valuetype == NUMBER)
			buff1 = N->l->Value.Number;
		if (N->r->valuetype == NUMBER)
			buff2 = N->r->Value.Number;
		if (N->l->valuetype != NUMBER && N->l->valuetype != NAME|| N->r->valuetype != NUMBER && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << "minus IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = buff1 - buff2;
	}
};
void interpret_term(ast N) {
	fout_diag << "interpret_term" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "term")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A term NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//term : factor
		interpret_factor(N->l);
		N->valuetype = N->l->valuetype;
		N->Value = N->l->Value;
	}
	if (N->nodetype == 2) {//term : term "*" factor
		interpret_term(N->l);
		interpret_factor(N->r);
		double buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "mult IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Number;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "mult IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Number;
		}
		if (N->l->valuetype == NUMBER)
			buff1 = N->l->Value.Number;
		if (N->r->valuetype == NUMBER)
			buff2 = N->r->Value.Number;
		if (N->l->valuetype != NUMBER && N->l->valuetype != NAME|| N->r->valuetype != NUMBER && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << "mult IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = buff1 * buff2;
	}
	if (N->nodetype == 3) {//term : term "/" factor
		interpret_term(N->l);
		interpret_factor(N->r);
		double buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "didv IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Number;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "didv IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Number;
		}
		if (N->l->valuetype == NUMBER)
			buff1 = N->l->Value.Number;
		if (N->r->valuetype == NUMBER)
			buff2 = N->r->Value.Number;
		if (N->l->valuetype != NUMBER && N->l->valuetype != NAME|| N->r->valuetype != NUMBER && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << "didv IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = buff1 / buff2;
	}
	if (N->nodetype == 4) {//term : term "%" factor
		interpret_term(N->l);
		interpret_factor(N->r);
		double buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "mod IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Number;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "mod IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Number;
		}
		if (N->l->valuetype == NUMBER)
			buff1 = N->l->Value.Number;
		if (N->r->valuetype == NUMBER)
			buff2 = N->r->Value.Number;
		if (N->l->valuetype != NUMBER && N->l->valuetype != NAME|| N->r->valuetype != NUMBER && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << "mod IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		if (int(buff1) != buff1 || int(buff2) != buff2) {
			fout_diag << "\t" << "ERROR" << "\t" << "mod IS FOR INTEGERS ONLY" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = int(buff1) % int(buff2);
	}
	if (N->nodetype == 5) {//term : term "//" factor
		interpret_term(N->l);
		interpret_factor(N->r);
		double buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "fdv IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Number;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "fdv IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Number;
		}
		if (N->l->valuetype == NUMBER)
			buff1 = N->l->Value.Number;
		if (N->r->valuetype == NUMBER)
			buff2 = N->r->Value.Number;
		if (N->l->valuetype != NUMBER && N->l->valuetype != NAME|| N->r->valuetype != NUMBER && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << "fdv IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = floor(buff1 / buff2);
	}
};
void interpret_factor(ast N) {
	fout_diag << "interpret_factor" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "factor")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A factor NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//factor : power
		interpret_power(N->l);
		N->valuetype = N->l->valuetype;
		N->Value = N->l->Value;
	}
	if (N->nodetype == 2) {//factor : "+" factor
		interpret_factor(N->l);
		double buff;
		if (N->l->valuetype == NUMBER)
			buff = N->l->Value.Number;
		else if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "factor IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff = S->VALUE.Number;
		}
		else {
			fout_diag << "\t" << "ERROR" << "\t" << "factor IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = buff;
	}
	if (N->nodetype == 3) {//factor : "-" factor
		interpret_factor(N->l);
		double buff;
		if (N->l->valuetype == NUMBER)
			buff = N->l->Value.Number;
		else if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "factor IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff = S->VALUE.Number;
		}
		else {
			fout_diag << "\t" << "ERROR" << "\t" << "factor IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = -1.0 * buff;
	}
};
void interpret_power(ast N) {
	fout_diag << "interpret_power" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "power")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A power NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//power : atom_expr
		interpret_atom_expr(N->l);
		N->Value = N->l->Value;
		N->valuetype = N->l->valuetype;
	}
	if (N->nodetype == 2) {//power : atom_expr "**" factor
		interpret_atom_expr(N->l);
		interpret_factor(N->r);
		double buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "power IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Number;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "power IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Number;
		}
		if (N->l->valuetype == NUMBER)
			buff1 = N->l->Value.Number;
		if (N->r->valuetype == NUMBER)
			buff2 = N->r->Value.Number;
		if (N->l->valuetype != NUMBER && N->l->valuetype != NAME|| N->r->valuetype != NUMBER && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << "power IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = pow(buff1, buff2);
	}
};
void interpret_atom_expr(ast N) {
	fout_diag << "interpret_atom_expr" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "atom_expr")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT AN atom_expr NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//atom_expr : atom
		N->Value = N->l->Value;
		N->valuetype = N->l->valuetype;
	}
	if (N->nodetype == 2) {//atom_expr : "(" expr ")"
		interpret_expr(N->l);
		N->Value = N->l->Value;
		N->valuetype = N->l->valuetype;
	}
};