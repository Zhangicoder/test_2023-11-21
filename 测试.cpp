//将一个数组中的奇数放在左边，偶数放在右边
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void move_odd_even(int arr[10], int sz)
{
	int left = 0;
	int right = sz - 1;
	//寻找偶数
	while (left < right)
	{
		while ( arr[left] % 2 == 1)
		{
			left++;
		}
		//寻找奇数
		while ( arr[right] % 2 == 0)
		{
			right--;
		}
		if (left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
}
int main()
{
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		scanf("%d", &arr[i]);
	}
	move_odd_even(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}