#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "chararray.h"

struct ChArray
{
	char arr[1024];
	int m_size;
};
typedef void* CharArray;
CharArray init_CharArray()
{
	struct  ChArray* pArr = malloc(sizeof(struct ChArray));
	if (pArr == NULL)
	{
		return;
	}
	memset(pArr->arr, 0, sizeof(pArr->arr));
	pArr->m_size = 0;

	return pArr;
}
void push_CharArray(CharArray p, void* data)
{
	if (p == NULL || data == NULL)
	{
		return;
	}
	struct ChArray* pArr = p;
	pArr->arr[pArr->m_size] = data;
	pArr->m_size++;
}

int size_CharArray(CharArray p)
{
	if (p == NULL)
	{
		return -1;
	}
	struct ChArray* pArr = p;
	return pArr->m_size;
}

void foreach_CharArray(CharArray p, void(*myprint)(char))
{
	if (p == NULL)
	{
		return;
	}
	struct ChArray* pArr = p;
	for (int i = 0; i < pArr->m_size; pArr++)
	{
		myprint(pArr->arr[i]);
	}
}
