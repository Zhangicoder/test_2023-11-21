#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int a[5][5];
	int i, j;
	int sum = 0;
	srand((unsigned int)time(NULL));
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			a[i][j] = rand() % 10 + 1;
		}
	}
	printf("随机生成的数组为：\n");
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%2d ", a[i][j]);
			if (j == 4)
			{
				printf("\n");
			}
		}
	}
	printf("\n");
	sum = a[0][0] + a[1][1] + a[2][2] + a[3][3] + a[4][4] + a[0][4] + a[1][3] + a[3][1] + a[4][0];
	printf("和为：%d\n", sum);
	return 0;
}