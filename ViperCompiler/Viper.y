%{
using namespace std;
#include "ctype.h"
#include "string.h"
#include "iostream"
#include "fstream"
#include "math.h"
#define D(x) if (!VIPER_COMPILER_DIAGNOSE) ; else x

const int TOKEN_TABLE_SIZE = 4096;
const int VIPER_COMPILER_DIAGNOSE = 1;
ofstream fout_diag("PROCESS.log", ios::out);
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
		t = new Token[TOKEN_TABLE_SIZE];
		Pointer = 0;
	}
};
typedef union {
	int Int;
	double Double;
	char * String;
	char Char;
} Arg;
class Function {
	char * name;
	Arg * Arguments;
	TokenTable * Definations;
	char * Return;
};
int yylex();
int ReadTokens(ifstream &f, TokenTable * T);
void PrintTokens(TokenTable * T);
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
%token	<Double>			NUMBER
%token	<Char>				CHAR
%token	<Name>				NAME
%token	<String>			STRING
%token	INDENT
%token	DEDENT
%token	ENDMARKER
%token	UNKNOWN
%token	ASYNC				"async"
%token	AWAIT				"await"
%token	ELLIPSIS			"..."
%token	LBRACE				"}"
%token	RBRACE				"{"
%token	COLON				":"
%token	EQUAL				"="
%token	AT					"@"
%token	SEMI				";"
%token	NEWLINE				"\n"
%token	FROM				"from"
%token	EXEC				"exec"
%token	WITH				"with"
%token	RAISE				"raise"
%token	TRY					"try"
%token	DEL					"del"
%token	AS					"as"
%token	ASSERT				"assert"
%token	IS					"is"
%token	EXCEPT				"except"
%token	FINALLY				"finally"
%token	LAMBDA				"lambda"
%token	YIELD				"yield"
%token	IMPORT				"import"
%token	WHILE				"while"
%token	BREAK				"break"
%token	CONTINUE			"continue"
%token	GLOBAL				"global"
%token	ELIF				"elif"
%token	ELSE				"else"
%token	PASS				"pass"
%token	RETURN				"return"
%token	IN					"in"
%token	FOR					"for"
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
%token	NONLOCAL			"nonlocal"
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
%left "-" "+"
%left "*" "/"
%precedence NEG /* negation--unary minus */
%right "**" /* exponentiation */

%%
file_input				: file_input_sub ENDMARKER												{D(fout_diag << "YACC:\tfile_input : file_input_sub ENDMARKER\n");}
						;
and_expr				: shift_expr															{D(fout_diag << "YACC:\tand_expr : shift_expr\n");}
						| and_expr "&" shift_expr												{D(fout_diag << "YACC:\tand_expr : and_expr \"&\" shift_expr\n");}
						;
and_test				: not_test																{D(fout_diag << "YACC:\tand_test : not_test\n");}
						| and_test "and" not_test												{D(fout_diag << "YACC:\tand_test : and_test \"and\" not_test\n");}
						;
annassign				: ":" test
						| ":" test "=" test
						;
arglist					: arglist_sub
						| arglist_sub ","
						;
arglist_sub				: argument
						| arglist_sub "," argument
						;
argument				: test																	{D(fout_diag << "YACC:\targument : test\n");}
						| test comp_for
						| test "=" test
						| "**" test
						| "*" test 
						;
arith_expr				: term																	{D(fout_diag << "YACC:\tarith_expr : term\n");}
						| arith_expr "+" term													{D(fout_diag << "YACC:\tarith_expr : arith_expr \"+\" term\n");}
						| arith_expr "-" term													{D(fout_diag << "YACC:\tarith_expr : arith_expr \"-\" term\n");}
						;
assert_stmt				: "assert" test
						| "assert" test "," test
						;
async_funcdef			: ASYNC funcdef
						;
async_stmt				: ASYNC funcdef
						| ASYNC with_stmt
						| ASYNC for_stmt
						;
