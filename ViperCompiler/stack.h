void _Stack::ClearStack(){
	if (top <= -1)
		return;
	while (top > -1){
		interpret_stmt(S[top]);
		top--;
	}
};
void _Stack::PushStack(ast T){
	if (top == STACK_SIZE - 1){
		STACK_SIZE *= 2;
		S = (ast *)realloc(S, STACK_SIZE * sizeof(ast));
	}
	S[++top] = T;
};