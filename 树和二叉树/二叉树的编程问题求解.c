#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "�������ı�ʾ.h"

static int g_loop_num = 0;
//�ݹ����Ҷ�ӽ��ĸ������������)
void get_TreeLeafNum(struct BinaryNode* node, int* num)
{
	//�ݹ���˳�����
	if (node == NULL)
	{
		return;
	}
	g_loop_num++;
	//�����ҽ�㶼Ϊ��ʱ��˵����Ҷ�ӽ��
	if (node->lchild == NULL && node->rchild == NULL)
	{
		(*num)++;
	}
	get_TreeLeafNum(node->lchild, num);
	get_TreeLeafNum(node->rchild, num);
	
}

//����������ĸ߶�
int getTreeHeight(struct BinaryNode* node)
{
	if (node == NULL)
	{
		return 0;
	}
	//������������Ķ�
	int heightL = getTreeHeight(node->lchild);
	int heightR = getTreeHeight(node->rchild);
	//������ȵ������������Ķȵ����ֵ �ټ�һ
	return heightL > heightR ? heightL + 1 : heightR + 1;//��ȵ�ʱ�򷵻غ�ߵ�

}

//�������ĸ���(����������
	//ʵ��˼·����copyĳ�������������ٿ������������ٹ��ڸý����
struct BinaryNode* copyBinaryTree(struct BinaryNode* node)
{
	if (node == NULL)
	{
		return NULL;
	}
	struct BinaryNode* leftNode = copyBinaryTree(node->lchild);
	struct BinaryNode* RightNode = copyBinaryTree(node->rchild);

	struct BinaryNode* newNode = malloc(sizeof(struct BinaryNode));
	newNode->lchild = leftNode;
	newNode->rchild = RightNode;

	newNode->ch = node->ch;
	return newNode;
}
//�������ı���
void show_BinaryNode(struct BinaryNode* node)
{
	if (node == NULL)
	{
		return;
	}
	printf("%c ", node->ch);
	show_BinaryNode(node->lchild);
	show_BinaryNode(node->rchild);
}
//���������ͷ�(����������
void destroy_BinaryNode(struct BinaryNode* node)
{
	if (node == NULL)
	{
		return;
	}
	destroy_BinaryNode(node->lchild);
	destroy_BinaryNode(node->rchild);
	printf("%c���ͷ���\n", node->ch);
	free(node);
}


void test_11()
{
	struct BinaryNode nodeA = { 'A',NULL,NULL };
	struct BinaryNode nodeB = { 'B',NULL,NULL };
	struct BinaryNode nodeC = { 'C',NULL,NULL };
	struct BinaryNode nodeD = { 'D',NULL,NULL };
	struct BinaryNode nodeE = { 'E',NULL,NULL };
	struct BinaryNode nodeF = { 'F',NULL,NULL };
	struct BinaryNode nodeG = { 'G',NULL,NULL };
	struct BinaryNode nodeH = { 'H',NULL,NULL };

	//������ϵ
	nodeA.lchild = &nodeB;
	nodeA.rchild = &nodeF;
	nodeB.rchild = &nodeC;
	nodeC.lchild = &nodeD;
	nodeC.rchild = &nodeE;
	nodeF.rchild = &nodeG;
	nodeG.lchild = &nodeH;
	//������Ҷ�ӵ�����
	int num = 0;
	get_TreeLeafNum(&nodeA, &num);
	printf("��������Ҷ�ӽ�����Ϊ: %d\n", num);
	printf("����ִ�еĴ���Ϊ��%d\n", g_loop_num);

	//����������ĸ߶�
	int height = getTreeHeight(&nodeA);
	printf("�����������Ϊ��%d\n", height);

	//�������ĸ���
	struct BinaryNode* newTree = copyBinaryTree(&nodeA);
	printf("new Tree is \n");
	show_BinaryNode(newTree);
	printf("\n");

	//���������ͷ�
	destroy_BinaryNode(newTree);

}