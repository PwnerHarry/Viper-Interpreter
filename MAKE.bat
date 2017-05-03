@echo off
del tokens.txt
del Interpreter.exe
del Token.exe
Accessories\bison -d Viper.y
Accessories\flex Viper.l
g++ lex.yy.cc
ren a.exe Token.exe
start Accessories\Tokenize.bat %1
g++ Viper.tab.c
ren a.exe Interpreter.exe
start Accessories\Interpret.bat
del lex.yy.cc
