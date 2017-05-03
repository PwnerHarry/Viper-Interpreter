ast newnode(char * symbol, int nodetype, int valuetype) {
	ast N = new asn;
	N->nodetype = nodetype;
	N->valuetype = valuetype;
	N->symbol = new char[64];
	strcpy(N->symbol, symbol);
	if (nodetype == VALUE_TYPE_NUMBER || nodetype == VALUE_TYPE_BOOL || nodetype == VALUE_TYPE_NAME || nodetype == VALUE_TYPE_CHAR || nodetype == VALUE_TYPE_STRING)
		N->valuenode = true;
	return N;
};
ast newnet(char * symbol, int nodetype, ast L, ast R, ast J){
	ast N = newnode(symbol, nodetype);
	N->l = L;
	N->r = R;
	N->j = J;
	return N;
};