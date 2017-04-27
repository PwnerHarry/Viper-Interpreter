void _Stack::ClearStack(){
	//cout << "ClearStack" << "\n";
	if (top <= -1)
		return;
	while (top > -1){
		//cout << "top is :\t" << top << "\n";
		interpret_stmt(S[top]);
		if (S[top]->valuetype == -BREAK)
			Break = true;
		top--;
	}
};
void _Stack::PushStack(ast T){
	//cout << "PushStack" << "\n";
	if (top == STACK_SIZE - 1){
		STACK_SIZE *= 2;
		S = (ast *)realloc(S, STACK_SIZE * sizeof(ast));
	}
	if (!Break)
		S[++top] = T;
	max_top = max_top < top ? top : max_top;
};