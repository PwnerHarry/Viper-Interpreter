%{
using namespace std;
const int INPUT = 12345;
typedef union {
	double Number;
	char * String;
	char * Name;
	char Char;
	bool Bool;
	int Int;
} SValue;
#include "fstream"
const int TOKEN_TABLE_SIZE = 4096;
ofstream fout_diag("PARSER.log", ios::out);
#include "stdafx.h"
TokenTable * T = new TokenTable;
#include "ast.h"
#include "symtable.h"
union YYSTYPE{
	ast AST;
	double Number;
	char * String;
	int Int;
	char * Name;
	char Char;
	bool Bool;
};
char * inttype(int type);
%}
%define api.value.type		{union YYSTYPE}
%token	<Number>			NUMBER
%token	<String>			STRING
%token	<Name>				NAME
%token	<Char>				CHAR
%token	<Bool>				BOOL
%token	<Int>				INT
%token	INDENT
%token	DEDENT
%token	ENDMARKER
%token	UNKNOWN
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
		$<AST>$ = newnode(INPUT);
		$<AST>$->l = $<AST>1;
		ROOT = $<AST>$;
		fout_diag << "BISON\tinput : file_input ENDMARKER\n";
	};

and_expr:
	shift_expr {
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\tand_expr : shift_expr\n";
		dispasn($<AST>$);
	}|
	and_expr "&" shift_expr {
		$<AST>$ = newnode(NUMBER);
		$<AST>$->Value.Number = int($<AST>1->Value.Number) & int($<AST>3->Value.Number);
		delete $<AST>1;
		delete $<AST>3;
		fout_diag << "BISON\tand_expr : and_expr \"&\" shift_expr\n";
		dispasn($<AST>$);
	};

and_test:
	not_test {
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\tand_test : not_test\n";
		dispasn($<AST>$);
	}|
	and_test "and" not_test {
		$<AST>$ = newnode(BOOL);
		$<AST>$->Value.Bool = $<AST>1->Value.Bool && $<AST>3->Value.Bool;
		fout_diag << "BISON\tand_test : and_test \"and\" not_test\n";
		dispasn($<AST>$);
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
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\tarith_expr : term\n";
		dispasn($<AST>$);
	}|
	arith_expr "+" term {
		$<AST>$ = newnode(NUMBER);
		$<AST>$->Value.Number = $<AST>1->Value.Number + $<AST>3->Value.Number;
		delete $<AST>1;
		delete $<AST>3;
		fout_diag << "BISON\tarith_expr : arith_expr \"+\" term\n";
		dispasn($<AST>$);
	}|
	arith_expr "-" term {
		$<AST>$ = newnode(NUMBER);
		$<AST>$->Value.Number = $<AST>1->Value.Number - $<AST>3->Value.Number;
		delete $<AST>1;
		delete $<AST>3;
		fout_diag << "BISON\tarith_expr : arith_expr \"-\" term\n";
		dispasn($<AST>$);
	};

atom:
	"True" {
		$<AST>$->Value.Bool = true;
		dispasn($<AST>$);
	}|
	"False" {
		$<AST>$->Value.Bool = false;
		dispasn($<AST>$);
	}|
	NAME {
		$<AST>$ = newnode(NAME);
		$<AST>$->Value.Name = $<Name>1;
		fout_diag << "BISON\tatom : NAME\n";
		dispasn($<AST>$);
	}|
	STRING {
		$<AST>$ = newnode(STRING);
		$<AST>$->Value.String = $<String>1;
		fout_diag << "BISON\tatom : STRING\n";
		dispasn($<AST>$);
	}|
	NUMBER {
		$<AST>$ = newnode(NUMBER);
		$<AST>$->Value.Number = $<Number>1;
		fout_diag << "BISON\tatom : NUMBER\n";
		dispasn($<AST>$);
	};

atom_expr:
	atom {
		//如果NAME被规约成这个，它就应该应该提供值而不是其他
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\tatom_expr : atom\n";
		dispasn($<AST>$);
	}|
	atom trailer_plus {
		fout_diag << "BISON\tatom_expr : atom trailer_plus\n";		
	};

