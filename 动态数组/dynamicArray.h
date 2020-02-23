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

//初始化动态数组
struct dynamicArray* init_DynamicArray(int capacity);

//插入元素
void insert_dynamicArray(struct dynamicArray* arr, int pos, void* data);

// 遍历动态数组
void for_each_dynamicArray(struct dynamicArray* arr, void(*myprint)(void*));

// 按照位置删除数组中的元素
void removeByPos_dynamicArray(struct dynamicArray* arr, int pos);

// 按照值删除数组中的元素
void removeByValue_dynamicArray(struct dynamicArray* arr, struct Person* data, int(*mycompare)(void*, void*));

// 销毁数组
void destory_dynamicArray(struct dynamicArray* arr);

