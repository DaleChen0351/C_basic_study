#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//主题：二级指针做函数参数的输出特性
//说明：被调函数分配内存，主调函数使用 

void allocateSpace(int**pa)
{
	int* temp = malloc(sizeof(int) * 10);
	for (int i = 0; i < 10; i++)
	{
		temp[i] = i + 100;
	}
	*pa = temp;

}
//打印 用二级指针
void printSpace2(int** arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", (*arr)[i]);
	}
}

//打印 用一级指针
void printSpace1(int * arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", arr[i]);
	}
	
}


//free 用二级指针和一级指针都可以
void freeSpace(int ** p)
{
	if (*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}
void test_11()
{
	int* p = NULL;
	allocateSpace(&p); 
	printSpace1(p,10);
	printf("\n");
	printSpace2(&p, 10);
	freeSpace(&p);
}

