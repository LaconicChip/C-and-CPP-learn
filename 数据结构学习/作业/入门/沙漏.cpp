#include<iostream>
using namespace std;
int main()
{
	char c;//·ûºÅ
	int N;//·ûºÅÊý
	cin >> N >> c;
	int line = 0;
	while (1)
	{
		if (2 * line * line - 1 <= N)//k*k+k*k-1
		{
			line++;
		}
		else
		{
			if(line!=0)
			{
				line--;
			}
			break;
		}
	}
	// ÉÏ°ë
	for (int i = line; i >= 1; i--)
	{

		for (int j = 0; j < line - i; j++) 
		{
			cout << " ";
		}

		for (int j = 0; j < 2 * i - 1; j++) 
		{
			cout << c;
		}
		cout << endl;
	}
	//ÏÂ°ë
	for (int i = 2; i <= line; i++) {

		for (int j = 0; j < line - i; j++) {
			cout <<" ";
		}

		for (int j = 0; j < 2 * i - 1; j++) {
			cout << c;
		}
		cout << endl;
	}

	int num = N - (2 * line * line - 1);
	cout << num << endl;

	return 0;
}



