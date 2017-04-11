class _Object;
class Token;
class TokenTable;
class _Object {
public:
	union {
	double Number;
	char * String;
	char Char;
	} Value;
	_Object(){
		Value.Number = 0;
		Value.String = 0;
		Value.Char = 0;
	};
};
class Token {
public:
	int lineno;
	int type;
	int layer;
	int availability;
	_Object Object;
	Token(){
		layer = 0;
		availability = 0;
		lineno = 0;
		type = 0;
	};
};
class TokenTable {
public:
	int Pointer;
	int Size;
	Token * t;
	TokenTable() {
		Size = 0;
		t = new Token[TOKEN_TABLE_SIZE];
		Pointer = 0;
	}
};