atom					: "..."
						| "None"
						| "True"
						| "False"
						| NAME
						| NUMBER																{D(fout_diag << "YACC:\tatom : NUMBER\n");}
						| string_plus
						| "(" ")"
						| "(" yield_expr ")"
						| "(" testlist_comp ")"
						| "[" "]"
						| "[" testlist_comp "]"
						| "{" "}"
						| "{" dictorsetmaker "}"
						;
atom_expr				: atom trailer_star														{D(fout_diag << "YACC:\tatom_expr : atom trailer_star\n");}
						| AWAIT atom trailer_star
						;
augassign				: "+="
						| "-="
						| "*="
						| "@="
						| "/="
						| "%="
						| "&="
						| "|="
						| "^="
						| "<<="
						| ">>="
						| "**="
						| "//="
						;
break_stmt				: "break"
						;
classdef				: "class" NAME ":" suite												{D(fout_diag << "YACC:\tclassdef : \"class\" NAME : suite\n");}
						| "class" NAME "(" ")" ":" suite
						| "class" NAME "(" arglist ")" ":" suite
						;
comparison				: expr																	{D(fout_diag << "YACC:\tcomparison : expr\n");}
						| comparison comp_op expr												{D(fout_diag << "YACC:\tcomparison : comparison comp_op expr\n");}
						;
compound_stmt			: if_stmt
						| while_stmt
						| for_stmt
						| try_stmt
						| with_stmt
						| funcdef																{D(fout_diag << "YACC:\tcompound_stmt : funcdef\n");}
						| classdef
						| decorated
						| async_stmt
						;
comp_for				: "for" exprlist "in" or_test
						| "for" exprlist "in" or_test comp_iter
						| ASYNC "for" exprlist "in" or_test
						| ASYNC "for" exprlist "in" or_test comp_iter
						;
comp_if					: "if" test_nocond
						| "if" test_nocond comp_iter
						;
comp_iter				: comp_for
						| comp_if
						;
comp_op					: "<"																	{D(fout_diag << "YACC:\tcomp_op : \"<\"\n");}
						| ">" 																	{D(fout_diag << "YACC:\tcomp_op : \">\"\n");}
						| "==" 																	{D(fout_diag << "YACC:\tcomp_op : \"==\"\n");}
						| ">="																	{D(fout_diag << "YACC:\tcomp_op : \">=\"\n");}
						| "<="																	{D(fout_diag << "YACC:\tcomp_op : \"<=\"\n");}
						| "<>"																	{D(fout_diag << "YACC:\tcomp_op : \"<>\"\n");}
						| "!="																	{D(fout_diag << "YACC:\tcomp_op : \"!=\"\n");}
						| "in"																	{D(fout_diag << "YACC:\tcomp_op : \"in\"\n");}
						| "not" "in"															{D(fout_diag << "YACC:\tcomp_op : \"not\" \"in\"\n");}
						| "is"																	{D(fout_diag << "YACC:\tcomp_op : \"is\"\n");}
						| "is" "not"															{D(fout_diag << "YACC:\tcomp_op : \"is\" \"not\"\n");}
						;
continue_stmt			: "continue"
						;
decorated				: decorators classdef
						| decorators funcdef
						| decorators async_funcdef
						;
decorator				: "@" dotted_name NEWLINE
						| "@" dotted_name "(" ")" NEWLINE
						| "@" dotted_name "(" arglist ")" NEWLINE
						;
decorators				: decorator
						| decorators decorator
						;
del_stmt				: "del" exprlist
						;
dictorsetmaker			: test ":" test comp_for
						| test ":" test dictorsetmaker_sub
						| test ":" test dictorsetmaker_sub ","
						| "**" expr comp_for
						| "**" expr dictorsetmaker_sub
						| "**" expr dictorsetmaker_sub ","
						| test comp_for
						| test dictorsetmaker_lsub
						| test dictorsetmaker_lsub ","
						| star_expr comp_for
						| star_expr dictorsetmaker_lsub
						| star_expr dictorsetmaker_lsub ","
						;
