#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// ��ζ����ʹ��һά�����ָ��
		// 1 �ȶ�����������ͣ��ٴ�������ָ�����   typedef int(ARRAY_TYPE)[5];
		// 2 �ȶ�������ָ������ͣ���			             typedef int(*ARRAY_TYPE)[5];
		// 3 ֱ�Ӷ���                                               int(*p)[5];
// Ҳ������������ָ�������Ϊ�����Ĳ�����ʡȥ����lenֵ

//  typedef int(ARRAY_TYPE)[5];
void test_31()
{
	int arr[5] = { 1,2,3,4,5 };
	//ע�⣺��������ָ��
	typedef int(ARRAY_TYPE)[5];// ARRAY_TYPE ��һ���������ͣ�������5�� int����Ԫ�ص�����
	//*arrp �� arr�ȼ�
	ARRAY_TYPE * arrp = &arr;
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", (*arrp)[i]);
	}
	printf("sizeof arrp = %d\n", sizeof *arrp);
}
// typedef int(*ARRAY_TYPE)[5]; �� ֱ�Ӷ���
void test_32()
{
	int arr[5] = { 1,2,3,4,5 };
	typedef int(*ARRAY_TYPE)[5];
	ARRAY_TYPE p = &arr;
	// Ҳ����ֱ�Ӷ���
	int(*parr)[5] = &arr;
	parr = &arr;
}

//һά�����ָ�� Ҳ����ͨ��������������
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
