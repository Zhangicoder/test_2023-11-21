//最基础的冒泡排序的写法
//冒泡排序的核心思想是一个数组中相邻两个元素的交换
//以下代码写的是升序排法
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void bubble_sort(int arr[], int sz)
{
	int i, j;
	for (i = 0; i < sz-1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0};
	int sz = sizeof(arr) /sizeof( arr[0]);
	bubble_sort(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}