#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//���⣺����ָ���������������������
//˵�����������������ڴ棬��������ʹ�� 

void allocateSpace(int**pa)
{
	int* temp = malloc(sizeof(int) * 10);
	for (int i = 0; i < 10; i++)
	{
		temp[i] = i + 100;
	}
	*pa = temp;

}
//��ӡ �ö���ָ��
void printSpace2(int** arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", (*arr)[i]);
	}
}

//��ӡ ��һ��ָ��
void printSpace1(int * arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", arr[i]);
	}
	
}


//free �ö���ָ���һ��ָ�붼����
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

