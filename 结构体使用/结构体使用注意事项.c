#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//浅拷贝和深拷贝

//浅拷贝：逐字节拷贝，系统默认提供的。
struct Person
{
	char name[64];//栈区上开辟
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
// 包含指向堆区的属性
struct Person2
{
	char* name;//指向堆区
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
	p1 = p2;   //依然是使用默认的浅拷贝
	printf("name = %s    age = %d\n", p1.name, p1.age);
	printf("name = %s    age = %d\n", p2.name, p2.age);

	//到目前为止，运行时没有问题的

	if (p1.name != NULL)
	{
		free(p1.name);
		p1.name = NULL;
	}
	//susan保存的区域已经由p1.name 释放了，p2.name 无权限访问和释放了
	if (p2.name != NULL)
	{
		free(p2.name);
		p2.name = NULL;
	}
	//这样的话，会造成两个问题
		// 1， Dale字符串没有指针指向，造成了内存泄漏
		// 2 ， Susan字符串被释放两次，崩溃
	
}


//解决方案：
//C++可以利用复制构造函数，C语言没有好办法，手动操作。即深拷贝，复制出来一份同样的，分别维护自己的堆区变量
	//先释放原来的内容
	//重新申请新的空间
	//
// 深拷贝
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

	//先释放p1.name 原先指向的内容
	if (p1.name != NULL)
	{
		free(p1.name);
		p1.name = NULL;
	}
	//再新分配内存
	int len = strlen(p2.name) + 1;
	p1.name = malloc(len);
	//最后赋值
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

// 不是所有的结构体赋值都需要，除非属性中有指向堆区的变量。栈区是不会出现的
void main_02()
{
	//test_11();
	//test_12();
	test_13();
}









