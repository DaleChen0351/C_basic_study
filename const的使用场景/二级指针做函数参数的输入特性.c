#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//主题：二级指针做函数参数的输入特性
//说明：主调函数分配内存，被调函数使用 

//二级指针做函数的参数
pirntArray(int** p, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", *(p[i]));
	}
}


//在堆区创建指针数组，栈区存放实际的数据值
void test_01()
{
	//在栈上创建数据
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;


	int ** pointArr = malloc(sizeof(int*) * 4);
	pointArr[0] = &a;
	pointArr[1] = &b;
	pointArr[2] = &c;
	pointArr[3] = &d;
	pirntArray(pointArr, 4);
	//注意释放
	if (pointArr != NULL)
	{
		free(pointArr);
	}
	pointArr = NULL;
}



//在栈上创建指针数组，堆区存放实际的数据值
void test_02()
{
	int * pointArr[5];// 这个数组是纵向连续被压入栈中的。推测数组的首地址，就是栈的栈顶的地址。

	for (int i = 0; i < 5; i++)
	{
		//堆上分配内存
		pointArr[i] = malloc(sizeof(int*));
		*(pointArr[i]) = i + 100;
	}

	int len = sizeof(pointArr) / sizeof(int*);
	pirntArray(pointArr, len);
	//注意释放
	for (int i = 0; i < 5; i++)
	{
		if (pointArr[i] != NULL)
		{
			free(pointArr[i]);
			pointArr[i] = NULL;
		}
	}

	

}

int main()
{
	//test_01();
	//test_02();
	//test_11();
	test_21();
}