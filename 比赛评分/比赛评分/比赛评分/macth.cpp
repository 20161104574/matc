#include "head.h"
int main()
{
	while (1)
	{
		switch (menu_select())
		{
		case 1:
			t_output();
			break;
		case 2:
			s_output();
			break;
		case 3:
			mark();
			break;
		case 4:
			show();
			break;
		case 5:
			ranking();
			break;
		case 0:
			save();

			printf("谢谢使用！\n");
			system("pause");
			return 0;
		}
	}
}
//菜单模块
extern int menu_select()
{
	int MenuItem;
	printf("\n ");
	printf("         |-------欢迎使用打分系统-------  |          \n");
	printf("          |             菜单               |          \n");
	printf("          |	  1 --- 读取裁判信息       |          \n");
	printf("          |	  2 --- 读取选手信息	   |          \n");
	printf("          |	  3 --- 裁判打分     	   |          \n");
	printf("          |	  4 --- 选手成绩           |          \n");
	printf("          |	  5 --- 成绩排名           |          \n");
	printf("          |	  0 --- 退出系统           |          \n");
	do
	{
		printf("\n请输入选项（0－5）：");
		fflush(stdin);
		scanf("%d", &MenuItem);
	} while (MenuItem<0 || MenuItem>5);
	return MenuItem;
}
//读取裁判信息模块
extern void t_output()
{
	FILE *fp;
	int i;
	fp = fopen("jury.txt", "r");
	if (fp == NULL)
	{
		printf("文件打开失败！\n");
		exit(-1);
	}
	else
	{
		printf("姓名 性别 电话号码\n");
		for (i = 0; i < 5; i++)
			fscanf(fp, "%s %s %ld\n", &t[i].name, &t[i].sex, &t[i].num);
		for (i = 0; i < 5; i++)
			printf("%2s %3s %8ld\n", t[i].name, t[i].sex, t[i].num);
	}
	fclose(fp);
}
//读取选手信息模块
extern void s_output()
{
	FILE *fp;
	int i;
	fp = fopen("player.txt", "r");
	if (fp == NULL)
	{
		printf("文件打开失败！\n");
		exit(-1);
	}
	else
	{
		printf("序号 姓名   性别  节目名称 节目类别   班级    电话号码\n");
		for (i = 0; i < 6; i++)
			fscanf(fp, "%d %s %s %s  %s %s %ld\n", &s[i].snum, &s[i].name, &s[i].sex, &s[i].showname,  &s[i].showtype, &s[i].stuclass, &s[i].num);
		for (i = 0; i < 6; i++)
			printf("%3d %6s %4s %9s  %8s %6s %9ld\n", s[i].snum, s[i].name, s[i].sex, s[i].showname, s[i].showtype, s[i].stuclass, s[i].num);
	}
	fclose(fp);
}
//裁判打分模块
extern void mark()
{
	float grade[10];
	float sum;
	int i, j, n, x;
	float temp;
	for (n = 0; n < 6; n++)
	{
		printf("---请给第 %d 位选手打分---\n", s[n].snum);
		for (x = 0; x < 5; x++)
		{
			printf("请第 %d 位裁判打分:\n", x + 1);
			scanf("%f", &grade[x]);
		}
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (grade[j] > grade[j + 1])
				{
					temp = grade[j];
					grade[j] = grade[j + 1];
					grade[j + 1] = temp;
				}
			}
		}
		sum = 0;
		for (i = 1; i < 4; i++)
		{
			sum = sum + grade[i];
		}
		s[n].grade = sum / 3.0;
		printf("平均成绩：%.2f\n", s[n].grade);
	}
}
//显示选手成绩模块
extern void show()
{
	int i;
	printf("序号 姓名   性别  节目名称   节目类别   班级    电话号码  平均成绩\n");
	for (i = 0; i < 6; i++)
	{
		printf("%3d %6s %4s %9s %9s %10s %9ld %8.2f\n", s[i].snum, s[i].name, s[i].sex, s[i].showname,s[i].showtype, s[i].stuclass, s[i].num, s[i].grade);
	}
}
//显示选手排名模块
extern void ranking()
{
	int i, j;
	int x;
	struct Student t[100];
	struct Student temp;
	for (i = 0; i < 6; i++)
	{
		t[i] = s[i];
	}
	x = 6;
	a = x;
	for (i = 0; i < x - 1; i++)
	{
		for (j = 0; j < x - 1; j++)
		{
			if (s[j].grade < s[j + 1].grade)
			{
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}
	printf("序号 姓名   性别  节目名称 节目类别   班级    电话号码  平均成绩  排名\n");
	for (i = 0; i < x; i++)
	{
		printf("%3d %6s %4s %9s %8s %10s %9ld %8.2f %5d\n", s[i].snum, s[i].name, s[i].sex, s[i].showname,s[i].showtype, s[i].stuclass, s[i].num, s[i].grade, i + 1);
	}
}
//保存模块
int a;
extern void save()
{
	int i;
	FILE *fp;
	fp = fopen("show.txt", "w");
	if (fp == NULL)
	{
		printf("文件打开失败！\n");
		exit(-1);
	}
	else
	{
		for (i = 0; i<a; i++)
		{
			fprintf(fp, "%d %s %s %s %s %s %ld %.2f %d\n", s[i].snum, s[i].name, s[i].sex, s[i].showname, s[i].showtype, s[i].stuclass, s[i].num, s[i].grade, i + 1);
		}
	}
	fclose(fp);

}