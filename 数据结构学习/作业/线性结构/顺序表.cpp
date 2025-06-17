#include<iostream>
#include <cstdlib>
using namespace std;
#define MAXSIZE 10000
#define ERROR 0
#define OK 1
typedef struct{
	char NO[20];
	char name[50];
	float price;
}Book;


typedef struct{
	Book *elem;//存储空间基地
	int length;//图书数
}Sqlist;



//初始化
bool InitList(Sqlist &L)
{
	L.elem = new Book[MAXSIZE];
	if(!L.elem)
	{
		cerr<<"error"<<endl;//错误
		return false;
	}
	L.length=0;
	return 1;
}
//销毁
void DestoryList (Sqlist &L)
{
	if(L.elem)
	{
		delete L.elem;
	}
}

//清空
void clearlist(Sqlist &L)
{
	L.length=0;
}

//判断是否为空
bool IsEmpty(const Sqlist &L)
{
	//return static_cast<bool>(L.length);
	return (L.length == 0);
}

//取值
bool GetElem(const Sqlist &L,const size_t i,Book &e)
{
	if(i<1||i>MAXSIZE)
	{
		cerr<<"out of range"<<endl;
	}
	e=L.elem[i-1];
	return true;
}

//顺序查找
int LocateElem(Sqlist &L,Book &e)
//L中查找e，返回序号（第几个元素）
{
	for(int i=0;i<L.length;++i){
		if(L.elem[i] == e)
		{
			return i+i;	//成功返回序号
		}
		return 0;//失败返回0
	}
}

//插入算法
int ListInsert_Sq(Sqlist &L,int i,Book e)
{
	if(i<1||i>L.length+1)
	{
		return ERROR;//i不合法
	}
	if(L.length==MAXSIZE)
	{
		return ERROR;//存储空间已满
	}
	for(int j=L.length-1;j>=i-1;j--)
	{
		L.elem[j+1]=L.elem[j];//插入位置元素后移
	}
	L.elem[i-1]=e;//将新增元素e放在第i位置

	L.length++;//表长+1
	return OK;
}
//L.elem=(Book*)malloc(sizeof(Book)*MAXSIZE);

//删除
bool EraseList(Sqlist &L,int i)
{
	if(i<0||i>L.length)
	{
		cerr << "wrong erase position!" << endl;
		return false;
	}
	if(L.length == 0)
	{
		cerr << "List has no length" << endl;
		return false;
	}
	for(int j=i+1;i<L.length;j++){
		L.elem[j-1]=L.elem[j];
	}
	L.length-=1;
	return true;
}

void PrintList(Sqlist &L) {
	for (int i = 1; i <= L.length; i++) {
		if (i > 1) cout<<" ";
		cout<<L.elem[i];
		//printf("%d", L.elem[i]);
	}
	printf("\n");
}

int main()
{
	int n,j=0;
	Book xy;
	Sqlist L;
	cin>>n;
	InitList(L);
	for(int i=1;i<=n;i++)
	{
		Book temp;
		cin>>temp;
		ListInsert_Sq(L,L.length+1,temp);
		//cin>>&L.elem[i];
	}
	cin>>xy;
	
	while(L.elem[j]<xy){
		j++;
	}
	ListInsert_Sq(L,j,xy);
	
	PrintList(L); 
	
	DestoryList (L);
	
	return 0;
}
