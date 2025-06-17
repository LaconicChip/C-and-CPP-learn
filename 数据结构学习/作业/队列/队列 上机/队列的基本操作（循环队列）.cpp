#include<iostream>
using namespace std;

int q[10];       // ���д洢
int front = 0;    // ��ͷ
int rear = 0;     // ��β
bool enqueue(int x);
bool dequeue(int &x);

int main()
{
	int n;
	int choice;
	int num;
	cin >> n;

	while (n--)
	{
		cin >> choice;
		if (choice == 1)
		{
			cin >> num;
			if (!enqueue(num))
			{
				cout << "invalid" << endl;
			}
		}
		else
		{  
			int val;
			if (!dequeue(val))
			{
				cout << "invalid" << endl;
			}
				
			else
			{
				cout << val << endl;
			}
				
		}

	}

	return 0;
}

//���
bool enqueue(int x)
{
	if ((rear + 1) % 10 == front)
	{
		return false;
	}
	q[rear] = x;
	rear = (rear + 1) % 10;
	return true;
}

// ����
bool dequeue(int &x)
{
	if (front == rear)   
		return false;

	x = q[front];
	front = (front + 1) % 10; 
	return true;
}
