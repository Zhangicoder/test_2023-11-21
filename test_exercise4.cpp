#define _CRT_SECURE_NO_WARNINGS
//实现一个函数，可以左旋字符串中的k个字符
#include <stdio.h>
#include<string.h>
void left_rotate(char arr[], int k)
{
	int i = 0;
	int j = 0;
	int len = strlen(arr);
	for (i = 0; i < k; i++)
	{
		int tmp = arr[0];
		for ( j = 0; j < len - 1; j++)
		{
			arr[j] = arr[j+1];
		}
		arr[j] = tmp;
	}
}
int main()
{
	char arr[] = "abcdef";
	int k = 0;
	scanf("%d", &k);
	left_rotate(arr,k);
	printf("%s\n", arr);
    return 0;
}