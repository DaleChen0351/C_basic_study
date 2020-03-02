#include "dynamicArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//初始化动态数组
struct dynamicArray* init_DynamicArray(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}
	// 申请内存空间
	struct dynamicArray* arr = malloc(sizeof(struct dynamicArray));
	if (NULL == arr)
	{
		return NULL;
	}
	// 设置容量
	arr->m_capacity = capacity;
	// 设置大小
	arr->m_size = 0;
	// 维护在堆区数组的指针 首地址
	arr->pAddr = malloc(sizeof(void*) * arr->m_capacity);
	return arr;
}
//插入元素
void insert_dynamicArray(struct dynamicArray* arr, int pos, void* data)
{
	if (arr == NULL || data == NULL)
	{
		return;
	}
	//pos
	if (pos < 0 || pos > arr->m_size) // 当pos == arr->size 相当于是尾插
	{
		//无效的位置 尾插
		pos = arr->m_size;
	}
	// 判断是否满载，需要扩容
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
	// 插入元素
	//从最后一个位置开始向后移动，直到插入位置pos停止
	for (int i = arr->m_size - 1; i >= pos; i--)
	{
		arr->pAddr[i + 1] = arr->pAddr[i];
	}
	// 插入元素
	arr->pAddr[pos] = data;
	// size ++
	arr->m_size++;


}

// 遍历动态数组
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
// 按照位置删除数组中的元素
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
// 按照值删除数组中的元素
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
// 销毁数组
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