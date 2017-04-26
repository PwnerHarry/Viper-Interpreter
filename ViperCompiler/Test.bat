@echo off
del /F /S /Q lex.yy.cc
del /F /S /Q a.exe
del /F /S /Q Viper.exe
del /F /S /Q Token.exe
del /F /S /Q tokens.txt
del /F /S /Q Viper.tab.c
del /F /S /Q Viper.tab.h
del /F /S /Q PARSER.log
del /F /S /Q INTERPRETER.log
Accessories\bison -d Viper.y
Accessories\flex Viper.l
g++ lex.yy.cc
ren a.exe Token.exe
Token Test.vi
echo Lexer Success!
del /F /S /Q lex.yy.cc
del /F /S /Q a.exe
g++ Viper.tab.c
ren a.exe Viper.exe
Viper tokens.txt
pause