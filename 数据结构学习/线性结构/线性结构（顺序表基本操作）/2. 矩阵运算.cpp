#include<iostream>
using namespace std;
int main                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 ()
{ 
	int n;
	int sum = 0;
	int a[10][10];
	
	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == n - 1 || j == n - 1 || i + j == n - 1) {
				continue;
			}
			sum += a[i][j];
		}
	}
	cout << sum << endl;
	return 0;	
	
	
}  
