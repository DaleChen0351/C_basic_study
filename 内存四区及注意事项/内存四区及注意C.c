#include "myheader.h"

//栈区注意事项 
// 不要返回局部变量的地址
char* getString()
{
	char str[] = "hello,world!";// 复制字符串到栈区
	return str;
}
void test_02()
{
	char* p = NULL;
	p = getString();
	printf("%s\n", p);// 烫烫烫烫烫 （0xCC）；
	//补充
	char* mp = malloc(20);
	printf("%s\n", mp);// 屯屯屯屯屯屯屯屯屯屯（0xCD）
}
// 字符串常量保存在全局区的字符串常量区
char* getStringHeap()
{
	char* mp = "hello,world!";// 字符串保存于全局区中的字符串常量区，返回指针，该地址不会因为函数调用结束而消失
	return mp;

}
void test_04()
{
	char* p = NULL;
	p = getStringHeap();
	printf("%s\n", p);
}
//Heap 的标准操作
int* getIntArray()
{
	int* p = malloc(sizeof(int) * 5);
	if (p == NULL)// 判断是否成功申请到内存空间
	{
		return NULL;
	}
	for (int i = 0; i < 5; i++)
	{
		p[i] = i + 100;// 连续的数据空间，可当成是数组对待，故可以用[]操作
	}
	return p;
}
void test_06()
{
	int *p = getIntArray();
	if (p != NULL)
	{
		for (int i = 0; i < 5; i++)
		{
			printf("%d\n", p[i]);
		}
	}
	free(p);
	p = NULL;

}

// ANSI并没有统一标准，有些编译器可以修改字符串常量有些不可以。
//而且，有些编译器把相同的多个字符串常量看成是同一个，优化内存空间
void test_07()
{
	char* p1 = "hello,world!";// 字符串本身保存在 全局区的字符串常量区
	char* p2 = "hello,world!";
	printf("%d\n", p1);
	printf("%d\n", p2);
	printf("%d\n", &"hello,world!");// 内存地址均相同
	// 修改
	//p1[0] = 'z'; // 不能修改，修改会报错
	printf("%c\n", p1[0]);
}


//calloc and realloc
	// malloc 不初始化堆区的内容，而calloc都初始化为0, 且参数为两个
	// 释放操作是一致的
void test_08()
{
	int * p = malloc(sizeof(int) * 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", p[i]);
	}
	int *p2 = calloc(10, sizeof(int));
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", p2[i]);
	}
	free(p);
	free(p2);
	p = NULL;
	p2 = NULL;

}

//realloc的机制
//如果比原来的内存要大， 有两种分配情况：
//1 如果原来的空间后面有足够大的空闲空间，那么直接在后面继续开辟内存，返回原有的首地址
//2 否则，那么系统会直接分配一个新的空间，这个新空间就是需要的内存大小空间，
//  并且，将原来空间下的数据拷贝到新空间下，并且将原有的空间释放，返回新空间的首地址
void test_09()
{
	int * p = malloc(sizeof(int) * 10);
	printf("point  addr = %d\n", p);
	for (int idx = 0; idx < 10; idx++)
	{
		p[idx] = idx + 1;
	}
	int * newp = realloc(p, 20 * sizeof(int));// 11 两次的地址是一致的，20是不一样的
	printf("new point  addr = %d\n", newp);//
	printf("\n");
	for (int idx = 0; idx < 20; idx++) // 利用realloc开辟的空间，未使用的部分和malloc开辟空间是一致的，均是无意义的数
	{
		printf("%d\n", newp[idx]);
	}
}