#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h> // offsetof()


// void* 指针
void test_01()
{
	void* p = NULL;
	int *pint = NULL;
	char *pchar = NULL;

	pchar = p;//万能指针，不需要强制类型转化就可以给等号左边赋值
	printf("sizeof p = %d\n", sizeof p);
	printf("sizeof pint = %d\n ", sizeof pint);
}
// 自定义数据类型通过指针修改值
struct Person {
	char a;
	int b;
	char c;
	int d;
};
// 自定义数据类型 通过指针修改
void test_02()
{
	struct Person p = { 'a', 1,'c',10 };
	//方式一
	struct Person*pp = NULL;
	pp = &p;
	pp->d = 1000;
	printf("d = %d\n", pp->d);

	// 方式二 通过地址偏移
	char* pchar = NULL;
	pchar = pp;
	*(int*)(pchar + 12) = 2000;// 内存对齐

	printf("d = %d\n", pp->d);

	// 方式三 通过地址偏移
	int* pint = pp;
	*(pint + 3) = 3000;
	printf(" d = %d\n", pp->d);
	// int*


}

// 如果主调函数中没有给指针分配内存，被调函数用同级的指针是无法修改主调函数中的指针变量的指向的（只能修改函数的形参）
// 二级指针
typedef char* PCHAR;
void allocateSpace(PCHAR* pp)
{
	PCHAR temp = malloc(100);
	memset(temp, 0, 100);
	strcpy(temp, "hello,world!");
	for (int i = 0; i < 20; i++)
	{
		printf("%c", temp[i]);
	}
	*pp = temp;
}
void test_03()
{
	PCHAR p = NULL;
	allocateSpace(&p);
	printf("%s\n", p);
	free(p);
	p = NULL;
}

// 
//空指针
//不允许向NULL 和非法地址拷贝内存
void test_04()
{
	//char *p = NULL;
	char* p = 0x1122;
	strcpy(p, "1111");//内存访问冲突
	printf("%s", *p);
}
//野指针
//1 解引用未初始化的指针
//2 malloc后free释放内存，但是指针没有置空，然后解引用
//3 指针的操作超越变量的作用域
void test_05()
{
	//char* p = NULL;
	//printf("%s", *p);//引发了未经处理的异常:读取访问权限冲突。 	p 是 nullptr。
    
	int* pc = malloc(sizeof(int));
	*pc = 20;
	printf("pc = %d\n", *pc);
	free(pc);
		//pc = NULL; //故使用完指针一定要指向NULL，这样的话，如果后面有人误使用了此指针进行了解引用操作，程序会直接崩掉，避免引用了无意义的值
	printf("pc = %d\n", *pc);//此处的值是无意义的
}
//释放空指针，是可以的
//野指针不可以重复释放
//释放之后的内存，已经没有权限进行操作，但是你再去free，相当于是再去操作,会奔溃

//指针的步长
	//1 指针变量 +1之后 跳跃的字节数量
void test_06()
{
	char* p1 = NULL;
	printf("p1 addr = %d\n", p1);
	p1++;
	printf("p1 addr = %d\n", p1);

	float* p2 = NULL;
	printf("p2 addr = %d\n", p2);
	printf("p2 addr = %d\n", p2+1);
	printf("p2 addr = %d\n", p2 + 2);

	int num = 0xaabbccdd;
	unsigned char* pp = &num;//如果想按照字节取数，一定要用unsigned char*
	printf("%x\n", *(pp+3));// 最高位 aa
	printf("%x\n", *pp);// 最低位dd

}
	// 2.1解引用的时候，取得字节数 
void test_07()
{
	int a = 1000;
	char* p = &a;
	printf("a = %d", *(int*)p);
}
struct Student
{
	char group;
	int age;
	char name[64];
	int size;
};
	//2.2 自定义数据类型
		//计算结构体中属性的偏移量：offsetof(struct name, feature name);  #include <stddef.h>
void test_08()
{
	printf("sizeof stu = %d\n", sizeof(struct Student));// 76 也就是说，sizeof计算的是实际分配的内存大小，内存对齐导致的浪费也要计算
	//计算结构体的偏移量
	printf("int size 的偏移量 = %d\n", offsetof(struct Student, size));// 72

	struct Student stu = { "A",22,"hello,world!",100 };
	char* p = &stu;
	printf("stu.size = %d\n", *(int*)(p + offsetof(struct Student, size)));
}
// 指针的间接赋值：1 一个指针变量 一个普通变量 2 建立关系 3 利用* 号解引用赋值
	//通过函数
	//通过地址
		// 在Qt中可以，*(int*)268464 = 1000;// 将内存地址 int值强制转化成一个指针

//多级指针
void test_09()
{
	int a = 10;
	int *q = &a;
	int **t = &q;
	int ***m = &t;
	//利用三级指针m修改a的值为1000;
	int **t2 = *m;
	int *q2 = *t2;
	*q2 = 1000;
	printf("a = %d", *q2);
}
//指针做函数参数
	//指针做函数参数，具备输入和输出特性
		//输入特性：主调函数中分配内存，被调函数中使用内存(栈上和堆上都可以)
		//输出特性：被调函数中分配内存，主调函数中使用内存
			// 如果主调函数中没有给指针分配内存，被调函数用同级的指针是无法修改主调函数中的指针变量的指向的（只能修改函数的形参）
void myprintf(char* s)
{
	printf("string = %s\n",s);
}
//输入特性
void test_A()
{
	//分配到栈上
	char name[64];
	memset(name, 0, 64);
	strcpy(name, "hello,world!");
	myprintf(name);
	//分配到堆上
	char* p = malloc(sizeof(char) * 64);
	memset(p, 0, 64);
	strcpy(p, "who is your sister?");
	myprintf(p);
	free(p);
	p = NULL;

}
//输出特性

void allocatSpace(char** p)
{
	char* temp = malloc(64);
	memset(temp, 0, 64);
	strcpy(temp, "this is good!");
	*p = temp;//temp的指向赋值为name指针，通过指针传递
}
int DirectAddress()
{
	char* temp = malloc(64);
	memset(temp, 0, 64);
	strcpy(temp, "DirectAddress,this is good!");
	
	return (unsigned int)temp;
}

void test_B()
{
	char* name = NULL;//需要改变char*的值
	allocatSpace(&name);
	printf("%s\n", name);
	// 所以说，指针就是保持的地址值，而且用uint表示的值而已，没什么神秘的
	char* addr = NULL;
	unsigned int ret = DirectAddress();
	addr = (char*)ret;
	printf("%s\n", addr);
}



int main()
{
	//test_01();
	//test_03();
	//test_04();
	//test_05();
	//test_06();
	//test_07();
	//test_08();
	//test_09();
	//test_10();
	//test_B();

	//test_11();
	//test_12();
	//test_13();
}