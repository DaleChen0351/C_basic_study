#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include "test.h" // 方式二

//extern test
void test_01()
{
	// 方式一
	extern int g_b; // 告诉编译器，这个变量是个外部链接的变量，编译当前文件的时候不要报错
	printf("%d\n", g_b);
	extern const const_val;
	printf("%d\n", const_val);
}
// static
static int s_c = 10;
//void test_02()
//{
//	static int l_s_c = 20;
//	int number = 200;
//	printf("%d\n", s_c);
//	printf("局部静态变量的地址是： %d\n", &l_s_c);
//	printf("全局静态变量的地址是： %d\n", &s_c);
//	printf("全局变量的地址是  ：%d\n", &g_b);
//	printf("一般局部变量的地址是：%d\n", &number);
//}

int main()
{
	test_01();
	//test_02();
	system("pause");
}