#include <iostream>

#include <malloc.h>

using namespace std;

#define SIZE 2000


typedef struct

{
	
	int *Elem;
	
	int Length;
	
	int Listsize;
	
} Sqlist; // 顺序表结构体

// 初始化顺序表
void Init_Sqlist(Sqlist &L) {
	L.Elem = (int *)malloc(SIZE * sizeof(int));
	L.Length = 0;
	L.Listsize = SIZE;
}

// 输入顺序表数据
void Input(Sqlist &L) {
	scanf("%d", &L.Length);
	for (int i = 0; i < L.Length; i++) {
		scanf("%d", &L.Elem[i]);
	}
}

// 归并两个有序表
void Union_List(Sqlist La, Sqlist Lb, Sqlist &Lc) {
	int i = 0, j = 0, k = 0;
	while (i < La.Length && j < Lb.Length) {
		if (La.Elem[i] < Lb.Elem[j]) {
			Lc.Elem[k++] = La.Elem[i++];
		} else {
			Lc.Elem[k++] = Lb.Elem[j++];
		}
	}
	// 处理剩余元素
	while (i < La.Length) {
		Lc.Elem[k++] = La.Elem[i++];
	}
	while (j < Lb.Length) {
		Lc.Elem[k++] = Lb.Elem[j++];
	}
	Lc.Length = k;
}

// 输出顺序表
void Output(Sqlist Lc) {
	for (int i = 0; i < Lc.Length; i++) {
		printf("%d", Lc.Elem[i]);
		if (i < Lc.Length - 1) {
			printf(" ");
		}
	}
	printf("\n");
}

int main()

{
	
	Sqlist La, Lb, Lc;
	
	Init_Sqlist(La); // 初始化表La
	
	Init_Sqlist(Lb);
	
	Init_Sqlist(Lc);
	
	Input(La); // 输入La表数据
	
	Input(Lb);
	
	Union_List(La, Lb, Lc); // 归并La Lb至Lc表中
	
	Output(Lc);             // 输出Lc表
	
}
