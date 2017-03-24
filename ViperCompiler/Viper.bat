@echo off
del /F /S /Q lex.yy.cc
del /F /S /Q a.exe
del /F /S /Q ViperS.exe
del /F /S /Q ViperL.exe
del /F /S /Q tokens.txt
del /F /S /Q Viper.tab.c
del /F /S /Q Viper.tab.h
del /F /S /Q PROCESS.log
CLS
bison -d Viper.y
pause
CLS
flex ViperFirstLexer.l
pause
CLS
g++ lex.yy.cc
CLS
ren a.exe ViperL.exe
ViperL Viper.vi
echo Lexer Success!
del /F /S /Q lex.yy.cc
del /F /S /Q a.exe
g++ Viper.tab.c
ren a.exe ViperS.exe
CLS
ViperS tokens.txt
pause