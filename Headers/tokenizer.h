int ReadTokens(ifstream &f, TokenTable * T) {
	int layer = 0;
	int Break = 0;
	int i = 0;
	for (; i < TOKEN_TABLE_SIZE; i++) {
		if (f.eof()){
			cout << "EOF" << endl;
			break;
		}
		f >> T->t[i].lineno;
		f >> T->t[i].type;
		T->t[i].layer = layer;
		switch (T->t[i].type) {
			case VALUE_TYPE_STRING:{
				char temp;
				f.get(temp);
				f.get(temp);
				T->t[i].Object.Value.String = new char[64];
				f.getline(T->t[i].Object.Value.String, 64);
				for (int j = 0; j < 64; j++)
					if (T->t[i].Object.Value.String[j] == '\0')
						T->t[i].Object.Value.String[j - 1] = '\0';
				break;
			}
			case VALUE_TYPE_NUMBER:{
				f >> T->t[i].Object.Value.Number;
				break;
			}
			case VALUE_TYPE_CHAR:{
				char temp;
				f.get(temp);
				f.get(temp);
				f.get(T->t[i].Object.Value.Char);
				f.get(temp);
				break;
			}
			case VALUE_TYPE_NAME:{
				T->t[i].Object.Value.String = new char[64];
				f >> T->t[i].Object.Value.String;
				break;
			}
			case INDENT:{
				layer++;
				T->t[i].Object.Value.String = new char[64];
				f >> T->t[i].Object.Value.String;
				free(T->t[i].Object.Value.String);
				break;
			}
			case DEDENT:{
				T->t[i].layer = --layer;
				T->t[i].Object.Value.String = new char[64];
				f >> T->t[i].Object.Value.String;
				free(T->t[i].Object.Value.String);
				break;
			}
			case ENDMARKER:{
				Break = 1;
				T->t[i].Object.Value.String = new char[64];
				f >> T->t[i].Object.Value.String;
				free(T->t[i].Object.Value.String);
				break;
			}
			default:{
				T->t[i].Object.Value.String = new char[64];
				f >> T->t[i].Object.Value.String;
				break;
			}
		}
		if (!f.eof()){
			T->t[i].availability = 1;
		}
		if (Break)
			break;
		if (T->t[i].type == UNKNOWN) {
			i = (i == 0)? 0: i - 1;
			continue;
		}
	}
	T->Size = i;
	f.close();
	return 0;
};
int yylex() {
	int i = T->Pointer;
	if (i == TOKEN_TABLE_SIZE)
		return -1;
	if (T->t[i].availability == 0)
		return 0;
	switch (T->t[i].type) {
		case VALUE_TYPE_STRING:{
			yylval.String = T->t[i].Object.Value.String;
			fout_diag << green << "FLEX" << white << "\t" << "STRING" << "\t" << yylval.String << endl;
			cout << green << "FLEX" << white << "\t" << "STRING" << "\t" << yylval.String << endl;
			break;
		}
		case VALUE_TYPE_NUMBER:{
			yylval.Number = T->t[i].Object.Value.Number;
			fout_diag << green << "FLEX" << white << "\t" << "NUMBER" << "\t" << yylval.Number << endl;
			cout << green << "FLEX" << white << "\t" << "NUMBER" << "\t" << yylval.Number << endl;
			break;
		}
		case VALUE_TYPE_CHAR:{
			yylval.Char = T->t[i].Object.Value.Char;
			fout_diag << green << "FLEX" << white << "\t" << "CHAR" << "" << "\t" << yylval.Char << endl;
			cout << green << "FLEX" << white << "\t" << "CHAR" << "" << "\t" << yylval.Char << endl;
			break;
		}
		case VALUE_TYPE_NAME:{
			yylval.Name = T->t[i].Object.Value.String;
			fout_diag << green << "FLEX" << white << "\t" << "NAME" << "\t" << yylval.Name << endl;
			cout << green << "FLEX" << white << "\t" << "NAME" << "\t" << yylval.Name << endl;
			break;
		}
		case INDENT:{
			fout_diag << green << "FLEX" << white << "\t" << "INDENT" << endl;
			cout << green << "FLEX" << white << "\t" << "INDENT" << endl;
			break;
		}
		case DEDENT:{
			fout_diag << green << "FLEX" << white << "\t" << "DEDENT" << endl;
			cout << green << "FLEX" << white << "\t" << "DEDENT" << endl;
			break;
		}
		case NEWLINE:{
			fout_diag << green << "FLEX" << white << "\t" << "NEWLINE" << endl;
			cout << green << "FLEX" << white << "\t" << "NEWLINE" << endl;
			break;
		}
		case ENDMARKER:{
			fout_diag << green << "FLEX" << white << "\t" << "ENDMARKER" << endl;
			cout << green << "FLEX" << white << "\t" << "ENDMARKER" << endl;
			break;
		}
		default:{
			yylval.Name = T->t[i].Object.Value.String;
			fout_diag << green << "FLEX" << white << "\t" << yylval.Name << endl;
			cout << green << "FLEX" << white << "\t" << yylval.Name << endl;
			break;
		}
	}
	T->Pointer++;
	return T->t[i].type;
}