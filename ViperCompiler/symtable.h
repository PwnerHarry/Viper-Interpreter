const int FUNCTION = -123;
class symentry {
public:
	char * NAME;
	int LIMITS[2];
	int TYPE;
	SValue VALUE;
	symentry * NEXT;
	symentry() {
		NAME = NULL;
		TYPE = 0;
		VALUE.Number = 0;
		LIMITS[0] = -1;
		LIMITS[1] = -1;
		NEXT = NULL;
	};
};
typedef symentry * SymTable;
SymTable SYMTABLE = 0;
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
SymTable addEntry(char * SYMNAME, int BEGIN, int END, int TYPE, SValue VALUE);//Definitions after main
void disptable();