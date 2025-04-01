#include<stdio.h>
#include<cstring>
typedef struct Student 
{
	char name[100];
	int age;
}stu;
//定义函数写在下面
void method(stu *p);



int main()
{
	
	stu a;
	strcpy(a.name,"zhangsan");
	a.age=18;
	 
	method(&a); 
	 
	printf("修改后的学生数据为\n%s,年龄%d\n",a.name,a.age);
	
	return 0;
}


//如果要在函数中修改a的值，直接接受a的内存地址，通过修改内存地址中的只就可以修改了
void method(stu *p)
//指针p记录的是a的内存地址
{
	printf("接收到main函数中学生数据为\n%s,年龄%d\n",(*p).name,(*p).age);
	//修改
	printf("请输入要修改的学生名字\n");
	scanf("%s",(*p).name);
	printf("请输入要修改的学生年龄\n");
	scanf("%d",&((*p).age));
}
