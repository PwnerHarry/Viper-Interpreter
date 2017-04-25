class asn {
public:
	int nodetype;
	bool valuenode;
	asn * jump;
	asn * l;
	asn * r;
	SValue Value;
	asn() {
		nodetype = 0;
		valuenode = false;
		l = 0;
		r = 0;
		jump = 0;
		Value.Number = 0;
	};
};
typedef asn * ast;
ast newast(int nodetype, ast l, ast r) {
	ast N = new asn;
	N->nodetype = nodetype;
	N->l = l;
	N->r = r;
	return N;
};
ast ROOT = 0;
void dispasn(ast N);//定义在y文件末
ast newnode(int nodetype);
ast interpret(ast N);