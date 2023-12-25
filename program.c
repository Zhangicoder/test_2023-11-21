#include"program.h"
int setplayeramount(int num)
{
	printf("请输入选手人数:>");
	scanf("%d", &num);
	return num;
}
int setjudgeamount(int num)
{
	printf("请输入评委人数:>");
	scanf("%d", &num);
	return num;
}
void scoreing(player* p, judge* pj, int player_num, int judge_num)
{
	for (int j = 0; j < judge_num; j++)
	{
		printf("请分别输入评委的ID:>");
		scanf("%s", &pj[j].ID);
	}
	for (int i = 0; i < player_num; i++)
	{
		printf("\nplayer %d is singing\n", i+1);
		printf("please enter his ID:");
		scanf("%s", p[i].ID);
		printf("please enter his name:");
		scanf("%s", p[i].name);
		float sum = 0,max=0,min=10;
		printf("\nscoring...\n");
		for (int j = 0; j < judge_num; j++)
		{
			printf("judge %s gives score:", pj[j].ID);
			scanf("%f", &(pj[j].scores));
			p[i].score[j] = pj[j].scores;
			sum += pj[j].scores;
			if (pj[j].scores > max)
			{
				max = pj[j].scores;
			}
			if (pj[j].scores < min)
			{
				min = pj[j].scores;
			}
		}
		sum = sum - max - min;
		p[i].scores = sum / (judge_num-2);
		printf("\ncomputing...\n");
		printf("delete a maximum score:%f\n", max);
		printf("delete a minimum score:%f\n", min);
		printf("\nfinal score...\n");
		printf("The final socre of player %d is %.3f\n", i + 1, p[i].scores);
	}
}
int cmp_struct_byscores(const void* e1,const void* e2)
{
	return (((player*)e2)->scores) - (((player*)e1)->scores);
}
void player_ranking(player* p, int num)
{
	int i, j;
	qsort(p, num, sizeof(player), cmp_struct_byscores);
	printf("order of players:\n");
	printf("order\tfinal score\tID\n"); 
	for (i = 0; i < num; i ++ )
	{
		printf("%d\t%.3f\t       %s\n",i+1,p[i].scores,p[i].ID);
	}
}
//计算评委评分水准
void computejudge(player* p,judge* pj,int player_num,int judge_num)
{
	int i, j;
	for (i = 0; i < judge_num; i++)
	{
		float sum = 0;
		for (j = 0; j < player_num; j++)
		{
			sum += pow((p[j].score[i] - p[j].scores), 2);
		}
		pj[i].pf = 10 - sqrt(sum / player_num);
	}
}
int cmp_struct_bypf(const void* e1,const void* e2)
{
	return (((judge*)e2)->pf) - (((judge*)e1)->pf);
}
void judgeranking(player* p, judge* pj, int player_num,int judge_num)
{
	computejudge(p, pj, player_num, judge_num);
	//排序
	qsort(pj, judge_num, sizeof(judge), cmp_struct_bypf);
	printf("order of judges:\n");
	printf("order\tranking\tID\n");
	int i = 0;
	for (i = 0; i < judge_num; i++)
	{
		printf("%d\t%.3f\t%s\n", i + 1, pj[i].pf, pj[i].ID);
	}
}
void awarding(player *p,int num)
{
	int max = 0;
	char name[20];
	for (int i = 0; i < num; i++)
	{
		if (p[i].scores > max)
		{
			strcpy(name, p[i].name);
		}
	}
	char arr[6][50];
	FILE* pf = fopen("youwin.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	for (int i = 0;i < 6; i++)
	{
		fscanf(pf, "%s", arr+i);
		printf("%s\n", arr + i);
	}
	printf("-----------------------------\n");
	printf("	Champion\n");
	printf("-----------------------------\n");
	printf("      %s\n", name);
	fclose(pf);
	pf = NULL;
}