%{
#include "iostream"
#include "ctype.h"
#include "malloc.h"
#include "fstream"
#include "math.h"
#include "string.h"
#include "Headers\\color.h"

using namespace std;
ofstream fout_diag("PARSER.log", ios::out);
/**/
typedef union {
	double Number;
	char * String;
	char * Name;
	char Char;
	bool Bool;
} SValue;
/**/
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
const int TOKEN_TABLE_SIZE = 512;
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
int ReadTokens(ifstream &f, TokenTable * T);
void PrintTokens(TokenTable * T);
/**/
class asn {
public:
	int nodetype;
	bool valuenode;
	char * symbol;
	int valuetype;
	asn * j;
	asn * l;
	asn * r;
	SValue Value;
	asn() {
		symbol = 0;
		nodetype = 0;
		valuetype = 0;
		valuenode = false;
		l = 0;
		r = 0;
		j = 0;
		Value.Number = 0;
	};
};
typedef asn * ast;
ast ROOT = 0;
ast newnode(char * symbol, int nodetype, int valuetype = 0);
ast newnet(char * symbol, int nodetype, ast L = 0, ast R = 0, ast J = 0);
/**/
class symentry {
public:
	char * VALUE_TYPE_NAME;
	int LIMITS[2];
	int TYPE;
	SValue VALUE;
	symentry * NEXT;
	symentry() {
		VALUE_TYPE_NAME = NULL;
		TYPE = 0;
		VALUE.Number = 0;
		LIMITS[0] = -1;
		LIMITS[1] = -1;
		NEXT = NULL;
	};
};
typedef symentry * SymTable;
SymTable SYMTABLE = 0;
SymTable initTable();
SymTable searchTable(char * VALUE_TYPE_NAME);
void disptable();
SymTable addEntry(char * SYMNAME, int BEGIN, int END, int TYPE);
/**/
union YYSTYPE{
	ast AST;
	double Number;
	char * String;
	char * Name;
	char Char;
	bool Bool;
};
int yylex();
void yyerror(char *s);
/**/
char * inttype(int type);
/**/
void interpret_input();
void interpret_stmt(ast N);
void interpret_simple_stmt(ast N);
void interpret_small_stmt(ast N);
void interpret_compound_stmt(ast N);
void interpret_while_stmt(ast N);
void interpret_if_stmt(ast N);
void interpret_flow_stmt(ast N);
void interpret_test(ast N);
void interpret_or_test(ast N);
void interpret_and_test(ast N);
void interpret_not_test(ast N);
void interpret_comparison(ast N);
void interpret_suite(ast N);
void interpret_suite_sub(ast N);
void interpret_pass_stmt(ast N);
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
void interpret_print_stmt(ast N);
/**/
int STACK_SIZE = 100;
class _Stack {
public:
	int top;
	ast * S;
	_Stack(){
		top = -1;
		S = (ast *)calloc(STACK_SIZE, sizeof(ast));
	};
	void PushStack(ast T);
	void ClearStack();
};
_Stack MAINSTACK;
/**/
%}
%define api.value.type		{union YYSTYPE}
%token	<Number>			VALUE_TYPE_NUMBER
%token	<String>			VALUE_TYPE_STRING
%token	<Name>				VALUE_TYPE_NAME
%token	<Char>				VALUE_TYPE_CHAR
%token	<Bool>				VALUE_TYPE_BOOL
%token	INDENT
%token	DEDENT
%token	ENDMARKER
%token	UNKNOWN
%token	BOOL_TRUE			"True"
%token	BOOL_FALSE			"False"
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
%token	PRINT				"print"
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
		$<AST>$ = newnet("input", 1, $<AST>1);
		ROOT = $<AST>$;
		fout_diag << "BISON" << "\t" << "input : file_input ENDMARKER" << endl;
		cout << red << "BISON" << white << "\t" << "input : file_input ENDMARKER" << endl;
		cout << blue << "THE SYNTAX OF THE SOURCE FILE IS PERFECT" << endl;
	};
	
