#include<stdio.h>
int main()
{
	int n;
	int m[10][10];
	int sum = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			scanf("%d", &m[i][j]);
		}
	}

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j <= i; j++) 
		{
			sum += m[i][j];
		}
	}

	printf("%d", sum);

	return 0;
}
