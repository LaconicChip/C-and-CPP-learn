#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

void insert(ListNode *&head, int x) {
	ListNode *newNode = new ListNode(x);
	if (!head || head->val >= x) {
		newNode->next = head;
		head = newNode;
		return;
	}
	ListNode *current = head;
	while (current->next && current->next->val < x) {
		current = current->next;
	}
	if (current->next && current->next->val == x) {
		delete newNode;
		return;
	}
	newNode->next = current->next;
	current->next = newNode;
}

void printList(ListNode *head) {
	if (!head) return;
	cout << head->val;
	head = head->next;
	while (head) {
		cout << " " << head->val;
		head = head->next;
	}
	cout << endl;
}

int main() {
	int n, x;
	cin >> n;
	ListNode *head = nullptr;
	ListNode *tail = nullptr;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		ListNode *newNode = new ListNode(x);
		if (!head) {
			head = tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
	}
	cin >> x;
	insert(head, x);
	printList(head);
	return 0;
}