and_expr:
	shift_expr {
		$<AST>$ = newnet("and_expr", 1, $<AST>1);
		fout_diag << "BISON" << "\t" << "and_expr : shift_expr" << endl;
		cout << red << "BISON" << white << "\t" << "and_expr : shift_expr" << endl;
	}|
	and_expr "&" shift_expr {
		$<AST>$ = newnet("and_expr", 2, $<AST>1, $<AST>3);
		fout_diag << "BISON" << "\t" << "and_expr : and_expr \"&\" shift_expr" << endl;
		cout << red << "BISON" << white << "\t" << "and_expr : and_expr \"&\" shift_expr" << endl;
	};

and_test:
	not_test {
		$<AST>$ = newnet("and_test", 1, $<AST>1);
		fout_diag << "BISON" << "\t" << "and_test : not_test" << endl;
		cout << red << "BISON" << white << "\t" << "and_test : not_test" << endl;
	}|
	and_test "and" not_test {
		$<AST>$ = newnet("and_test", 2, $<AST>1, $<AST>3);
		fout_diag << "BISON" << "\t" << "and_test : and_test \"and\" not_test" << endl;
		cout << red << "BISON" << white << "\t" << "and_test : and_test \"and\" not_test" << endl;
	};

arglist:
	arglist_sub | arglist_sub "," ;

arglist_sub:
	argument | arglist_sub "," argument ;

argument:
	test | test "=" test | "**" test | "*" test ;

arith_expr:
	term {
		$<AST>$ = newnet("arith_expr", 1, $<AST>1);
		fout_diag << "BISON" << "\t" << "arith_expr : term" << endl;
		cout << red << "BISON" << white << "\t" << "arith_expr : term" << endl;
	}|
	arith_expr "+" term {
		$<AST>$ = newnet("arith_expr", 2, $<AST>1, $<AST>3);
		fout_diag << "BISON" << "\t" << "arith_expr : arith_expr \"+\" term" << endl;
		cout << red << "BISON" << white << "\t" << "arith_expr : arith_expr \"+\" term" << endl;
	}|
	arith_expr "-" term {
		$<AST>$ = newnet("arith_expr", 3, $<AST>1, $<AST>3);
		fout_diag << "BISON" << "\t" << "arith_expr : arith_expr \"-\" term" << endl;
		cout << red << "BISON" << white << "\t" << "arith_expr : arith_expr \"-\" term" << endl;
	};

atom:
	"True" {
		$<AST>$ = newnode("atom", 1, VALUE_TYPE_BOOL);
		$<AST>$->Value.Bool = true;
		fout_diag << "BISON" << "\t" << "atom : \"True\"" << endl;
		cout << red << "BISON" << white << "\t" << "atom : \"True\"" << endl;
	}|
	"False" {
		$<AST>$ = newnode("atom", 2, VALUE_TYPE_BOOL);
		$<AST>$->Value.Bool = false;
		fout_diag << "BISON" << "\t" << "atom : \"False\"" << endl;
		cout << red << "BISON" << white << "\t" << "atom : \"False\"" << endl;
	}|
	VALUE_TYPE_NAME {
		$<AST>$ = newnode("atom", 3, VALUE_TYPE_NAME);
		$<AST>$->Value.Name = $<Name>1;
		fout_diag << "BISON" << "\t" << "atom : VALUE_TYPE_NAME" << endl;
		cout << red << "BISON" << white << "\t" << "atom : VALUE_TYPE_NAME" << endl;
	}|
	VALUE_TYPE_STRING {
		$<AST>$ = newnode("atom", 4, VALUE_TYPE_STRING);
		$<AST>$->Value.String = $<String>1;
		fout_diag << "BISON" << "\t" << "atom : VALUE_TYPE_STRING" << endl;
		cout << red << "BISON" << white << "\t" << "atom : VALUE_TYPE_STRING" << endl;
	}|
	VALUE_TYPE_CHAR {
		$<AST>$ = newnode("atom", 5, VALUE_TYPE_CHAR);
		$<AST>$->Value.Char = $<Char>1;
		fout_diag << "BISON" << "\t" << "atom : VALUE_TYPE_NUMBER" << endl;
		cout << red << "BISON" << white << "\t" << "atom : VALUE_TYPE_CHAR" << endl;
	}|
	VALUE_TYPE_NUMBER {
		$<AST>$ = newnode("atom", 6, VALUE_TYPE_NUMBER);
		$<AST>$->Value.Number = $<Number>1;
		fout_diag << "BISON" << "\t" << "atom : VALUE_TYPE_NUMBER" << endl;
		cout << red << "BISON" << white << "\t" << "atom : VALUE_TYPE_NUMBER" << endl;
	};

