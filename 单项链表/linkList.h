#pragma once


//节点的声明
struct LinkNode
{
	int num;
	struct LinkNode *next;
};

//初始化链表
struct LinkNode* init_LinkList_C();
//遍历链表
void foreach_LinkList_C(struct LinkNode* pH);
