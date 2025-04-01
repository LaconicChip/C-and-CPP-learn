#include<iostream>
using namespace std;

int age(int m);

int main()

{
	int n;
	cin>>n;
	cout<<age(n);
	
	return 0;
}
int age(int m)
{
	if(m==1)
	{
		return 10;
	}
	else
	{
		return age(m-1)+2;
	}
	
}
