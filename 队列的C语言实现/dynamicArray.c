#include "dynamicArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//��ʼ����̬����
struct dynamicArray* init_DynamicArray(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}
	// �����ڴ�ռ�
	struct dynamicArray* arr = malloc(sizeof(struct dynamicArray));
	if (NULL == arr)
	{
		return NULL;
	}
	// ��������
	arr->m_capacity = capacity;
	// ���ô�С
	arr->m_size = 0;
	// ά���ڶ��������ָ�� �׵�ַ
	arr->pAddr = malloc(sizeof(void*) * arr->m_capacity);
	return arr;
}
//����Ԫ��
void insert_dynamicArray(struct dynamicArray* arr, int pos, void* data)
{
	if (arr == NULL || data == NULL)
	{
		return;
	}
	//pos
	if (pos < 0 || pos > arr->m_size) // ��pos == arr->size �൱����β��
	{
		//��Ч��λ�� β��
		pos = arr->m_size;
	}
	// �ж��Ƿ����أ���Ҫ����
	if (arr->m_capacity <= arr->m_size)
	{
		int newCapacity = arr->m_capacity * 2;
		void** newSpace = malloc(sizeof(void*) * newCapacity);

		memcpy(newSpace, arr->pAddr, sizeof(void*)*arr->m_capacity);

		free(arr->pAddr);
		//Update capacity
		arr->m_capacity = newCapacity;
		//Update pAddr
		arr->pAddr = newSpace;
	}
	// ����Ԫ��
	//�����һ��λ�ÿ�ʼ����ƶ���ֱ������λ��posֹͣ
	for (int i = arr->m_size - 1; i >= pos; i--)
	{
		arr->pAddr[i + 1] = arr->pAddr[i];
	}
	// ����Ԫ��
	arr->pAddr[pos] = data;
	// size ++
	arr->m_size++;


}

// ������̬����
void for_each_dynamicArray(struct dynamicArray* arr, void(*myprint)(void*))
{
	if (NULL == arr)
	{
		return;
	}
	if (NULL == myprint)
	{
		return;
	}
	for (int i = 0; i < arr->m_size; i++)
	{
		myprint(arr->pAddr[i]);
	}
}
// ����λ��ɾ�������е�Ԫ��
void removeByPos_dynamicArray(struct dynamicArray* arr, int pos)
{
	if (arr == NULL)
	{
		return;
	}
	if (pos < 0 || pos >arr->m_size - 1)
	{
		return;
	}
	// remove
	for (int i = pos; i < arr->m_size - 1; i++)
	{
		arr->pAddr[i] = arr->pAddr[i + 1];
	}
	arr->m_size--;
}
// ����ֵɾ�������е�Ԫ��
void removeByValue_dynamicArray(struct dynamicArray* arr, struct Person* data, int(*mycompare)(void*, void*))
{
	if (arr == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	//
	for (int idx = 0; idx < arr->m_size; idx++)
	{
		if (mycompare(arr->pAddr[idx], data))
		{
			removeByPos_dynamicArray(arr, idx);
			break;
		}
	}
}
// ��������
void destory_dynamicArray(struct dynamicArray* arr)
{
	if (arr == NULL)
	{
		return;
	}
	if (arr->pAddr != NULL)
	{
		free(arr->pAddr);
		arr->pAddr = NULL;
	}
	free(arr);
	arr = NULL;
}