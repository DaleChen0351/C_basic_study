#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//函数指针做函数的参数 也就是回调函数
void test_21()
{
	printf("hello, world!");
}


//底层设计
void printArray(void* arr[], int elesize, int len, void(*myprint)(void*))//必须知道需要遍历的元素的大小，否则无法获得每个元素的首地址
{
	char* p = arr;
	for (int i = 0; i < len; i++)
	{
		myprint(p + elesize * i);
	}
}

//上层使用
void Myprint(void* data)
{
	int* t_data = data;
	printf("data = %d\n", *t_data);
}
void test_22()
{
	int arr[5] = { 1,2,3,4,5 };
	int len = sizeof(arr) / sizeof(int);
	printArray(arr, sizeof(int), len,Myprint);
}

struct Person
{
	char name[64];
	int age;
};
int my_find_function(void* arr, int eleSize, int len, void* data, int(*mycompare)(void*, void*))
{
	char* p = arr;
	for (int i = 0; i < len; i++)
	{
		if (mycompare((p + i *eleSize), data))
		{
			return 1;
		}
	}
	return 0;
}
int Mycompare(void*a, void*b)
{
	struct Person* p1 = a;
	struct Person* p2 = b;
	return p1->age == p2->age  &&  strcmp(p1->name, p2->name) == 0;
}
void test_23()
{
	struct Person ps[] = {
		{"aaa",111},
		{"bbb",222},
		{"ccc",333},
	};
	int eleSize = sizeof(struct Person);
	int len = sizeof(ps) / sizeof(struct Person);
	struct Person person = { "bbb",222 };
	int ret = 0;
	ret = my_find_function(ps, eleSize, len, &person, Mycompare);
	printf("ret = %d", ret);
}
