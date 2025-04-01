#include <stdio.h>

int main() {
	int a;
	int b;
	char op;

	scanf("%d", &a);
	scanf(" %c", &op);
	scanf("%d", &b);

	if (op == '/' && b == 0) {
		printf("no answer");
		return 0;
	}

	int sum;
	switch (op) {
	case '+':
		sum = a + b;
		break;
	case '-':
		sum = a - b;
		break;
	case '*':
		sum = a * b;
		break;
	case '/':
		sum = a / b;
		break;
	default:
		printf("输入无效！\n");
		return 0;
	}

	if (sum < 0 || sum > 9) {
		printf("no answer");
	}
	else {
		printf("%d\n", sum);
	}

	return 0;
}
