//一个接口函数
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//size_t my_strlen(const char* str)
//{
//	size_t count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	size_t n = my_strlen(arr);
//	printf("%u\n", n);
//	return 0;
//}
void my_strcpy(char* p2,const char* p1)
{
	assert(p2);
	assert(p1);
	while (*p1)
	{
		*p2++ = *p1++;
	}
	*p2 = *p1;
}
int main()
{
	char arr1[] = "abcdef";
	char arr2[20] = { 0 };
	my_strcpy(arr2, arr1);
	printf("%s\n", arr2);
	return 0;
}