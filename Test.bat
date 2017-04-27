@ECHO OFF
del /F /S /Q .\lex.yy.cc 2>nul
del /F /S /Q .\a.exe 2>nul
del /F /S /Q .\Interpreter.exe 2>nul
del /F /S /Q .\Token.exe 2>nul
del /F /S /Q .\tokens.txt 2>nul
del /F /S /Q .\Viper.tab.c 2>nul
del /F /S /Q .\Viper.tab.h 2>nul
del /F /S /Q .\PARSER.log 2>nul
del /F /S /Q .\INTERPRETER.log 2>nul
.\Accessories\bison -d .\Viper\Viper.y
.\Accessories\flex .\Viper\Viper.l
g++ .\lex.yy.cc
ren .\a.exe .\Token.exe 2>nul
.\Token %1
del /F /S /Q .\lex.yy.cc 2>nul
del /F /S /Q .\a.exe 2>nul
g++ .\Viper.tab.c
ren .\a.exe .\Interpreter.exe 2>nul
.\Interpreter .\tokens.txt
pause