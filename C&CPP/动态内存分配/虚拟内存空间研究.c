#include<stdio.h>
#include<stdlib.h>

void method(int* p, int size);

int main()
{
	int* p = (int*)malloc(25 * sizeof(int));
	int size = 25;

	method(p, size);
	free(p);//�����ͷ�



	//�����ڴ�
	
	
		int gbps = 1024 * 1024 * 1024;
		int count = 0;
		while (1)
		{
			int* pp = (int*)malloc(gbps);//����ʧ��ʱ����NULL
			count++;
			if (pp == NULL)
			{
				printf("����ʧ��");
				free(pp);
				break;
			}
			printf("�ڴ�%d�ɹ�%p\n", count, pp);
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