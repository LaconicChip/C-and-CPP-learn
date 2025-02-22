#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int arr[]={0,1,2,3,4,5,6,7,8,9};
	int len=sizeof(arr)/sizeof(int);
	
	srand(time(NULL));
	for(int i=0;i<len;i++)
	{
		int index=rand()%10;
		int temp=arr[i];
		arr[i]=arr[index];
		arr[index]=temp;
	}
	for(int i=0;i<len;i++)
	{
		printf("%d",arr[i]);
	}
}
