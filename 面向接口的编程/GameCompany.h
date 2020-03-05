#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Player
{
	char name[64];
	int level;
	int exp;
};


//��ʼ����Ϸ
 void init_Game(void** gameHandle, char* name);
//��Ϸս��    ������Ϸ���
 int fight_Game(void* gameHandle, int level);
//�鿴�����Ϣ
void print_Game(void* gameHandle);
//�뿪��Ϸ
typedef void(*CLOSE_GAME)(void* gameHandle);
void close_Game(void* gameHandle);
