@echo off
del /F /S /Q lex.yy.cc
del /F /S /Q a.exe
del /F /S /Q ViperS.exe
del /F /S /Q ViperL.exe
del /F /S /Q tokens.txt
del /F /S /Q Viper.tab.c
del /F /S /Q Viper.tab.h
del /F /S /Q PROCESS.log
del /F /S /Q ASSEMBLY.via
Accessories\bison -d Viper.y
Accessories\flex Viper.l
g++ lex.yy.cc
ren a.exe ViperL.exe
ViperL Test.vi
echo Lexer Success!
del /F /S /Q lex.yy.cc
del /F /S /Q a.exe
g++ Viper.tab.c
ren a.exe ViperS.exe
ViperS tokens.txt
pause