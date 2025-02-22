#include<stdio.h>
#include<stdlib.h>
int main()
{
	/*
		malloc  申请空间（连续）
		calloc  申请空间+数据初始化
		realloc 修改空间大小
		free    释放空间

		stdlib.h头文件
	*/

	//malloc申请10个int类型的整数
	//返回这片空间的首地址
	int* p = (int*)malloc(10 * sizeof(int));//cpp中要强制转化
	if (p == NULL) {
		perror("Failed to allocate memory");
		return 1;
	}
	//calloc申请10个int类型整数
	//int *p= (int*)calloc(10, sizeof(int));//效率低不常用


	printf("%p\n", p);

	//赋值
	for (int i = 0; i < 10; i++)
	{
		//第一种
		//*(p + i) = (i + 1) * 10;
		//第二种
		p[i] = (i + 1) * 10;
		//被解释为：p[i]--->p+i  外面跟里面相加
		//i[p]同理=i+p
	}

	for (int i = 0; i < 10; i++)
	{
		//遍历
		printf("%d\n", *(p + i));
	}
	printf("***************\n");

	//修改空间大小
	int* pp = (int*)realloc(p, 20 * sizeof(int));
	
	for (int i = 10; i < 20; i++)
	{
		//赋值
		*(p + i) = (i + 1) * 10;

	}
	for (int i = 0; i < 20; i++)
	{
		//遍历
		printf("%d\n", *(p + i));
	}
	//释放内存
	free(pp);

	return 0;
}