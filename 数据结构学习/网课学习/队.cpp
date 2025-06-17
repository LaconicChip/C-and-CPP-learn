#include<iostream>
using namespace std;

#define MAXSIZE 100

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
	q->rear=0;
	return q;
}

int isEmpty(Queue *Q){
	if(Q->front==Q->rear)
	{
		cout<<"空的"<<endl;
		return 1;
	}
	return 0;
}

//出队
Elemtype deletequene(Queue *Q)
{
	if(Q->front==Q->rear)
	{
		cout<<"空的"<<endl;
		return 0;
	}
	Elemtype e=Q->data[Q->front];
	Q->front++;
	return e;
}
//调整队列
int queneFULL(Queue *Q)
{
	if(Q->front>0){
		int step=Q->front;
		for(int i=Q->front;i<=Q->rear;i++)
		{
			Q->data[i-step]=Q->data[i];
		}
		Q->front=0;
		Q->rear=Q->rear-step;
		return 1;
	}
	else{
		cout<<"真的满了"<<endl;
		return 0;
	}
}


//入队
int equeue(Queue *Q,Elemtype e)
{
	if(Q->rear>=MAXSIZE)
	{
		if(!queneFULL(Q)){
			return 0;
		}
	}
	Q->data[Q->rear]=e;
	Q->rear++;
	return 1;
}

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
	Queue* q=initQueue();
	
	equeue(q,10);
	equeue(q,20);
	equeue(q,30);
	equeue(q,40);
	equeue(q,50);
	equeue(q,60);
	
	cout<<deletequene(q)<<endl;
	cout<<deletequene(q)<<endl;
	Elemtype e;
	gethead(q,e);
	cout<<e<<endl;
	
	return 0;
}
