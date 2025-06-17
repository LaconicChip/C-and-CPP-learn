#include <iostream>
using namespace std;

const int MAXSIZE = 10000;

int main() {
	int n;
	cin >> n;
	int list[MAXSIZE];
	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}
	
	int i, x;
	cin >> i >> x;
	
	if (n == MAXSIZE) {
		cout << "错误：表满不能插入。" << endl;
	} else if (i < 1 || i > n + 1) {
		cout << "错误：插入位置不合法。" << endl;
	} else {

		for (int j = n; j >= i; j--) {
			list[j] = list[j - 1];
		}
		list[i - 1] = x;
		n++;
	}
	
	// 输出顺序表
	for (int k = 0; k < n; k++) {
		cout << list[k] << " ";
	}
	cout << endl;
	
	return 0;
}
