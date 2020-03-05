#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GameCompany.h"
#include <time.h>


//初始化游戏
typedef void(*INIT_GAME)(void** gameHandle, char* name);
//游戏战斗    返回游戏结果
typedef int(*FIGHT)(void* gameHandle, int level); //gameHandle代表一个人
//查看玩家信息
typedef void(*PRINT_GAME)(void* gameHandle);
//离开游戏
typedef void(*CLOSE_GAME)(void* gameHandle);

void playGame(INIT_GAME init, FIGHT fight, PRINT_GAME printGame, CLOSE_GAME closeGame)
{
	void* gameHandle = NULL;
	char name[64];
	int level = -1;
	printf("请输入玩家的姓名： \n");
	scanf("%s", name);
	init(&gameHandle, name);

	system("cls"); //换行符
	while (1)
	{
		getchar();
		system("cls");
		
		printf("请输入游戏的难度： \n");
		scanf("%d", &level);
		getchar();//把缓冲区的换行符都取走
		int ret = fight(gameHandle, level);
		if (ret == 0)
		{
			printf("挑战失败\n");
			break;
		}
		else
		{
			printf("挑战成功\n");

		}
		printGame(gameHandle);
	}
	
	
	//离开游戏
	closeGame(gameHandle);
}


int main()
{
	srand((unsigned int)time(NULL));
	playGame(init_Game, fight_Game, print_Game, close_Game);

}