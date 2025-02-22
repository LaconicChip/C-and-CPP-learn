#include<stdio.h>
#include<stdlib.h>

void method(int* p, int size);

int main()
{
	int* p = (int*)malloc(25 * sizeof(int));
	int size = 25;

	method(p, size);
	free(p);//随手释放



	//虚拟内存
	
	
		int gbps = 1024 * 1024 * 1024;
		int count = 0;
		while (1)
		{
			int* pp = (int*)malloc(gbps);//申请失败时返回NULL
			count++;
			if (pp == NULL)
			{
				printf("申请失败");
				free(pp);
				break;
			}
			printf("内存%d成功%p\n", count, pp);
		}
	
	
	return 0;
}

void method(int* p, int size)
{

	for (int i = 0; i < size; i++)
	{
		printf("%d ", *(p + i));
	}
	printf("\n");
}