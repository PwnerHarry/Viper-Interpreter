@echo off
del /F /S /Q lex.yy.cc
del /F /S /Q a.exe
del /F /S /Q ViperS.exe
del /F /S /Q ViperL.exe
del /F /S /Q tokens.txt
del /F /S /Q Viper.tab.c
del /F /S /Q Viper.tab.h
bison -d Viper.y
pause
flex ViperFirstLexer.l
pause
g++ lex.yy.cc
pause
ren a.exe ViperL.exe
ViperL Test.vi
echo Lexer Success!
del /F /S /Q lex.yy.cc
del /F /S /Q a.exe
g++ Viper.tab.c
ren a.exe ViperS.exe
ViperS tokens.txt
pause