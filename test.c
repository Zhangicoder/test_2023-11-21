#include"program.h"
void menu()
{
	printf("************************************\n");
	printf("****  1.set contestant amount ******\n");
	printf("****  2.set judge amount ***********\n");
	printf("****  3.scoreing *******************\n");
	printf("****  4.player ranking *************\n");
	printf("****  5.judge ranking  *************\n");
	printf("****  6.awarding   *****************\n");
	printf("****  0.exit      ******************\n");
	printf("************************************\n");
}
int main()
{
	int judge_num = 5;//评委的默认人数
	int player_num = 5;//选手的默认人数
	judge judger[5];
	player play[5];
	int input;
	do {
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			player_num = setplayeramount(player_num);
			break;
		case 2:
			judge_num = setjudgeamount(judge_num);
			break; 
		case 3:
			scoreing(play, judger,player_num,judge_num);
			break;
		case 4:
			player_ranking(play,player_num);
			break;
		case 5:
			judgeranking(play,judger,player_num,judge_num);
			break;
		case 6:
			awarding(play,player_num);
			break;
		case 0:
			printf("程序退出\n");
			break;
		default:
			printf("选择错误,请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}