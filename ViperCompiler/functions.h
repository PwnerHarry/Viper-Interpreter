int yylex();
int ReadTokens(ifstream &f, TokenTable * T);
void PrintTokens(TokenTable * T);
void yyerror(char *s);