#include<stdio.h>
int main()
{
	/*
	打开文件：fopen
	
	写出数据：fgetc读一个字符，读不到返回-1
			  fgets读一行，读不到返回null
			  fread一次读多个,读不到返回0
	
	关闭文件：fclose
	*/
	//读一个fgetc
	FILE* file=fopen("C:\\Users\\Lacon\\Desktop\\a.txt", "r");//r为只读

	int c;

	while ((c = fgetc(file)) != -1)
	{
		printf("%c", c);
	}

	//while (1)
	//{	
	//	c = fgetc(file);
	//	if (c==-1)
	//	{
	//		printf("结束");
	//		break;
	//	}
	//	printf("%c", c);

	//}

	fclose(file);
	printf("\n\n");

	//读一行fgets
	//以换行符为准    
	FILE* files = fopen("C:\\Users\\Lacon\\Desktop\\b.txt", "r");

	//读取
	char arr[1024];
	//char* str1=fgets(arr, 1024,files);
	//printf("%s\n", str1);

	//char* str2 = fgets(arr, 1024, files);
	//printf("%s\n", str2);

	//char* str3 = fgets(arr, 1024, files);
	//printf("%s\n", str3);

	//char* str4 = fgets(arr, 1024, files);
	//printf("%s\n", str4);

	char* str;
	while ((str = fgets(arr, 1024, files)) != NULL)
	{
		printf("%s", str);
	}
	fclose(files);

	printf("\n");

	//读一堆fread
	FILE* filess = fopen("C:\\Users\\Lacon\\Desktop\\c.txt", "r");
	char arr1[4];
	//FILE* filess = fopen("C:\\Users\\Lacon\\Desktop\\c.txt", "r");
	//char arr1[1024];
	//int n=fread(arr1, 1, 1024, filess);//arr1为存储的数组，1为数组类型所占字节，1024为读取的长度，filess为上边定义的读取的文件
	//printf("%d\n", n);
	//printf("%s\n", arr1);
	//会导致出现一堆垃圾数据
	printf("*******************************************************************************************\n");
	int a;
	//循环改进：

	while ((a = fread(arr1, 1, 4, filess)) != 0)
	{
		for (int i = 0; i < a; i++)
		{
			printf("%c", arr1[i]);
		}
	}


	fclose(filess);

	return 0;
}