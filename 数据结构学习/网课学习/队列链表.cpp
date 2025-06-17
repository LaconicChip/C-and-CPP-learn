#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct QueueNode
{
	ElemType data;
	QueueNode *next;
}QueueNode;

typedef struct{
	
	QueueNode* front;
	QueueNode* rear;
}Queue;

Queue* initQueue()
{
	Queue* q=new Queue;
	QueueNode* node=new QueueNode;
	node->data=0;
	node->next=NULL;
	q->front=node;
	q->rear=node;
	return q;
}
//判空
int isempty(Queue *q)
{
	if(q->front==q->rear)
		return 1;
	else
		return 0;
}

//入队(尾插法)
void equeue(Queue*q,ElemType e)
{
	QueueNode *node=new QueueNode;
	node->data=e;
	node->next=NULL;
	q->rear->next=node;
	q->rear=node;
}

//出队（释放头节点）
int dequeue(Queue*q,ElemType &e)
{
	if(isempty(q))
	{
		cout<<"空队"<<endl;
		return 0;
	}
	QueueNode *node=q->front->next;
	e=node->data;
	q->front->next=node->next;
	
	if(q->rear==node)//删空了
	{
		q->rear=q->front;
	}
	
	delete node;
	return 1;
}
//获取队头
ElemType getfront(Queue *q)
{
	if(isempty(q))
	{
		cout<<"空队"<<endl;
		return 0;
	}
	return q->front->next->data;
}

int main()
{
	Queue*q=initQueue();
	equeue(q,10);
	equeue(q,20);
	equeue(q,30);
	equeue(q,40);
	equeue(q,50);
	
	ElemType e;
	dequeue(q,e);
	cout<<e<<endl;
	dequeue(q,e);
	cout<<e<<endl;
	cout<<getfront(q)<<endl;
	return 0;
}
