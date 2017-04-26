int STACK_SIZE = 100;
class _Stack {
public:
	int top;
	ast * S;
	_Stack(){
		top = -1;
		S = (ast *)calloc(STACK_SIZE, sizeof(ast));
	};
	void PushStack(ast T){
		if (top == STACK_SIZE - 1){
			STACK_SIZE *= 2;
			S = (ast *)realloc(S, STACK_SIZE * sizeof(ast));
		}
		S[++top] = T;
	};
	void ClearStack(){
		if (top <= -1)
			return;
		while (top > -1){
			interpret_stmt(S[top--]);
		}
	}
};
_Stack STACK;