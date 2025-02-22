#include<stdio.h>
struct Student 
{
	char name[100];
	int age;
};
typedef struct
{
	char name[100];
	int attack;
	int defense;
	int blood;
} M;//起别名

int main()
{
	struct Student stu1={"zhangsan",23};
	struct Student stu2={"lisi",20};
	struct Student stu3={"wangwu",25};
	
	struct Student stuArr[3]={stu1,stu2,stu3};
	
	for(int i=0;i<3;i++)
	{
		printf("%s %d\n",stuArr[i].name,stuArr[i].age);
	}
	
	
//typedef运用
	M taro={"泰罗",100,90,500};
	M reo={"泰罗",90,80,450};
	M eddie={"泰罗",120,70,600};
	
	M arr[3]={taro,reo,eddie};
	
	for(int i=0;i<3;i++)
	{
		M temp=arr[i];
		printf("奥特曼的名字是%s，攻击力是%d，防御力是%d，生命是%d\n",temp.name,temp.attack,temp.defense,temp.blood);
	}
	
	return 0;
}
