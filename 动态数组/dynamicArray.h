#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// struct
struct dynamicArray
{
	void** pAddr;
	int m_capacity;
	int m_size;
};

//��ʼ����̬����
struct dynamicArray* init_DynamicArray(int capacity);

//����Ԫ��
void insert_dynamicArray(struct dynamicArray* arr, int pos, void* data);

// ������̬����
void for_each_dynamicArray(struct dynamicArray* arr, void(*myprint)(void*));

// ����λ��ɾ�������е�Ԫ��
void removeByPos_dynamicArray(struct dynamicArray* arr, int pos);

// ����ֵɾ�������е�Ԫ��
void removeByValue_dynamicArray(struct dynamicArray* arr, struct Person* data, int(*mycompare)(void*, void*));

// ��������
void destory_dynamicArray(struct dynamicArray* arr);

