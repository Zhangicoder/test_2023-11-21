#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct point
{
	int x;
	int y;
};
struct point find_num(int arr[3][3],int r,int c,int k)
{
	int x = 0;
	int y = c - 1;
	struct point p = { 1,-1 };
	while (x <= r - 1 && y >= 0)
	{
		if (k < arr[x][y])
			y--;
		else if (k > arr[x][y])
			x++;
		else {
			p.x = x+1;
			p.y = y+1;
			return p;
		}
	}
	return p;
}
int main()
{
	int k;
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	scanf("%d", &k);
	struct point ret = find_num(arr, 3, 3, k);
	if (ret.y != -1)
		printf("在第%d行 第%d列\n", ret.x, ret.y);
	else
		printf("找不到");
	return 0;
}