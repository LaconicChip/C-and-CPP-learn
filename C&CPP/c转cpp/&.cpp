#include<iostream>
using namespace std;

void c(int &a)//可直接使用&取a地址修改，c不可以

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
