#define _CRT_SECURE_NO_WARNINGS
#include "game2.h"

void menu()
{
    printf("******************\n");
    printf("****  1.play  ****\n");
    printf("****  0.exit  ****\n");
    printf("******************\n");
}
void game()
{
    //存放布置好的雷的信息
    char mine[ROWS][COLS];
    //存放排查出的雷的信息
    char show[ROWS][COLS];
    //初始化数组的内容为制定的内容
    //mine 数组在没有布置雷的时候，都是'0'
    InitBoard(mine, ROWS, COLS, '0');
    //show数组在没有排查雷的时候，都是'*'
    InitBoard(show, ROWS, COLS, '*');

    //设置雷
    SetMine(mine, ROW, COL);
    //打印
    //DisplayBoard(mine, ROW, COL);
    
    DisplayBoard(show, ROW, COL);

    FindMine(mine, show, ROW, COL);

}

int main()
{
    int input = 0;
    //设置随机数的生成起点
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("选择错误，请重新选择\n");
            break;
        }
    } while (input);
    return 0;
}