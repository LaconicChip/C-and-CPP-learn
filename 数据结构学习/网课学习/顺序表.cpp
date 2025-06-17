#include<iostream>
#include <cstdlib>
using namespace std;

#define MAXSIZE 100

typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} Sqlist;

//初始化
Sqlist* Initlist()
{
    Sqlist *L=(Sqlist*)malloc(sizeof(Sqlist));
    L->length=0;
    return L;
}
//尾部加元素
int addelem(Sqlist *L,int elem)
{
    if(L->length>=MAXSIZE)
    {
        cout<<"顺序表满";
        return 0;
    }
    L->data[L->length]=elem;
    L->length++;
    return 1;
}
//遍历
void listelem(Sqlist *L)
{
    for(int i=0; i<L->length; i++)
    {
        printf("%d",L->data[i]);
    }
    printf("\n");
}
//插入
int insertelem(Sqlist *L,int pos,int elem)
{
    if(L->length>=MAXSIZE)
    {
        cout<<"顺序表满\n";
        return 0;
    }
    if(pos<1||pos>L->length+1)
    {
        cout<<"插入位置错误\n";
        return 0;
    }
    if(pos<=L->length)
    {
        for(int i=L->length-1; i>=pos-1; i--)
        {
            L->data[i+1]=L->data[i];
        }
        L->data[pos-1]=elem;
        L->length++;
        return 1;
    }
}
//删除
int deleteelem(Sqlist *L,int pos,ElemType *e)//e为记录被删除的元素值
{
    if(L->length<=0)
    {
        cout<<"顺序表空\n";
        return 0;
    }
    if(pos<1||pos>L->length)
    {
        cout<<"删除位置错误\n";
        return 0;
    }

    *e=L->data[pos-1];
    if(pos<L->length)
    {
        for(int i=pos-1; i<L->length-1; i++)
        {
            L->data[i]=L->data[i+1];
        }
    }
    L->length--;
    return 1;
}
//查找元素返回位置
int findelem(Sqlist *L,ElemType elem)
{
    if(L->length<=0)
    {
        cout<<"顺序表空\n";
        return 0;
    }
    for(int i=0; i<L->length; i++)
    {
        if(elem==L->data[i])
        {
            return i+1;
        }
    }
    return 0;
}


int main()
{
    Sqlist *L=Initlist();

    printf("初始化成功，目前长度占用%d\n",L->length);
    printf("目前占用内存%zu字节",sizeof(L->data));
    addelem(L,66);
    addelem(L,99);
    addelem(L,89);
    listelem(L);
    insertelem(L,2,58);
    listelem(L);
    int de;
    deleteelem(L,3,&de);
    listelem(L);
    printf("被删除元素为%d",de);
    return 0;
}