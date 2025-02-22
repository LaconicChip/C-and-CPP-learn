#include<iostream>
using namespace std;

struct stu 
{
	char name[100];//或者使用string
	string Number;
	int age;
};


int main(void)
{
	//在c语言中，需要引用结构体需要加上struct，而CPP不用

	stu a = { "李华","001",100 };
	struct stu b = { "张三","002",10 };
	stu c = { "赵四","003",88 };
	stu arr[3] = {a,b,c};

	for (int i = 0; i < 3; i++)
	{
		cout << "名字:" << arr[i].name << " " << "年龄:" << arr[i].age << " " << "学号:" << arr[i].Number << endl;
	}
	

	return 0;
}