atom_expr:
	atom {
		$<AST>$ = newnet("atom_expr", 1, $<AST>1);
		fout_diag << "BISON" << "\t" << "atom_expr : atom" << endl;
		cout << red << "BISON" << white << "\t" << "atom_expr : atom" << endl;
	}|
	"(" expr ")" {
		$<AST>$ = newnet("atom_expr", 2, $<AST>2);
		fout_diag << "BISON" << "\t" << "atom_expr : \"(\" expr \")\"" << endl;
		cout << red << "BISON" << white << "\t" << "atom_expr : \"(\" expr \")\"" << endl;
	};

break_stmt:
	"break" ;

classdef:
	"class" VALUE_TYPE_NAME ":" suite | "class" VALUE_TYPE_NAME "(" ")" ":" suite |	"class" VALUE_TYPE_NAME "(" arglist ")" ":" suite ;

comparison:
	expr {
		$<AST>$ = newnet("comparison", 1, $<AST>1);
		fout_diag << "BISON" << "\t" << "comparison : expr" << endl;
		cout << red << "BISON" << white << "\t" << "comparison : expr" << endl;
	}|
	comparison comp_op expr {
		$<AST>$ = newnet("comparison", 2, $<AST>1, $<AST>3, $<AST>2);
		fout_diag << "BISON" << "\t" << "comparison : comparison comp_op expr" << endl;
		cout << red << "BISON" << white << "\t" << "comparison : comparison comp_op expr" << endl;
	};

compound_stmt:
	if_stmt {
		$<AST>$ = newnet("compound_stmt", 1, $<AST>1);
		fout_diag << "BISON" << "\t" << "compound_stmt : if_stmt" << endl;
		cout << red << "BISON" << white << "\t" << "compound_stmt : if_stmt" << endl;
	}|
	while_stmt{
		$<AST>$ = newnode("compound_stmt", 2);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON" << "\t" << "compound_stmt : while_stmt" << endl;
		cout << red << "BISON" << white << "\t" << "compound_stmt : while_stmt" << endl;
	}| funcdef | classdef ;

