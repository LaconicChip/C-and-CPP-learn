#include<stdio.h>
#include<string.h>
typedef struct Student {
    char number[100];
    char name[100];
    int math;
    int english;
    int PC;
    int total;
}stu;

stu students[100]; 
int count = 0; 

void menu() {
    printf("********学生成绩管理系统********\n");
    printf("1. 添加学生信息\n");
    printf("2. 修改学生信息\n");
    printf("3. 删除学生信息\n");
    printf("4. 查询学生信息\n");
    printf("5. 排序\n");
    printf("6. 统计\n");
    printf("7. 显示所有学生信息\n");
    printf("0. 退出系统\n");
    printf("************************************\n");
}
//1.添加学生信息
void addStudent() {
	//检查学生数量
	if (count >= 100) {
		printf("学生数量已达上限，无法添加！\n");
		return;
	}
	
	while(1)
	{
		int flag=1;
		char newNumber[100];
		printf("请输入学号：");
		scanf("%s", newNumber);
		for (int i = 0; i < count; i++) //检测学号重复
		{
			if (strcmp(students[i].number, newNumber) == 0) 
			{
				printf("学号已存在，请重新输入！\n");
				flag=0;
				break;
			}
		}
		if(flag)
		{
			strcpy(students[count].number,newNumber);
			break;
		}
	}

    printf("请输入姓名：");
    scanf("%s", students[count].name);
	
	int temp;
	while(1)//成绩范围检查
	{
		printf("请输入数学成绩：");
		scanf("%d",&temp);
		if(temp>=0&&temp<=100)
		{
			break;
		}
		printf("成绩不在合法范围，请重新输入\n");
	}
	students[count].math = temp;
    
	while(1)//成绩范围检查
	{
		printf("请输入英语成绩：");
		scanf("%d",&temp);
		if(temp>=0&&temp<=100)
		{
			break;
		}
		printf("成绩不在合法范围，请重新输入\n");
	}
    students[count].english=temp;
	
	while(1)//成绩范围检查
	{
		printf("请输入计算机成绩：");
		scanf("%d",&temp);
		if(temp>=0&&temp<=100)
		{
			break;
		}
		printf("成绩不在合法范围，请重新输入\n");
	}
	students[count].PC=temp;
    
    students[count].total = students[count].math + students[count].english + students[count].PC;
    count++;
    printf("学生信息添加成功！\n");
}

//2.修改学生信息
void fixStudent() {
    if (count == 0)
    {
        printf("目前没有学生信息，请添加学生信息后再试\n\n\n\n\n");
        return;
    }

    char number[100];
    printf("请输入要修改的学生学号：");
    scanf("%s", number);
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].number, number) == 0) {
            printf("找到学生信息，当前信息如下：\n");
            printf("学号：%s 姓名：%s 数学：%d 英语：%d 计算机：%d 总分：%d\n", students[i].number, students[i].name, students[i].math, students[i].english, students[i].PC, students[i].total);
			//printf("小Tips：以下信息如不想修改请输入-1跳过此项修改\n\n");
            printf("请输入新的姓名：");
            scanf("%s", students[i].name);
			while (getchar() != '\n');// 清空残留的换行符，ai改的

			int temp;
			while(1)//成绩范围检查
			{
				printf("请输入新的数学成绩：");
				scanf("%d",&temp);
				if(temp>=0&&temp<=100)
				{
					break;
				}
				printf("成绩不在合法范围，请重新输入\n");
			}
            students[i].math=temp;
			
			while(1)//成绩范围检查
			{
				printf("请输入新的英语成绩：");
				scanf("%d",&temp);
				if(temp>=0&&temp<=100)
				{
					break;
				}
				printf("成绩不在合法范围，请重新输入\n");
			}
            students[i].english=temp;
            
			while(1)//成绩范围检查
			{
				printf("请输入新的计算机成绩：");
				scanf("%d",&temp);
				if(temp>=0&&temp<=100)
				{
					break;
				}
				printf("成绩不在合法范围，请重新输入\n");
			}
			students[i].PC=temp;

            students[i].total = students[i].math + students[i].english + students[i].PC;
            printf("学生信息修改成功\n");
            return;
        }
    }
    printf("未找到学号为%s的学生信息\n", number);
}
//3.删除学生信息
void deleteStudent() {
    if (count == 0)
    {
        printf("目前没有学生信息，请添加学生信息后再试\n\n\n\n\n");
        return;
    }

    char number[100];
    printf("请输入要删除的学生学号：");
    scanf("%s", number);
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].number, number) == 0) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("学生信息删除成功！\n");
            return;
        }
    }
    printf("未找到学号为%s的学生信息\n", number);
}

