#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ǳ���������

//ǳ���������ֽڿ�����ϵͳĬ���ṩ�ġ�
struct Person
{
	char name[64];//ջ���Ͽ���
	int age;
};
void printPerson(struct Person* p1)
{
	printf("name = %s   age = %d\n", p1->name, p1->age);
}
void test_11()
{
	struct Person p1 = { "Dale",28 };
	struct Person p2 = { "Bob", 30 };

	printPerson(&p1);
	printPerson(&p2);
	p1 = p2;
	printPerson(&p1);
	printPerson(&p2);
}
// ����ָ�����������
struct Person2
{
	char* name;//ָ�����
	int age;
};

void test_12()
{
	struct Person2 p1;
	struct Person2 p2;

	p1.name = malloc(sizeof(char) * 64);
	strcpy(p1.name, "Dale");
	p1.age = 18;

	p2.name = malloc(sizeof(char) * 64);
	strcpy(p2.name, "Susan");
	p2.age = 18;

	printf("name = %s    age = %d\n", p1.name, p1.age);
	printf("name = %s    age = %d\n", p2.name, p2.age);
	p1 = p2;   //��Ȼ��ʹ��Ĭ�ϵ�ǳ����
	printf("name = %s    age = %d\n", p1.name, p1.age);
	printf("name = %s    age = %d\n", p2.name, p2.age);

	//��ĿǰΪֹ������ʱû�������

	if (p1.name != NULL)
	{
		free(p1.name);
		p1.name = NULL;
	}
	//susan����������Ѿ���p1.name �ͷ��ˣ�p2.name ��Ȩ�޷��ʺ��ͷ���
	if (p2.name != NULL)
	{
		free(p2.name);
		p2.name = NULL;
	}
	//�����Ļ����������������
		// 1�� Dale�ַ���û��ָ��ָ��������ڴ�й©
		// 2 �� Susan�ַ������ͷ����Σ�����
	
}


//���������
//C++�������ø��ƹ��캯����C����û�кð취���ֶ�����������������Ƴ���һ��ͬ���ģ��ֱ�ά���Լ��Ķ�������
	//���ͷ�ԭ��������
	//���������µĿռ�
	//
// ���
void test_13()
{
	struct Person2 p1;
	struct Person2 p2;

	p1.name = malloc(sizeof(char) * 64);
	strcpy(p1.name, "Dale");
	p1.age = 18;

	p2.name = malloc(sizeof(char) * 64);
	strcpy(p2.name, "Susan");
	p2.age = 18;


	printf("name = %s    age = %d\n", p1.name, p1.age);
	printf("name = %s    age = %d\n", p2.name, p2.age);

	//���ͷ�p1.name ԭ��ָ�������
	if (p1.name != NULL)
	{
		free(p1.name);
		p1.name = NULL;
	}
	//���·����ڴ�
	int len = strlen(p2.name) + 1;
	p1.name = malloc(len);
	//���ֵ
	strcpy(p1.name, p2.name);
	p1.age = p2.age;

	printf("name = %s    age = %d\n", p1.name, p1.age);
	printf("name = %s    age = %d\n", p2.name, p2.age);

	if (p1.name != NULL)
	{
		free(p1.name);
		p1.name = NULL;
	}
	if (p2.name != NULL)
	{
		free(p2.name);
		p2.name = NULL;
	}

}

// �������еĽṹ�帳ֵ����Ҫ��������������ָ������ı�����ջ���ǲ�����ֵ�
void main_02()
{
	//test_11();
	//test_12();
	test_13();
}









