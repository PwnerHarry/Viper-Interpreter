# ViperCompiler
A compiler for a subset of Python using different techs under Windows

This project is still under developments, the features that have already been finished:

	LEXER:			Handle tokens and INDENT and DEDENTS
	PARSER:			All grammers has been set, yet there are only few semantic movements implemented
	DEBUGGER:		Store the process of lexing and parsing into a log file.
We are still working on:

	PARSER:			Try to bring in the semantic movements
	SYMBOL TABLE:		There is nothing more confusing than this, to understand how this should turn out to be.
The features that are not so hurry to realize yet we wish to bring them on someday:

	Code Optimization
	Cross compiling
	GUI
How to run this:

	Turn on your windows
	Make sure that your g++ is in a directory the system environment variables as "Path"
	run ./ViperCompiler/test.bat which compiles the test.vi
