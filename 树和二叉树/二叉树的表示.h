#pragma once
//��������ʾ����һ��Ӹ���㿪ʼ�洢����Ӧ�ģ��������еĽ��ʱҲֻ�ܴӸ���ʼ
struct BinaryNode
{
	char ch;
	struct BinaryNode* lchild;
	struct BinaryNode* rchild;
};
//��������ʾ��
//ÿ�����������ָ�������������ֱ�ָ�����Ӻ��Һ��ӣ�����һ��ָ��ý��ĸ��ڵ�
struct TribNode
{
	char ch;
	struct TribNode* lchild;
	struct TribNode* rchild;
	struct TribNode* parent;
};
//�������ķǵݹ����
struct BinaryNode_2
{
	char ch;
	struct BinaryNode_2* lchild;
	struct BinaryNode_2* rchild;
	unsigned int state;
};
