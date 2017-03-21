%option C++ noyywrap

%{
using namespace std;
#include <fstream>
#include "Viper.tab.h"
int mylineno = 1;
int prev_dent = 0;
int curr_dent = 0;
ifstream* fin = 0;
ofstream* fout = 0;
%}

comment		[#][^\n]+
docstring	\t\'\'\'
char		\'[^\n']\'
str1		\"[^\n"]+\"
str2		\'[^\n']+\'
string		{str1}|{str2}
ws			[ ]+
letter		[A-Za-z]
digit		[0-9]
name		[\_]?({letter}|\$)({letter}|{digit}|\_|\$)*
num1		{digit}+\.?([eE][-+]?{digit}+)?
num2		{digit}*\.{digit}+([eE][-+]?{digit}+)?
number		{num1}|{num2}
literal		{number}
%%

{ws}		/* skip blanks and tabs */
{docstring}	{
				int c;
				while((c = yyinput()) != 0) {
				if(c == '\'') 
					if((c = yyinput()) == '\'')
						if((c = yyinput()) =='\'')
							break;
				else if (c == '\n')
					mylineno++;
				else
					unput(c);
				}
				if ((c = yyinput()) == '\n')
					*fout << mylineno << "\t" << INDENT << "\t" << "INDENT" << "\n";
			}
\n			{
				curr_dent = 0;
				char c;
				if ((c = yyinput()) != '\t' && prev_dent != 0)
					for (int i = 0; i < prev_dent + 1; i++)
						*fout << mylineno << "\t" << DEDENT << "\t" << "DEDENT" << "\n";
				unput(c);
				*fout << mylineno++ << "\t" << NEWLINE << "\t" << "NEWLINE" << "\n";
				return NEWLINE;
			}
\t			{
				curr_dent = 0;
				char c;
				while((c = yyinput()) == '\t'){
					curr_dent++;
				}
				if (c != '\n'){
				unput(c);
				if (curr_dent > prev_dent)
					for (int i = 0; i < curr_dent - prev_dent; i++)
						*fout << mylineno << "\t" << INDENT << "\t" << "INDENT" << "\n";	
				if (curr_dent < prev_dent)
					for (int i = 0; i < prev_dent - curr_dent; i++)
						*fout << mylineno << "\t" << DEDENT << "\t" <<"DEDENT" << "\n";
				prev_dent = curr_dent;
				}
			}
"..."		{*fout << mylineno << "\t" << ELLIPSIS << "\t" << YYText() << "\n"; return ELLIPSIS;}
"("			{*fout << mylineno << "\t" << OPARENT << "\t" << YYText() << "\n"; return OPARENT;}
")"			{*fout << mylineno << "\t" << CPARENT << "\t" << YYText() << "\n"; return CPARENT;}
"["			{*fout << mylineno << "\t" << OBRACK << "\t" << YYText() << "\n"; return OBRACK;}
"]"			{*fout << mylineno << "\t" << CBRACK << "\t" << YYText() << "\n"; return CBRACK;}
"{"			{*fout << mylineno << "\t" << OBRACE << "\t" << YYText() << "\n"; return OBRACE;}
"}"			{*fout << mylineno << "\t" << CBRACE << "\t" << YYText() << "\n"; return CBRACE;}
"@"			{*fout << mylineno << "\t" << AT << "\t" << YYText() << "\n"; return AT;}
","			{*fout << mylineno << "\t" << COMMA << "\t" << YYText() << "\n"; return COMMA;}
":"			{*fout << mylineno << "\t" << COLON << "\t" << YYText() << "\n"; return COLON;}
"."			{*fout << mylineno << "\t" << PERIOD << "\t" << YYText() << "\n"; return PERIOD;}
"="			{*fout << mylineno << "\t" << ASSIGN << "\t" << YYText() << "\n"; return ASSIGN;}
";"			{*fout << mylineno << "\t" << SEMICOLON << "\t" << YYText() << "\n"; return SEMICOLON;}
"+="		{*fout << mylineno << "\t" << PLUS_EQUAL << "\t" << YYText() << "\n"; return PLUS_EQUAL;}
"-="		{*fout << mylineno << "\t" << MINUS_EQUAL << "\t" << YYText() << "\n"; return MINUS_EQUAL;}
"*="		{*fout << mylineno << "\t" << MULTIPLY_EQUAL << "\t" << YYText() << "\n"; return MULTIPLY_EQUAL;}
"/="		{*fout << mylineno << "\t" << DIVIDE_EQUAL << "\t" << YYText() << "\n"; return DIVIDE_EQUAL;}
"//="		{*fout << mylineno << "\t" << FD_EQUAL << "\t" << YYText() << "\n"; return FD_EQUAL;}
"%="		{*fout << mylineno << "\t" << MOD_EQUAL << "\t" << YYText() << "\n"; return MOD_EQUAL;}
"**="		{*fout << mylineno << "\t" << POWER_EQUAL << "\t" << YYText() << "\n"; return POWER_EQUAL;}