dictorsetmaker_sub		: %empty
						| "," test ":" test
						| "," "**" expr
						| dictorsetmaker_sub "," test ":" test
						| dictorsetmaker_sub "," "**" expr
						;
dictorsetmaker_lsub		: %empty
						| "," test
						| "," star_expr
						| dictorsetmaker_lsub "," test
						| dictorsetmaker_lsub "," star_expr
						;
dotted_as_name			: dotted_name
						| dotted_name "as" NAME
						;
dotted_as_names			: dotted_as_name
						| dotted_as_names "," dotted_as_name
						;
dotted_name				: NAME
						| dotted_name "," NAME
						;
dot_plus				: "."
						| "..."
						| dot_plus "."
						| dot_plus "..."
						;
eval_input				: testlist eval_input_sub ENDMARKER
						;
eval_input_sub			: %empty
						| eval_input_sub NEWLINE
						;
except_clause			: "except"
						| "except" test
						| "except" test "as" NAME
						;
exprlist				: exprlist_es exprlist_sub
						| exprlist_es exprlist_sub ","
						;
exprlist_es				: expr
						| star_expr
						;
exprlist_sub			: %empty
						| exprlist_sub "," exprlist_es
						;
expr					: xor_expr																{D(fout_diag << "YACC:\texpr : xor_expr\n");}
						| expr "|" xor_expr														{D(fout_diag << "YACC:\texpr : expr \"|\" xor_expr\n");}
						;
expr_stmt				: testlist_star_expr annassign
						| testlist_star_expr augassign yield_expr
						| testlist_star_expr augassign testlist
						| testlist_star_expr expr_stmt_sub_sub
						;
expr_stmt_sub_sub		: %empty
						| expr_stmt_sub_sub "=" yield_expr
						| expr_stmt_sub_sub "=" testlist_star_expr
						;
factor					: power																	{D(fout_diag << "YACC:\tfactor : power\n");}
						| "+" factor															{D(fout_diag << "YACC:\tfactor : \"+\" factor\n");}
						| "-" factor															{D(fout_diag << "YACC:\tfactor : \"-\" factor\n");}
						| "~" factor															{D(fout_diag << "YACC:\tfactor : \"~\" factor\n");}
						;
file_input_sub			: %empty																{D(fout_diag << "YACC:\tfile_input_sub : \n");}
						| file_input_sub NEWLINE												{D(fout_diag << "YACC:\tfile_input_sub : file_input_sub NEWLINE\n");}
						| file_input_sub stmt													{D(fout_diag << "YACC:\tfile_input_sub : file_input_sub stmt\n");}
						;
flow_stmt				: break_stmt
						| continue_stmt
						| return_stmt															{D(fout_diag << "YACC:\tflow_stmt : return_stmt\n");}
						| raise_stmt
						| yield_stmt
						;
for_stmt				: "for" exprlist "in" testlist ":" suite
						| "for" exprlist "in" testlist ":" suite "else" ":" suite
						;
funcdef					: "def" NAME parameters ":" suite										{D(fout_diag << "YACC:\tfuncdef : \"def\" NAME parameters \":\" suite\n");}
						| "def" NAME parameters "->" test ":" suite								{D(fout_diag << "YACC:\tfuncdef : \"def\" NAME parameters \"->\" test \":\" suite\n");}
						;
global_stmt				: "global" NAME
						| global_stmt "," NAME
						;
if_stmt					: "if" test ":" suite if_stmt_sub
						| "if" test ":" suite if_stmt_sub "else" ":" suite
						;
if_stmt_sub				: %empty
						| if_stmt_sub "elif" test ":" suite
						;
import_as_name			: NAME
						| NAME "as" NAME
						;
import_as_names			: import_as_name
						| import_as_name ","
						| import_as_name "," import_as_names
						;
import_from				: "from" dot_plus dotted_name "import" import_sub
						| "from" dot_plus "import" import_sub
						;
import_name				: "import" dotted_as_names
						;
