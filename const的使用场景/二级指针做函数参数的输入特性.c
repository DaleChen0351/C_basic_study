#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//���⣺����ָ����������������������
//˵�����������������ڴ棬��������ʹ�� 

//����ָ���������Ĳ���
pirntArray(int** p, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", *(p[i]));
	}
}


//�ڶ�������ָ�����飬ջ�����ʵ�ʵ�����ֵ
void test_01()
{
	//��ջ�ϴ�������
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
	//ע���ͷ�
	if (pointArr != NULL)
	{
		free(pointArr);
	}
	pointArr = NULL;
}



//��ջ�ϴ���ָ�����飬�������ʵ�ʵ�����ֵ
void test_02()
{
	int * pointArr[5];// �������������������ѹ��ջ�еġ��Ʋ�������׵�ַ������ջ��ջ���ĵ�ַ��

	for (int i = 0; i < 5; i++)
	{
		//���Ϸ����ڴ�
		pointArr[i] = malloc(sizeof(int*));
		*(pointArr[i]) = i + 100;
	}

	int len = sizeof(pointArr) / sizeof(int*);
	pirntArray(pointArr, len);
	//ע���ͷ�
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