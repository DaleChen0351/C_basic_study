#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//�����ϣ���ά����ı���Ҳ��һά����(�������ռ䣩
// �������������������ά����������ָ���һ��һά�����ָ��
		//1 sizeof ͳ��������ά����ĳ���
		// 2 ����������ȡ��ַ���õ�����ָ��������ά�����ָ��

//��ά��������ֶ��巽ʽ
void test_21()
{
	//��ʽ1���ɶ��Ժ�
	int arr[3][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	//��ʽ2����ά����ı���Ҳ�������ռ��ϵ�����
	int arr2[2][2] = { 1,2,3,4 };
	//��ʽ3��
	int arr3[][2] = { 1,2,3,4 };
}

//��ά��������ƽ���֮����ָ���һ��һά�����ָ��  // ��Ӧ�ģ�һά��������ƽ���֮����ָ���һ��Ԫ�ص�ָ��
void test_22()
{
	int arr[3][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
		int(*p)[3] = arr;//��ά��������� ��ָ���һ��һά�����ָ��   
		int (*p2)[3][3] = &arr;//��ά�����ָ��
	//�����ŵı��ʾ��� *(p + n)
	printf("%d\n", arr[1][2]);//���˿���
	printf("%d\n", *(*(arr + 1) + 2));//���������ģ����ν�������չ��
}

// ��ά�����������Ĳ���
//��ʽ1
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
//��ʽ2
void print2Array2(int(*p)[3], int row, int col) //��ά����ָ������������ʱ������һ��ָ���һ��һά�����ָ��
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
//��ʽ�� ֱ�Ӵ��ݶ�ά�����ָ��
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
	printf("��ʽ����\n");
	print2Array3(&arr);
}

int main_02()
{
	//test_22();
	test_23();
}