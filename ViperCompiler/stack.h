const int STACK_SIZE = 1000;
class _Stack {
public:
	int top;
	ast * S;
	_Stack(){
		top = -1;
		S = (ast *)calloc(STACK_SIZE, sizeof(ast));
	};
	void PushStack(ast T){
		S[++top] = T;
		if (top >= STACK_SIZE){
			fprintf(stderr, "Stack Overflow");
		}
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