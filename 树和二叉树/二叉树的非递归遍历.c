//二叉树的非递归遍历
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "二叉树的表示.h"
#include "seqlist.h"




void test_21()
{
	struct BinaryNode_2 nodeA = { 'A',NULL,NULL,0 };
	struct BinaryNode_2 nodeB = { 'B',NULL,NULL ,0};
	struct BinaryNode_2 nodeC = { 'C',NULL,NULL ,0};
	struct BinaryNode_2 nodeD = { 'D',NULL,NULL ,0};
	struct BinaryNode_2 nodeE = { 'E',NULL,NULL ,0};
	struct BinaryNode_2 nodeF = { 'F',NULL,NULL ,0};
	struct BinaryNode_2 nodeG = { 'G',NULL,NULL ,0};
	struct BinaryNode_2 nodeH = { 'H',NULL,NULL ,0};

	//建立关系
	nodeA.lchild = &nodeB;
	nodeA.rchild = &nodeF;
	nodeB.rchild = &nodeC;
	nodeC.lchild = &nodeD;
	nodeC.rchild = &nodeE;

	nodeF.rchild = &nodeG;
	nodeG.lchild = &nodeH;

	//建立遍历二叉树的辅助栈
	SeqStack* stack = init_SeqStack();

	push_SeqStack(stack, &nodeA);
	while (!isEmpty_SeqStack(stack))
	{
		struct BinaryNode_2* topNode = pop_SeqStack(stack);
		
		if (topNode->state)
		{
			printf("%c ", topNode->ch);
			
			continue;
		}
		else
		{
			topNode->state = 1;
			//入栈（先序遍历）
			push_SeqStack(stack, topNode->rchild);
			push_SeqStack(stack, topNode->lchild);
			push_SeqStack(stack, topNode);
		}
	}
	destroy_SeqStack(stack);
	stack = NULL;
}

