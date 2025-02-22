#include<iostream>
using namespace std;

#define MIN 150//差不多就是定义宏变量比如这个，c语言中只能使用这个，应该
int main()
{
	const int MAX=150;//定义常量，MAX不可被修改，可看作宏定义
	
	cout<<MAX<<endl;
	
	return 0;
}
