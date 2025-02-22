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
