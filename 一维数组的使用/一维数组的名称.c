#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//һά��������Ʋ���ָ�룬ֻ����Щʱ����Ե�ָ��ʹ�ö���
	//����������������£�һά��������ƶ���ָ����׵�ַԪ��
		//1 sizeof ������
		//2 ��������ȡ��ַ���õ���������ָ��

//�������� �� ָ�볣�� int *const p;

// ��ӡ����
void printArray(int arr[], int len)//�ɶ��Ժã�int arr[] �ȼ���int* arr��
{
	for (int i = 0; i < len; i++)
	{
		//���ַ��ʷ�ʽ
		printf("%d\n", arr[i]);
		printf("%d\n", *(arr + i));//����
	}
}
void test_01()
{

		//�������1��
	int arr[5] = { 1,2,3,4,5 };
	printf("sizeof arr = %d\n", sizeof arr); //20

		//�������2��������ȡ��ַ��ָ����ָ������������׵�ַ�����+1 ��ָ��Ĳ������������������Ԫ�صĺ�
	printf("&arr = %d\n", &arr);
	printf("&arr = %d\n", &arr+1);

	//�������� ָ�볣�� ָ���ָ�򲻿����޸� 
	//arr = NULL;

	//��ӡ����
	printArray(arr, 5);
}
//�����ŵı��ʾ��� *(p+n)
void test_02()
{
	int arr[5] = { 1,2,3,4,5 };

	int * p = arr;
	p = p + 3;
	printf("p = p + 3 ֮��  %d\n", p[0]); 
	//�����ſ��ԷŸ���
	printf("p[-1] = %d\n", p[-1]);
}

void main_02()
{
	//test_01()
}