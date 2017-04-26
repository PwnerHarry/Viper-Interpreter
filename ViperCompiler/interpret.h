void interpret_input() {
	ast N = ROOT;
	if (strcmp(N->symbol, "input")){
		fout_diag << "this is not a input node" << "\n";
		return;
	}
	while (N){
		if (N->r && !strcmp(N->r->symbol, "stmt")){
			fout_diag << "FOUND A stmt NODE AND PUSHED IT INTO THE STACK" << "\n";
			STACK.PushStack(N->r);
		}
		if (N->l){
			if (!strcmp(N->l->symbol, "file_input")){//Èç¹ûÊÇfile_input
				fout_diag << "WENT INTO A file_input NODE" << "\n";
				N = N->l;
			}
			else {
				if (!strcmp(N->r->symbol, "stmt")){
					fout_diag << "FOUND A stmt NODE AND PUSHED IT INTO THE STACK" << "\n";
					STACK.PushStack(N->r);
				}
				fout_diag << "NO file_input NODES ANYMORE" << "\n";
				break;
			}
		}
		else 
			break;
	}
	STACK.ClearStack();
};
void interpret_stmt(ast N){
	fout_diag << "interpret_stmt" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "stmt")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A stmt NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//stmt: simple_stmt
		interpret_simple_stmt(N->l);
	}
	if (N->nodetype == 2) {//stmt: compound_stmt
		interpret_compound_stmt(N->l);
	}
};
void interpret_simple_stmt(ast N){
	fout_diag << "interpret_simple_stmt" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "simple_stmt")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A simple_stmt NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//simple_stmt: small_stmt NEWLINE
		interpret_small_stmt(N->l);
	}
};
void interpret_small_stmt(ast N){
	fout_diag << "interpret_small_stmt" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "small_stmt")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A small_stmt NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//small_stmt: expr_stmt
		interpret_expr_stmt(N->l);
	}
	if (N->nodetype == 2) {//small_stmt: pass_stmt
		interpret_pass_stmt(N->l);
	}
	if (N->nodetype == 3) {//small_stmt: flow_stmt
		interpret_flow_stmt(N->l);
	}
};
void interpret_compound_stmt(ast N){
	fout_diag << "interpret_compound_stmt" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "compound_stmt")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A compound_stmt NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//compound_stmt: if_stmt
		interpret_if_stmt(N->l);
	}
};
void interpret_if_stmt(ast N){
	fout_diag << "interpret_if_stmt" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "if_stmt")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT AN if_stmt NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		fout_diag << "\t" << "TYPE\t" << inttype(N->valuetype) << "\n";
		fout_diag << "\t" << "NTYPE\t" << N->nodetype << "\n";
		fout_diag << "\t" << "VALUE\t" << N->Value.Number << "\n";
		return;
	}
	if (N->nodetype == 1) {//if_stmt: "if" test ":" suite if_stmt_sub
		interpret_test(N->l);
		if (N->l->Value.Bool == true) {
			interpret_suite(N->r);
		}
		else if (N->j->nodetype == 2) {
			interpret_if_test_sub(N->j);
		}
	}
	if (N->nodetype == 2) {//"if" test ":" suite if_stmt_sub "else" ":" suite
		interpret_test(N->l);
		if (N->l->Value.Bool == true) {
			interpret_suite(N->r);
		}
		else if (N->j->nodetype == 2) {
			interpret_if_test_sub(N->j);
		}
		else {
			interpret_suite(N->k);
		}
	}
};
void interpret_test(ast N){
	fout_diag << "interpret_test" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "test")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A test NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
};
void interpret_if_test_sub(ast N){
	fout_diag << "interpret_if_test_sub" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "if_test_sub")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT AN if_test_sub NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
};
void interpret_suite(ast N){
	fout_diag << "interpret_suite" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "suite")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A suite NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
};
void interpret_pass_stmt(ast N){
	fout_diag << "interpret_pass_stmt" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "pass_stmt")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A pass_stmt NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
};
void interpret_flow_stmt(ast N){
	fout_diag << "interpret_flow_stmt" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "flow_stmt")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A simple_stmt NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
};
void interpret_expr_stmt(ast N){
	fout_diag << "interpret_expr_stmt" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "expr_stmt")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A expr_stmt NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//expr_stmt: NAME "=" expr
		interpret_expr(N->r);
		SymTable S = searchTable(N->l->Value.Name);
		if (S){
			fout_diag << "\t" << "EXISTING SYMBOL FOUND" << "\n";
			if (S->TYPE && S->TYPE != N->r->valuetype){
				fout_diag << "\t" << "INCOMPATIBLE VALUE TYPE" << "\n";
				return;
			}
		}
		else {
			fout_diag << "\t" << "TIS A NEW SYMBOL" << "\n";
			S = addEntry(N->l->Value.Name, -1, -1, N->r->valuetype);
		}
		S->VALUE = N->r->Value;
	}
};
void interpret_expr(ast N) {
	fout_diag << "interpret_expr" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "expr")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A expr NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//expr: xor_expr
		interpret_xor_expr(N->l);
		N->valuetype = N->l->valuetype;
		N->Value = N->l->Value;
	}
	if (N->nodetype == 2) {//expr : expr "|" xor_expr
		interpret_expr(N->l);
		interpret_xor_expr(N->r);
		double buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "logical xor IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Number;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "logical xor IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Number;
		}
		if (N->l->valuetype == NUMBER)
			buff1 = N->l->Value.Number;
		if (N->r->valuetype == NUMBER)
			buff2 = N->r->Value.Number;
		if (N->l->valuetype != NUMBER && N->l->valuetype != NAME|| N->r->valuetype != NUMBER && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << "logical xor IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		if (int(buff1) != buff1 || int(buff2) != buff2) {
			fout_diag << "\t" << "ERROR" << "\t" << "logical xor CAN ONLY PROCEED WITH INTEGERS" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = int(buff1) | int(buff2);
	}
};
void interpret_xor_expr(ast N) {
	fout_diag << "interpret_xor_expr" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "xor_expr")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A xor_expr NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//xor_expr : and_expr
		interpret_and_expr(N->l);
		N->valuetype = N->l->valuetype;
		N->Value = N->l->Value;
	}
	if (N->nodetype == 2) {//xor_expr : xor_expr "^" and_expr
		interpret_xor_expr(N->l);
		interpret_and_expr(N->r);
		double buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "logical xor IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Number;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "logical xor IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Number;
		}
		if (N->l->valuetype == NUMBER)
			buff1 = N->l->Value.Number;
		if (N->r->valuetype == NUMBER)
			buff2 = N->r->Value.Number;
		if (N->l->valuetype != NUMBER && N->l->valuetype != NAME|| N->r->valuetype != NUMBER && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << "logical xor IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		if (int(buff1) != buff1 || int(buff2) != buff2) {
			fout_diag << "\t" << "ERROR" << "\t" << "logical xor CAN ONLY PROCEED WITH INTEGERS" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = int(buff1) ^ int(buff2);
	}
};
void interpret_and_expr(ast N) {
	fout_diag << "interpret_and_expr" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "and_expr")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A and_expr NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//and_expr : shift_expr
		interpret_shift_expr(N->l);
		N->valuetype = N->l->valuetype;
		N->Value = N->l->Value;
	}
	if (N->nodetype == 2) {//and_expr : and_expr "&" shift_expr
		interpret_and_expr(N->l);
		interpret_shift_expr(N->r);
		double buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "logical and IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Number;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "logical and IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Number;
		}
		if (N->l->valuetype == NUMBER)
			buff1 = N->l->Value.Number;
		if (N->r->valuetype == NUMBER)
			buff2 = N->r->Value.Number;
		if (N->l->valuetype != NUMBER && N->l->valuetype != NAME|| N->r->valuetype != NUMBER && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << "logical and IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		if (int(buff1) != buff1 || int(buff2) != buff2) {
			fout_diag << "\t" << "ERROR" << "\t" << "logical and CAN ONLY PROCEED WITH INTEGERS" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = int(buff1) & int(buff2);
	}
};
void interpret_shift_expr(ast N) {
	fout_diag << "interpret_shift_expr" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "shift_expr")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A shift_expr NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//shift_expr : arith_expr
		interpret_arith_expr(N->l);
		N->valuetype = N->l->valuetype;
		N->Value = N->l->Value;
	}
	if (N->nodetype == 2) {//shift_expr : shift_expr "<<" arith_expr
		interpret_shift_expr(N->l);
		interpret_arith_expr(N->r);
		double buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "<< IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Number;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "<< IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Number;
		}
		if (N->l->valuetype == NUMBER)
			buff1 = N->l->Value.Number;
		if (N->r->valuetype == NUMBER)
			buff2 = N->r->Value.Number;
		if (N->l->valuetype != NUMBER && N->l->valuetype != NAME|| N->r->valuetype != NUMBER && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << "<< IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		if (int(buff1) != buff1 || int(buff2) != buff2) {
			fout_diag << "\t" << "ERROR" << "\t" << "DIGITS MOVE CAN ONLY PROCEED WITH INTEGERS" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = buff1 * pow(2, int(buff2));
	}
	if (N->nodetype == 3) {//shift_expr : shift_expr ">>" arith_expr
		interpret_shift_expr(N->l);
		interpret_arith_expr(N->r);
		double buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << ">> IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Number;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << ">> IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Number;
		}
		if (N->l->valuetype == NUMBER)
			buff1 = N->l->Value.Number;
		if (N->r->valuetype == NUMBER)
			buff2 = N->r->Value.Number;
		if (N->l->valuetype != NUMBER && N->l->valuetype != NAME|| N->r->valuetype != NUMBER && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << ">> IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		if (int(buff1) != buff1 || int(buff2) != buff2) {
			fout_diag << "\t" << "ERROR" << "\t" << "DIGITS MOVE CAN ONLY PROCEED WITH INTEGERS" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = buff1 / pow(2, int(buff2));
	}
};
void interpret_arith_expr(ast N) {
	fout_diag << "interpret_arith_expr" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "arith_expr")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A arith_expr NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//arith_expr : term
		interpret_term(N->l);
		N->valuetype = N->l->valuetype;
		N->Value = N->l->Value;
	}
	if (N->nodetype == 2) {//arith_expr : arith_expr "+" term
		interpret_arith_expr(N->l);
		interpret_term(N->r);
		double buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "plus IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Number;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "plus IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Number;
		}
		if (N->l->valuetype == NUMBER)
			buff1 = N->l->Value.Number;
		if (N->r->valuetype == NUMBER)
			buff2 = N->r->Value.Number;
		if (N->l->valuetype != NUMBER && N->l->valuetype != NAME|| N->r->valuetype != NUMBER && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << "plus IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = buff1 + buff2;
	}
	if (N->nodetype == 3) {//arith_expr : arith_expr "-" term
		interpret_arith_expr(N->l);
		interpret_term(N->r);
		double buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "minus IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Number;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "minus IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Number;
		}
		if (N->l->valuetype == NUMBER)
			buff1 = N->l->Value.Number;
		if (N->r->valuetype == NUMBER)
			buff2 = N->r->Value.Number;
		if (N->l->valuetype != NUMBER && N->l->valuetype != NAME|| N->r->valuetype != NUMBER && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << "minus IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = buff1 - buff2;
	}
};
void interpret_term(ast N) {
	fout_diag << "interpret_term" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "term")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A term NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//term : factor
		interpret_factor(N->l);
		N->valuetype = N->l->valuetype;
		N->Value = N->l->Value;
	}
	if (N->nodetype == 2) {//term : term "*" factor
		interpret_term(N->l);
		interpret_factor(N->r);
		double buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "mult IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Number;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "mult IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Number;
		}
		if (N->l->valuetype == NUMBER)
			buff1 = N->l->Value.Number;
		if (N->r->valuetype == NUMBER)
			buff2 = N->r->Value.Number;
		if (N->l->valuetype != NUMBER && N->l->valuetype != NAME|| N->r->valuetype != NUMBER && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << "mult IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = buff1 * buff2;
	}
	if (N->nodetype == 3) {//term : term "/" factor
		interpret_term(N->l);
		interpret_factor(N->r);
		double buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "didv IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Number;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "didv IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Number;
		}
		if (N->l->valuetype == NUMBER)
			buff1 = N->l->Value.Number;
		if (N->r->valuetype == NUMBER)
			buff2 = N->r->Value.Number;
		if (N->l->valuetype != NUMBER && N->l->valuetype != NAME|| N->r->valuetype != NUMBER && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << "didv IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = buff1 / buff2;
	}
	if (N->nodetype == 4) {//term : term "%" factor
		interpret_term(N->l);
		interpret_factor(N->r);
		double buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "mod IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Number;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "mod IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Number;
		}
		if (N->l->valuetype == NUMBER)
			buff1 = N->l->Value.Number;
		if (N->r->valuetype == NUMBER)
			buff2 = N->r->Value.Number;
		if (N->l->valuetype != NUMBER && N->l->valuetype != NAME|| N->r->valuetype != NUMBER && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << "mod IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		if (int(buff1) != buff1 || int(buff2) != buff2) {
			fout_diag << "\t" << "ERROR" << "\t" << "mod IS FOR INTEGERS ONLY" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = int(buff1) % int(buff2);
	}
	if (N->nodetype == 5) {//term : term "//" factor
		interpret_term(N->l);
		interpret_factor(N->r);
		double buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "fdv IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Number;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "fdv IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Number;
		}
		if (N->l->valuetype == NUMBER)
			buff1 = N->l->Value.Number;
		if (N->r->valuetype == NUMBER)
			buff2 = N->r->Value.Number;
		if (N->l->valuetype != NUMBER && N->l->valuetype != NAME|| N->r->valuetype != NUMBER && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << "fdv IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = floor(buff1 / buff2);
	}
};
void interpret_factor(ast N) {
	fout_diag << "interpret_factor" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "factor")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A factor NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//factor : power
		interpret_power(N->l);
		N->valuetype = N->l->valuetype;
		N->Value = N->l->Value;
	}
	if (N->nodetype == 2) {//factor : "+" factor
		interpret_factor(N->l);
		double buff;
		if (N->l->valuetype == NUMBER)
			buff = N->l->Value.Number;
		else if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "factor IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff = S->VALUE.Number;
		}
		else {
			fout_diag << "\t" << "ERROR" << "\t" << "factor IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = buff;
	}
	if (N->nodetype == 3) {//factor : "-" factor
		interpret_factor(N->l);
		double buff;
		if (N->l->valuetype == NUMBER)
			buff = N->l->Value.Number;
		else if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "factor IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff = S->VALUE.Number;
		}
		else {
			fout_diag << "\t" << "ERROR" << "\t" << "factor IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = -1.0 * buff;
	}
};
void interpret_power(ast N) {
	fout_diag << "interpret_power" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "power")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A power NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//power : atom_expr
		interpret_atom_expr(N->l);
		N->Value = N->l->Value;
		N->valuetype = N->l->valuetype;
	}
	if (N->nodetype == 2) {//power : atom_expr "**" factor
		interpret_atom_expr(N->l);
		interpret_factor(N->r);
		double buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "power IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Number;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != NUMBER) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "power IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Number;
		}
		if (N->l->valuetype == NUMBER)
			buff1 = N->l->Value.Number;
		if (N->r->valuetype == NUMBER)
			buff2 = N->r->Value.Number;
		if (N->l->valuetype != NUMBER && N->l->valuetype != NAME|| N->r->valuetype != NUMBER && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << "power IS FOR NUMBERS ONLY" << "\n";
			return;
		}
		N->valuetype = NUMBER;
		N->Value.Number = pow(buff1, buff2);
	}
};
void interpret_atom_expr(ast N) {
	fout_diag << "interpret_atom_expr" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "atom_expr")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT AN atom_expr NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//atom_expr : atom
		N->Value = N->l->Value;
		N->valuetype = N->l->valuetype;
	}
	if (N->nodetype == 2) {//atom_expr : "(" expr ")"
		interpret_expr(N->l);
		N->Value = N->l->Value;
		N->valuetype = N->l->valuetype;
	}
};