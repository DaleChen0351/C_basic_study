#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//本质上，二维数组的本质也是一维数组(即连续空间）
// 除了两种特殊情况，二维数组名都是指向第一个一维数组的指针
		//1 sizeof 统计整个二维数组的长度
		// 2 对数组名称取地址，得到的是指向整个二维数组的指针

//二维数组的三种定义方式
void test_21()
{
	//形式1：可读性好
	int arr[3][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	//形式2：二维数组的本质也是连续空间上的数组
	int arr2[2][2] = { 1,2,3,4 };
	//形式3：
	int arr3[][2] = { 1,2,3,4 };
}

//二维数组的名称降级之后，是指向第一个一维数组的指针  // 对应的，一维数组的名称降级之后，是指向第一个元素的指针
void test_22()
{
	int arr[3][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
		int(*p)[3] = arr;//二维数组的名称 是指向第一个一维数组的指针   
		int (*p2)[3][3] = &arr;//二维数组的指针
	//中括号的本质就是 *(p + n)
	printf("%d\n", arr[1][2]);//给人看的
	printf("%d\n", *(*(arr + 1) + 2));//给机器看的，两次将中括号展开
}

// 二维数组做函数的参数
//形式1
void print2Array(int p[][3], int row,int col )
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", p[i][j]);
			//printf("%d", *(*(p + i) + j));
		}
		printf("\n");
	}
}
//形式2
void print2Array2(int(*p)[3], int row, int col) //二维数组指针做参数传递时降级成一个指向第一个一维数组的指针
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			//printf("%d ", p[i][j]);
			printf("%d ", *(*(p + i) + j));
		}
		printf("\n");
	}
}
//形式三 直接传递二维数组的指针
typedef int(*ARRAY_2D_P)[3][3];
void print2Array3(ARRAY_2D_P p) //
{
	int row = sizeof(*p) / sizeof((*p)[0]);
	int col = sizeof((*p)[0]) / sizeof((*p)[0][0]);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", (*p)[i][j]);
		}
		printf("\n");
	}
}
void test_23()
{
	int arr[3][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	print2Array(arr, 3, 3);
	print2Array2(arr, 3, 3);
	printf("方式三：\n");
	print2Array3(&arr);
}

int main_02()
{
	//test_22();
	test_23();
}