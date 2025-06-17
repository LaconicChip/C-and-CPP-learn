/*
【问题描述】删除单链表（带头结点，头插入法建立单链表）的第i个结点

【样例输入1】   

5

6 7 8 9 10

3

【样例输出1】  10 9 7 6


【样例输入2】   

1

8

1

【样例输出2】  null



【样例输入3】   

1

8

2

【样例输出2】  error

【样例说明】第一行输入链表长度5，第二行依次输入链表元素，以空格间隔，第三行输入删除的元素序列3.

以空格间隔依次输出删除后的单链表元素，若为空表则输出null，若为无效删除，则输出error。
*/



#include<iostream>
#include<cstdlib>
using namespace std;

struct list
{
	int num;
	list* next;
};




int main()
{
	int n,m;
	cin >> n;

	list* head = (list*)malloc(sizeof(list));
	head->next = NULL;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		list* newnum = (list*)malloc(sizeof(list));
		newnum->num = a;
		newnum->next = head->next;
		head->next = newnum;
	}

	cin >> m;//删除的节点位置

	list* p = head;
	int t = 0;
	while (p->next != NULL && t < m - 1) {
		p = p->next;
		t++;
	}

	if (p->next == NULL || m < 1) {
		cout << "error" << endl;
		return 0;
	}
	else {
		list* temp = p->next; // 要删除的节点
		p->next = temp->next; // 跳过要删除的节点
		free(temp); // 释放内存
	}


	list* flag = head->next;
	if (flag == NULL) {
		cout << "null" << endl;
	}
	else {
		while (flag != NULL) {
			cout << flag->num << " ";
			flag = flag->next;
		}
		cout << endl;
	}

	while (head != NULL) {
		list* temp = head;
		head = head->next;
		free(temp);//释放内存
	}

	return 0;
}
