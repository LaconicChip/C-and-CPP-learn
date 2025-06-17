#include <iostream>
using namespace std;
#define OK 1

typedef struct book
{
	int num[8];
	book *next;
} Lnode,*Linklist;
//创建
int Lintlist_L(Linklist &L)
{
	L=new Lnode;
	//L=(Linklist)malloc(sizeof(Lnode));
	L->next=NULL;
	return OK;
}
//销毁
int destorylist_L(Linklist &L)
{
	Lnode *p;//等价Linklist p
	while (L)//等价(L!=NULL)
	{
		p=L;
		L=L->next;
		delete p;
	}
	return OK;
}

//清空链表
int clearlist_L(Linklist &L)
{
	Lnode *p,*q;
	p=L->next;
	while(p)
	{
		q=p->next;
		delete p;
		p=q;
	}
	L->next=NULL;
	return OK;
}

//求表长
int listlength_L(Linklist L)
{
	Linklist p;
	p=L->next;
	int i=0;
	while (p)
	{
		i++;
		p=p->next;
	}
	return i;
}

int getelem_L(Linklist L,int i,book &e)
{
	Linklist p;
	p=L->next;
	int j=1;
	while(p&&j<i)
	{
		p=p->next;
		++j;
	}
	if(!p||j>i)
	{
		e=p->data;
	}
	return OK;
}

int main() {
	
	return 0;
}
