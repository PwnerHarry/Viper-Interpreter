@echo off
del /F /S /Q lex.yy.cc
del /F /S /Q a.exe
del /F /S /Q ViperS.exe
del /F /S /Q ViperL.exe
del /F /S /Q tokens.txt
del /F /S /Q Viper.tab.c
del /F /S /Q Viper.tab.h
del /F /S /Q PROCESS.log
bison -d Viper.y
flex ViperFirstLexer.l
clang++ lex.yy.cc
pause
ren a.exe ViperL.exe
ViperL Test.vi
echo Lexer Success!
del /F /S /Q lex.yy.cc
del /F /S /Q a.exe
clang++ Viper.tab.c
pause
ren a.exe ViperS.exe
ViperS tokens.txt