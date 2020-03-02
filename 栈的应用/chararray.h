#pragma once

struct ChArray
{
	char arr[1024];
	int m_size;
};
typedef void* CharArray;

CharArray init_CharArray();
void push_CharArray(CharArray p, void* data);
int size_CharArray(CharArray p);
void foreach_CharArray(CharArray p, void(*myprint)(char));


