//一个接口函数
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int cmp(const void* e1,const void* e2)
{
	return *(int*)e2 > *(int*)e1;
}
int third(int* nums,int number)
{
	qsort(nums, number, sizeof(nums[0]), cmp);
	int count = 1;
	for (int i = 0; i < number - 1; i++)
	{
		if (nums[i + 1] != nums[i])
		{
			count++;
		}
		if (count == 3)
		{
			return nums[i + 1];
		}
	}
	return nums[0];

}
