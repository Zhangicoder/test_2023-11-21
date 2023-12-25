#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct player
{
	char ID[20];
	char name[20];
	float score[20];
	float scores;
}player;

typedef struct judge
{
	char ID[20];
	float scores;
	float pf;
}judge;
//设置选手人数
int setplayeramount(int num);
//设置参赛人数
int setjudgeamount(int num);
//评委给某位选手打分
void scoreing(player* p,judge* pj,int player_num,int judge_num);
//选手排名
void player_ranking(player* p, int num);
//评委排名
void judgeranking(player* p, judge* pj, int player_num, int judge_num);
//给冠军颁奖
void awarding(player* p,int num);
