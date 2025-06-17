#include<iostream>
using namespace std;

int q[10];       // 队列存储
int front = 0;    // 队头
int rear = 0;     // 队尾
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

//入队
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

// 出队
bool dequeue(int &x)
{
	if (front == rear)   
		return false;

	x = q[front];
	front = (front + 1) % 10; 
	return true;
}
