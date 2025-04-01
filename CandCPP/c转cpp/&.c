//c中通过指针实现函数修改数值
#include<stdio.h>

void P(int*a);

int main()
{
	int a=5;
	P(&a);
	printf("%d\n",a);
	
	return 0;
}
void P(int*a)
{
	(*a)++;
}
