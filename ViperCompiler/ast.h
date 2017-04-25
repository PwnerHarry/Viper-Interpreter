class asn {
public:
	int nodetype;
	bool valuenode;
	char * symbol;
	int valuetype;
	asn * jump;
	asn * l;
	asn * r;
	SValue Value;
	asn() {
		symbol = 0;
		nodetype = 0;
		valuetype = 0;
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
