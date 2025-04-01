#include <iostream>

using namespace std;

typedef struct {
	int *base;
	int *top;
	int stacksize;
}SqStack;

void InitStack(SqStack &S);
void PushStack(SqStack &S);
void PopStack(SqStack &S);

int main()

{

	SqStack S;

	InitStack(S);

	int choice;

	while (cin >> choice)

	{

		if (choice == -1)  break;

		switch (choice)

		{

		case 1:PushStack(S); break;

		case 0:PopStack(S); break;

		}

	}

	return 0;

}

void InitStack(SqStack &S)
{
	S.base = (int*)malloc(100 * sizeof(int));
	S.top = S.base;
	S.stacksize = 100;//栈MAX
}

void PushStack(SqStack &S) {
	int x;
	cin >> x;
	if (S.top - S.base >= S.stacksize) { // 栈满
		cout << "error "<<" ";
	}
	else {
		*S.top = x;
		S.top++; 
	}
}

void PopStack(SqStack &S)
{
	if (S.base == S.top)
	{
		cout << "error"<<" ";
	}
	else
	{
		S.top--;
		cout << *S.top << " ";
	}
}