"from"		{*fout << mylineno << "\t" << FROM << "\t" << YYText() << "\n"; return FROM;}
"nonlocal"		{*fout << mylineno << "\t" << NONLOCAL << "\t" << YYText() << "\n"; return NONLOCAL;}
"raise"		{*fout << mylineno << "\t" << RAISE << "\t" << YYText() << "\n"; return RAISE;}
"try"		{*fout << mylineno << "\t" << TRY << "\t" << YYText() << "\n"; return TRY;}
"del"		{*fout << mylineno << "\t" << DEL << "\t" << YYText() << "\n"; return DEL;}
"as"		{*fout << mylineno << "\t" << AS << "\t" << YYText() << "\n"; return AS;}
"assert"	{*fout << mylineno << "\t" << ASSERT << "\t" << YYText() << "\n"; return ASSERT;}
"is"		{*fout << mylineno << "\t" << IS << "\t" << YYText() << "\n"; return IS;}
"except"	{*fout << mylineno << "\t" << EXCEPT << "\t" << YYText() << "\n"; return EXCEPT;}
"finally"	{*fout << mylineno << "\t" << FINALLY << "\t" << YYText() << "\n"; return FINALLY;}
"lambda"	{*fout << mylineno << "\t" << LAMBDA << "\t" << YYText() << "\n"; return LAMBDA;}
"yield"		{*fout << mylineno << "\t" << YIELD << "\t" << YYText() << "\n"; return YIELD;}
"exec"		{*fout << mylineno << "\t" << EXEC << "\t" << YYText() << "\n"; return EXEC;}
"import"	{*fout << mylineno << "\t" << IMPORT << "\t" << YYText() << "\n"; return IMPORT;}
"with"		{*fout << mylineno << "\t" << WITH << "\t" << YYText() << "\n"; return WITH;}
"print"		{*fout << mylineno << "\t" << PRINT << "\t" << YYText() << "\n"; return PRINT;}
"while"		{*fout << mylineno << "\t" << WHILE << "\t" << YYText() << "\n"; return WHILE;}
"break"		{*fout << mylineno << "\t" << BREAK << "\t" << YYText() << "\n"; return BREAK;}
"continue"	{*fout << mylineno << "\t" << CONTINUE << "\t" << YYText() << "\n"; return CONTINUE;}
"global"	{*fout << mylineno << "\t" << GLOBAL << "\t" << YYText() << "\n"; return GLOBAL;}
"elif"		{*fout << mylineno << "\t" << ELIF << "\t" << YYText() << "\n"; return ELIF;}
"else"		{*fout << mylineno << "\t" << ELSE << "\t" << YYText() << "\n"; return ELSE;}
"pass"		{*fout << mylineno << "\t" << PASS << "\t" << YYText() << "\n"; return PASS;}
"return"	{*fout << mylineno << "\t" << RETURN << "\t" << YYText() << "\n"; return RETURN;}
"in"		{*fout << mylineno << "\t" << IN << "\t" << YYText() << "\n"; return IN;}
"for"		{*fout << mylineno << "\t" << FOR << "\t" << YYText() << "\n"; return FOR;}
"class"		{*fout << mylineno << "\t" << CLASS << "\t" << YYText() << "\n"; return CLASS;}
"not"		{*fout << mylineno << "\t" << NOT << "\t" << YYText() << "\n"; return NOT;}
"and"		{*fout << mylineno << "\t" << AND << "\t" << YYText() << "\n"; return AND;}
"or"		{*fout << mylineno << "\t" << OR << "\t" << YYText() << "\n"; return OR;}
"if"		{*fout << mylineno << "\t" << IF << "\t" << YYText() << "\n"; return IF;}
"def"		{*fout << mylineno << "\t" << DEF << "\t" << YYText() << "\n"; return DEF;}

