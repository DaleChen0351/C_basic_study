#pragma once

typedef void* LinkQueue;
// 队列的节点
struct QueueNode
{
	struct QueLQueueueNode* next;
};
//链式实现的队列的结构体
struct LQueue
{
	//头结点
	struct QueueNode m_header;
	//队列大小
	int m_size;
	//维护尾结点的指针
	struct QueueNode* pTail;
};

//初始化
LinkQueue init_LinkQueue();

//从尾部入队
void push_LinkQueue(LinkQueue lq, void* data);

//从头部出队
void pop_LinkQueue(LinkQueue lq);

//返回头部元素指针
void* front_LinkQueue(LinkQueue lq);

//返回尾部元素指针
void* back_LinkQueue(LinkQueue lq);

//返回队伍大小
int size_LinkQueue(LinkQueue lq);

//销毁
void destroy_LinkQueue(LinkQueue lq);