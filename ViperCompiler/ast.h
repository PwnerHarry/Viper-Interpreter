ast newnode(char * symbol, int nodetype, int valuetype) {
	ast N = new asn;
	N->nodetype = nodetype;
	N->valuetype = valuetype;
	N->symbol = new char[64];
	strcpy(N->symbol, symbol);
	if (nodetype == NUMBER || nodetype == BOOL || nodetype == NAME || nodetype == CHAR || nodetype == STRING)
		N->valuenode = true;
	return N;
};