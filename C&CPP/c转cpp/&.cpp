#include<iostream>
using namespace std;

void c(int &a)
{
	a++;
}

int main()
{
	int a=1;
	c(a);
	cout<<a<<endl;
	
	return 0;
}
