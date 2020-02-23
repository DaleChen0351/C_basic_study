#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//节点的声明
//节点的声明
struct LinkNode
{
	int num;
	struct LinkNode* next;
};

//静态链表
void test_31()
{
	//创建节点

	//建立关系

	//遍历链表的节点


}

//动态链表
//分配内存
struct LinkNode** allocateNodeSpace(int len)
{
	struct LinkNode** temp = malloc(sizeof(struct LinkNode*)*len);
	for (int i = 0; i < len; i++)
	{
		temp[i] = malloc(sizeof(struct LinkNode));
		temp[i]->num = i + 1;
	}
	return temp;
}
//释放内存
void freeNodeSpace(struct LinkNode** p, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (p[i] != NULL)
		{
			free(p[i]);
			p[i] = NULL;
		}
	}
	free(p);
	p = NULL;
}
void test_32()
{
	struct LinkNode** pNodeArr= NULL;
	pNodeArr = allocateNodeSpace(5);
	//建立关系
	pNodeArr[0]->next = pNodeArr[1];
	pNodeArr[1]->next = pNodeArr[2];
	pNodeArr[2]->next = pNodeArr[3];
	pNodeArr[3]->next = pNodeArr[4];
	pNodeArr[4]->next = NULL;
	//打印
	struct LinkNode * currentNode = pNodeArr[0];
	while (currentNode != NULL)
	{
		printf("%d\n", currentNode->num);
		currentNode = currentNode->next;
	}
	//释放内存
	freeNodeSpace(pNodeArr,5);
	pNodeArr = NULL;
}
void main_03()
{
	test_32();
}