#include<iostream>
using namespace std;

#define MAXSIZE 100

typedef int ElemType;
/*
typedef struct{
	ElemType data[MAXSIZE];
	int top;
}Stack;
*/

//初始化
/*
void intStack(Stack *s)
{
	s->top=-1;
}
*/
//顺序存储
typedef struct{
	ElemType *data;
	int top;
}Stack;


Stack* intStack()
{
	Stack *s=new Stack;
	s->data=new ElemType[MAXSIZE];
	s->top=-1;
	return s;
}

//判断栈是否为空
int isEmpty(Stack *s)
{
	if(s->top==-1)
	{
		cout<<"空的"<<endl;
		return 1;
	}
	else
	{
		cout<<"非空"<<endl;
		return 0;
	}
	return 0;
}

//压栈/进栈
int push(Stack *s,ElemType e)
{
	if(s->top>=MAXSIZE-1){
		cout<<"满了"<<endl;
		return 0;
	}
	s->top++;
	s->data[s->top]=e;
	return 1;
}
//出栈
int pop(Stack *s,ElemType *e)//e为返回被删除的值
{
	if(s->top==-1){
		cout<<"空的"<<endl;
		return 0;
	}
	*e=s->data[s->top];
	s->top--;
	return 1;
}

//获取栈顶元素
int getTop(Stack *s,ElemType *e)
{
	if(s->top==-1){
		cout<<"空的"<<endl;
		return 0;
	}
	*e=s->data[s->top];
	return 1;
}


//----------------------------------------------------------------



//链式存储
typedef struct Lstack
{
	ElemType data;
	Lstack *next;
}Lstack,*Lliststack;
//初始化
Lliststack LintStack()
{
	Lliststack s=new Lstack;
	s->data=0;
	s->next=NULL;
	return s;
}
//判空
int Lisempty(Lliststack s)
{
	if(s->next==NULL){
		cout<<"空栈"<<endl;
		return 1;
	}
	else{
		return 0;
	}
}

//压栈
int Lpush(Lliststack s,ElemType e)
{
	Lliststack p=new Lstack;
	p->data=e;
	p->next=s->next;
	s->next=p;
	return 1; 
}
//出栈
int Lpop(Lliststack s,ElemType &e)
{
	if(s->next==NULL){
		cout<<"空栈"<<endl;
		return 0;
	}
	e=s->next->data;
	Lliststack q=s->next;
	s->next=q->next;
	delete q;
	return 1;
}
//获取栈顶
int LgetTop(Lliststack s,ElemType &e)
{
	if(s->next==NULL){
		cout<<"栈空"<<endl;
		return 0;
	}
	e=s->next->data;
	return 1;
}


int main()
{
	Stack *s=intStack();
	push(s,10);
	push(s,20);
	push(s,30);
	ElemType e;
	pop(s,&e);
	cout<<e<<endl;
	getTop(s,&e);
	cout<<e<<endl;
	
	cout<<"_______________________________"<<endl;
	
	Lstack *ls=LintStack();
	Lpush(ls,10);
	Lpush(ls,20);
	Lpush(ls,30);
	//ElemType e;
	Lpop(ls,e);
	cout<<e<<endl;
	LgetTop(ls,e);
	cout<<e<<endl;
	
	return 0;
}
