/*输入若干个不超过100的整数，建立单链表，然后通过一趟遍历在单链表中确定值最小的结点。输出该结点的值



【输入格式】:

首先输入一个整数n，表示测试数据的个数，然后在下一行依次输入n个不超过100的整数。



【输出格式】:

输出单链表中值最小的结点的值

【输入样例】:

30

30 85 97 43 70 69 29 77 22 64 25 55 39 95 69 99 61 97 69 59 12 88 55 75 66 13 75 36 85 67

【输出样例】:

min=12
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
	int n;
	cin >> n;

	list* head = NULL;
	list* tail = NULL;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		list* newnum =(list*)malloc(sizeof(list));
		newnum->num = a;
		newnum->next = NULL;

		if (head == NULL)
		{
			head = newnum;
			tail = newnum;
		}
		else {
			tail->next = newnum;
			tail = newnum;
		}
	}
	int min = head->num;
	list* flag = head->next;

	while (flag != NULL)
	{
		if (flag->num < min)
		{
			min = flag->num;
		}
		flag = flag->next;
	}

	cout <<"min="<< min << endl;

	list* temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);//释放内存
	}

	return 0;
}
