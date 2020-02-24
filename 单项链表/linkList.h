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
//在特定数据前插入新数据
void insert_LinkList_C(struct LinkNode* pHeader, int oldVal, int newVal);
//删除链表
void remove_LinkList_C(struct LinkNode* pHeader, int val);
//清空链表
void clear_LinkList_C(struct LinkNode* pHeader);
//销毁链表
void destroy_LinkList(struct LinkNode* pHeader);


//remove_if
