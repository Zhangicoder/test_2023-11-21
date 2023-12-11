#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

#define N 10
#define M 3
#define SIZE 100
typedef struct student
{
	long id;
	int score[M];
}STUDENT;
void menu();
int readdata(STUDENT stu[], int grade[]);//读入平时成绩和期末卷面成绩
void compute(int* max, int* min, double* pass, double ave[], double f[]
	, STUDENT stu[], int sum);//计算成绩统计数据
void showgrade(STUDENT stu[], int sum, int grade[]);//显示成绩分段人数C
//输出统计信息
void showstatistics(int max, int min, double pass, double ave[], double f[]);
int main()
{
	int input;
	int sum, max, min;
	double pass = 0;
	int grade[11] = { 0 };
	STUDENT stu[SIZE];
	double ave[SIZE], f[SIZE];
	do {
		menu();
		printf("请选择>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			sum = readdata( stu,grade );
			break;
		case 2:
			compute(&max, &min, &pass, ave, f, stu, sum);
			break;
		case 3:
			showgrade(stu, sum, grade);
			break;
		case 4:
			showstatistics(max, min, pass, ave, f);
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("选择错误，请重新选择>\n");
			break;
		}
	} while (input);
	return 0;
}
void menu()
{
	printf("******************************\n");
	printf("**   1.读入成绩数据     ******\n");
	printf("**   2.计算成绩统计信息 ******\n");
	printf("**   3.显示成绩分段人数 ******\n");
	printf("**   4.显示统计信息     ******\n");
	printf("**   0.退出             ******\n");
	printf("******************************\n");
}
int readdata(STUDENT stu[], int grade[])
{
	grade[10] = { 0 };
	FILE* pf;
	pf = fopen("a.txt", "r");
	int i = 0;
	int sum	= 0;//人数
	int temp;//计算总评成绩
	int a1, a2;//成绩计算比例
	bool flag;//判断成绩是否有效
	printf("请输入平时成绩和期末成绩的比例\n");
	fscanf(pf,"%d %d", &a1, &a2);
	printf("请输入学号和姓名：\n");
	while (i < SIZE && !feof(pf))
	{
		fscanf(pf, "%d", &stu[i].id);
		sum++;
		flag = true;
		while(flag) {
			fscanf(pf, "%d%d", &stu[i].score[0], &stu[i].score[1]);
			if (stu[i].score[0] <= 100 && stu[i].score[0] >= 0
				, stu[i].score[1] <= 100 && stu[i].score[1] >= 0)
			{
				flag = false;
			}
			else
			{
				printf("\007 错误数据，请再次输入学生平时成绩和期末成绩");
			}
		}
		//计算总评成绩
		temp = (int)(1.0 * a1 / 100 * stu[i].score[0] + 1.0 * a2 / 100 * stu[i].score[1]);
		stu[i].score[2] = temp;
		//按照总评成绩统计分数段情况
		temp = (stu[i].score[2]) / 10;
		if (temp == 10)
			grade[10]++;//100分
		else
			grade[temp]++;
		i++;
	}
	fclose(pf);
	printf("读取了%d份成绩\n", sum);
	return sum;
}
void compute(int* max, int* min, double* pass, double ave[], double f[], STUDENT stu[], int sum)
{
	int i, j;
	int passsum = 0;
	double total[3];
	double temp;
	*max = *min = stu[0].score[2];
	if (stu[0].score[2] >= 60)
	{
		passsum++;
	}
	for (i = 1; i < sum; i++)
	{
		//找最大值
		if (stu[i].score[2] > *max)
		{
			*max = stu[i].score[2];
		}
		//找最小值
		if (stu[i].score[2] < *min)
		{
			*min = stu[i].score[2];
		}
		if (stu[i].score[2] >= 60)
		{
			passsum++;
		}
	}
	*pass = (1.0 * passsum / sum) * 100;//及格率
	//求平时成绩，期末成绩和总评成绩的平均分
	//初始化为0
	for (i = 0; i < 3; i++)
	{
		total[i] = 0;
	}
	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < sum; i++)
		{
			total[j] =total[j]+stu[i].score[j];
		}
	}
	for (j = 0; j < 3; j++)
	{
		ave[j] = total[j] / sum;
	}
	//求平时成绩，期末成绩，总成绩的标准差
	for (j = 0; j < 3; j++)
	{
		f[j] = 0;
		for (i = 0; i < sum; i++)
		{
			temp = stu[i].score[j] - ave[j];
			f[j] = f[j] + temp * temp;
		}
		f[j] = sqrt(fabs(f[j] / sum));
	}
}
void showgrade(STUDENT stu[], int sum, int grade[])
{
	int i, j;
	//输出学生的学号，平时成绩，期末成绩和总评成绩
	for (i = 0; i < sum; i++)
	{
		printf("%4d", stu[i].id);
		for (j = 0; j < M; j++)
		{
			printf("%4d", stu[i].score[j]);
		}
		printf("\n");
	}
	//显示成绩分段S
	for (i = 10; i >= 1; i--)
	{
		printf("grade %2d: %d \n", i, grade[i]);
	}
}
void showstatistics(int max, int min, double pass, double ave[], double f[])
{
	int j;
	char str1[3][25] = { "average","final grade average","overall grade average" };
	char str2[3][25] = { "sd of normal grade","sd of final grade","sd of overall grade"};
	printf("\n及格率 = %6.2f 最高分 = %d 最低分 = %d\n ", pass, max, min);
	for (j = 0; j < 3; j++)
	{
		printf("\n%s = %6.2f %s = %6.2f\n", str1[j], ave[j], str2[j], f[j]);
	}
}