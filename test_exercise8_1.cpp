//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int is_left_move(char arr1[], char arr2[])
{
	int len = strlen(arr1);
	for(int i=0;i<len;i++)
	{
		char tmp = arr1[0];
		int j = 0;
		for (j = 0; j < len - 1; j++)
		{
			arr1[j] = arr1[j + 1];
		}
		arr1[len - 1] = tmp;
		if (strcmp(arr2, arr1) == 0)
			return 1;
	}
	return 0;
}
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "efabcd";
	int ret = is_left_move(arr1, arr2);
	if (ret == 1)
		printf("ok\n");
	else
		printf("no\n");
	return 0;
}