#pragma once
#include "dynamicArray.h" 

#define MAX 1024
typedef void* SeqQueue;

//初始化队列
SeqQueue init_SeqQueue();

//入队
void push_SeqQueue(SeqQueue sq, void* data);

//出队
void pop_SeqQueue(SeqQueue sq);

//返回front
void* front_SeqQueue(SeqQueue sq);

//返回back
void* back_SeqQueue(SeqQueue sq);

//返回队伍大小
int size_SeqQueue(SeqQueue sq);

//销毁
void destroy_SeqQueue(SeqQueue sq);