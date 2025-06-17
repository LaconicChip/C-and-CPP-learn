# include <stdio.h>

# include <stdlib.h>

# define initsize 100  //初始分配量

# define LISTINCREMENT 10  //分配增量

typedef int ElemType;


typedef struct // 结构体定义

{
	    
	ElemType *elem;
	
	int length;
	
	int listsize;
	
} SqList;



void IntiList(SqList *L, int n) {
	L->elem = (ElemType *)malloc(initsize * sizeof(ElemType));
	L->length = n;
	L->listsize = initsize;
}

void ListInsert(SqList *L, int j, ElemType x) {
	if (L->length >= L->listsize) {
		ElemType *newbase = (ElemType *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) exit(1);
		L->elem = newbase;
		L->listsize += LISTINCREMENT;
	}
	for (int i = L->length; i >= j; i--) {
		L->elem[i + 1] = L->elem[i];
	}
	L->elem[j] = x;
	L->length++;
}

void PrintList(SqList L) {
	for (int i = 1; i <= L.length; i++) {
		if (i > 1) printf(" ");
		printf("%d", L.elem[i]);
	}
	printf("\n");
}


int main()

{
	
	int n, j = 0;
	
	ElemType x;
	
	SqList L;
	
	scanf("%d", &n);
	
	IntiList(&L, n);    //初始化L表
	
	for (int i = 1; i <= n; i++)      
		
	{
		
		scanf("%d", &L.elem[i]);
		
	}
	
	scanf("%d", &x);
	
	while (L.elem[j] < x)      //查找插入位置j
		
	{
		
		j++;
		
	}
	
	ListInsert(&L, j, x);     //插入
	
	PrintList(L);      //输出
	
	free(L.elem);     //释放空间
	
	return 0;
	
}


