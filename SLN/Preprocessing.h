#pragma once
//File Interface
//Get a file and read it
//Then hand it to the compiler!
int OpenFile(char * D) {
	ifstream FIN(D, ios::in);
	if (FIN.fail() || FIN.bad()) {
		fprintf(stderr, "Destination Error");
		exit(1);
	}
	if (FIN.good()) {
		Destination = D;
		cout << "Destination loaded" << endl;
	}
}
