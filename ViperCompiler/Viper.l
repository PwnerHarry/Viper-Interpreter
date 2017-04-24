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
				*fout << mylineno++ << "\t" << NEWLINE << "\t" << "NEWLINE" << "\n";
				int c = yyinput();
				unput(c);
				if (c != '\t' && prev_dent != 0) {
					for (int i = 0; i < prev_dent; i++) {
						*fout << mylineno << "\t" << DEDENT << "\t" << "DEDENT" << "\n";
						*fout << mylineno << "\t" << NEWLINE << "\t" << "NEWLINE" << "\n";
					}
					prev_dent = 0;
				}
			}
\t			{
				curr_dent = 1;
				char c;
				while((c = yyinput()) == '\t')
					curr_dent++;
				unput(c);
				if (c == '\n')
					curr_dent = 0;
				else {
					if (curr_dent > prev_dent)
						for (int i = 0; i < curr_dent - prev_dent; i++)
							*fout << mylineno << "\t" << INDENT << "\t" << "INDENT" << "\n";	
					if (curr_dent < prev_dent)
						for (int i = 0; i < prev_dent - curr_dent; i++)
							*fout << mylineno << "\t" << DEDENT << "\t" <<"DEDENT" << "\n";
					prev_dent = curr_dent;
				}
				
			}
"..."		{*fout << mylineno << "\t" << ELLIPSIS << "\t" << YYText() << "\n";}
"("			{*fout << mylineno << "\t" << LPAR << "\t" << YYText() << "\n";}
")"			{*fout << mylineno << "\t" << RPAR << "\t" << YYText() << "\n";}
"["			{*fout << mylineno << "\t" << LSQB << "\t" << YYText() << "\n";}
"]"			{*fout << mylineno << "\t" << RSQB << "\t" << YYText() << "\n";}
"{"			{*fout << mylineno << "\t" << LBRACE << "\t" << YYText() << "\n";}
"}"			{*fout << mylineno << "\t" << RBRACE << "\t" << YYText() << "\n";}
"@"			{*fout << mylineno << "\t" << AT << "\t" << YYText() << "\n";}
","			{*fout << mylineno << "\t" << COMMA << "\t" << YYText() << "\n";}
":"			{*fout << mylineno << "\t" << COLON << "\t" << YYText() << "\n";}
"."			{*fout << mylineno << "\t" << DOT << "\t" << YYText() << "\n";}
"="			{*fout << mylineno << "\t" << EQUAL << "\t" << YYText() << "\n";}
";"			{*fout << mylineno << "\t" << SEMI << "\t" << YYText() << "\n";}
"+="		{*fout << mylineno << "\t" << PLUSEQUAL << "\t" << YYText() << "\n";}
"-="		{*fout << mylineno << "\t" << MINEQUAL << "\t" << YYText() << "\n";}
"*="		{*fout << mylineno << "\t" << STAREQUAL << "\t" << YYText() << "\n";}
"/="		{*fout << mylineno << "\t" << SLASHEQUAL << "\t" << YYText() << "\n";}
"|="		{*fout << mylineno << "\t" << VBAREQUAL << "\t" << YYText() << "\n";}
"//="		{*fout << mylineno << "\t" << DOUBLESLASHEQUAL << "\t" << YYText() << "\n";}
"%="		{*fout << mylineno << "\t" << PERCENTEQUAL << "\t" << YYText() << "\n";}
"**="		{*fout << mylineno << "\t" << DOUBLESTAREQUAL << "\t" << YYText() << "\n";}
"&="		{*fout << mylineno << "\t" << AMPEREQUAL << "\t" << YYText() << "\n";}
"^="		{*fout << mylineno << "\t" << CIRCUMFLEXEQUAL << "\t" << YYText() << "\n";}
"@="		{*fout << mylineno << "\t" << ATEQUAL << "\t" << YYText() << "\n";}
"<<="		{*fout << mylineno << "\t" << LEFTSHIFTEQUAL << "\t" << YYText() << "\n";}
">>="		{*fout << mylineno << "\t" << RIGHTSHIFTEQUAL << "\t" << YYText() << "\n";}


