#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 //˼·
// ���϶�һ����Сֵ���±꣬ͨ�� j = i + 1�ҵ���ʵ����Сֵ�±�
//�жϼ��������ʵ��Сֵ�±꣬�Ϳ�ʼ�϶���i�Ƿ���ȣ��������ȣ�����i ��min�±������Ԫ��

//ѡ������Ч�ʱ�ð������Ч�ʸ�

//��С���� ѡ������ int��������
void selectSort01(int arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		int minIdx = i;//��������Сֵ���±�
		for (int j = i + 1; j < len; j++)
		{
			if (arr[minIdx] > arr[j])//����������Сֵ������ֵ��
			{
				minIdx = j;//������±�
			}
		}
		//��������ֵ������Сֵ�򽻻�˳���Ա�֤��i��λ�ñ�����Ǵ�����濪ʼ����Сֵ
		if (minIdx != i)
		{
			int temp = arr[i];
			arr[i] = arr[minIdx];
			arr[minIdx] = temp;
		}
	}
}
//��ӡ����
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

//ͨ��ѡ�������㷨��ʵ�ֶ�ָ�����ݵĽ������򣬴Ӵ�С
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
			//����ָ��ָ���
			char* temp = pArr[i];
			pArr[i] = pArr[maxidx];
			pArr[maxidx] = temp;

		}
	}

}
unsigned int Mycompare(char* stra, char* strb)
{
	if (strcmp(stra, strb) < 0)//ǰ���ASCILL��ֵС�ں���� ��С��0   ���䣺 ǰ�� - ����
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//��ӡ�ַ�������
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