break_stmt:
	"break" {
		$<AST>$ = newnode(BREAK);
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
		dispasn($<AST>$);
	}|
	comparison comp_op expr {
		$<AST>$ = newnode(NUMBER);
		switch (int($<AST>2->Value.Number)) {
			case LESS: {
				if ($<AST>1->Value.Number < $<AST>3->Value.Number)
					$<AST>$->Value.Number = 1;
				else
					$<AST>$->Value.Bool = 0;
				break;
			}
			case GREATER: {
				if ($<AST>1->Value.Number > $<AST>3->Value.Number)
					$<AST>$->Value.Number = 1;
				else
					$<AST>$->Value.Number = 0;
				break;
			}
			case EQEQUAL: {
				if ($<AST>1->Value.Number == $<AST>3->Value.Number)
					$<AST>$->Value.Number = 1;
				else
					$<AST>$->Value.Number = 0;
				break;
			}
			case GREATEREQUAL: {
				if ($<AST>1->Value.Number >= $<AST>3->Value.Number)
					$<AST>$->Value.Number = 1;
				else
					$<AST>$->Value.Number = 0;
				break;
			}
			case LESSEQUAL: {
				if ($<AST>1->Value.Number <= $<AST>3->Value.Number)
					$<AST>$->Value.Number = 1;
				else
					$<AST>$->Value.Number = 0;
				break;
			}
			case NOTEQUAL: {
				if ($<AST>1->Value.Number != $<AST>3->Value.Number)
					$<AST>$->Value.Number = 1;
				else
					$<AST>$->Value.Number = 0;
				break;
			}
			case IS: {
				/*解释运行树的时候再说吧*/
				break;
			}
			default: {
				break;
			}
		}
		fout_diag << "BISON\tcomparison : comparison comp_op expr\n";
		delete $<AST>1;
		delete $<AST>2;
		delete $<AST>3;
		dispasn($<AST>$);
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
		$<AST>$ = newnode(NUMBER);
		$<AST>$->Value.Number = LESS;
		fout_diag << "BISON\tcomp_op : \"<\"\n";
	}|
	">" {
		$<AST>$ = newnode(NUMBER);
		$<AST>$->Value.Number = GREATER;
		fout_diag << "BISON\tcomp_op : \">\"\n";
	}|
	"==" {
		$<AST>$ = newnode(NUMBER);
		$<AST>$->Value.Number = EQEQUAL;
		fout_diag << "BISON\tcomp_op : \"==\"\n";
	}|
	">=" {
		$<AST>$ = newnode(NUMBER);
		$<AST>$->Value.Number = GREATEREQUAL;
		fout_diag << "BISON\tcomp_op : \">=\"\n";
	}|
	"<=" {
		$<AST>$ = newnode(NUMBER);
		$<AST>$->Value.Number = LESSEQUAL;
		fout_diag << "BISON\tcomp_op : \"<=\"\n";
	}|
	"<>" {
		$<AST>$ = newnode(NUMBER);
		$<AST>$->Value.Number = NOTEQUAL;
		fout_diag << "BISON\tcomp_op : \"<>\"\n";
	}|
	"!=" {
		$<AST>$ = newnode(NUMBER);
		$<AST>$->Value.Number = NOTEQUAL;
		fout_diag << "BISON\tcomp_op : \"!=\"\n";
	}|
	"is" {
		$<AST>$ = newnode(NUMBER);
		$<AST>$->Value.Number = IS;
		fout_diag << "BISON\tcomp_op : \"is\"\n";
	}|
	"is" "not" {
		$<AST>$ = newnode(NUMBER);
		$<AST>$->Value.Number = -2;
		fout_diag << "BISON\tcomp_op : \"is\" \"not\"\n";
	};

continue_stmt			: "continue"
						;

expr:
	xor_expr {
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\texpr : xor_expr\n";
		dispasn($<AST>$);
	}|
	expr "|" xor_expr {
		$<AST>$ = newnode(NUMBER);
		$<AST>$->Value.Number = int($<AST>1->Value.Number) | int($<AST>3->Value.Number);
		delete $<AST>1;
		delete $<AST>3;
		fout_diag << "BISON\texpr : expr \"|\" xor_expr\n";
		dispasn($<AST>$);
	};

expr_stmt:
	NAME "=" expr {
		$<AST>$ = newnode(EQUAL);
		$<AST>$->l = newnode(NAME);
		$<AST>$->l->Value.Name = $<Name>1;
		$<AST>$->r = $<AST>3;
		fout_diag << "BISON\texpr_stmt : NAME \'=' expr\n";
		dispasn($<AST>$);
	};

