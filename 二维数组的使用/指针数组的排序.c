#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 //思路
// 先认定一个最小值的下标，通过 j = i + 1找到真实的最小值下标
//判断计算出的真实最小值下标，和开始认定的i是否相等，如果不相等，交换i 和min下标的两个元素

//选择排序效率比冒泡排序效率高

//从小到大 选择排序法 int类型数据
void selectSort01(int arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		int minIdx = i;//假设是最小值的下标
		for (int j = i + 1; j < len; j++)
		{
			if (arr[minIdx] > arr[j])//如果假设的最小值比其他值大
			{
				minIdx = j;//则更新下标
			}
		}
		//如果假设的值不是最小值则交换顺序，以保证第i个位置保存的是从其后面开始数最小值
		if (minIdx != i)
		{
			int temp = arr[i];
			arr[i] = arr[minIdx];
			arr[minIdx] = temp;
		}
	}
}
//打印数组
void printArray(int *arr, int len)
{
	for (int i = 0; i < len; i ++)
	{
		printf("%d\n", arr[i]);
	}
}
void test_31()
{
	int arr[] = { 3,2,5,1,4 };
	int len = sizeof(arr) / sizeof(int);
	selectSort01(arr, len);
	printArray(arr, len);
}

//通过选择排序算法，实现对指针数据的降序排序，从大到小
void selectSort2(char**pArr, int len, unsigned int(*mycompare)(char* stra,char* strb))
{
	for (int i = 0; i < len; i++)
	{
		int maxidx = i;
		for (int j = i + 1; j < len; j++)
		{
			if (mycompare(pArr[maxidx], pArr[j]))
			{
				maxidx = j;
			}
		}
		if (maxidx != i)
		{
			//交换指针指向的
			char* temp = pArr[i];
			pArr[i] = pArr[maxidx];
			pArr[maxidx] = temp;

		}
	}

}
unsigned int Mycompare(char* stra, char* strb)
{
	if (strcmp(stra, strb) < 0)//前面的ASCILL码值小于后面的 则小于0   记忆： 前面 - 后面
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//打印字符串数组
void printArray2(char * arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%s\n",arr[i] );
	}
}

void test_32()
{
	char* pArr[] = { "aaa","bbb","fff","ddd","eee","ccc" };
	int len = sizeof(pArr) / sizeof(char*);
	selectSort2(pArr, len, Mycompare);
	printArray2(pArr, len);
}
void main_03()
{
	test_32();
}