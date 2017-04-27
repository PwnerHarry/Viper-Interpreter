%{
#include "iostream"
#include "ctype.h"
#include "malloc.h"
#include "fstream"
#include "math.h"
#include "string.h"

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
/**/
class symentry {
public:
	char * NAME;
	int LIMITS[2];
	int TYPE;
	SValue VALUE;
	symentry * NEXT;
	symentry() {
		NAME = NULL;
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
SymTable searchTable(char * NAME);
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
		$<AST>$ = newnode("and_test", 1);
		$<AST>$->l = $<AST>1;
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
		$<AST>$ = newnode("break_stmt", 1);
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
		$<AST>$ = newnode("comparison", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON\tcomparison : expr\n";
	}|
	comparison comp_op expr {
		$<AST>$ = newnode("comparison", 2);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>3;
		$<AST>$->j = $<AST>2;
		fout_diag << "BISON\tcomparison : comparison comp_op expr\n";
	};

compound_stmt:
	if_stmt {
		$<AST>$ = newnode("compound_stmt", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON\tcompound_stmt : if_stmt\n";
	}|
	while_stmt{
		$<AST>$ = newnode("compound_stmt", 2);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON\tcompound_stmt : while_stmt\n";
	}|
	funcdef {
		$<AST>$ = newnode("compound_stmt", 3);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON\tcompound_stmt : funcdef\n";
	}|
	classdef{
		$<AST>$ = newnode("compound_stmt", 4);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON\tcompound_stmt : classdef\n";
	};

comp_op:
	"<" {
		$<AST>$ = newnode("comp_op", 1);
		$<AST>$->Value.Number = LESS;
		fout_diag << "BISON\tcomp_op : \"<\"\n";
	}|
	">" {
		$<AST>$ = newnode("comp_op", 2);
		$<AST>$->Value.Number = GREATER;
		fout_diag << "BISON\tcomp_op : \">\"\n";
	}|
	"==" {
		$<AST>$ = newnode("comp_op", 3);
		$<AST>$->Value.Number = EQEQUAL;
		fout_diag << "BISON\tcomp_op : \"==\"\n";
	}|
	">=" {
		$<AST>$ = newnode("comp_op", 4);
		$<AST>$->Value.Number = GREATEREQUAL;
		fout_diag << "BISON\tcomp_op : \">=\"\n";
	}|
	"<=" {
		$<AST>$ = newnode("comp_op", 5);
		$<AST>$->Value.Number = LESSEQUAL;
		fout_diag << "BISON\tcomp_op : \"<=\"\n";
	}|
	"<>" {
		$<AST>$ = newnode("comp_op", 6);
		$<AST>$->Value.Number = NOTEQUAL;
		fout_diag << "BISON\tcomp_op : \"<>\"\n";
	}|
	"!=" {
		$<AST>$ = newnode("comp_op", 7);
		$<AST>$->Value.Number = NOTEQUAL;
		fout_diag << "BISON\tcomp_op : \"!=\"\n";
	}|
	"is" {
		$<AST>$ = newnode("comp_op", 8);
		$<AST>$->Value.Number = IS;
		fout_diag << "BISON\tcomp_op : \"is\"\n";
	}|
	"is" "not" {
		$<AST>$ = newnode("comp_op", 9);
		$<AST>$->Value.Number = -2;
		fout_diag << "BISON\tcomp_op : \"is\" \"not\"\n";
	};

continue_stmt:
	"continue" {
		$<AST>$ = newnode("continue_stmt", 1);
	};

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
		$<AST>$ = newnode("flow_stmt", 1);
		$<AST>$->l = $<AST>1;
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
	};

if_stmt:
	"if" test ":" suite newline_plus {
		$<AST>$ = newnode("if_stmt", 1);
		$<AST>$->l = $<AST>2;
		$<AST>$->r = $<AST>4;
		fout_diag << "BISON\tif_stmt : \"if\" test \":\" suite if_stmt_sub\n";
	}|
	"if" test ":" suite newline_plus "else" ":" suite {
		$<AST>$ = newnode("if_stmt", 2);
		$<AST>$->l = $<AST>2;
		$<AST>$->r = $<AST>4;
		$<AST>$->j = $<AST>8;
		fout_diag << "BISON\tif_stmt : \"if\" test \":\" suite if_stmt_sub \"else\" \":\" suite\n";
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
		fout_diag << "BISON\tnot_test : comparison\n";
	}|
	"not" not_test {
		$<AST>$ = newnode("not_test", 2);
		$<AST>$->l = $<AST>2;
		fout_diag << "BISON\tnot_test : \"not\" not_test\n";
	};

or_test:
	and_test {
		$<AST>$ = newnode("or_test", 1);
		$<AST>$->l = $<AST>1;
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
		$<AST>$ = newnode("pass_stmt", 1);
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

print_stmt:
	"print" "(" expr ")" {
		$<AST>$ = newnode("print_stmt", 1);
		$<AST>$->l = $<AST>3;
		fout_diag << "BISON\tprint_stmt : \"print\" \"(\" atom \")\"" << "\n";
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
		$<AST>$ = newnode("simple_stmt", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON\tsimple_stmt : small_stmt NEWLINE\n";
	};

sliceop					: ":"
						| ":" test
						;
small_stmt:
	expr_stmt {
		$<AST>$ = newnode("small_stmt", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON\tsmall_stmt : expr_stmt\n";
	}|
	pass_stmt {
		$<AST>$ = newnode("small_stmt", 2);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON\tsmall_stmt : pass_stmt\n";
	}|
	flow_stmt {
		$<AST>$ = newnode("small_stmt", 3);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON\tsmall_stmt : flow_stmt\n";
	}|
	print_stmt {
		$<AST>$ = newnode("small_stmt", 4);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON\tsmall_stmt : print_stmt\n";
	};

stmt:
	simple_stmt {
		$<AST>$ = newnode("stmt", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON\tstmt : simple_stmt\n";
	}|
	compound_stmt {
		$<AST>$ = newnode("stmt", 2);
		$<AST>$->l = $<AST>1;
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
		$<AST>$ = newnode("suite", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON\tsuite : simple_stmt\n";
	}|
	NEWLINE INDENT suite_sub DEDENT {
		$<AST>$ = newnode("suite", 2);
		$<AST>$->l = $<AST>3;
		fout_diag << "BISON\tsuite : NEWLINE INDENT suite_sub DEDENT\n";
	};

suite_sub:
	stmt {
		$<AST>$ = newnode("suite_sub", 1);
		$<AST>$->r = $<AST>1;
		fout_diag << "BISON\tsuite_sub : stmt\n";
	}|
	suite_sub stmt {
		$<AST>$ = newnode("suite_sub", 2);
		$<AST>$->l = $<AST>1;
		$<AST>$->r = $<AST>2;
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
		$<AST>$ = newnode("test", 1);
		$<AST>$->l = $<AST>1;
		fout_diag << "BISON\ttest : or_test\n";
	};

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
	"while" test ":" suite {
		$<AST>$ = newnode("while_stmt", 1);
		$<AST>$->l = $<AST>2;
		$<AST>$->r = $<AST>4;
	};

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
		fprintf(stderr, "1 argument required!\n");
		exit(1);
	}
	ifstream fin(argv[1], ios::in);
	if (fin.fail() || fin.bad()) {
		fprintf(stderr, "Destination Error\nPlease Drag a source file onto this EXE\n");
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
#include "tokenizer.h"
#include "ast.h"
#include "tools.h"
#include "symtable.h"
#include "interpret.h"
#include "stack.h"