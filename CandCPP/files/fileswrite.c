#include<stdio.h>
int main()
{
	/*
	打开文件    fopen

	写出数据：  fputc 一次写一个字符，返回写出的字符
				fputs 一次写一个字符串，写出成功返回非负数，一般忽略返回值
				fwrite 一次读多个，返回写出的个数

	关闭文件：  fclose
	*/

	/*
	模式:
		r：read只读模式,不能写，强行写出数据无法写到本地文件

		w：write只写模式
			细节1：文件不存在会创建，但是要保证前面的文件夹存在
			细节2：如果文件已经存在，会把文件清空
			细节3：上面的创建或者清空，都是fopen这个函数底层干的事情

		a：append追加写出模式
			细节1：文件不存在会创建，但是要保证前面的文件夹存在
			细节2：上面的创建或者续写，都是fopen这个函数底层干的事情
	*/

	//1.打开文件
	FILE* file = fopen("C:\\Users\\Lacon\\Desktop\\1.txt", "a");//w只写

	//2.写出数据
	//fputc
	//a--97 一般写ASCII表值
	int c = fputc(97, file);//输出a
	printf("%d\n", c);
	
	//fputs
	int n=fputs("你好你好AAA",file);
	//一般忽略返回值，因为输出失败会有EOF错误
	printf("%d\n", n);

	//fwrite 
	char arr[] = { 97,98,99,100,101 };//输出abcde
	int a = fwrite(arr, 1, 5, file);
	printf("%d\n", a);

	//关闭文件
	fclose(file);

	return 0;
}