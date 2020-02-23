#pragma once

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//栈区注意事项
char* getString();

void test_02();

// heap 
char* getStringHeap();

void test_04();

//Heap 的标准操作
int* getIntArray();

//Heap 的标准操作
void test_06();

void test_07();

#ifdef __cplusplus
}
#endif // cplusplus