import_stmt				: import_name
						| import_from
						;
import_sub				: "*"
						| "(" import_as_names ")"
						| import_as_names
						;
lambdef					: "lambda" varargslist ":" test
						| "lambda" ":" test
						;
lambdef_nocond			: "lambda"  ":" test_nocond
						| "lambda" varargslist ":" test_nocond
						;
nonlocal_stmt			: "nonlocal" NAME
						| nonlocal_stmt "," NAME
						;
not_test				: "not" not_test
						| comparison															{D(fout_diag << "YACC:\tnot_test : comparison\n");}
						;
or_test					: and_test																{D(fout_diag << "YACC:\tor_test : and_test\n");}
						| or_test "or" and_test													{D(fout_diag << "YACC:\tor_test : or_test \"or\" and_test\n");}
						;
parameters				: "(" ")"																{D(fout_diag << "YACC:\tparameters : \"(\" \")\"\n");}
						| "(" typedargslist ")"													{D(fout_diag << "YACC:\tparameters : \"(\" typedargslist \")\"\n");}
						;
pass_stmt				: "pass"
						;
power					: atom_expr																{D(fout_diag << "YACC:\tpower : atom_expr\n");}
						| atom_expr "**" factor
						;
raise_stmt				: "raise"
						| "raise" test
						| "raise" test "from" test
						;
return_stmt				: "return"																{D(fout_diag << "YACC:\treturn_stmt : \"return\"\n");}
						| "return" testlist														{D(fout_diag << "YACC:\treturn_stmt : \"return\" testlist\n");}
						;
shift_expr				: arith_expr															{D(fout_diag << "YACC:\tshift_expr : arith_expr\n");}
						| shift_expr "<<" arith_expr											{D(fout_diag << "YACC:\tshift_expr : shift_expr \"<<\" arith_expr\n");}
						| shift_expr ">>" arith_expr											{D(fout_diag << "YACC:\tshift_expr : shift_expr \">>\" arith_expr\n");}
						;
simple_stmt				: small_stmt simple_stmt_sub NEWLINE									{D(fout_diag << "YACC:\tsimple_stmt : small_stmt simple_stmt_sub NEWLINE\n");}
						| small_stmt simple_stmt_sub ";" NEWLINE
						;
simple_stmt_sub			: %empty																{D(fout_diag << "YACC:\tsimple_stmt_sub : \n");}
						| simple_stmt_sub ";" small_stmt
						;
single_input			: NEWLINE																{D(fout_diag << "YACC:\tsingle_input : NEWLINE\n");}
						| simple_stmt															{D(fout_diag << "YACC:\tsingle_input : simple_stmt\n");}
						| compound_stmt NEWLINE													{D(fout_diag << "YACC:\tsingle_input : compound_stmt NEWLINE\n");}
						;
sliceop					: ":"
						| ":" test
						;
small_stmt				: expr_stmt																{D(fout_diag << "YACC:\tsmall_stmt : expr_stmt\n");}
						| del_stmt
						| pass_stmt
						| flow_stmt																{D(fout_diag << "YACC:\tsmall_stmt : flow_stmt\n");}
						| import_stmt
						| global_stmt
						| nonlocal_stmt
						| assert_stmt
						;
star_expr				: "*" expr
						;
stmt					: simple_stmt															{D(fout_diag << "YACC:\tstmt : simple_stmt\n");}
						| compound_stmt															{D(fout_diag << "YACC:\tstmt : compound_stmt\n");}
						;
string_plus				: STRING
						| STRING string_plus
						;
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
suite					: simple_stmt															{D(fout_diag << "YACC:\tsuite : simple_stmt\n");}
						| NEWLINE INDENT suite_sub DEDENT										{D(fout_diag << "YACC:\tsuite : NEWLINE INDENT suite_sub DEDENT\n");}
						;
suite_sub				: stmt																	{D(fout_diag << "YACC:\tsuite_sub : stmt\n");}
						| suite_sub stmt														{D(fout_diag << "YACC:\tsuite_sub : suite_sub stmt\n");}
						;
