typedef union {
	double Number;
	char * String;
	char * Name;
	char Char;
	bool Bool;
	int Int;
} SValue;
class asn {
public:
	int nodetype;
	bool valuenode;
	asn * l;
	asn * r;
	SValue Value;
	asn() {
		nodetype = 0;
		valuenode = false;
		l = 0;
		r = 0;
		Value.Number = 0;
	};
};
typedef asn * ast;
ast newnode(int nodetype) {
	ast N = new asn;
	N->nodetype = nodetype;
	if (nodetype == NUMBER || nodetype == BOOL || nodetype == NAME || nodetype == INT || nodetype == CHAR || nodetype == STRING)
		N->valuenode = true;
	return N;
};
ast newast(int nodetype, ast l, ast r) {
	ast N = new asn;
	N->nodetype = nodetype;
	N->l = l;
	N->r = r;
	return N;
};
void dispasn(ast N);//定义在y文件末