#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//结构体的定义
	//1 用typedef定义结构体，后面跟着的单词是一个类型的别名
	//2 否则，后面跟着的单词是
	//3 匿名结构体变量，后期无法使用

//结构体变量
	//在栈区创建
	//在堆区创建

//结构体变量数组
	//在栈区创建
	//在堆区创建




typedef struct Person
{
	char name[64];
	int age;
}Person1;//别名

void test_01()
{
	Person1 p = { "aaa",27 };
}
struct Persons
{
	char name[64];
	int age;
}myPerson = { "aaaaa",11 };//结构体对象
void test_02()
{
	printf("name = %s,  age = %d\n", myPerson.name, myPerson.age);
	myPerson.age = 100;
	printf("name = %s,  age = %d\n", myPerson.name, myPerson.age);
}
//方式三：匿名结构体变量   后期无法重复产生此结构体变量
struct
{
	char names[64];
	int age;
}MyPersons;//结构体变量 唯一
void test_03()
{
	MyPersons.age = 1111;
	strcpy(MyPersons.names, "niming");
	printf("name = %s,  age = %d\n", MyPersons.names, MyPersons.age);
}


void test_04()
{
	//栈区创建结构体变量
	struct Persons p = {"Dale",24};
	printf("name = %s,  age = %d\n", p.name, p.age);

	//堆区创建结构体变量
	struct Persons* pp = malloc(sizeof(struct Persons));
	pp->age = 30;
	//不可以直接等号赋值字符串变量
	strcpy(pp->name, "Susan");
	printf("name = %s,  age = %d\n", pp->name, pp->age);
	free(pp);
	pp = NULL;
}

//打印结构体变量数组
void PrintStructArr(struct Persons pArry[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("name = %s,  age = %d\n", pArry[i].name, pArry[i].age); 
	}
}
//扩展打印结构体变量数组 采用一维数组指针
void PrintStructArr2(struct Persons(*parr)[2])
{
	for (int i = 0; i < 2; i++)
	{
		printf("name = %s,  age = %d\n", (*parr)[i].name, (*parr)[i].age);
	}
}

//结构体变量数组
void test_05()
{
	//在栈上创建
	struct Persons p[] = {
		{"aaa",11},
		{"bbb",22}
	};
	int len = sizeof(p) / sizeof(struct Persons);
	printf("在栈区创建 \n");
	PrintStructArr(p, len);
	printf("在栈区创建2  \n");
	PrintStructArr2(&p);
	//在堆区创建
	struct Persons* pArr = malloc(sizeof(struct Persons) * 4);
	for (int i = 0; i < 4; i++)
	{
		sprintf(pArr[i].name, "name_%d", i + 1);
		pArr[i].age = i + 18;
	}
	printf("在堆区创建 \n");
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