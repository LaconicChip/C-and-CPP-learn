#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int contains(int arr[],int len,int num);
int main()
{
	int arr[10]={0};
	int len=sizeof(arr)/sizeof(int);
	int sum=0;
	
	srand(time(NULL));
	for(int i=0;i<len;)
	{
		int num=rand()%100+1;
		int flag=contains(arr,len,num);
		if(!flag)
		{
			arr[i]=num;	
			i++;
		}
		
	}
	//求和
	for(int i=0;i<len;i++)
	{
		sum+=arr[i];
	}
	printf("总和%d\n",sum);
	
	//求平均数
	int average=sum/len;
	printf("平均数%d\n",average);
	
	//统计比平均数小的数
	int count=0;
	for (int i=0;i<len;i++)
	{
		if (arr[i]<average)
		{
			printf("%d\n",arr[i]);
			count++;
		}
		
	}
	printf("小于平均数的数共有%d个\n",count);
	
	
	return 0;
}
int contains(int arr[],int len,int num)
{
	for (int i=0;i<len;i++)
	{
		if (arr[i]==num)
		{
			return 1;
		}
	}
	return 0;
}

