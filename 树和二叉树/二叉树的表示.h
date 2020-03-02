#pragma once
//二叉链表示法，一般从根结点开始存储。相应的，访问树中的结点时也只能从根开始
struct BinaryNode
{
	char ch;
	struct BinaryNode* lchild;
	struct BinaryNode* rchild;
};
//三叉链表示法
//每个结点有三个指针域，其中两个分别指向左孩子和右孩子，还有一个指向该结点的父节点
struct TribNode
{
	char ch;
	struct TribNode* lchild;
	struct TribNode* rchild;
	struct TribNode* parent;
};
//二叉树的非递归遍历
struct BinaryNode_2
{
	char ch;
	struct BinaryNode_2* lchild;
	struct BinaryNode_2* rchild;
	unsigned int state;
};
