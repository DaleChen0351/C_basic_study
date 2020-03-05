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


//初始化游戏
 void init_Game(void** gameHandle, char* name);
//游戏战斗    返回游戏结果
 int fight_Game(void* gameHandle, int level);
//查看玩家信息
void print_Game(void* gameHandle);
//离开游戏
typedef void(*CLOSE_GAME)(void* gameHandle);
void close_Game(void* gameHandle);
