#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�ṹ��Ķ���
	//1 ��typedef����ṹ�壬������ŵĵ�����һ�����͵ı���
	//2 ���򣬺�����ŵĵ�����
	//3 �����ṹ������������޷�ʹ��

//�ṹ�����
	//��ջ������
	//�ڶ�������

//�ṹ���������
	//��ջ������
	//�ڶ�������




typedef struct Person
{
	char name[64];
	int age;
}Person1;//����

void test_01()
{
	Person1 p = { "aaa",27 };
}
struct Persons
{
	char name[64];
	int age;
}myPerson = { "aaaaa",11 };//�ṹ�����
void test_02()
{
	printf("name = %s,  age = %d\n", myPerson.name, myPerson.age);
	myPerson.age = 100;
	printf("name = %s,  age = %d\n", myPerson.name, myPerson.age);
}
//��ʽ���������ṹ�����   �����޷��ظ������˽ṹ�����
struct
{
	char names[64];
	int age;
}MyPersons;//�ṹ����� Ψһ
void test_03()
{
	MyPersons.age = 1111;
	strcpy(MyPersons.names, "niming");
	printf("name = %s,  age = %d\n", MyPersons.names, MyPersons.age);
}


void test_04()
{
	//ջ�������ṹ�����
	struct Persons p = {"Dale",24};
	printf("name = %s,  age = %d\n", p.name, p.age);

	//���������ṹ�����
	struct Persons* pp = malloc(sizeof(struct Persons));
	pp->age = 30;
	//������ֱ�ӵȺŸ�ֵ�ַ�������
	strcpy(pp->name, "Susan");
	printf("name = %s,  age = %d\n", pp->name, pp->age);
	free(pp);
	pp = NULL;
}

//��ӡ�ṹ���������
void PrintStructArr(struct Persons pArry[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("name = %s,  age = %d\n", pArry[i].name, pArry[i].age); 
	}
}
//��չ��ӡ�ṹ��������� ����һά����ָ��
void PrintStructArr2(struct Persons(*parr)[2])
{
	for (int i = 0; i < 2; i++)
	{
		printf("name = %s,  age = %d\n", (*parr)[i].name, (*parr)[i].age);
	}
}

//�ṹ���������
void test_05()
{
	//��ջ�ϴ���
	struct Persons p[] = {
		{"aaa",11},
		{"bbb",22}
	};
	int len = sizeof(p) / sizeof(struct Persons);
	printf("��ջ������ \n");
	PrintStructArr(p, len);
	printf("��ջ������2  \n");
	PrintStructArr2(&p);
	//�ڶ�������
	struct Persons* pArr = malloc(sizeof(struct Persons) * 4);
	for (int i = 0; i < 4; i++)
	{
		sprintf(pArr[i].name, "name_%d", i + 1);
		pArr[i].age = i + 18;
	}
	printf("�ڶ������� \n");
	PrintStructArr(pArr, 4);
	if (pArr != NULL)
	{
		free(pArr);
		pArr = NULL;
	}
	
}


int main()
{
	//test_02();
	//test_03();
	//test_04();
	//test_05();
	//main_02();
	//main_03();
	//main_04();
	main_05();
}