factor:
	power {
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\tfactor : power\n";
		dispasn($<AST>$);
	}|
	"+" factor {
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\tfactor : \"+\" factor\n";
		dispasn($<AST>$);
	}|
	"-" factor{
		$<AST>$ = $<AST>1;
		$<AST>$->Value.Number = -1.0 * $<AST>$->Value.Number;
		fout_diag << "BISON\tfactor : \"-\" factor\n";
		dispasn($<AST>$);
	};

file_input:
	NEWLINE {
		$<AST>$ = newnode(0);
		fout_diag << "BISON\tfile_input : NEWLINE\n";
		
	}|
	stmt {
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\tfile_input : stmt\n";
	}|
	file_input NEWLINE {
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\tfile_input : file_input_sub NEWLINE\n";
	}|
	file_input stmt {
		$<AST>$ = $<AST>1;
		asn * A = $<AST>1;
		while (A->next)
			A = A->next;
		A->next = $<AST>2;//最右面的
		fout_diag << "BISON\tfile_input : file_input_sub stmt\n";
	};

flow_stmt:
	break_stmt {
		$<AST>$ = newnode(BREAK);
		fout_diag << "BISON\tflow_stmt : break_stmt\n";
	}|
	continue_stmt {
		$<AST>$ = newnode(CONTINUE);
		fout_diag << "BISON\tflow_stmt : continue_stmt\n";
	}|
	return_stmt {
		$<AST>$ = newnode(RETURN);
		fout_diag << "BISON\tflow_stmt : return_stmt\n";
	};

funcdef:
	"def" NAME parameters ":" suite {
		fout_diag << "BISON\tfuncdef : \"def\" NAME parameters \":\" suite\n";
		//To be fulfilled, yet not right now!
	};

if_stmt:
	"if" test ":" suite if_stmt_sub {
		$<AST>$ = newnode(IF);
		$<AST>$->Value.Bool = $<AST>2->Value.Bool;
		$<AST>$->l = $<AST>4;
		$<AST>4->l = $<AST>5;
		delete $<AST>2;
	}|
	"if" test ":" suite if_stmt_sub "else" ":" suite {
		$<AST>$ = newnode(IF);
		$<AST>$->Value.Bool = $<AST>2->Value.Bool;
		$<AST>$->l = $<AST>4;
		$<AST>$->r = $<AST>8;
		$<AST>4->l = $<AST>5;
		delete $<AST>2;
	};

if_stmt_sub:
	%empty {
		$<AST>$ = newnode(0);
	}|
	if_stmt_sub "elif" test ":" suite {
		$<AST>$ = newnode(ELIF);
		$<AST>$->Value.Bool = $<AST>3->Value.Bool;
		if (!$<AST>1->nodetype)
			$<AST>$->l = $<AST>5;
		else {
			ast T = $<AST>1;
			while (T->l)
				T = T->l;
			T->l = $<AST>5;
		}
		delete $<AST>3;
	};

not_test:
	"not" not_test {
		$<AST>$ = newnode(BOOL);
		if (!$<AST>1->Value.Number)
			$<AST>$->Value.Bool = true;
		else
			$<AST>$->Value.Bool = false;
		delete $<AST>1;
		delete $<AST>2;
		fout_diag << "BISON\tnot_test : \"not\" not_test\n";
		delete $<AST>2;
		dispasn($<AST>$);
	}|
	comparison {
		$<AST>$ = newnode(BOOL);
		if ($<AST>1->Value.Number)
			$<AST>$->Value.Bool = true;
		else
			$<AST>$->Value.Bool = false;
		fout_diag << "BISON\tnot_test : comparison\n";
		dispasn($<AST>$);
	};

