#include<stdio.h>
#include<stdlib.h>
#include<time.h>


struct spot
{
	char name[100];
	int count;
};


int main()
{
	struct spot arr[4] = { {"A",0},{"B",0},{"C",0},{"D",0} };

	srand(time(NULL));

	for (int i = 0; i < 80; i++)
	{

		//随机范围：rand()%(尾+1-头)+头
		int choose = rand() % 4;//获取随机用户投票，随机数范围为0-3
		arr[choose].count++;
		//choose表示给choose景点的投票
		//arr[choose]表示该景点
		//arr[choose].count表示该景点的票数
		//arr[choose].count++表示该景点的票数+1
	}

	int max = arr[0].count;
	int len = sizeof(arr) / sizeof(arr[0]);
	int A=0;
	for (int i =1; i < len; i++)//i=1因为0索引无需再和自己比较
	{
		if (max < arr[i].count)
		{
			max = arr[i].count;
			A = i;
		}
	}
	printf("票数最多的景点为%s,共有%d票\n",arr[A].name, arr[A].count);
	//遍历

	for (int i = 0; i < 4; i++)
	{
		struct spot temp = arr[i];
		//printf("%s %d", arr[i].name, arr[i].count);
		printf("%s %d\n", temp.name, temp.count);
	}



	return 0;
}
