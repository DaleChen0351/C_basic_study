#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



//结构体中嵌套一级指针
	//设计结构体
	//在堆区创建结构体指针数组
	//给每个结构体的也分配到堆区
	//给每个结构体
	//打印
	//释放：malloc 和 free个数要相同

struct Dog
{
	char* name; //结构体中嵌套一级指针
	int age;
};

//分配内存
struct Dog** allocateSpace()
{
	struct Dog** p = malloc(sizeof(struct Dog*) * 3);
	//给每个结构体指针分配结构体变量的空间
	for (int i = 0; i < 3; i++)
	{
		//给每个结构体开辟内存
		p[i] = malloc(sizeof(struct Dog));
		//给每个结构体的姓名赋值
		p[i]->name = malloc(sizeof(char) * 64);
		sprintf(p[i]->name, "name_%d", i + 1);//格式化字符串
		p[i]->age = 20 + i;
	}
	return p;
}

//打印数组
void printDogArray(struct Dog* p[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("name = %s, age = %d\n", p[i]->name, p[i]->age);
	}
}

//释放数组
void freeSpace(struct Dog** p, int len)
{
	if (p == NULL)
	{
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		if (p[i]->name != NULL)
		{
			free(p[i]->name);
			p[i]->name = NULL;
		}
		if (p[i] != NULL)
		{
			free(p[i]);
			p[i] = NULL;
		}
	}
	free(p);
}

void test_31()
{
	struct Dog** pArr = NULL;
	pArr = allocateSpace();
	printDogArray(pArr, 3);
	freeSpace(pArr, 3);
	pArr = NULL;
}

void main_03()
{
	test_31();
}