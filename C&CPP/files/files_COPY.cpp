#include<stdio.h>
int main()
{
	/*
	练习：
	利用代码拷贝文件
	要求：
	把桌面上的某某莫拷贝到桌面上aaa文件夹中
	*/

	/*
		纯文本文件：r w a
		windows里面记事本能打开而且能读懂的就是纯文本文件
		如txt md lrc
		
		二进制文件：rb wb ab

	*/

	//打开文件
	FILE* file1 = fopen("C:\\Users\\Lacon\\Desktop\\在百万豪装录音棚大声听 邓紫棋《唯一》【Hi-res】.mp4","rb");
	//2.打开目的地文件
	FILE* file2 = fopen("C:\\Users\\Lacon\\Desktop\\aaa\\在百万豪装录音棚大声听 邓紫棋《唯一》【Hi-res】.mp4", "wb");

	//3.利用循环读取数据源，读完之后在写到目的地
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