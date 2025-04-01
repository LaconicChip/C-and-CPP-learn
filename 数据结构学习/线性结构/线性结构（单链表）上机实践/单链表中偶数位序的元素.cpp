#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* next;
};

int main() {
	int n;
	cin >> n;
	
	Node* head = new Node();
	Node* current = head;
	
	for(int i = 0; i < n; i++) {
		int num;
		cin >> num;
		current->next = new Node();
		current = current->next;
		current->value = num;
	}
	
	int sum = 0;
	int position = 1;
	current = head->next;
	
	while(current != nullptr) {
		if(position % 2 == 0) {
			cout << current->value << " ";
			sum += current->value;
		}
		position++;
		current = current->next;
	}
	
	
	cout << endl << sum;
	
	return 0;
}