"**"		{*fout << mylineno << "\t" << POWER << "\t" << YYText() << "\n"; return POWER;}
"//"		{*fout << mylineno << "\t" << FLOOR_DIVISION << "\t" << YYText() << "\n"; return FLOOR_DIVISION;}
"+"			{*fout << mylineno << "\t" << PLUS << "\t" << YYText() << "\n"; return '+';}
"-"			{*fout << mylineno << "\t" << MINUS << "\t" << YYText() << "\n"; return '-';}
"*"			{*fout << mylineno << "\t" << MULTIPLY << "\t" << YYText() << "\n"; return '*';}
"/"			{*fout << mylineno << "\t" << DIVIDE << "\t" << YYText() << "\n"; return '/';}
"%"			{*fout << mylineno << "\t" << MOD << "\t" << YYText() << "\n"; return '%';}
"<>"		{*fout << mylineno << "\t" << UNEQUAL << "\t" << YYText() << "\n"; return UNEQUAL;}
"<"			{*fout << mylineno << "\t" << LESS_THAN << "\t" << YYText() << "\n"; return LESS_THAN;}
"<="		{*fout << mylineno << "\t" << LT_OR_EQUAL << "\t" << YYText() << "\n"; return LT_OR_EQUAL;}
"=="		{*fout << mylineno << "\t" << EQUAL << "\t" << YYText() << "\n"; return EQUAL;}
"!="		{*fout << mylineno << "\t" << UNEQUAL << "\t" << YYText() << "\n"; return UNEQUAL;}
">="		{*fout << mylineno << "\t" << MT_OR_EQUAL << "\t" << YYText() << "\n"; return MT_OR_EQUAL;}
">"			{*fout << mylineno << "\t" << MORE_THAN << "\t" << YYText() << "\n"; return MORE_THAN;}

{comment}	{
				int c;
				while((c = yyinput()) != 0) {
				if(c == '\n') {
					++mylineno;
					break;
				}	
				else
					unput(c);
				}
			}
{literal}	{
				*fout << mylineno << "\t" << NUMBER << "\t" << YYText() << "\n";
				return NUMBER;
			}
{name}		{
				*fout << mylineno << "\t" << NAME << "\t" << YYText() << "\n";
				return NAME;
			}
{char}		{
				*fout << mylineno << "\t" << CHAR << "\t" << YYText() << "\n";
				return CHAR;
			}
{string}	{
				*fout << mylineno << "\t" << STRING << "\t" << YYText() << "\n";
				return STRING;
			}
.			{
				fprintf(stderr, "Unknown Lexical Element!");
				exit(1);
			}
%%

int main(int argc, char* argv[]) {
	if (argc == 1) {
		fprintf(stderr, "Expected 1 or 2 arguments!");
		exit(1);
	}
	ifstream* in = new ifstream(argv[1], ios::in);
	fin = in;
	if (fin->bad()) {
		fprintf(stderr, "Input Error");
		exit(1);
	}
	ofstream* out = new ofstream("tokens.txt", ios::out);
	if (argc == 3)
		ofstream* out = new ofstream(argv[2], ios::out);
	fout = out;
	if (fout->bad()) {
		fprintf(stderr, "Output Error");
		exit(1);
	}
	FlexLexer* lexer = new yyFlexLexer(fin, fout);
	while(1){
        if (lexer->yylex() == 0) {
			*fout << mylineno << "\t" << ENDMARKER << "\t" << "ENDMARKER" <<"\n";
			break;
		}
	}
	fin->close();
	delete fin;
	fout->close();
	delete fout;
	return 0;
}
