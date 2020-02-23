#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//一维数组的名称不是指针，只是有些时候可以当指针使用而已
	//除了两种特殊情况下，一维数组的名称都是指针的首地址元素
		//1 sizeof 数组名
		//2 对数组名取地址，得到的是数组指针

//数组名称 是 指针常量 int *const p;

// 打印函数
void printArray(int arr[], int len)//可读性好，int arr[] 等价于int* arr。
{
	for (int i = 0; i < len; i++)
	{
		//两种访问方式
		printf("%d\n", arr[i]);
		printf("%d\n", *(arr + i));//本质
	}
}
void test_01()
{

		//特殊情况1：
	int arr[5] = { 1,2,3,4,5 };
	printf("sizeof arr = %d\n", sizeof arr); //20

		//特殊情况2：数组名取地址，指的是指向整个数组的首地址，如果+1 则指针的步长是整个数组的所有元素的和
	printf("&arr = %d\n", &arr);
	printf("&arr = %d\n", &arr+1);

	//数组名称 指针常量 指针的指向不可以修改 
	//arr = NULL;

	//打印函数
	printArray(arr, 5);
}
//中括号的本质就是 *(p+n)
void test_02()
{
	int arr[5] = { 1,2,3,4,5 };

	int * p = arr;
	p = p + 3;
	printf("p = p + 3 之后  %d\n", p[0]); 
	//中括号可以放负数
	printf("p[-1] = %d\n", p[-1]);
}

void main_02()
{
	//test_01()
}