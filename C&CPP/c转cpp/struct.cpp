#include<iostream>
using namespace std;

struct stu 
{
	char name[100];//����ʹ��string
	string Number;
	int age;
};


int main(void)
{
	//��c�����У���Ҫ���ýṹ����Ҫ����struct����CPP����

	stu a = { "�","001",100 };
	struct stu b = { "����","002",10 };
	stu c = { "����","003",88 };
	stu arr[3] = {a,b,c};

	for (int i = 0; i < 3; i++)
	{
		cout << "����:" << arr[i].name << " " << "����:" << arr[i].age << " " << "ѧ��:" << arr[i].Number << endl;
	}
	

	return 0;
}