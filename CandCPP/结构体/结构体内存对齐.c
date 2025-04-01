#include<stdio.h>
/*	只能放在自己类型整数倍的内存地址上
    简单理解：
		内存地址 / 占用字节=结果可以整除
		int存放的位置一定能被4整除
		longlong和double则一定能被8整除

	结构体的内存对齐：
		结构体的总大小为最大类型的整数倍

	对齐时会补充空白字节，但不会改变原本字节
	char对齐后还为1
*/
struct Num
{
	double a;//0 1 2 3 4 5 6 7
	char b;//8 空地址9 10 11
	int c;//12 13 14 15
	char d;//16
	//最大为double:8
	//1=16=17
	//故占用内存为3*8=24
};
struct Num1
{
	double a;//0 1 2 3 4 5 6 7
	char b;//8
	char d;//9 空地址10 11
	int c;//12 13 14 15
	//最大为double:8
	//1+15=16
	//故占用内存为2*8=16
};

int main()
{
	struct Num n;
	struct Num1 n1;
	printf("%zu\n", sizeof(n));
	printf("%zu\n", sizeof(n1));
	


	return 0;
}
