//一个接口函数
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, k;
	for (; scanf("%d %d", &n, &k) != EOF;);
	{	
		int a[n];
		for (int j = 1; j <= k; j++)
		{
			for (int i = 0; i < n; i++)
			{
				if ((i + 1) % j == 0)
				{
					a[i] = 1 - a[i];
				}
			}
		}
	}    
	return 0;
}
