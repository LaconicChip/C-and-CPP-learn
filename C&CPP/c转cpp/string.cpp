#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string str1="Hello";
	string str2=" World!";
	string str3=str1+str2;
	
	cout<<str3<<endl;
	
	
	string a;
	//cin>>a;//无法输入空格
	getline(cin,a);//获取一行
	cout<<a<<endl;
	cout<<a.length()<<endl;//获取长度
	
	cout<<"*****************************************************************"<<endl;
	
	string s="hello world!";
	cout<<s<<endl;
	string s_sub=s.substr(0);//获取字符并复制，括号为从哪里开始到那里结束，或者只填一个数从哪里开始直到结束
	cout<<s_sub;
	
	
	return 0;
}
