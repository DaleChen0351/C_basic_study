//二叉树的非递归遍历
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void inset_sort(int arr[], int len)
{
	for (int i = 1; i < len; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			int temp = arr[i];
			int j = i - 1;
			for (; j >= 0 &&temp<arr[j]; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
		
	}

}

void test_31()
{
	int arr[] = { 5,9,6,1,3,7 };
	int len = sizeof(arr) / sizeof(int);
	inset_sort(arr, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}


}