"from"		{*fout << mylineno << "\t" << FROM << "\t" << YYText() << "\n";}
"raise"		{*fout << mylineno << "\t" << RAISE << "\t" << YYText() << "\n";}
"del"		{*fout << mylineno << "\t" << DEL << "\t" << YYText() << "\n";}
"as"		{*fout << mylineno << "\t" << AS << "\t" << YYText() << "\n";}
"is"		{*fout << mylineno << "\t" << IS << "\t" << YYText() << "\n";}
"while"		{*fout << mylineno << "\t" << WHILE << "\t" << YYText() << "\n";}
"break"		{*fout << mylineno << "\t" << BREAK << "\t" << YYText() << "\n";}
"continue"	{*fout << mylineno << "\t" << CONTINUE << "\t" << YYText() << "\n";}
"elif"		{*fout << mylineno << "\t" << ELIF << "\t" << YYText() << "\n";}
"else"		{*fout << mylineno << "\t" << ELSE << "\t" << YYText() << "\n";}
"pass"		{*fout << mylineno << "\t" << PASS << "\t" << YYText() << "\n";}
"return"	{*fout << mylineno << "\t" << RETURN << "\t" << YYText() << "\n";}
"in"		{*fout << mylineno << "\t" << IN << "\t" << YYText() << "\n";}
"for"		{*fout << mylineno << "\t" << FOR << "\t" << YYText() << "\n";}
"class"		{*fout << mylineno << "\t" << CLASS << "\t" << YYText() << "\n";}
"not"		{*fout << mylineno << "\t" << NOT << "\t" << YYText() << "\n";}
"and"		{*fout << mylineno << "\t" << AND << "\t" << YYText() << "\n";}
"or"		{*fout << mylineno << "\t" << OR << "\t" << YYText() << "\n";}
"if"		{*fout << mylineno << "\t" << IF << "\t" << YYText() << "\n";}
"def"		{*fout << mylineno << "\t" << DEF << "\t" << YYText() << "\n";}


"**"		{*fout << mylineno << "\t" << DOUBLESTAR << "\t" << YYText() << "\n";}
"//"		{*fout << mylineno << "\t" << DOUBLESLASH << "\t" << YYText() << "\n";}
"+"			{*fout << mylineno << "\t" << PLUS << "\t" << YYText() << "\n";}
"-"			{*fout << mylineno << "\t" << MINUS << "\t" << YYText() << "\n";}
"*"			{*fout << mylineno << "\t" << STAR << "\t" << YYText() << "\n";}
"/"			{*fout << mylineno << "\t" << SLASH << "\t" << YYText() << "\n";}
"%"			{*fout << mylineno << "\t" << PERCENT << "\t" << YYText() << "\n";}
"<>"		{*fout << mylineno << "\t" << NOTEQUAL << "\t" << YYText() << "\n";}
"<"			{*fout << mylineno << "\t" << LESS << "\t" << YYText() << "\n";}
"<="		{*fout << mylineno << "\t" << LESSEQUAL << "\t" << YYText() << "\n";}
"<<"		{*fout << mylineno << "\t" << LEFTSHIFT << "\t" << YYText() << "\n";}
"=="		{*fout << mylineno << "\t" << EQEQUAL << "\t" << YYText() << "\n";}
"!="		{*fout << mylineno << "\t" << NOTEQUAL << "\t" << YYText() << "\n";}
">="		{*fout << mylineno << "\t" << GREATEREQUAL << "\t" << YYText() << "\n";}
">>"		{*fout << mylineno << "\t" << RIGHTSHIFT << "\t" << YYText() << "\n";}
">"			{*fout << mylineno << "\t" << GREATER << "\t" << YYText() << "\n";}
"|"			{*fout << mylineno << "\t" << VBAR << "\t" << YYText() << "\n";}
"&"			{*fout << mylineno << "\t" << AMPER << "\t" << YYText() << "\n";}
"^"			{*fout << mylineno << "\t" << CIRCUMFLEX << "\t" << YYText() << "\n";}
"~"			{*fout << mylineno << "\t" << TILDE << "\t" << YYText() << "\n";}
"->"		{*fout << mylineno << "\t" << RARROW << "\t" << YYText() << "\n";}

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
				*fout << mylineno << "\t" << UNKNOWN << "\t" << YYText() << "\n";
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
	ofstream* out;
	if (argc == 2)
		out = new ofstream("tokens.txt", ios::out);
	if (argc == 3)
		out = new ofstream(argv[2], ios::out);
	fout = out;
	if (fout->bad()) {
		fprintf(stderr, "Output Error");
		exit(1);
	}
	FlexLexer* lexer = new yyFlexLexer(fin, fout);
	while (lexer->yylex() != 0)
		;
	*fout << mylineno << "\t" << NEWLINE << "\t" << "NEWLINE" <<"\n";
	curr_dent = 0;
	if (curr_dent > prev_dent)
		for (int i = 0; i < curr_dent - prev_dent; i++)
			*fout << mylineno << "\t" << INDENT << "\t" << "INDENT" << "\n";	
	if (curr_dent < prev_dent)
		for (int i = 0; i < prev_dent - curr_dent; i++)
			*fout << mylineno << "\t" << DEDENT << "\t" <<"DEDENT" << "\n";
	prev_dent = curr_dent;
	*fout << mylineno << "\t" << ENDMARKER << "\t" << "ENDMARKER" <<"\n";
	fin->close();
	delete fin;
	fout->close();
	delete fout;
	return 0;
}
