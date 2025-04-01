#include<iostream>
#include<cstdlib>
using namespace std;

struct QNode
{
	int data;
	QNode* next;
};

struct LinkQueue {
	QNode* front;  // 队头指针
	QNode* rear;   // 队尾指针
};

void InitQueue(LinkQueue &q);
void EnQueue(LinkQueue &q);
void DeQueue(LinkQueue &q);

int main()

{

	int n, choice;

	LinkQueue Q;

	InitQueue(Q);

	cin >> n;

	while (n > 0)

	{

		cin >> choice;

		switch (choice)

		{

		case 1:EnQueue(Q); break;//入队列 

		case 0:DeQueue(Q); break;//出队列 

		}

		n--;

	}

	return 0;

}

void InitQueue(LinkQueue &q)
{
	q.front = q.rear = nullptr;
}

void EnQueue(LinkQueue &q)
{
	int num;
	cin >> num;

	QNode* newNode = new QNode();
	newNode->data = num;
	newNode->next = nullptr;

	if (q.rear == nullptr)
	{
		q.front = q.rear = newNode;
	}
	else
	{
		q.rear->next = newNode;
		q.rear = newNode;

	}
}

void DeQueue(LinkQueue &q)
{
	if (q.front == nullptr)
	{
		cout<< "invalid" << endl;
		return;
	}

	QNode* temp = q.front;
	cout << temp->data << endl;
	q.front = q.front->next;  // 移动队头指针
	if (q.front == nullptr) { 
		q.rear = nullptr;   
	}

	delete temp; 
}