//4.查询学生信息
void findStudent() {
    if (count == 0)
    {
        printf("目前没有学生信息，请添加学生信息后再试\n\n\n\n\n");
        return;
    }
	
    int a;
	while(1)
	{
	    printf("1. 按学号查询\n");
	    printf("2. 按姓名查询\n");
	    printf("3. 按某门课成绩挂科查询\n");
		printf("0. 退出查询\n");
	    printf("请选择查询方式：");
		
		//解决输入为非数字导致错误
		if (scanf("%d", &a) != 1) //跟AI学的，scanf获取到获取失败返回0，正常获取返回1
		{
			printf("输入有误，请重新选择！\n");
			while (getchar() != '\n'); // 清空缓冲区,不太知道原理，ai写的，用着先
			continue;
		}
		break;
	}
    switch (a) {
		case 0: 
		{
			printf("退出查询成功\n");
			break;
		}
    case 1: {
        char number[100];
        printf("请输入学号：");
        scanf("%s", number);
        for (int i = 0; i < count; i++) {
            if (strcmp(students[i].number, number) == 0) {
                printf("学号：%s 姓名：%s 数学：%d 英语：%d 计算机：%d 总分：%d\n",
                    students[i].number, students[i].name, students[i].math, students[i].english, students[i].PC, students[i].total);
                return;
            }
        }
        printf("未找到学号为%s的学生信息！\n", number);
        break;
    }
    case 2: {
        char name[100];
        printf("请输入姓名：");
        scanf("%s", name);
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(students[i].name, name) == 0) {
                printf("学号：%s 姓名：%s 数学：%d 英语：%d 计算机：%d 总分：%d\n",
                    students[i].number, students[i].name, students[i].math, students[i].english, students[i].PC, students[i].total);
                found = 1;
            }
        }
        if (!found) {
            printf("未找到姓名为%s的学生信息！\n", name);
        }
        break;
    }
    case 3: {
		int subject;
		while(1)
		{
			printf("请选择不及格的科目（1. 数学 2. 英语 3. 计算机）：");
			if(scanf("%d", &subject)!=1)
			{
				printf("输入不合法，请重新输入\n");
				while (getchar() != '\n'); 
				continue;
			}
			if(subject<1||subject>3)
			{
				printf("请重新输入正确的数字\n");
				continue;
			}
			break;
		}
        
        
        
        int found = 0;
        for (int i = 0; i < count; i++) {
            if ((subject == 1 && students[i].math < 60) ||
                (subject == 2 && students[i].english < 60) ||
                (subject == 3 && students[i].PC < 60)) {
                printf("学号：%s 姓名：%s 数学：%d 英语：%d 计算机：%d 总分：%d\n",
                    students[i].number, students[i].name, students[i].math, students[i].english, students[i].PC, students[i].total);
                found = 1;
            }
        }
        if (!found) {
            printf("未找到该科目不及格的学生信息。\n");
        }
        break;
    }
    default:
        printf("输入有误，请重新选择！\n");
		findStudent();
    }
}

//5.排序

