#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "二叉树的表示.h"

static int g_loop_num = 0;
//递归计算叶子结点的个数（先序遍历)
void get_TreeLeafNum(struct BinaryNode* node, int* num)
{
	//递归的退出条件
	if (node == NULL)
	{
		return;
	}
	g_loop_num++;
	//当左右结点都为空时，说明是叶子结点
	if (node->lchild == NULL && node->rchild == NULL)
	{
		(*num)++;
	}
	get_TreeLeafNum(node->lchild, num);
	get_TreeLeafNum(node->rchild, num);
	
}

//求出二叉树的高度
int getTreeHeight(struct BinaryNode* node)
{
	if (node == NULL)
	{
		return 0;
	}
	//求出左右子树的度
	int heightL = getTreeHeight(node->lchild);
	int heightR = getTreeHeight(node->rchild);
	//树的深度等于左右子树的度的最大值 再加一
	return heightL > heightR ? heightL + 1 : heightR + 1;//相等的时候返回后边的

}

//二叉树的复制(后续遍历）
	//实现思路，先copy某结点的左子树，再拷贝右子树，再挂在该结点上
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
//二叉树的遍历
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
//二叉树的释放(后续遍历）
void destroy_BinaryNode(struct BinaryNode* node)
{
	if (node == NULL)
	{
		return;
	}
	destroy_BinaryNode(node->lchild);
	destroy_BinaryNode(node->rchild);
	printf("%c被释放了\n", node->ch);
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

	//建立关系
	nodeA.lchild = &nodeB;
	nodeA.rchild = &nodeF;
	nodeB.rchild = &nodeC;
	nodeC.lchild = &nodeD;
	nodeC.rchild = &nodeE;
	nodeF.rchild = &nodeG;
	nodeG.lchild = &nodeH;
	//求树中叶子的数量
	int num = 0;
	get_TreeLeafNum(&nodeA, &num);
	printf("二叉树的叶子结点个数为: %d\n", num);
	printf("遍历执行的次数为：%d\n", g_loop_num);

	//求出二叉树的高度
	int height = getTreeHeight(&nodeA);
	printf("二叉树的深度为：%d\n", height);

	//二叉树的复制
	struct BinaryNode* newTree = copyBinaryTree(&nodeA);
	printf("new Tree is \n");
	show_BinaryNode(newTree);
	printf("\n");

	//二叉树的释放
	destroy_BinaryNode(newTree);

}