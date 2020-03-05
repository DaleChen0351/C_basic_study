#include "GameCompany.h"


int isWin(int winRate, int level)
{
	int random = rand() % 100 + 1;//�õ�����1-100��
	if (winRate > random)
	{
		//ʤ��
		return 10 * level;
	}
	else
	{
		//ʧ��
		return 0;
	}
}

//��ʼ����Ϸ
void init_Game(void** gameHandle, char* name)
{
	struct Player* player = malloc(sizeof(struct Player));
	player->exp = 0;
	player->level = 0;
	strcpy(player->name, name);
	*gameHandle = player;
}
//��Ϸս��    ������Ϸ���
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
//�鿴�����Ϣ
void print_Game(void* gameHandle)
{
	if (gameHandle == 0)
	{
		return;
	}
	struct Player* player = gameHandle;
	printf("name = %s,  level = %d,   exp = %d\n", player->name, player->level, player->exp);
}
//�뿪��Ϸ
void close_Game(void* gameHandle)
{
	if (gameHandle == 0)
	{
		return;
	}
	free(gameHandle);
	gameHandle = NULL;
}