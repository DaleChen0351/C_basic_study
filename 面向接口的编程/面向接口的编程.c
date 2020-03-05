#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GameCompany.h"
#include <time.h>


//��ʼ����Ϸ
typedef void(*INIT_GAME)(void** gameHandle, char* name);
//��Ϸս��    ������Ϸ���
typedef int(*FIGHT)(void* gameHandle, int level); //gameHandle����һ����
//�鿴�����Ϣ
typedef void(*PRINT_GAME)(void* gameHandle);
//�뿪��Ϸ
typedef void(*CLOSE_GAME)(void* gameHandle);

void playGame(INIT_GAME init, FIGHT fight, PRINT_GAME printGame, CLOSE_GAME closeGame)
{
	void* gameHandle = NULL;
	char name[64];
	int level = -1;
	printf("��������ҵ������� \n");
	scanf("%s", name);
	init(&gameHandle, name);

	system("cls"); //���з�
	while (1)
	{
		getchar();
		system("cls");
		
		printf("��������Ϸ���Ѷȣ� \n");
		scanf("%d", &level);
		getchar();//�ѻ������Ļ��з���ȡ��
		int ret = fight(gameHandle, level);
		if (ret == 0)
		{
			printf("��սʧ��\n");
			break;
		}
		else
		{
			printf("��ս�ɹ�\n");

		}
		printGame(gameHandle);
	}
	
	
	//�뿪��Ϸ
	closeGame(gameHandle);
}


int main()
{
	srand((unsigned int)time(NULL));
	playGame(init_Game, fight_Game, print_Game, close_Game);

}