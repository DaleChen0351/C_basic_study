#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



//�ṹ����Ƕ��һ��ָ��
	//��ƽṹ��
	//�ڶ��������ṹ��ָ������
	//��ÿ���ṹ���Ҳ���䵽����
	//��ÿ���ṹ��
	//��ӡ
	//�ͷţ�malloc �� free����Ҫ��ͬ

struct Dog
{
	char* name; //�ṹ����Ƕ��һ��ָ��
	int age;
};

//�����ڴ�
struct Dog** allocateSpace()
{
	struct Dog** p = malloc(sizeof(struct Dog*) * 3);
	//��ÿ���ṹ��ָ�����ṹ������Ŀռ�
	for (int i = 0; i < 3; i++)
	{
		//��ÿ���ṹ�忪���ڴ�
		p[i] = malloc(sizeof(struct Dog));
		//��ÿ���ṹ���������ֵ
		p[i]->name = malloc(sizeof(char) * 64);
		sprintf(p[i]->name, "name_%d", i + 1);//��ʽ���ַ���
		p[i]->age = 20 + i;
	}
	return p;
}

//��ӡ����
void printDogArray(struct Dog* p[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("name = %s, age = %d\n", p[i]->name, p[i]->age);
	}
}

//�ͷ�����
void freeSpace(struct Dog** p, int len)
{
	if (p == NULL)
	{
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		if (p[i]->name != NULL)
		{
			free(p[i]->name);
			p[i]->name = NULL;
		}
		if (p[i] != NULL)
		{
			free(p[i]);
			p[i] = NULL;
		}
	}
	free(p);
}

void test_31()
{
	struct Dog** pArr = NULL;
	pArr = allocateSpace();
	printDogArray(pArr, 3);
	freeSpace(pArr, 3);
	pArr = NULL;
}

void main_03()
{
	test_31();
}