term					: factor																{D(fout_diag << "YACC:\tterm : factor\n");}
						| term "*" factor														{D(fout_diag << "YACC:\tterm : term \"*\" factor\n");}
						| term "@" factor														{D(fout_diag << "YACC:\tterm : term \"@\" factor\n");}
						| term "/" factor														{D(fout_diag << "YACC:\tterm : term \"/\" factor\n");}
						| term "%" factor														{D(fout_diag << "YACC:\tterm : term \"%\" factor\n");}
						| term "//" factor														{D(fout_diag << "YACC:\tterm : term \"//\" factor\n");}
						;
test					: or_test																{D(fout_diag << "YACC:\ttest : or_test\n");}
						| or_test "if" or_test "else" test
						| lambdef																{D(fout_diag << "YACC:\ttest : lambdef\n");}
						;
testlist				: testlist_sub														{D(fout_diag << "YACC:\ttestlist : test testlist_sub\n");}
						| testlist_sub ","
						;
testlist_comp			: testlist_comp_sub_ts comp_for
						| testlist_comp_sub_ts testlist_comp_sub_co
						| testlist_comp_sub_ts testlist_comp_sub_co ","
						;
testlist_comp_sub_co	: %empty
						| testlist_comp_sub_co "," testlist_comp_sub_ts
						;		
testlist_comp_sub_ts	: test
						| star_expr
						;
testlist_star_expr		: test dictorsetmaker_lsub
						| test dictorsetmaker_lsub ","
						| star_expr dictorsetmaker_lsub
						| star_expr dictorsetmaker_lsub ","
						;
testlist_sub			: test																{D(fout_diag << "YACC:\ttestlist_sub : \n");}
						| testlist_sub "," test
						;
test_nocond				: or_test
						| lambdef_nocond
						;
tfpdef					: NAME 
						| NAME ":" test
						;
trailer					: "(" ")"																{D(fout_diag << "YACC:\ttrailer : \"(\" \")\"\n");}
						| "(" arglist ")"														{D(fout_diag << "YACC:\ttrailer : \"(\" arglist \")\"\n");}
						| "[" subscriptlist "]"													{D(fout_diag << "YACC:\ttrailer : \"[\" subscriptlist \"]\"\n");}
						| "." NAME																{D(fout_diag << "YACC:\ttrailer : \".\" NAME\n");}
						;
trailer_star			: %empty																{D(fout_diag << "YACC:\ttrailer_star : \n");}
						| trailer_star trailer													{D(fout_diag << "YACC:\ttrailer_star : trailer_star trailer\n");}
						;
try_stmt				: "try" ":" suite try_stmt_sub
						| "try" ":" suite try_stmt_sub "finally" ":" suite
						| "try" ":" suite try_stmt_sub "else" ":" suite 
						| "try" ":" suite try_stmt_sub "else" ":" suite "finally" ":" suite
						| "try" ":" suite "finally" ":" suite
						;
try_stmt_sub			: except_clause ":" suite
						| try_stmt_sub except_clause ":" suite
						;
typedargslist			: tfpdef  typedargslist_ct typedargslist_long
						| tfpdef "=" test typedargslist_ct typedargslist_long
						| "*" typedargslist_ct
						| "*" typedargslist_ct "," typedargslist_sub
						| "*" tfpdef typedargslist_ct
						| "*" tfpdef typedargslist_ct "," typedargslist_sub
						| "**" tfpdef
						| "**" tfpdef ","
						;
typedargslist_ct		: %empty
						| typedargslist_ct "," tfpdef
						| typedargslist_ct "," tfpdef "=" test
						;
typedargslist_long		: %empty
						| "," 
						| "," "*" typedargslist_ct
						| "," "*" typedargslist_ct "," typedargslist_sub
						| "," "*" tfpdef typedargslist_ct
						| "," "*" tfpdef typedargslist_ct "," typedargslist_sub
						| "," "**" tfpdef
						| "," "**" tfpdef ","
						;
