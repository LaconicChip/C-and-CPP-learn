#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef int ElemType;
typedef struct {
	ElemType *base;
	ElemType *top;
} SqStack;

void InitStack(SqStack &S) {
	S.base = new ElemType[MAXSIZE];
	S.top = S.base;
}

void Push(SqStack &S, ElemType e) {
	if (S.top - S.base == MAXSIZE) {//满
		return;
	}
	*S.top++ = e;
}

void Pop(SqStack &S, ElemType &e) {//空
	if (S.top == S.base) {
		return;
	}
	e = *--S.top;
}

bool StackEmpty(SqStack S) {
	return S.top == S.base;
}

int main() {
	int num;
	cin >> num;
	if (num == 0) {
		cout << "0" << endl;
		return 0;
	}
	SqStack S;
	InitStack(S);
	while (num > 0) {
		int remainder = num % 8;
		Push(S, remainder);
		num /= 8;
	}
	while (!StackEmpty(S)) {
		ElemType e;
		Pop(S, e);
		cout << e;
	}
	cout << endl;
	return 0;
}
