void interpret_input() {
	ast N = ROOT;
	if (strcmp(N->symbol, "input")){
		fout_diag << "this is not a input node" << "\n";
		return;
	}
	while (N){
		if (N->r && !strcmp(N->r->symbol, "stmt")){
			fout_diag << "FOUND A stmt NODE AND PUSHED IT INTO THE MAINSTACK" << "\n";
			MAINSTACK.PushStack(N->r);
		}
		if (N->l){
			if (!strcmp(N->l->symbol, "file_input")){//Èç¹ûÊÇfile_input
				fout_diag << "WENT INTO A file_input NODE" << "\n";
				N = N->l;
			}
			else {
				if (!strcmp(N->r->symbol, "stmt")){
					fout_diag << "FOUND A stmt NODE AND PUSHED IT INTO THE MAINSTACK" << "\n";
					MAINSTACK.PushStack(N->r);
				}
				fout_diag << "NO file_input NODES ANYMORE" << "\n";
				break;
			}
		}
		else 
			break;
	}
	MAINSTACK.ClearStack();
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
		return;
	}
	if (N->nodetype == 1) {//if_stmt: "if" test ":" suite if_stmt_sub
		interpret_test(N->l);
		if (N->l->Value.Bool == true) {
			fout_diag << "TRUE!!!!!!" << "\n";//!!!!
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
	if (N->nodetype == 1) {//test: or_test
		interpret_or_test(N->l);
		N->valuetype = N->l->valuetype;
		N->Value = N->l->Value;
	}
};
void interpret_or_test(ast N){
	fout_diag << "interpret_or_test" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "or_test")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A or_test NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//or_test : and_test
		interpret_and_test(N->l);
		N->valuetype = N->l->valuetype;
		N->Value = N->l->Value;
	}
	if (N->nodetype == 2) {//or_test :or_test "or" and_test
		interpret_or_test(N->l);
		interpret_and_test(N->r);
		bool buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != BOOL) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "or_test IS FOR BOOLEANS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Bool;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != BOOL) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "or_test IS FOR BOOLEANS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Bool;
		}
		if (N->l->valuetype == BOOL)
			buff1 = N->l->Value.Bool;
		if (N->r->valuetype == BOOL)
			buff2 = N->r->Value.Bool;
		if (N->l->valuetype != BOOL && N->l->valuetype != NAME|| N->r->valuetype != BOOL && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << "or_test IS FOR BOOLEANS ONLY" << "\n";
			return;
		}
		N->valuetype = BOOL;
		N->Value.Bool = buff1 || buff2;
	}
};
void interpret_and_test(ast N){
	fout_diag << "interpret_and_test" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "and_test")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A and_test NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//and_test : not_test
		interpret_not_test(N->l);
		N->valuetype = N->l->valuetype;
		N->Value = N->l->Value;
	}
	if (N->nodetype == 2) {//and_test :and_test "and" not_test
		interpret_and_test(N->l);
		interpret_not_test(N->r);
		bool buff1, buff2;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != BOOL) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "and_test IS FOR BOOLEANS ONLY" << "\n";
				return;
			}
			buff1 = S->VALUE.Bool;
		}
		if (N->r->valuetype == NAME) {
			SymTable S = searchTable(N->r->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != BOOL) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "and_test IS FOR BOOLEANS ONLY" << "\n";
				return;
			}
			buff2 = S->VALUE.Bool;
		}
		if (N->l->valuetype == BOOL)
			buff1 = N->l->Value.Bool;
		if (N->r->valuetype == BOOL)
			buff2 = N->r->Value.Bool;
		if (N->l->valuetype != BOOL && N->l->valuetype != NAME|| N->r->valuetype != BOOL && N->r->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << "and_test IS FOR BOOLEANS ONLY" << "\n";
			return;
		}
		N->valuetype = BOOL;
		N->Value.Bool = buff1 && buff2;
	}
}
void interpret_not_test(ast N){
	fout_diag << "interpret_not_test" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "not_test")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A not_test NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//not_test : comparison
		interpret_comparison(N->l);
		N->valuetype = N->l->valuetype;
		N->Value = N->l->Value;
	}
	if (N->nodetype == 2) {//not_test : "not" not_test
		interpret_not_test(N->l);
		bool buff;
		if (N->l->valuetype == NAME) {
			SymTable S = searchTable(N->l->Value.Name);
			if (!S) {
				fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
				return;
			}
			if (S->TYPE != BOOL) {
				fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
				fout_diag << "\t" << "ERROR" << "\t" << "not_test IS FOR BOOLEANS ONLY" << "\n";
				return;
			}
			buff = S->VALUE.Bool;
		}
		if (N->l->valuetype == BOOL)
			buff = N->l->Value.Bool;
		if (N->l->valuetype != BOOL && N->l->valuetype != NAME) {
			fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
			fout_diag << "\t" << "ERROR" << "\t" << "not_test IS FOR BOOLEANS ONLY" << "\n";
			return;
		}
		N->valuetype = BOOL;
		N->Value.Bool = !buff;
	}
}
void interpret_comparison(ast N){
	fout_diag << "interpret_comparison" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "comparison")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A comparison NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	if (N->nodetype == 1) {//comparison : expr
		interpret_expr(N->l);
		N->valuetype = N->l->valuetype;
		N->Value = N->l->Value;
	}
	if (N->nodetype == 2) {//comparison : comparison comp_op expr
		interpret_comparison(N->l);
		interpret_expr(N->r);
		if (N->j->nodetype == 1){//"<"
			double buff1, buff2;
			if (N->l->valuetype == NUMBER)
				buff1 = N->l->Value.Number;
			if (N->r->valuetype == NUMBER)
				buff2 = N->r->Value.Number;
			if (N->l->valuetype == NAME){
				SymTable S = searchTable(N->l->Value.Name);
				if (!S) {
					fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
					return;
				}
				if (S->TYPE != NUMBER) {
					fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
					fout_diag << "\t" << "ERROR" << "\t" << "comparison \"<\" IS FOR NUMBERS ONLY" << "\n";
					return;
				}
				buff1 = S->VALUE.Number;
			}
			if (N->r->valuetype == NAME){
				SymTable S = searchTable(N->r->Value.Name);
				if (!S) {
					fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
					return;
				}
				if (S->TYPE != NUMBER) {
					fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
					fout_diag << "\t" << "ERROR" << "\t" << "comparison \"<\" IS FOR NUMBERS ONLY" << "\n";
					return;
				}
				buff2 = S->VALUE.Number;
			}
			if (N->l->valuetype != NAME && N->l->valuetype != NUMBER ||N->r->valuetype != NAME && N->r->valuetype != NUMBER){
				fout_diag << "\t" << "ERROR" << "\t" << "comparison \"<\" IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			N->valuetype = BOOL;
			if (buff1 < buff2)
				N->Value.Bool = true;
			else
				N->Value.Bool = false;
		}
		if (N->j->nodetype == 2){//">"
			double buff1, buff2;
			if (N->l->valuetype == NUMBER)
				buff1 = N->l->Value.Number;
			if (N->r->valuetype == NUMBER)
				buff2 = N->r->Value.Number;
			if (N->l->valuetype == NAME){
				SymTable S = searchTable(N->l->Value.Name);
				if (!S) {
					fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
					return;
				}
				if (S->TYPE != NUMBER) {
					fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
					fout_diag << "\t" << "ERROR" << "\t" << "comparison \">\" IS FOR NUMBERS ONLY" << "\n";
					return;
				}
				buff1 = S->VALUE.Number;
			}
			if (N->r->valuetype == NAME){
				SymTable S = searchTable(N->r->Value.Name);
				if (!S) {
					fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
					return;
				}
				if (S->TYPE != NUMBER) {
					fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
					fout_diag << "\t" << "ERROR" << "\t" << "comparison \">\" IS FOR NUMBERS ONLY" << "\n";
					return;
				}
				buff2 = S->VALUE.Number;
			}
			if (N->l->valuetype != NAME && N->l->valuetype != NUMBER ||N->r->valuetype != NAME && N->r->valuetype != NUMBER){
				fout_diag << "\t" << "ERROR" << "\t" << "comparison \">\" IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			N->valuetype = BOOL;
			if (buff1 > buff2)
				N->Value.Bool = true;
			else
				N->Value.Bool = false;
		}
		if (N->j->nodetype == 3){//"=="
			double buff1, buff2;
			if (N->l->valuetype == NUMBER)
				buff1 = N->l->Value.Number;
			if (N->r->valuetype == NUMBER)
				buff2 = N->r->Value.Number;
			if (N->l->valuetype == NAME){
				SymTable S = searchTable(N->l->Value.Name);
				if (!S) {
					fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
					return;
				}
				if (S->TYPE != NUMBER) {
					fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
					fout_diag << "\t" << "ERROR" << "\t" << "comparison \"==\" IS FOR NUMBERS ONLY" << "\n";
					return;
				}
				buff1 = S->VALUE.Number;
			}
			if (N->r->valuetype == NAME){
				SymTable S = searchTable(N->r->Value.Name);
				if (!S) {
					fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
					return;
				}
				if (S->TYPE != NUMBER) {
					fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
					fout_diag << "\t" << "ERROR" << "\t" << "comparison \"==\" IS FOR NUMBERS ONLY" << "\n";
					return;
				}
				buff2 = S->VALUE.Number;
			}
			if (N->l->valuetype != NAME && N->l->valuetype != NUMBER ||N->r->valuetype != NAME && N->r->valuetype != NUMBER){
				fout_diag << "\t" << "ERROR" << "\t" << "comparison \"==\" IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			N->valuetype = BOOL;
			if (buff1 == buff2)
				N->Value.Bool = true;
			else
				N->Value.Bool = false;
		}
		if (N->j->nodetype == 4){//">="
			double buff1, buff2;
			if (N->l->valuetype == NUMBER)
				buff1 = N->l->Value.Number;
			if (N->r->valuetype == NUMBER)
				buff2 = N->r->Value.Number;
			if (N->l->valuetype == NAME){
				SymTable S = searchTable(N->l->Value.Name);
				if (!S) {
					fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
					return;
				}
				if (S->TYPE != NUMBER) {
					fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
					fout_diag << "\t" << "ERROR" << "\t" << "comparison \">=\" IS FOR NUMBERS ONLY" << "\n";
					return;
				}
				buff1 = S->VALUE.Number;
			}
			if (N->r->valuetype == NAME){
				SymTable S = searchTable(N->r->Value.Name);
				if (!S) {
					fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
					return;
				}
				if (S->TYPE != NUMBER) {
					fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
					fout_diag << "\t" << "ERROR" << "\t" << "comparison \">=\" IS FOR NUMBERS ONLY" << "\n";
					return;
				}
				buff2 = S->VALUE.Number;
			}
			if (N->l->valuetype != NAME && N->l->valuetype != NUMBER ||N->r->valuetype != NAME && N->r->valuetype != NUMBER){
				fout_diag << "\t" << "ERROR" << "\t" << "comparison \">=\" IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			N->valuetype = BOOL;
			if (buff1 >= buff2)
				N->Value.Bool = true;
			else
				N->Value.Bool = false;
		}
		if (N->j->nodetype == 5){//"<="
			double buff1, buff2;
			if (N->l->valuetype == NUMBER)
				buff1 = N->l->Value.Number;
			if (N->r->valuetype == NUMBER)
				buff2 = N->r->Value.Number;
			if (N->l->valuetype == NAME){
				SymTable S = searchTable(N->l->Value.Name);
				if (!S) {
					fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
					return;
				}
				if (S->TYPE != NUMBER) {
					fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
					fout_diag << "\t" << "ERROR" << "\t" << "comparison \"<=\" IS FOR NUMBERS ONLY" << "\n";
					return;
				}
				buff1 = S->VALUE.Number;
			}
			if (N->r->valuetype == NAME){
				SymTable S = searchTable(N->r->Value.Name);
				if (!S) {
					fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
					return;
				}
				if (S->TYPE != NUMBER) {
					fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
					fout_diag << "\t" << "ERROR" << "\t" << "comparison \"<=\" IS FOR NUMBERS ONLY" << "\n";
					return;
				}
				buff2 = S->VALUE.Number;
			}
			if (N->l->valuetype != NAME && N->l->valuetype != NUMBER ||N->r->valuetype != NAME && N->r->valuetype != NUMBER){
				fout_diag << "\t" << "ERROR" << "\t" << "comparison \"<=\" IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			N->valuetype = BOOL;
			if (buff1 <= buff2)
				N->Value.Bool = true;
			else
				N->Value.Bool = false;
		}
		if (N->j->nodetype == 6 || N->j->nodetype == 7){//"!=", "<>"
			double buff1, buff2;
			if (N->l->valuetype == NUMBER)
				buff1 = N->l->Value.Number;
			if (N->r->valuetype == NUMBER)
				buff2 = N->r->Value.Number;
			if (N->l->valuetype == NAME){
				SymTable S = searchTable(N->l->Value.Name);
				if (!S) {
					fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
					return;
				}
				if (S->TYPE != NUMBER) {
					fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
					fout_diag << "\t" << "ERROR" << "\t" << "comparison \"!=\" IS FOR NUMBERS ONLY" << "\n";
					return;
				}
				buff1 = S->VALUE.Number;
			}
			if (N->r->valuetype == NAME){
				SymTable S = searchTable(N->r->Value.Name);
				if (!S) {
					fout_diag << "\t" << "ERROR" << "\t" << "NOT AN EXISTING VARIABLE, HAS NO VALUES" << "\n";
					return;
				}
				if (S->TYPE != NUMBER) {
					fout_diag << "\t" << "ERROR" << "\t" << "EXISTING VARIABLE HAS INCOMPATIBLE TYPE" << "\n";
					fout_diag << "\t" << "ERROR" << "\t" << "comparison \"!=\" IS FOR NUMBERS ONLY" << "\n";
					return;
				}
				buff2 = S->VALUE.Number;
			}
			if (N->l->valuetype != NAME && N->l->valuetype != NUMBER ||N->r->valuetype != NAME && N->r->valuetype != NUMBER){
				fout_diag << "\t" << "ERROR" << "\t" << "comparison \"!=\" IS FOR NUMBERS ONLY" << "\n";
				return;
			}
			N->valuetype = BOOL;
			if (buff1 != buff2)
				N->Value.Bool = true;
			else
				N->Value.Bool = false;
		}
		if (N->j->nodetype == 8)//"is"
			;
		if (N->j->nodetype == 9)//"is" "not"
			;
	}
}
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
	if (N->nodetype == 1){//suite : simple_stmt
		interpret_simple_stmt(N->l);
	}
	if (N->nodetype == 2){//suite : NEWLINE INDENT suite_sub DEDENT
		interpret_suite_sub(N->l);
	}
};
void interpret_suite_sub(ast N){
	fout_diag << "interpret_suite_sub" << "\n";
	fout_diag << "\t" << "INITIATED" << "\n";
	if (strcmp(N->symbol, "suite_sub")){
		fout_diag << "\t" << "ERROR" << "\t" << "TIS NOT A suite_sub NODE" << "\n";
		fout_diag << "\t" << "ERROR" << "\t" << "TIS A " << N->symbol << " NODE" << "\n";
		return;
	}
	_Stack SUITESTACK;
	if (N->nodetype == 1){//suite_sub : stmt
		SUITESTACK.PushStack(N->r);
	}
	if (N->nodetype == 2){//suite_sub : suite_sub stmt
		SUITESTACK.PushStack(N->r);
		while (N->l && !strcmp(N->l->symbol, "suite_sub")){
			N = N->l;
			if (N->r && !strcmp(N->r->symbol, "stmt"))
				SUITESTACK.PushStack(N->r);
		}
		if (N->r && !strcmp(N->r->symbol, "stmt"))
			SUITESTACK.PushStack(N->r);
	}
	SUITESTACK.ClearStack();
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