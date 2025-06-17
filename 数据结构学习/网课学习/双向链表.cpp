#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct Node{
	ElemType data;
	Node *prev,*next;
}Node,*Linklist;

Linklist intlist()
{
	Linklist head=new Node;
	head->data=0;
	head->next=NULL;
	head->prev=NULL;
	return head;
}

//头插法
int insertHead(Linklist L,ElemType e)
{
	Linklist p=new Node;
	p->data=e;
	p->prev=L;
	p->next=L->next;
	if(L->next!=NULL)
	{
		L->next->prev=p;
	}
	L->next=p;
	return 1;
}
//遍历
void listnode(Linklist L)
{
	Linklist p=L->next;
	
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
//找尾节点
Linklist findtail(Linklist L)
{
	Linklist tail=L;
	while(tail->next!=NULL)
	{
		tail=tail->next;
	}
	return tail;
}

//尾插
Linklist inserttail(Linklist tail,ElemType e)
{
	Linklist p=new Node;
	p->data=e;
	p->prev=tail;
	tail->next=p;
	p->next=NULL;
	return p;
}
// 指定插入
int insertNode(Linklist L,int pos,ElemType e)
{
	Linklist p=L;
	int i=0;
	while(i<pos-1)//找前置节点
	{
		p=p->next;
		i++;
		if(p==NULL){
			return 0;
		}
	}
	Linklist q=new Node;
	q->data=e;
	q->prev=p;
	q->next=p->next;
	p->next->prev=q;
	p->next=q;
	return 1;
}

//删除节点
int deleteNode(Linklist L,int pos)
{
	Linklist p=L;
	int i=0;
	while(i<pos-1){
		p=p->next;
		i++;
		if(p==NULL){
			return 0;
		}
	}
	if(p->next==NULL){
		cout<<"删除位置有误"<<endl;
		return 0;
	}
	Linklist q=p->next;
	p->next=q->next;
	q->next->prev=p;
	delete q;
	return 1;
}
//释放链表
void freelist(Linklist L)
{
	Linklist p=L->next;
	Linklist q;
	while(p!=NULL){
		q=p->next;
		delete p;
		p=q;
	}
	L->next=NULL;
}

int main()
{
	Linklist L=intlist();
	
	insertHead(L,10);
	insertHead(L,20);
	insertHead(L,30);
	listnode(L);
	inserttail(findtail(L),10);
	inserttail(findtail(L),20);
	inserttail(findtail(L),30);
	listnode(L);
	insertNode(L,4,0);
	listnode(L);
	deleteNode(L,4);
	listnode(L);
	freelist(L);
	
	return 0;
	
}
