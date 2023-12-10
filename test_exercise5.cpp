#define _CRT_SECURE_NO_WARNINGS
//实现一个函数，可以左旋字符串中的k个字符
//第二种写法
#include <stdio.h>
#include<string.h>
#include<assert.h>
void reverse(char* left, char* right)
{
	assert(left && right);
	while (left < right) {
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_rotate(char arr[], int k)
{
	int len = strlen(arr);
	k%=len;
	//逆序左边
	reverse(arr, arr + k - 1);
	//逆序右边
	reverse(arr + k, arr + len - 1);
	//逆序整个字符串
	reverse(arr, arr + len - 1);

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
