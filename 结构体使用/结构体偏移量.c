#define _CRT_SECURE_ NO_WARNINGS

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h> //offsetof




struct Cat
{
	char a;
	int b;
};
//偏移量的计算
	//可以利用offsetof来计算结构体中的属性偏移
	//利用属性的地址 - 结构体的地址然后强制转化为(int) 类型来计算
void test_51()
{
	struct Cat cat = { 'h',17 };
	//方式一：offsetof
	printf("b属性偏移量为: %d\n", offsetof(struct Cat, b));
	//方式二：属性的地址 - 结构体的首地址
	int offset = (int)&cat.b - (int)&cat;
	printf("b属性偏移量为: %d\n", offset);

}


//通过偏移量 获得到数据
void test_52()
{
	struct Cat cat = { 'h',17 };
	char* p = (char*)&cat;
	printf("cat b = %d\n", *((int*)(p + offsetof(struct Cat, b))));
	printf("cat b = %d\n", *((int*)&cat + 1));
}
 
//结构体嵌套结构体
struct Cat2
{
	char c;
	int d;
	struct Cat cat;
};
//本质：就是展开而已
void test_53()
{
	struct Cat2 cat2 = { 'h',17,'e',20 };
	//利用offsetof计算偏移量
	int offset1 = offsetof(struct Cat2,cat);
	int offset2 = offsetof(struct Cat, b);
	printf("cat b = %d\n", *((int*)((char*)&cat2 + offset1 + offset2)));// 20
	printf("cat b = %d\n", ((struct Cat*)((char*)&cat2 + offset1))->b);
}


void main_05()
{
	//test_51();
	//test_52();
	test_53();
}