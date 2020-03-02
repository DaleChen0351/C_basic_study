#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "二叉树的表示.h"
//之所以打印根结点，在于最后都要落脚到根结点上，才能得到数据，


void recursion(struct BinaryNode* node)
{
	if (node == NULL)
	{
		return;
	}
	//先序遍历
	printf("%c ", node->ch);
	recursion(node->lchild);
	recursion(node->rchild);
	

}
void test_01()
{
	struct BinaryNode nodeA = { 'A',NULL,NULL };
	struct BinaryNode nodeB = { 'B',NULL,NULL };
	struct BinaryNode nodeC = { 'C',NULL,NULL };
	struct BinaryNode nodeD = { 'D',NULL,NULL };
	struct BinaryNode nodeE = { 'E',NULL,NULL };
	struct BinaryNode nodeF = { 'F',NULL,NULL };
	struct BinaryNode nodeG = { 'G',NULL,NULL };
	struct BinaryNode nodeH = { 'H',NULL,NULL };

	//建立关系
	nodeA.lchild = &nodeB;
	nodeA.rchild = &nodeF;
	nodeB.rchild = &nodeC;
	nodeC.lchild = &nodeD;
	nodeC.rchild = &nodeE;

	nodeF.rchild = &nodeG;
	nodeG.lchild = &nodeH;

	recursion(&nodeA);

}

void recursion_tri(struct TribNode* node)
{
	if (node == NULL)
	{
		return;
	}
	//先序遍历
	printf("%c ", node->ch);
	if (node->parent == NULL)
	{
		printf(" 没有父节点\n");
	}
	else
	{
		printf(" 的父节点是%c\n", node->parent->ch);
	}
	recursion_tri(node->lchild);
	recursion_tri(node->rchild);
}
void test_02()
{
	struct TribNode nodeA = { 'A',NULL,NULL ,NULL};
	struct TribNode nodeB = { 'B',NULL,NULL ,NULL};
	struct TribNode nodeC = { 'C',NULL,NULL,NULL};
	struct TribNode nodeD = { 'D',NULL,NULL,NULL};
	struct TribNode nodeE = { 'E',NULL,NULL ,NULL};
	struct TribNode nodeF = { 'F',NULL,NULL ,NULL};
	struct TribNode nodeG = { 'G',NULL,NULL,NULL};
	struct TribNode nodeH = { 'H',NULL,NULL,NULL };

	//建立关系
	nodeA.lchild = &nodeB;
	nodeA.rchild = &nodeF;
	nodeB.rchild = &nodeC;
	nodeC.lchild = &nodeD;
	nodeC.rchild = &nodeE;
	nodeF.rchild = &nodeG;
	nodeG.lchild = &nodeH;
	//关联父节点
	nodeB.parent = &nodeA;
	nodeC.parent = &nodeB;
	nodeD.parent = &nodeC;
	nodeE.parent = &nodeC;
	nodeF.parent = &nodeA;
	nodeG.parent = &nodeF;
	nodeH.parent = &nodeG;

	recursion_tri(&nodeA);
}
//
//
//
//
//class ClassName
//
//
//	void TestFunName()
//{
//
//}
//int newNum;
//void swap()
//const int MAX_NUM = 0;