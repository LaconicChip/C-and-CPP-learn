#include<stdio.h>
#include<cstring>

struct Message
{
	long long PhoneNumber;
	char mail[100];
};
//结构体嵌套
struct student
{
	char name[100];
	int age;
	char gender;
	double height;
	struct Message mes;
};

int main()
{
	struct student a;
	strcpy(a.name,"张三");
	a.age=18;
	a.gender='m';
	a.height=180.5;
	a.mes.PhoneNumber=12345678900;
	strcpy(a.mes.mail,"123456789@qq.com");

	printf("学生的信息为\n");
	printf("姓名为%s\n",a.name);
	printf("年龄为%d\n",a.age);
	printf("性别为%c\n",a.gender);
	printf("身高为%.1lf\n",a.height);
	printf("电话为%lld\n",a.mes.PhoneNumber);
	printf("邮箱为%s\n",a.mes.mail);
	printf("\n");
	
	//批量赋值
	student b={"李四",20,'f',160.5,{12366669999,"12345@qq.com"}};
	
	printf("学生的信息为\n");
	printf("姓名为%s\n",b.name);
	printf("年龄为%d\n",b.age);
	printf("性别为%c\n",b.gender);
	printf("身高为%.1lf\n",b.height);
	printf("电话为%lld\n",b.mes.PhoneNumber);
	printf("邮箱为%s\n",b.mes.mail);
	printf("\n");
	
	return 0;
}
