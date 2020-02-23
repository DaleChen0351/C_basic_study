#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// 如何定义和使用一维数组的指针
		// 1 先定义数组的类型，再创建数组指针变量   typedef int(ARRAY_TYPE)[5];
		// 2 先定义数组指针的类型，再			             typedef int(*ARRAY_TYPE)[5];
		// 3 直接定义                                               int(*p)[5];
// 也可以利用数组指针变量作为函数的参数，省去传递len值

//  typedef int(ARRAY_TYPE)[5];
void test_31()
{
	int arr[5] = { 1,2,3,4,5 };
	//注意：创建数组指针
	typedef int(ARRAY_TYPE)[5];// ARRAY_TYPE 是一个数据类型，代表有5个 int类型元素的数组
	//*arrp 与 arr等价
	ARRAY_TYPE * arrp = &arr;
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", (*arrp)[i]);
	}
	printf("sizeof arrp = %d\n", sizeof *arrp);
}
// typedef int(*ARRAY_TYPE)[5]; 和 直接定义
void test_32()
{
	int arr[5] = { 1,2,3,4,5 };
	typedef int(*ARRAY_TYPE)[5];
	ARRAY_TYPE p = &arr;
	// 也可以直接定义
	int(*parr)[5] = &arr;
	parr = &arr;
}

//一维数组的指针 也可以通过函数来传递了
typedef int(ARRAY_TYPE)[5];
void func(ARRAY_TYPE* pArr)
{
	int len = sizeof(*pArr) / sizeof(int);
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", (*pArr)[i]);
	}
	printf("sizeof arrp = %d\n", sizeof *pArr);

}

void test_33()
{
	int arr[5] = { 1,2,3,4,5 };
	func(&arr);
}

void main_03()
{
	test_33();
}
