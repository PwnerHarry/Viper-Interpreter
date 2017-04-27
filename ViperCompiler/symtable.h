SymTable initTable() {
	SymTable T = new symentry;
	SYMTABLE = T;
	return SYMTABLE;
};
SymTable searchTable(char * NAME) {
	SymTable T = SYMTABLE;
	while (T) {
		if (T->NAME && !strcmp(T->NAME, NAME))
			return T;
		else
			T = T->NEXT;
	}
	return 0;
};
SymTable addEntry(char * SYMNAME, int BEGIN, int END, int TYPE) {
	SymTable T = new symentry;
	T->NAME = SYMNAME;
	T->LIMITS[0] = BEGIN;
	T->LIMITS[1] = END;
	T->TYPE = TYPE;
	T->NEXT = SYMTABLE;
	SYMTABLE = T;
	return T;
};
void disptable(){
	SymTable S = SYMTABLE;
	fout_diag << "SYMBOL TABLE" << "\n";
	fout_diag << "NAME" << "\t" << "LBTM" << "\t" << "LTOP" << "\t" << "TYPE" << "\t" << "VALUE" << "\n";
	while (S) {
		if (S->TYPE){
			fout_diag << S->NAME << "\t" << S->LIMITS[0] << "\t" << S->LIMITS[1] << "\t" << inttype(S->TYPE) << "\t";
			switch (S->TYPE) {
				case NUMBER:{
					fout_diag << S->VALUE.Number << "\n";
					break;
				}
				case STRING:{
					fout_diag << S->VALUE.String << "\n";
					break;
				}
				case CHAR:{
					fout_diag << S->VALUE.Char << "\n";
					break;
				}
				case BOOL:{
					if (S->VALUE.Bool)
						fout_diag << "True" << "\n";
					else
						fout_diag << "False" << "\n";
					break;
				}
			}
		}
		S = S->NEXT;
	}
};