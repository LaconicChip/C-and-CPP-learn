#include<iostream>
using namespace std;
int main()
{
	int a[30] = { 0 };
	int n = 0;
	int len = sizeof(a) / sizeof(int);

	for (int i = 0; i < len; i++)
	{
		int num;
		cin>>num;
		if (num == -1)
		{
			break;
		}
		a[i] = num;
		n++;
	}

	int m;
	cin>>m;
	if (m > n || m < 1)
	{
		cout<<"Delete failed";
		return 0;
	}

	for (int i = m-1; i < n; i++)
	{
		a[i] = a[i+1];
	}
	n--;
	for (int i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