or_test:
	and_test {
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\tor_test : and_test\n";
		dispasn($<AST>$);
	}|
	or_test "or" and_test {
		$<AST>$ = newnode(BOOL);
		$<AST>$->Value.Bool = $<AST>1->Value.Bool || $<AST>3->Value.Bool;
		fout_diag << "BISON\tor_test : or_test \"or\" and_test\n";
		delete $<AST>1;
		delete $<AST>3;
		dispasn($<AST>$);
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
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\tpower : atom_expr" << "\n";
		dispasn($<AST>$);
	}|
	atom_expr "**" factor {
		$<AST>$ = newnode(NUMBER);
		$<AST>$->Value.Number = pow($<AST>1->Value.Number, $<AST>3->Value.Number);
		delete $<AST>1;
		delete $<AST>3;
		fout_diag << "BISON\tpower : atom_expr \"**\" factor" << "\n";
		dispasn($<AST>$);
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
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\tshift_expr : arith_expr\n";
		dispasn($<AST>$);
	}|
	shift_expr "<<" arith_expr {
		$<AST>$ = newnode(NUMBER);
		$<AST>$->Value.Number = $<AST>1->Value.Number * pow(2, int($<AST>3->Value.Number));
		delete $<AST>1;
		delete $<AST>3;
		fout_diag << "BISON\tshift_expr : shift_expr \"<<\" arith_expr\n";
		dispasn($<AST>$);
	}|
	shift_expr ">>" arith_expr {
		$<AST>$ = newnode(NUMBER);
		$<AST>$->Value.Number = $<AST>1->Value.Number / pow(2, int($<AST>3->Value.Number));
		delete $<AST>1;
		delete $<AST>3;
		fout_diag << "BISON\tshift_expr : shift_expr \">>\" arith_expr\n";
		dispasn($<AST>$);
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
		$<AST>$ = newnode(0);
		fout_diag << "BISON\tsmall_stmt : pass_stmt\n";
	}|
	flow_stmt {
		fout_diag << "BISON\tsmall_stmt : flow_stmt\n";
	};

stmt:
	simple_stmt {
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\tstmt : simple_stmt\n";
	}|
	compound_stmt {
		$<AST>$ = $<AST>1;
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
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\tterm : factor\n";
		dispasn($<AST>$);
	}|
	term "*" factor {
		$<AST>$ = newnode(NUMBER);
		$<AST>$->Value.Number = $<AST>1->Value.Number * $<AST>3->Value.Number;
		delete $<AST>1;
		delete $<AST>3;
		fout_diag << "BISON\tterm : term \"*\" factor\n";
		dispasn($<AST>$);
	}|
	term "/" factor {
		$<AST>$ = newnode(NUMBER);
		$<AST>$->Value.Number = $<AST>1->Value.Number / $<AST>3->Value.Number;
		delete $<AST>1;
		delete $<AST>3;
		fout_diag << "BISON\tterm : term \"/\" factor\n";
		dispasn($<AST>$);
	}|
	term "%" factor {
		$<AST>$ = newnode(INT);
		$<AST>$->Value.Number = int($<AST>1->Value.Number) % int($<AST>3->Value.Number);
		delete $<AST>1;
		delete $<AST>3;
		fout_diag << "BISON\tterm : term \"%\" factor\n";
		dispasn($<AST>$);
	}|
	term "//" factor {
		$<AST>$ = newnode(INT);
		$<AST>$->Value.Int = int(floor($<AST>1->Value.Number / $<AST>3->Value.Number));
		delete $<AST>1;
		delete $<AST>3;
		fout_diag << "BISON\tterm : term \"//\" factor\n";
		dispasn($<AST>$);
	};

test:
	or_test {
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\ttest : or_test\n";
		dispasn($<AST>$);
	}|
	or_test "if" or_test "else" test
	;

testlist:
	testlist_sub {
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\ttestlist : test testlist_sub\n";
		dispasn($<AST>$);
	}|
	testlist_sub ","
	;