comp_op:
	"<" {
		$<AST>$ = newnode("comp_op", 1);
		$<AST>$->Value.Number = LESS;
		fout_diag << "BISON" << "\t" << "comp_op : \"<\"" << endl;
		cout << red << "BISON" << white << "\t" << "comp_op : \"<\"" << endl;
	}|
	">" {
		$<AST>$ = newnode("comp_op", 2);
		$<AST>$->Value.Number = GREATER;
		fout_diag << "BISON" << "\t" << "comp_op : \">\"" << endl;
		cout << red << "BISON" << white << "\t" << "comp_op : \">\"" << endl;
	}|
	"==" {
		$<AST>$ = newnode("comp_op", 3);
		$<AST>$->Value.Number = EQEQUAL;
		fout_diag << "BISON" << "\t" << "comp_op : \"==\"" << endl;
		cout << red << "BISON" << white << "\t" << "comp_op : \"==\"" << endl;
	}|
	">=" {
		$<AST>$ = newnode("comp_op", 4);
		$<AST>$->Value.Number = GREATEREQUAL;
		fout_diag << "BISON" << "\t" << "comp_op : \">=\"" << endl;
		cout << red << "BISON" << white << "\t" << "comp_op : \">=\"" << endl;
	}|
	"<=" {
		$<AST>$ = newnode("comp_op", 5);
		$<AST>$->Value.Number = LESSEQUAL;
		fout_diag << "BISON" << "\t" << "comp_op : \"<=\"" << endl;
		cout << red << "BISON" << white << "\t" << "comp_op : \"<=\"" << endl;
	}|
	"<>" {
		$<AST>$ = newnode("comp_op", 6);
		$<AST>$->Value.Number = NOTEQUAL;
		fout_diag << "BISON" << "\t" << "comp_op : \"<>\"" << endl;
		cout << red << "BISON" << white << "\t" << "comp_op : \"<>\"" << endl;
	}|
	"!=" {
		$<AST>$ = newnode("comp_op", 7);
		$<AST>$->Value.Number = NOTEQUAL;
		fout_diag << "BISON" << "\t" << "comp_op : \"!=\"" << endl;
		cout << red << "BISON" << white << "\t" << "comp_op : \"!=\"" << endl;
	}|
	"is" | "is" "not" ;

continue_stmt:
	"continue" ;

