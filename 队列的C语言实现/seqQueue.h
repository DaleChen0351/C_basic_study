#pragma once
#include "dynamicArray.h" 

#define MAX 1024
typedef void* SeqQueue;

//��ʼ������
SeqQueue init_SeqQueue();

//���
void push_SeqQueue(SeqQueue sq, void* data);

//����
void pop_SeqQueue(SeqQueue sq);

//����front
void* front_SeqQueue(SeqQueue sq);

//����back
void* back_SeqQueue(SeqQueue sq);

//���ض����С
int size_SeqQueue(SeqQueue sq);

//����
void destroy_SeqQueue(SeqQueue sq);