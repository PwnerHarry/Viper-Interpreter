// ViperCompiler.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "headers.h"

int main(int argc, char * argv[])
{
	if (argc > 2) {
		cout << "Too many arguments!" << endl;
	}
	if (argc == 1) {
		fprintf(stderr, instructions);
		exit(1);
	}
	if (argc == 2) {
		char * _destination = argv[1];
		OpenFile(_destination);
	}
	//Preprocessing
	Lexer(Destination);
    return 0;
}