void lineStudents() {
    if (count == 0)
    {
        printf("目前没有学生信息，请添加学生信息后再试\n\n\n\n\n");
        return;
    }
	int a;
	while(1)
	{
	    printf("1. 按数学成绩排序\n");
	    printf("2. 按英语成绩排序\n");
	    printf("3. 按计算机成绩排序\n");
	    printf("4. 按总分排序\n");
		printf("0. 退出排序\n");
	    printf("请选择排序方式：");
	
		//解决输入为非数字导致错误
		if (scanf("%d", &a) != 1) //跟AI学的，scanf获取到获取失败返回0，正常获取返回1
		{
			printf("输入有误，请重新选择！\n");
			while (getchar() != '\n'); // 清空缓冲区,不太知道原理，ai写的，用着先
			continue;
		}
		if(a==0)
		{
			printf("退出成功\n");
			return;
		}
	    if (a < 1 || a > 4) 
		{
	        printf("输入有误，请重新选择！\n");
	        continue;
	    }
		break;
	}

    // 创建一个临时数组用于排序
    stu tempStudents[100];
    memcpy(tempStudents, students, sizeof(students));

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) 
		{
            int score1, score2;
            switch (a) 
			{
            case 1:
                score1 = tempStudents[j].math;
                score2 = tempStudents[j + 1].math;
                break;
            case 2:
                score1 = tempStudents[j].english;
                score2 = tempStudents[j + 1].english;
                break;
            case 3:
                score1 = tempStudents[j].PC;
                score2 = tempStudents[j + 1].PC;
                break;
            case 4:
                score1 = tempStudents[j].total;
                score2 = tempStudents[j + 1].total;
                break;
            }
            if (score1 < score2 || 
				(score1 == score2 && strcmp(tempStudents[j].number, tempStudents[j+1].number) > 0)) 
			{
				stu temp = tempStudents[j];
				tempStudents[j] = tempStudents[j + 1];
				tempStudents[j + 1] = temp;
            }
        }
    }

    printf("排序后的学生信息如下：\n");
    for (int i = 0; i < count; i++) {
        printf("学号：%s 姓名：%s 数学：%d 英语：%d 计算机：%d 总分：%d\n",
            tempStudents[i].number, tempStudents[i].name, tempStudents[i].math, tempStudents[i].english, tempStudents[i].PC, tempStudents[i].total);
    }
}


//6.统计
void statistics() {

    if (count == 0)
    {
        printf("目前没有学生信息，请添加学生信息后再试\n\n\n\n\n");
        return;//避免下边的除0错误
    }

    int mathPass = 0, englishPass = 0, PCPass = 0;
    int scoreRanges[5] = { 0 }; 
    
    for (int i = 0; i < count; i++) {
        if (students[i].math >= 60) mathPass++;
        if (students[i].english >= 60) englishPass++;
        if (students[i].PC >= 60) PCPass++;
        //students[i].total = students[i].math + students[i].english + students[i].PC;
		double avg = students[i].total / 3.0f;
		if (avg >= 0 && avg < 60) scoreRanges[0]++;
		else if (avg >= 60 && avg < 70) scoreRanges[1]++;
		else if (avg >= 70 && avg < 80) scoreRanges[2]++;
		else if (avg >= 80 && avg < 90) scoreRanges[3]++;
		else if (avg >= 90 && avg <= 100) scoreRanges[4]++;
    }
    printf("数学及格率：%d%%\n", mathPass * 100 / count);
    printf("英语及格率：%d%%\n", englishPass * 100 / count);
    printf("计算机及格率：%d%%\n", PCPass * 100 / count);
    printf("不同分数段学生人数：\n");
    printf("平均分0-59分：%d人\n", scoreRanges[0]);
    printf("平均分60-69分：%d人\n", scoreRanges[1]);
    printf("平均分70-79分：%d人\n", scoreRanges[2]);
    printf("平均分80-89分：%d人\n", scoreRanges[3]);
    printf("平均分90-100分：%d人\n", scoreRanges[4]);
}


//7.显示所有学生信息
void AllStudents() {

    if (count == 0)
    {
        printf("目前没有学生信息，请添加学生信息后再试\n\n\n\n\n");
        return;//避免除0错误
    }

    printf("所有学生信息如下：\n");
    for (int i = 0; i < count; i++) {
        printf("学号：%s 姓名：%s 数学：%d 英语：%d 计算机：%d 总分：%d\n", students[i].number, students[i].name, students[i].math, students[i].english, students[i].PC, students[i].total);
    }
}

int main() {
    int a;
	
    while (1) {
        menu();
        //解决输入为非数字导致错误
		if (scanf("%d", &a) != 1) //跟AI学的，scanf获取到不应该获取到的数返回0，正常获取返回1
		{
			printf("输入无效，请重新输入。\n");
			while (getchar() != '\n'); // 清空缓冲区
			continue;
		}
        switch (a) {
        case 1:
            addStudent();
            break;
        case 2:
            fixStudent();
            break;
        case 3:
            deleteStudent();
            break;
        case 4:
            findStudent();
            break;
        case 5:
            lineStudents();
            break;
        case 6:
            statistics();
            break;
        case 7:
            AllStudents();
            break;
        case 0:
            printf("退出系统！\n");
            return 0;
        default:
            printf("输入有误，请重新选择！\n");
        }
    }
    return 0;
}
