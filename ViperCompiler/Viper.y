%{
using namespace std;
#include "ctype.h"
#include "string.h"
#include "iostream"
#include "fstream"
#include "math.h"
#define D(x) if (!VIPER_COMPILER_DIAGNOSE); else x

const int TOKEN_TABLE_SIZE = 4096;
const int VIPER_COMPILER_DIAGNOSE = 1;
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
file_input				: file_input_sub ENDMARKER												{D(printf("YACC:\t file_input : file_input_sub ENDMARKER\n"));}
						;
comp_op					: "<"																	{D(printf("YACC:\t comp_op : \"<\"\n"));}
						| ">" 																	{D(printf("YACC:\t comp_op : \">\"\n"));}
						| "==" 																	{D(printf("YACC:\t comp_op : \"==\"\n"));}
						| ">="																	{D(printf("YACC:\t comp_op : \">=\"\n"));}
						| "<="																	{D(printf("YACC:\t comp_op : \"<=\"\n"));}
						| "<>"																	{D(printf("YACC:\t comp_op : \"<>\"\n"));}
						| "!="																	{D(printf("YACC:\t comp_op : \"!=\"\n"));}
						| "in"																	{D(printf("YACC:\t comp_op : \"in\"\n"));}
						| "not" "in"															{D(printf("YACC:\t comp_op : \"not\" \"in\"\n"));}
						| "is"																	{D(printf("YACC:\t comp_op : \"is\"\n"));}
						| "is" "not"															{D(printf("YACC:\t comp_op : \"is\" \"not\"\n"));}
						;
single_input			: NEWLINE																{D(printf("YACC:\t single_input : NEWLINE\n"));}
						| simple_stmt															{D(printf("YACC:\t single_input : simple_stmt\n"));}
						| compound_stmt NEWLINE													{D(printf("YACC:\t single_input : compound_stmt NEWLINE\n"));}
						;
file_input_sub			: %empty																{D(printf("YACC:\t file_input_sub : \n"));}
						| NEWLINE file_input_sub												{D(printf("YACC:\t file_input_sub : NEWLINE file_input_sub\n"));}
						| stmt file_input_sub													{D(printf("YACC:\t file_input_sub : stmt file_input_sub\n"));}
						;
eval_input_sub			: %empty
						| eval_input_sub NEWLINE
						;
eval_input				: testlist eval_input_sub ENDMARKER
						;
classdef				: "class" NAME ":" suite												{D(printf("YACC:\t classdef : \"class\" NAME : suite\n"));}
						| "class" NAME "(" ")" ":" suite
						| "class" NAME "(" arglist ")" ":" suite
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
typedargslist_ct		: %empty
						| "," tfpdef typedargslist_ct
						| "," tfpdef "=" test typedargslist_ct
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
parameters				: "(" ")"																{D(printf("YACC:\t parameters : \"(\" \")\"\n"));}
						| "(" typedargslist ")"													{D(printf("YACC:\t parameters : \"(\" typedargslist \")\"\n"));}
						;
funcdef					: "def" NAME parameters ":" suite										{D(printf("YACC:\t funcdef : \"def\" NAME parameters \":\" suite\n"));}
						| "def" NAME parameters "->" test ":" suite								{D(printf("YACC:\t funcdef : \"def\" NAME parameters \"->\" test \":\" suite\n"));}
						;
async_funcdef			: ASYNC funcdef
						;
decorator				: "@" dotted_name NEWLINE
						| "@" dotted_name "(" ")" NEWLINE
						| "@" dotted_name "(" arglist ")" NEWLINE
						;
decorators				: decorator
						| decorator decorators
						;
decorated				: decorators classdef
						| decorators funcdef
						| decorators async_funcdef
						;
tfpdef					: NAME 
						| NAME ":" test
						;
suite_sub				: stmt																	{D(printf("YACC:\t suite_sub : stmt\n"));}
						| stmt suite_sub														{D(printf("YACC:\t suite_sub : stmt suite_sub\n"));}
						;
suite					: simple_stmt															{D(printf("YACC:\t suite : simple_stmt\n"));}							
						| NEWLINE INDENT suite_sub DEDENT										{D(printf("YACC:\t suite : NEWLINE INDENT suite_sub DEDENT\n"));}
						;
stmt					: simple_stmt															{D(printf("YACC:\t stmt : simple_stmt\n"));}
						| compound_stmt															{D(printf("YACC:\t stmt : compound_stmt\n"));}
						;
simple_stmt_sub			: %empty																{D(printf("YACC:\t simple_stmt_sub : \n"));}
						| ";" small_stmt simple_stmt_sub
simple_stmt				: small_stmt simple_stmt_sub NEWLINE									{D(printf("YACC:\t simple_stmt : small_stmt simple_stmt_sub NEWLINE\n"));}
						| small_stmt simple_stmt_sub ";" NEWLINE
						;
varargslist_another_sub	: varargslist_sub
						| varargslist_sub ","
						| varargslist_sub "," "*" varargslist_sub_sub_sub
						| varargslist_sub "," "**" vfpdef
						| varargslist_sub "," "**" vfpdef "," ;
varargslist_sub_sub_sub	: vfpdef varargslist_sub_sub
						| varargslist_sub_sub ;
varargslist_sub_sub		: varargslist_sub
						| varargslist_sub ","
						| varargslist_sub "," "**" vfpdef
						| varargslist_sub "," "**" vfpdef "," ;
varargslist_sub			: %empty
						| "," vfpdef varargslist_sub
						| "," vfpdef "=" test varargslist_sub ;
varargslist				: vfpdef "=" test varargslist_another_sub
						| vfpdef varargslist_another_sub
						| "*" varargslist_sub_sub_sub
						| "**" vfpdef
						| "**" vfpdef "," ;
sliceop					: ":"
						| ":" test
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
subscriptlist_sub		: %empty
						| "," subscript subscriptlist_sub
						;
subscriptlist			: subscript subscriptlist_sub
						| subscript subscriptlist_sub ","
						;
argument				: test																	{D(printf("YACC:\t argument : test\n"));}
						| test comp_for
						| test "=" test
						| "**" test
						| "*" test 
						;
arglist_sub				: %empty
						| "," argument arglist_sub
						;
arglist					: argument arglist_sub
						| argument arglist_sub ","
						;
trailer					: "(" ")"																{D(printf("YACC:\t trailer : \"(\" \")\"\n"));}
						| "(" arglist ")"														{D(printf("YACC:\t trailer : \"(\" arglist \")\"\n"));}
						| "[" subscriptlist "]"													{D(printf("YACC:\t trailer : \"[\" subscriptlist \"]\"\n"));}
						| "." NAME																{D(printf("YACC:\t trailer : \".\" NAME\n"));}
						;
testlist_sub			: %empty																{D(printf("YACC:\t testlist_sub : \n"));}
						| "," test testlist_sub
testlist				: test testlist_sub														{D(printf("YACC:\t testlist : test testlist_sub\n"));}
						| test testlist_sub ","
						;
yield_arg				: "from" test
						| testlist
						;
yield_expr				: "yield"
						| "yield" yield_arg
						;
small_stmt				: expr_stmt																{D(printf("YACC:\t small_stmt : expr_stmt\n"));}
						| del_stmt
						| pass_stmt
						| flow_stmt																{D(printf("YACC:\t small_stmt : flow_stmt\n"));}
						| import_stmt
						| global_stmt
						| nonlocal_stmt
						| assert_stmt
						;
expr_sub_sub			: %empty
						| "=" yield_expr expr_sub_sub
						| "=" testlist_star_expr expr_sub_sub
						;
expr_sub				: annassign
						| augassign yield_expr
						| augassign testlist
						| expr_sub_sub
						;
expr_stmt				: testlist_star_expr expr_sub
						;
annassign				: ":" test
						| ":" test "=" test
						;
testlist_star_expr		: dictorsetmaker_sub dictorsetmaker_sub
						| dictorsetmaker_sub dictorsetmaker_sub ","
						;
star_expr				: "*" expr
						;
exprlist_es				: expr
						| star_expr
						;
exprlist_sub			: %empty
						| "," exprlist_es exprlist_sub
						;
exprlist				: exprlist_es exprlist_sub
						| exprlist_es exprlist_sub ","
lambdef_nocond			: "lambda"  ":" test_nocond
						| "lambda" varargslist ":" test_nocond
						;
test_nocond				: or_test
						| lambdef_nocond
						;
comp_if					: "if" test_nocond
						| "if" test_nocond comp_iter
						;
comp_iter				: comp_for
						| comp_if
						;
comp_for				: "for" exprlist "in" or_test
						| "for" exprlist "in" or_test comp_iter
						| ASYNC "for" exprlist "in" or_test
						| ASYNC "for" exprlist "in" or_test comp_iter
						;
testlist_comp_sub_ts	: test
						| star_expr
						;
dictorsetmaker_sub		: %empty
						| "," testlist_comp_sub_ts dictorsetmaker_sub
						;
dictorsetmaker_tt		: test ":" test
						| "**" expr
						;
dictorsetmaker_tt_sub	: %empty
						| "," dictorsetmaker_tt dictorsetmaker_tt_sub
						;
dictorsetmaker			: dictorsetmaker_tt comp_for
						| dictorsetmaker_tt dictorsetmaker_tt_sub
						| dictorsetmaker_tt dictorsetmaker_tt_sub ","
						| testlist_comp_sub_ts comp_for
						| testlist_comp_sub_ts dictorsetmaker_sub
						| testlist_comp_sub_ts dictorsetmaker_sub ","
						;
lambdef					: "lambda" varargslist ":" test
						| "lambda" ":" test
						;
testlist_comp_sub_co	: %empty
						| "," testlist_comp_sub_ts testlist_comp_sub_co
						;
testlist_comp			: testlist_comp_sub_ts comp_for
						| testlist_comp_sub_ts testlist_comp_sub_co
						| testlist_comp_sub_ts testlist_comp_sub_co ","
						;
string_plus				: STRING
						| STRING string_plus ;
atom_sub_yt				: %empty
						| yield_expr
						| testlist_comp ;
atom_sub_t				: %empty
						| testlist_comp ;
atom_sub_d				: %empty
						| dictorsetmaker ;
atom					: "..."
						| "None"
						| "True"
						| "False"
						| NAME
						| NUMBER																{D(printf("YACC:\t atom : NUMBER\n"));}
						| string_plus
						| "(" atom_sub_yt ")"
						| "[" atom_sub_t "]"
						| "{" atom_sub_d "}" ;
trailer_star			: %empty																{D(printf("YACC:\t trailer_star : \n"));}
						| trailer trailer_star													{D(printf("YACC:\t trailer_star : trailer trailer_star\n"));}
						;
except_clause			: "except"
						| "except" test
						| "except" test "as" NAME
						;
while_stmt				: "while" test ":" suite
						| "while" test ":" suite "else" ":" suite
						;
for_stmt				: "for" exprlist "in" testlist ":" suite
						| "for" exprlist "in" testlist ":" suite "else" ":" suite
						;
try_stmt_sub_sub		: "finally" ":" suite
						;
try_stmt_sub_plus		: except_clause ":" suite
						| except_clause ":" suite try_stmt_sub_plus
						;
try_stmt_sub			: try_stmt_sub_plus
						| try_stmt_sub_plus try_stmt_sub_sub
						| try_stmt_sub_plus "else" ":" suite
						| try_stmt_sub_plus "else" ":" suite try_stmt_sub_sub
						| try_stmt_sub_sub
						;
try_stmt				: "try" ":" suite try_stmt_sub
						;
with_stmt_sub			: %empty
						| "," with_item with_stmt_sub
						;
with_stmt				: "with" with_item with_stmt_sub ":" suite
						;
with_item				: test
						| test "as" expr
						;
atom_expr				: atom trailer_star														{D(printf("YACC:\t atom_expr : atom trailer_star\n"));}
						| AWAIT atom trailer_star
						;
power					: atom_expr																{D(printf("YACC:\t power : atom_expr\n"));}
						| atom_expr "**" factor
						;
factor					: power																	{D(printf("YACC:\t factor : power\n"));}
						| "+" factor															{D(printf("YACC:\t factor : \"+\" factor\n"));}
						| "-" factor															{D(printf("YACC:\t factor : \"-\" factor\n"));}
						| "~" factor															{D(printf("YACC:\t factor : \"~\" factor\n"));}
						;
term_sub				: %empty																{D(printf("YACC:\t term_sub : \n"));}
						| "*" factor term_sub													{D(printf("YACC:\t term_sub : \"*\" factor term_sub\n"));}
						| "@" factor term_sub													{D(printf("YACC:\t term_sub : \"@\" factor term_sub\n"));}
						| "/" factor term_sub													{D(printf("YACC:\t term_sub : \"/\" factor term_sub\n"));}
						| "%" factor term_sub													{D(printf("YACC:\t term_sub : \"$\" factor term_sub\n"));}
						| "//" factor term_sub													{D(printf("YACC:\t term_sub : \"//\" factor term_sub\n"));}
						;
term					: factor term_sub														{D(printf("YACC:\t term : factor term_sub\n"));}
						;
arith_expr_sub			: %empty																{D(printf("YACC:\t arith_expr_sub : \n"));}
						| "+" term arith_expr_sub												{D(printf("YACC:\t arith_expr_sub : \"+\" term arith_expr_sub\n"));}
						| "-" term arith_expr_sub												{D(printf("YACC:\t arith_expr_sub : \"-\" term arith_expr_sub\n"));}
						;
arith_expr				: term arith_expr_sub													{D(printf("YACC:\t arith_expr : term arith_expr_sub\n"));}
						;
shift_expr_sub			: %empty																{D(printf("YACC:\t shift_expr_sub :  \n"));}
						| "<<" expr shift_expr_sub
						| ">>" expr shift_expr_sub
						;
shift_expr				: arith_expr shift_expr_sub												{D(printf("YACC:\t shift_expr : arith_expr shift_expr_sub\n"));}
						;
and_expr_sub			: %empty																{D(printf("YACC:\t and_expr_sub :  \n"));}
						| "&" shift_expr and_expr_sub
						;
and_expr				: shift_expr and_expr_sub												{D(printf("YACC:\t and_expr : shift_expr and_expr_sub\n"));}
						;
xor_expr_sub			: %empty																{D(printf("YACC:\t xor_expr_sub : \n"));}
						| "^" and_expr xor_expr_sub
						;
xor_expr				: and_expr xor_expr_sub													{D(printf("YACC:\t xor_expr : and_expr xor_expr_sub\n"));}
						;
expr_sub				: %empty																{D(printf("YACC:\t expr_sub : \n"));}
						| "|" xor_expr expr_sub ;
expr					: xor_expr expr_sub														{D(printf("YACC:\t expr : xor_expr expr_sub\n"));}
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
comparison_sub			: %empty																{D(printf("YACC:\t comparison_sub : \n"));}
						| comp_op expr comparison_sub 											{D(printf("YACC:\t comparison_sub :  comp_op expr comparison_sub\n"));}
						;
comparison				: expr comparison_sub													{D(printf("YACC:\t comparison : expr comparison_sub\n"));}
						;
not_test				: "not" not_test
						| comparison															{D(printf("YACC:\t not_test : comparison\n"));}
						;
and_test_sub			: %empty																{D(printf("YACC:\t and_test_sub : \n"));}
						| "and" not_test and_test_sub
						;
and_test				: not_test and_test_sub													{D(printf("YACC:\t and_test : not_test and_test_sub\n"));}
						;
or_test_sub				: %empty																{D(printf("YACC:\t or_test_sub : \n"));}
						| "or" and_test or_test_sub
						;											
or_test					: and_test or_test_sub													{D(printf("YACC:\t or_test : and_test or_test_sub\n"));}
						;
test					: or_test																{D(printf("YACC:\t test : or_test\n"));}
						| or_test "if" or_test "else" test
						| lambdef																{D(printf("YACC:\t test : lambdef\n"));}
						;
assert_stmt				: "assert" test
						| "assert" test "," test
						;
compound_stmt			: if_stmt
						| while_stmt
						| for_stmt
						| try_stmt
						| with_stmt
						| funcdef																{D(printf("YACC:\t compound_stmt : funcdef\n"));}
						| classdef
						| decorated
						| async_stmt
						;
async_stmt				: ASYNC funcdef
						| ASYNC with_stmt
						| ASYNC for_stmt
						;
if_stmt_sub				: %empty
						| "elif" test ":" suite if_stmt_sub ;
if_stmt					: "if" test ":" suite if_stmt_sub
						| "if" test ":" suite if_stmt_sub "else" ":" suite
						;
global_stmt				: "global" NAME
						| global_stmt "," NAME ;
nonlocal_stmt			: "nonlocal" NAME
						| nonlocal_stmt "," NAME ;
dotted_name				: NAME
						| dotted_name "," NAME ;
vfpdef					: NAME ;
continue_stmt			: "continue" ;
flow_stmt				: break_stmt
						| continue_stmt
						| return_stmt															{D(printf("YACC:\t flow_stmt : return_stmt\n"));}
						| raise_stmt
						| yield_stmt
						;
del_stmt				: "del" exprlist
						;
break_stmt				: "break" ;
pass_stmt				: "pass" ;
import_as_name			: NAME
						| NAME "as" NAME ;
dotted_as_name			: dotted_name
						| dotted_name "as" NAME ;
import_as_names			: import_as_name
						| import_as_name ","
						| import_as_name "," import_as_names ;
dotted_as_names			: dotted_as_name
						| dotted_as_names "," dotted_as_name ;
import_sub				: "*"
						| "(" import_as_names ")"
						| import_as_names
						;
dot_plus				: "."
						| "..."
						| "." dot_plus
						| "..." dot_plus
						;
import_from				: "from" dot_plus dotted_name "import" import_sub
						| "from" dot_plus "import" import_sub
						;
import_name				: "import" dotted_as_names
						;
import_stmt				: import_name
						| import_from
						;
raise_stmt				: "raise"
						| "raise" test
						| "raise" test "from" test
						;
yield_stmt				: yield_expr
						;
return_stmt				: "return"																{D(printf("YACC:\t return_stmt : \"return\"\n"));}
						| "return" testlist														{D(printf("YACC:\t return_stmt : \"return\" testlist\n"));}
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
	D(DispTokens(T));
	D(printf("START PARSING\n"));
	return yyparse();
};
void DispTokens(TokenTable * T) {
	system("CLS");
	for (int i = 0; i < TOKEN_TABLE_SIZE && T->t[i].availability != 0; i++) {
		cout << T->t[i].lineno << "\t" << T->t[i].layer << "\t";
		switch (T->t[i].type) {
			case STRING:{
				cout << "STRING" << "\t" << T->t[i].value.S;
				break;
			}
			case NUMBER:{
				cout << "NUMBER" << "\t" << T->t[i].value.D;
				break;
			}
			case CHAR:{
				cout << "CHAR" << "\t" << T->t[i].value.C;
				break;
			}
			case NAME:{
				cout << "NAME" << "\t" << T->t[i].value.S;
				break;
			}
			case INDENT:{
				cout << "INDENT";
				break;
			}
			case DEDENT:{
				cout << "DEDENT";
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
	D(printf("TOKENS READ SUCCESSFULLY\n"));
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
			D(printf("LEX:\tSTRING\t%s\n", yylval.String));
			break;
		}
		case NUMBER:{
			yylval.Double = T->t[i].value.D;
			D(printf("LEX:\tNUMBER\t%lf\n", yylval.Double));
			break;
		}
		case CHAR:{
			yylval.Char = T->t[i].value.C;
			D(printf("LEX:\tCHAR\t%c\n", yylval.Char));
			break;
		}
		case NAME:{
			yylval.Name = T->t[i].value.S;
			D(printf("LEX:\tNAME\t%s\n", yylval.Name));
			break;
		}
		case INDENT:{
			D(printf("LEX:\tINDENT\n"));
			break;
		}
		case DEDENT:{
			D(printf("LEX:\tDEDENT\n"));
			break;
		}
		case NEWLINE:{
			D(printf("LEX:\tNEWLINE\n"));
			break;
		}
		default:{
			yylval.Name = T->t[i].value.S;
			D(printf("LEX:\tDEFAULT\t%s\n", yylval.Name));
			break;
		}
	}
	T->Pointer++;
	return T->t[i].type;
}
void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}