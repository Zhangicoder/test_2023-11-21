//用函数指针数组改进计算器代码
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void menu()
{
	printf("************************\n");
	printf("*** 1.add  2.sub   *****\n");
	printf("*** 3.mul  4.div   *****\n");
	printf("*** 0.exit  ************\n");
	printf("************************\n");
}
int add(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}
int mul(int x, int y)
{
	return x * y;
}
int div(int x, int y)
{
	return x / y;
}

int main()
{
	int input;
	int x, y, ret;
	do
	{
		menu();
		printf("请选择>");
		scanf("%d", &input);
		int (*pfarr[5])(int, int) = { 0,add,sub,mul,div };
		if (input == 0)
		{
			printf("退出计算器\n");
		}
		else if (input >= 1&&input<=4)
		{
			printf("请输入两个操作数>");
			scanf("%d %d", &x, &y);
			ret = pfarr[input](x, y);
			printf("%d\n",ret);
		}
		else
		{
			printf("选择错误\n");
		}
		
	} while (input);
}
