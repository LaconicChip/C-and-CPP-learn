#include <iostream>
#include <cstring>
using namespace std;

const int MAXSIZE = 100;

// 栈的定义
struct SqStack {
	char data[MAXSIZE]; 
	int top;       
};

// 初始化栈
void InitStack(SqStack &S) {
	S.top = -1; //表示栈空
}

// 入栈
bool PushStack(SqStack &S, char ch) {
	if (S.top == MAXSIZE - 1) { // 栈满
		return false;
	}
	S.data[++S.top] = ch;
	return true;
}

// 出栈
bool PopStack(SqStack &S, char &ch) {
	if (S.top == -1) { // 栈空
		return false;
	}
	ch = S.data[S.top--]; // 取出栈顶数据，栈顶指针减1
	return true;
}

// 判断括号
bool IsMatched(const char *expr) {
	SqStack S;
	InitStack(S); // 初始化栈
	while (*expr != '#') {
		if (*expr == '(' || *expr == '[') {
			if (!PushStack(S, *expr)) { //栈满
				return false;
			}
		}
		else if (*expr == ')' || *expr == ']') {
			if (S.top == -1) { // 栈空
				return false;
			}
			char topChar;
			PopStack(S, topChar); // 弹出栈顶元素
			if ((*expr == ')' && topChar != '(') || (*expr == ']' && topChar != '[')) {
				return false; // 括号不匹配
			}
		}
		expr++; // 移动到下一个
	}
	return S.top == -1;
}

int main() {
	char expr[1000];
	cin.getline(expr, 1000);
	if (IsMatched(expr)) {
		cout << "ok" << endl;
	}
	else {
		cout << "error" << endl;
	}
	return 0;
}
