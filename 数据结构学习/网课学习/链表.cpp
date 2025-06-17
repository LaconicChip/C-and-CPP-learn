#include <iostream>
#include <cstdlib>
using namespace std;

typedef int ElemType;

typedef struct Lnode
{
    ElemType data;
    Lnode *next;
} Lnode;

//初始化
Lnode* initList()
{
    Lnode* head=new Lnode;
    head->data=0;
    head->next=NULL;
    return head;
}
//头插
void insertHead(Lnode*L,ElemType e)
{
    Lnode *p=new Lnode;
    p->data=e;
    p->next=L->next;
    L->next=p;
}
//遍历
void listNode(Lnode* L)
{
    Lnode* p=L->next;
    while(p!=NULL)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
    cout << endl;
}
//获取尾节点
Lnode* gettail(Lnode* L)
{
    Lnode*p=L;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    return p;
}

//尾插法
Lnode* inserttail(Lnode *tail,ElemType e)
{
    Lnode* p=new Lnode;
    p->data=e;
    tail->next=p;
    p->next=NULL;
    return p;
}

//指定位置插入
int insertNode(Lnode *L,int pos,ElemType e)
{
    Lnode* p=L;
    int i=0;

    //遍历找前驱节点
    while(i<pos-1)
    {
        p=p->next;
        i++;
        if(p==NULL)
        {
            return 0;
        }
    }

    Lnode* q=new Lnode;
    q->data=e;
    q->next=p->next;
    p->next=q;
    return 1;
}
//删除节点
int deleteNode(Lnode* L,int pos)
{
    Lnode* p=L;
    int i=0;

    while(i<pos-1)
    {
        p=p->next;
        i++;
        if(p==NULL)
        {
            return 0;
        }
    }

    if(p->next==NULL)
    {
        cout << "删除位置有误"<< endl;
        return 0;
    }

    Lnode* q=p->next;
    p->next=q->next;
    delete q;
    return 1;
}
//获取链表长度(包括头结点)
int Lnodelength(Lnode* L)
{
    Lnode* p=L;
    int len=0;
    while(p!=NULL)
    {
        p=p->next;
        len++;
    }
    cout << "链表长度为"<<len<< endl;
	return 0;
}

 //双指针找k个节点
int findNodeFS(Lnode *L,int k)
{
	Lnode* fast=L->next;
	Lnode* slow=L->next;
	for(int i=0;i<k;i++){
		fast=fast->next;
	}
	while(fast!=NULL)
	{
		fast=fast->next;
		slow=slow->next;
	}
	cout<<"倒数第"<<k<<"个节点值为"<<slow->data<<endl;
}

//释放链表
void freelist(Lnode* L)
{
    Lnode* p=L->next;
    Lnode* q;

    while(p!=NULL)
    {
        q=p->next;
        delete p;
        p=q;
    }
    L->next=NULL;
}

int delMiddleMode(Lnode* head)
{
	Lnode* fast=head->next;
	Lnode* slow=head;
	
	while(fast!=NULL&&fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	Lnode* q=slow->next;
	slow->next=q->next;
	free(q);
	return 1;
}

int main() {
    Lnode* L=initList();
    insertHead(L,10);
    insertHead(L,20);
    insertHead(L,30);
    inserttail(gettail(L),10);
    inserttail(gettail(L),20);
    inserttail(gettail(L),30);
    insertNode(L,4,0);
    listNode(L);
    deleteNode(L,4);
    listNode(L);
    Lnodelength(L);
	findNodeFS(L,3);
    freelist(L);
    Lnodelength(L);
    return 0;
}

