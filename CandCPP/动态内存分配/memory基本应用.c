#include<stdio.h>
#include<stdlib.h>
int main()
{
	/*
		malloc  ����ռ䣨������
		calloc  ����ռ�+���ݳ�ʼ��
		realloc �޸Ŀռ��С
		free    �ͷſռ�

		stdlib.hͷ�ļ�
	*/

	//malloc����10��int���͵�����
	//������Ƭ�ռ���׵�ַ
	int* p = (int*)malloc(10 * sizeof(int));//cpp��Ҫǿ��ת��
	if (p == NULL) {
		perror("Failed to allocate memory");
		return 1;
	}
	//calloc����10��int��������
	//int *p= (int*)calloc(10, sizeof(int));//Ч�ʵͲ�����


	printf("%p\n", p);

	//��ֵ
	for (int i = 0; i < 10; i++)
	{
		//��һ��
		//*(p + i) = (i + 1) * 10;
		//�ڶ���
		p[i] = (i + 1) * 10;
		//������Ϊ��p[i]--->p+i  ������������
		//i[p]ͬ��=i+p
	}

	for (int i = 0; i < 10; i++)
	{
		//����
		printf("%d\n", *(p + i));
	}
	printf("***************\n");

	//�޸Ŀռ��С
	int* pp = (int*)realloc(p, 20 * sizeof(int));
	
	for (int i = 10; i < 20; i++)
	{
		//��ֵ
		*(p + i) = (i + 1) * 10;

	}
	for (int i = 0; i < 20; i++)
	{
		//����
		printf("%d\n", *(p + i));
	}
	//�ͷ��ڴ�
	free(pp);

	return 0;
}