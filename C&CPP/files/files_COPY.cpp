#include<stdio.h>
int main()
{
	/*
	��ϰ��
	���ô��뿽���ļ�
	Ҫ��
	�������ϵ�ĳĳĪ������������aaa�ļ�����
	*/

	/*
		���ı��ļ���r w a
		windows������±��ܴ򿪶����ܶ����ľ��Ǵ��ı��ļ�
		��txt md lrc
		
		�������ļ���rb wb ab

	*/

	//���ļ�
	FILE* file1 = fopen("C:\\Users\\Lacon\\Desktop\\�ڰ����װ¼��������� �����塶Ψһ����Hi-res��.mp4","rb");
	//2.��Ŀ�ĵ��ļ�
	FILE* file2 = fopen("C:\\Users\\Lacon\\Desktop\\aaa\\�ڰ����װ¼��������� �����塶Ψһ����Hi-res��.mp4", "wb");

	//3.����ѭ����ȡ����Դ������֮����д��Ŀ�ĵ�
	char arr[1024];
	int n;
	while ((n = fread(arr, 1, 1024, file1)) != 0)
	{
		fwrite(arr, 1, n, file2);
	}

	fclose(file1);
	fclose(file2);
	
	return 0;
}