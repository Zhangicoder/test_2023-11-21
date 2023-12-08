#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main()
{
    int input;
    int sum = 0;
    int i = 0;
    scanf("%d", &input);
    while (input)
    {
        int bit = input % 10;
        if (bit % 2 == 1)
        {
            bit = 1;
        }
        else
        {
            bit = 0;
        }
        sum += bit * pow(10, i);
        i++;
        input /= 10;
    }
    printf("%d\n", sum);
    return 0;
}