expr:
	xor_expr {
		$<AST>$ = newnode("expr", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON" << "\t" << "expr : xor_expr" << endl;
		cout << red << "BISON" << white << "\t" << "expr : xor_expr" << endl;
	}|
	expr "|" xor_expr {
		$<AST>$ = newnode("expr", 2);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON" << "\t" << "expr : expr \"|\" xor_expr" << endl;
		cout << red << "BISON" << white << "\t" << "expr : expr \"|\" xor_expr" << endl;
	};

expr_stmt:
	VALUE_TYPE_NAME "=" expr {
		$<AST>$ = newnode("expr_stmt", 1);
		$<AST>$->l = newnode("VALUE_TYPE_NAME", VALUE_TYPE_NAME);
		$<AST>$->l->Value.Name = $<Name>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON" << "\t" << "expr_stmt : VALUE_TYPE_NAME \'=' expr" << endl;
		cout << red << "BISON" << white << "\t" << "expr_stmt : VALUE_TYPE_NAME \'=' expr" << endl;
	};

factor:
	power {
		$<AST>$ = newnode("factor", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON" << "\t" << "factor : power" << endl;
		cout << red << "BISON" << white << "\t" << "factor : power" << endl;
	}|
	"+" factor {
		$<AST>$ = newnode("factor", 2);
		$<AST>$->l = $<AST>2;
		fout_diag << "BISON" << "\t" << "factor : \"+\" factor" << endl;
		cout << red << "BISON" << white << "\t" << "factor : \"+\" factor" << endl;
	}|
	"-" factor{
		$<AST>$ = newnode("factor", 3);
		$<AST>$->l = $<AST>2;
		fout_diag << "BISON" << "\t" << "factor : \"-\" factor" << endl;
		cout << red << "BISON" << white << "\t" << "factor : \"-\" factor" << endl;
	};

file_input:
	NEWLINE {
		$<AST>$ = newnode("file_input", 1);
		$<AST>$->r = newnode("NEWLINE", NEWLINE);
		fout_diag << "BISON" << "\t" << "file_input : NEWLINE" << endl;
		cout << red << "BISON" << white << "\t" << "file_input : NEWLINE" << endl;
		
	}|
	stmt {
		$<AST>$ = newnode("file_input", 2);
		$<AST>$->r = $<AST>1;
		fout_diag << "BISON" << "\t" << "file_input : stmt" << endl;
		cout << red << "BISON" << white << "\t" << "file_input : stmt" << endl;
	}|
	file_input NEWLINE {
		$<AST>$ = newnode("file_input", 3);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = newnode("NEWLINE", NEWLINE);
		fout_diag << "BISON" << "\t" << "file_input : file_input NEWLINE" << endl;
		cout << red << "BISON" << white << "\t" << "file_input : file_input NEWLINE" << endl;
	}|
	file_input stmt {
		$<AST>$ = newnode("file_input", 4);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>2;
		fout_diag << "BISON" << "\t" << "file_input : file_input stmt" << endl;
		cout << red << "BISON" << white << "\t" << "file_input : file_input stmt" << endl;
	};

flow_stmt:
	break_stmt | continue_stmt | return_stmt ;

funcdef:
	"def" VALUE_TYPE_NAME parameters ":" suite;

if_stmt:
	"if" test ":" suite newline_plus {
		$<AST>$ = newnode("if_stmt", 1);
		$<AST>$->l = $<AST>2;
		$<AST>$->r = $<AST>4;
		fout_diag << "BISON" << "\t" << "if_stmt : \"if\" test \":\" suite newline_plus" << endl;
		cout << red << "BISON" << white << "\t" << "if_stmt : \"if\" test \":\" suite newline_plus" << endl;
	}|
	"if" test ":" suite newline_plus "else" ":" suite {
		$<AST>$ = newnode("if_stmt", 2);
		$<AST>$->l = $<AST>2;
		$<AST>$->r = $<AST>4;
		$<AST>$->j = $<AST>8;
		fout_diag << "BISON" << "\t" << "if_stmt : \"if\" test \":\" suite newline_plus \"else\" \":\" suite" << endl;
		cout << red << "BISON" << white << "\t" << "if_stmt : \"if\" test \":\" suite newline_plus \"else\" \":\" suite" << endl;
	};

newline_plus:
	NEWLINE
	|
	NEWLINE newline_plus
	;

not_test:
	comparison {
		$<AST>$ = newnode("not_test", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON" << "\t" << "not_test : comparison" << endl;
		cout << red << "BISON" << white << "\t" << "not_test : comparison" << endl;
	}|
	"not" not_test {
		$<AST>$ = newnode("not_test", 2);
		$<AST>$->l = $<AST>2;
		fout_diag << "BISON" << "\t" << "not_test : \"not\" not_test" << endl;
		cout << red << "BISON" << white << "\t" << "not_test : \"not\" not_test" << endl;
	};

or_test:
	and_test {
		$<AST>$ = newnode("or_test", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON" << "\t" << "or_test : and_test" << endl;
		cout << red << "BISON" << white << "\t" << "or_test : and_test" << endl;
	}|
	or_test "or" and_test {
		$<AST>$ = newnode("or_test", 2);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON" << "\t" << "or_test : or_test \"or\" and_test" << endl;
		cout << red << "BISON" << white << "\t" << "or_test : or_test \"or\" and_test" << endl;
	};

parameters:
	"(" ")" | "(" typedargslist ")" ;

pass_stmt:
	"pass" ;

power:
	atom_expr {
		$<AST>$ = newnode("power", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON" << "\t" << "power : atom_expr" << endl;
		cout << red << "BISON" << white << "\t" << "power : atom_expr" << endl;
	}|
	atom_expr "**" factor {
		$<AST>$ = newnode("power", 2);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON" << "\t" << "power : atom_expr \"**\" factor" << endl;
		cout << red << "BISON" << white << "\t" << "power : atom_expr \"**\" factor" << endl;
	};

print_stmt:
	"print" "(" expr ")" {
		$<AST>$ = newnode("print_stmt", 1);
		$<AST>$->l = $<AST>3;
		fout_diag << "BISON" << "\t" << "print_stmt : \"print\" \"(\" atom \")\"" << endl;
		cout << red << "BISON" << white << "\t" << "print_stmt : \"print\" \"(\" atom \")\"" << endl;
	};

return_stmt:
	"return" | "return" testlist ;

shift_expr:
	arith_expr {
		$<AST>$ = newnode("shift_expr", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON" << "\t" << "shift_expr : arith_expr" << endl;
		cout << red << "BISON" << white << "\t" << "shift_expr : arith_expr" << endl;
	}|
	shift_expr "<<" arith_expr {
		$<AST>$ = newnode("shift_expr", 2);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON" << "\t" << "shift_expr : shift_expr \"<<\" arith_expr" << endl;
		cout << red << "BISON" << white << "\t" << "shift_expr : shift_expr \"<<\" arith_expr" << endl;
	}|
	shift_expr ">>" arith_expr {
		$<AST>$ = newnode("shift_expr", 3);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON" << "\t" << "shift_expr : shift_expr \">>\" arith_expr" << endl;
		cout << red << "BISON" << white << "\t" << "shift_expr : shift_expr \">>\" arith_expr" << endl;
	};

simple_stmt:
	small_stmt NEWLINE {
		$<AST>$ = newnode("simple_stmt", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON" << "\t" << "simple_stmt : small_stmt NEWLINE" << endl;
		cout << red << "BISON" << white << "\t" << "simple_stmt : small_stmt NEWLINE" << endl;
	};

small_stmt:
	expr_stmt {
		$<AST>$ = newnode("small_stmt", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON" << "\t" << "small_stmt : expr_stmt" << endl;
		cout << red << "BISON" << white << "\t" << "small_stmt : expr_stmt" << endl;
	}| pass_stmt | flow_stmt |
	print_stmt {
		$<AST>$ = newnode("small_stmt", 4);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON" << "\t" << "small_stmt : print_stmt" << endl;
		cout << red << "BISON" << white << "\t" << "small_stmt : print_stmt" << endl;
	};

stmt:
	simple_stmt {
		$<AST>$ = newnode("stmt", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON" << "\t" << "stmt : simple_stmt" << endl;
		cout << red << "BISON" << white << "\t" << "stmt : simple_stmt" << endl;
	}|
	compound_stmt {
		$<AST>$ = newnode("stmt", 2);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON" << "\t" << "stmt : compound_stmt" << endl;
		cout << red << "BISON" << white << "\t" << "stmt : compound_stmt" << endl;
	}|
	error {
		fout_diag << "A SYNTACTIC ERROR HAS BEEN FOUND AT LINE" << "\t" << T->t[T->Pointer - 1].lineno << endl;
		cout << red << "A SYNTACTIC ERROR HAS BEEN FOUND AT LINE " << yellow << T->t[T->Pointer - 1].lineno << white << endl;
		system("pause > nul");
		fout_diag.close();
		exit(1);
	};

suite:
	simple_stmt {
		$<AST>$ = newnode("suite", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON" << "\t" << "suite : simple_stmt" << endl;
		cout << red << "BISON" << white << "\t" << "suite : simple_stmt" << endl;
	}|
	NEWLINE INDENT suite_sub DEDENT {
		$<AST>$ = newnode("suite", 2);
		$<AST>$->l = $<AST>3;
		fout_diag << "BISON" << "\t" << "suite : NEWLINE INDENT suite_sub DEDENT" << endl;
		cout << red << "BISON" << white << "\t" << "suite : NEWLINE INDENT suite_sub DEDENT" << endl;
	};

suite_sub:
	stmt {
		$<AST>$ = newnode("suite_sub", 1);
		$<AST>$->r = $<AST>1;
		fout_diag << "BISON" << "\t" << "suite_sub : stmt" << endl;
		cout << red << "BISON" << white << "\t" << "suite_sub : stmt" << endl;
	}|
	suite_sub stmt {
		$<AST>$ = newnode("suite_sub", 2);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>2;
		fout_diag << "BISON" << "\t" << "suite_sub : suite_sub stmt" << endl;
		cout << red << "BISON" << white << "\t" << "suite_sub : suite_sub stmt" << endl;
	};

term:
	factor {
		$<AST>$ = newnode("term", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON" << "\t" << "term : factor" << endl;
		cout << red << "BISON" << white << "\t" << "term : factor" << endl;
	}|
	term "*" factor {
		$<AST>$ = newnode("term", 2);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON" << "\t" << "term : term \"*\" factor" << endl;
		cout << red << "BISON" << white << "\t" << "term : term \"*\" factor" << endl;
	}|
	term "/" factor {
		$<AST>$ = newnode("term", 3);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON" << "\t" << "term : term \"/\" factor" << endl;
		cout << red << "BISON" << white << "\t" << "term : term \"/\" factor" << endl;
	}|
	term "%" factor {
		$<AST>$ = newnode("term", 4);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON" << "\t" << "term : term \"%\" factor" << endl;
		cout << red << "BISON" << white << "\t" << "term : term \"%\" factor" << endl;
	}|
	term "//" factor {
		$<AST>$ = newnode("term", 5);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON" << "\t" << "term : term \"//\" factor" << endl;
		cout << red << "BISON" << white << "\t" << "term : term \"//\" factor" << endl;
	};

test:
	or_test {
		$<AST>$ = newnode("test", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON" << "\t" << "test : or_test" << endl;
		cout << red << "BISON" << white << "\t" << "test : or_test" << endl;
	};

testlist:
	testlist_sub | testlist_sub "," ;

testlist_sub:
	test | testlist_sub "," test ;

tfpdef:
	VALUE_TYPE_NAME;

typedargslist:
	tfpdef | typedargslist_sub ;

typedargslist_sub:
	"," tfpdef | typedargslist_sub "," tfpdef ;
						
while_stmt:
	"while" test ":" suite {
		$<AST>$ = newnode("while_stmt", 1);
		$<AST>$->l = $<AST>2;
		$<AST>$->r = $<AST>4;
		fout_diag << "BISON" << "\t" << "while_stmt : \"while\" test \":\" suite" << endl;
		cout << red << "BISON" << white << "\t" << "while_stmt : \"while\" test \":\" suite" << endl;
	};

xor_expr:
	and_expr {
		$<AST>$ = newnode("xor_expr", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON" << "\t" << "xor_expr : and_expr" << endl;
		cout << red << "BISON" << white << "\t" << "xor_expr : and_expr" << endl;
	}|
	xor_expr "^" and_expr {
		$<AST>$ = newnode("xor_expr", 2);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON" << "\t" << "xor_expr : xor_expr \"^\" and_expr" << endl;
		cout << red << "BISON" << white << "\t" << "xor_expr : xor_expr \"^\" and_expr" << endl;
	};
%%

int main(int argc, char * argv[]) {
	if (argc != 2) {
		cout << red << "Destination required!" << white << endl;
		exit(1);
	}
	ifstream fin(argv[1], ios::in);
	if (fin.fail() || fin.bad()) {
		cout << red << "Destination Error" << white << endl;
		cout << "Please Drag a source file onto " << yellow << "MAKE.bat" << white << endl;
		exit(1);
	}
	ReadTokens(fin, T);
	initTable();
	yyparse();
	fout_diag.close();
	fout_diag.open("INTERPRETER.log", ios::out);
	cout << yellow << "Syntactic and Semantic Analysis Complete" << white << endl;
	cout << yellow << "Press any button to interpret the source code" << white << endl;
	cout << yellow << "THIS LOG IS STORED AS " << red << "PARSER.LOG" << white << endl;
	system("pause > nul");
	system("CLS");
	interpret_input();
	disptable();
	fout_diag.close();
	system("pause > nul");
	cout << yellow << "Interpretation Complete" << white << endl;
	cout << yellow << "LOG DURING INTERPRETATION IS STORED AS " << red << "INTERPRETER.LOG" << white << endl;
	return 0;
};
#include "Headers\\tokenizer.h"
#include "Headers\\ast.h"
#include "Headers\\tools.h"
#include "Headers\\symtable.h"
#include "Headers\\interpret.h"
#include "Headers\\stack.h"