typedargslist_sub		: %empty
						| "**" tfpdef
						| "**" tfpdef ","
						;
varargslist				: vfpdef "=" test varargslist_another_sub
						| vfpdef varargslist_another_sub
						| "*" varargslist_sub_sub_sub
						| "**" vfpdef
						| "**" vfpdef ","
						;
varargslist_another_sub	: varargslist_sub
						| varargslist_sub ","
						| varargslist_sub "," "*" varargslist_sub_sub_sub
						| varargslist_sub "," "**" vfpdef
						| varargslist_sub "," "**" vfpdef ","
						;
varargslist_sub			: %empty
						| varargslist_sub "," vfpdef
						| varargslist_sub "," vfpdef "=" test
						;
varargslist_sub_sub		: varargslist_sub
						| varargslist_sub ","
						| varargslist_sub "," "**" vfpdef
						| varargslist_sub "," "**" vfpdef ","
						;
varargslist_sub_sub_sub	: varargslist_sub_sub
						| vfpdef varargslist_sub_sub
						;
vfpdef					: NAME
						;
while_stmt				: "while" test ":" suite
						| "while" test ":" suite "else" ":" suite
						;
with_item				: test
						| test "as" expr
						;
with_stmt				: "with" with_stmt_sub ":" suite
						;
with_stmt_sub			: with_item
						| with_stmt_sub "," with_item
						;
xor_expr				: and_expr																{D(fout_diag << "YACC:\txor_expr : and_expr\n");}
						| xor_expr "^" and_expr													{D(fout_diag << "YACC:\txor_expr : xor_expr \"^\" and_expr\n");}
						;
yield_arg				: "from" test
						| testlist
						;
yield_expr				: "yield"
						| "yield" yield_arg
						;
yield_stmt				: yield_expr
						;
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
	D(PrintTokens(T));
	yyparse();
	fout_diag.close();
	return 0;
};
void PrintTokens(TokenTable * T) {
	system("CLS");
	for (int i = 0; i < TOKEN_TABLE_SIZE && T->t[i].availability != 0; i++) {
		fout_diag << T->t[i].lineno << "\t" << T->t[i].layer << "\t";
		switch (T->t[i].type) {
			case STRING:{
				fout_diag << "STRING" << "\t" << T->t[i].value.S;
				break;
			}
			case NUMBER:{
				fout_diag << "NUMBER" << "\t" << T->t[i].value.D;
				break;
			}
			case CHAR:{
				fout_diag << "CHAR" << "\t" << T->t[i].value.C;
				break;
			}
			case NAME:{
				fout_diag << "NAME" << "\t" << T->t[i].value.S;
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
			default:{
				fout_diag << T->t[i].value.S;
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
			yylval.String = T->t[i].value.S;
			D(fout_diag << "LEX:\tSTRING\t" << yylval.String << endl);
			break;
		}
		case NUMBER:{
			yylval.Double = T->t[i].value.D;
			D(fout_diag << "LEX:\tNUMBER\t" << yylval.Double << endl);
			break;
		}
		case CHAR:{
			yylval.Char = T->t[i].value.C;
			D(fout_diag << "LEX:\tCHAR\t" << yylval.Char << endl);
			break;
		}
		case NAME:{
			yylval.Name = T->t[i].value.S;
			D(fout_diag << "LEX:\tNAME\t" << yylval.Name << endl);
			break;
		}
		case INDENT:{
			D(fout_diag << "LEX:\tINDENT" << endl);
			break;
		}
		case DEDENT:{
			D(fout_diag << "LEX:\tDEDENT" << endl);
			break;
		}
		case NEWLINE:{
			D(fout_diag << "LEX:\tNEWLINE" << endl);
			break;
		}
		default:{
			yylval.Name = T->t[i].value.S;
			D(fout_diag << "LEX:\t" << yylval.Name << endl);
			break;
		}
	}
	T->Pointer++;
	return T->t[i].type;
}
void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}