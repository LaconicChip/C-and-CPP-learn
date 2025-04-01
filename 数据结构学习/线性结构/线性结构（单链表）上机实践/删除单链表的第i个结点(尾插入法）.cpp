#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

int main() {
	int n, pos;
	cin >> n;
	
	Node* head = new Node();
	head->next = nullptr;
	Node* tail = head; // 尾指针
	
	// 尾插法建表
	for(int i=0; i<n; i++){
		int val;
		cin >> val;
		Node* newNode = new Node();
		newNode->data = val;
		newNode->next = nullptr;
		tail->next = newNode;
		tail = newNode;
	}
	
	cin >> pos;
	
	//删除位置的前一个节点
	if(pos >=1 && pos <=n){
		Node* p = head;
		for(int i=1; i<pos; i++){ // 移动pos-1次
			p = p->next;
		}
		Node* temp = p->next;     // 要删除的节点
		p->next = temp->next;    
		delete temp;              
	}
	
	Node* curr = head->next;
	if(curr == nullptr){
		cout << "null";
	}else{
		bool first = true; 
		while(curr != nullptr){
			if(!first) cout << " ";
			cout << curr->data;
			first = false;
			curr = curr->next;
		}
	}
	

	while(head != nullptr){
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	
	return 0;
}