testlist_sub:
	test {
		$<AST>$ = $<AST>1;
		fout_diag << "BISON\ttestlist_sub : \n";
		dispasn($<AST>$);
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
	$<AST>$ = $<AST>1;
	fout_diag << "BISON\txor_expr : and_expr\n";
	dispasn($<AST>$);
}|
xor_expr "^" and_expr {
	$<AST>$ = newnode(NUMBER);
	$<AST>$->Value.Number = int($<AST>1->Value.Number) ^ int ($<AST>3->Value.Number);
	delete $<AST>1;
	delete $<AST>3;
	fout_diag << "BISON\txor_expr : xor_expr \"^\" and_expr\n";
	dispasn($<AST>$);
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
	interpret(ROOT);
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
}
void dispasn(ast N) {
	switch (N->nodetype){
		case NUMBER:{
			fout_diag << "SVAL\t" << N->Value.Number << "\n";
			break;
		}
		case INT:{
			fout_diag << "SVAL\t" << N->Value.Int << "\n";
			break;
		}
		case BOOL:{
			if (N->Value.Bool)
				fout_diag << "SVAL\t" << "true" << "\n";
			else
				fout_diag << "SVAL\t" << "false" << "\n";
			break;
		}
		case CHAR:{
			fout_diag << "SVAL\t" << N->Value.Char << "\n";
			break;
		}
		case STRING:{
			fout_diag << "SVAL\t" << N->Value.String << "\n";
			break;
		}
		case NAME:{
			fout_diag << "SVAL\t" << N->Value.Name << "\n";
			break;
		}
		default:
			break;
	}
};
ast newnode(int nodetype) {
	ast N = new asn;
	N->nodetype = nodetype;
	if (nodetype == NUMBER || nodetype == BOOL || nodetype == NAME || nodetype == INT || nodetype == CHAR || nodetype == STRING)
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
ast interpret(ast N) {
	if (N == ROOT) {
		fout_diag << "INTERPRETING ROOT NODE" << "\n";
		if (N->l == 0) {
			fout_diag << "SOURCE FILE EMPTY" << "\n";
			return 0;//CAN DO ABSOLUTELY NOTHING
		}
		if (N->l && N->l->nodetype == 0) {
			fout_diag << "SOURCE FILE EMPTY" << "\n";
			return 0;//CAN DO ABSOLUTELY NOTHING
		}
		fout_diag << "NOT AN EMPTY SOURCE FILE" << "\n" << "\n" << "\n";
		fout_diag << "TYPE OF NODE ROOT->L" << "\t" << inttype(N->l->nodetype) << "\n";
		N = N->l;
	}
	switch (N->nodetype) {
		case EQUAL:{
			fout_diag << "ENTERING A NODE TYPE OF EQUAL" << "\n";
			fout_diag << "TYPE OF NODE N->L" << "\t" << inttype(N->l->nodetype) << "\n";
			fout_diag << "TYPE OF NODE N->R" << "\t" << inttype(N->r->nodetype) << "\n";
			if (N->l->nodetype == NAME && N->l->valuenode && N->r->nodetype && N->r->valuenode){
				fout_diag << "SEARCHING FOR A NAME IN THE TABLE:\t" << N->l->Value.Name << "\n";
				SymTable S = searchTable(N->l->Value.Name);
				if (!S){
					fout_diag << "NOT FOUND IN THE TABLE" << "\n";
					S = addEntry(N->l->Value.Name, -1, -1, N->r->nodetype);
					fout_diag << "SYMBOL TABLE\tNEW SYMBOL\t" << S->NAME << "\n";
				}
				if (S && S->TYPE != 0 && S->TYPE != N->r->nodetype) {
					fout_diag << "incompatible variable value" << "\n";
					return 0;
				}
				switch (N->r->nodetype) {
					case NUMBER:{
						S->VALUE.Number = N->r->Value.Number;
						break;
					};
					case INT:{
						S->VALUE.Int = N->r->Value.Int;
						break;
					};
					case CHAR:{
						S->VALUE.Char = N->r->Value.Char;
						break;
					};
					case STRING:{
						S->VALUE.String = N->r->Value.String;
						break;
					};
					case NAME:{
						SymTable s = searchTable(N->r->Value.Name);
						if (!s){
							fout_diag << "a non-existed variable cannot be on the right side of a expr_stmt" << "\n";
							return 0;
						}
						S->LIMITS[0] = s->LIMITS[0];
						S->LIMITS[1] = s->LIMITS[1];
						S->VALUE.Number = s->VALUE.Number;
						S->VALUE.Int = s->VALUE.Int;
						break;
					};
				}
			}
			break;
		}
	}
	return 0;
}
char * inttype(int type){
	switch (type) {
		case EQUAL:{
			char * R = new char[32];
			strcpy(R, "EQUAL");
			return R;
			break;
		}
		case INT:{
			char * R = new char[32];
			strcpy(R, "INT");
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
		case 0:{
			char * R = new char[32];
			strcpy(R, "NULL");
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
				case INT:{
					fout_diag << S->VALUE.Int << "\n";
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
			}
		}
		S = S->NEXT;
	}
};