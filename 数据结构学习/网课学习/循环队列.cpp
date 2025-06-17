#include<iostream>
using namespace std;

#define MAXSIZE 10//牺牲一个位置，故实际大小为9

typedef int Elemtype;

typedef struct
{
	//Elemtype data[MAXSIZE];
	Elemtype *data;
	int front;
	int rear;
}Queue;

Queue* initQueue()
{
	Queue *q=new Queue;
	q->data=new Elemtype[MAXSIZE];
	q->front=0;
	q->rear=MAXSIZE-1;//修改点
	return q;
}
//判空
int isEmpty(Queue *Q){
	if(Q->front==Q->rear)
	{
		cout<<"空的"<<endl;
		return 0;
	}
	return 1;
}

//公式：队尾或队头+1再取余

// 入队
int equeue(Queue *q,Elemtype e)
{
	q->rear=(q->rear+1)%MAXSIZE;
	if((q->rear+1)%MAXSIZE==q->front)
	{
		cout<<"满了"<<endl;
		return 0;
	}
	q->data[q->rear]=e;
	//q->rear=(q->rear+1)%MAXSIZE;
	return 1;
}

//出队
int dequeue(Queue* q,Elemtype &e)
{
	isEmpty(q);
	e=q->data[q->front];
	q->front=(q->front+1)%MAXSIZE;
	return 1;
}
//获取队头
int gethead(Queue *Q,Elemtype &e)
{
	if(Q->front==Q->rear)
	{
		cout<<"空的"<<endl;
		return 0;
	}
	e=Q->data[Q->front];
	return 1;
}

int main()
{
	Queue *q=initQueue();
	
	for(int i=1;i<=10;i++)
	{
		equeue(q,10*i);
	}
	
	Elemtype e;
	dequeue(q,e);
	cout<<e<<endl;
	dequeue(q,e);
	cout<<e<<endl;
	
	gethead(q,e);
	cout<<e<<endl;
	
	return 0;
}
