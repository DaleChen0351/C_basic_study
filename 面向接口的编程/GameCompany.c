#include "GameCompany.h"


int isWin(int winRate, int level)
{
	int random = rand() % 100 + 1;//得到的是1-100；
	if (winRate > random)
	{
		//胜利
		return 10 * level;
	}
	else
	{
		//失败
		return 0;
	}
}

//初始化游戏
void init_Game(void** gameHandle, char* name)
{
	struct Player* player = malloc(sizeof(struct Player));
	player->exp = 0;
	player->level = 0;
	strcpy(player->name, name);
	*gameHandle = player;
}
//游戏战斗    返回游戏结果
int fight_Game(void* gameHandle, int level)
{
	struct Player* player = gameHandle;
	int addExp;
	switch (level)
	{
	case 1:
		addExp = isWin(90, 1);
		break;
	case 2:
		addExp = isWin(60, 2);
	case 3:
		addExp = isWin(30, 3);
	default:
		break;
	}
	if (addExp != 0)
	{
		player->exp += addExp;
		player->level = player->exp / 10;
		return 1;
	}
	return 0;
}
//查看玩家信息
void print_Game(void* gameHandle)
{
	if (gameHandle == 0)
	{
		return;
	}
	struct Player* player = gameHandle;
	printf("name = %s,  level = %d,   exp = %d\n", player->name, player->level, player->exp);
}
//离开游戏
void close_Game(void* gameHandle)
{
	if (gameHandle == 0)
	{
		return;
	}
	free(gameHandle);
	gameHandle = NULL;
}