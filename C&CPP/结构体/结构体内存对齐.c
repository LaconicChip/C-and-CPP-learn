#include<stdio.h>
/*	ֻ�ܷ����Լ��������������ڴ��ַ��
    ����⣺
		�ڴ��ַ / ռ���ֽ�=�����������
		int��ŵ�λ��һ���ܱ�4����
		longlong��double��һ���ܱ�8����

	�ṹ����ڴ���룺
		�ṹ����ܴ�СΪ������͵�������

	����ʱ�Ჹ��հ��ֽڣ�������ı�ԭ���ֽ�
	char�����Ϊ1
*/
struct Num
{
	double a;//0 1 2 3 4 5 6 7
	char b;//8 �յ�ַ9 10 11
	int c;//12 13 14 15
	char d;//16
	//���Ϊdouble:8
	//1=16=17
	//��ռ���ڴ�Ϊ3*8=24
};
struct Num1
{
	double a;//0 1 2 3 4 5 6 7
	char b;//8
	char d;//9 �յ�ַ10 11
	int c;//12 13 14 15
	//���Ϊdouble:8
	//1+15=16
	//��ռ���ڴ�Ϊ2*8=16
};

int main()
{
	struct Num n;
	struct Num1 n1;
	printf("%zu\n", sizeof(n));
	printf("%zu\n", sizeof(n1));
	


	return 0;
}
