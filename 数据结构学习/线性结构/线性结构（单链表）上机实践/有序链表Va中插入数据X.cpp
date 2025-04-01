#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

int main() {
	// 创建头节点
	Node* head = new Node();
	head->next = nullptr;
	
	int n, num;
	cin >> n;
	
	Node* tail = head;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		Node* newNode = new Node{num, nullptr};
		tail->next = newNode;
		tail = newNode;       // 更新尾指针
	}
	
	// 输入要插入的数字
	int x;
	cin >> x;
	
	Node* curr = head;
	while (curr->next && curr->next->data < x) {
		curr = curr->next;
	}
	
	// 插入新节点
	Node* newNode = new Node{x, curr->next};
	curr->next = newNode;
	
	Node* p = head->next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	
	return 0;
}
