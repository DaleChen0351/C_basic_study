#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 提供代码可一致性
typedef long long INT; // long long => int
void test_01()
{
	typedef char* PCHAR;
	PCHAR P1, P2;

	char* p1, p2;// p2 是char类型


}




// 宏函数
// 要保证运算的完整性才可以
// 宏函数在一定程度上，比普通函数效率高，普通函数会有入栈和出栈时间上的开销
// 我们通常将一些比较频繁 短小的函数封装为宏函数
#define MYADD(x,y)    ((x)+(y))
void test_08()
{
	printf("Myadd = %d\n", MYADD(1, 2));
}
//宏函数
//宏定义不重视作用域
//宏变量没有数据类型
void test_11()
{
#define MAX 1024//从这行开始，一直到文件尾。宏不重视作用域
	

}
//条件编译
#define DEBUG

#ifndef DEBUG    //ifdef
void test_12()
{
	printf("debug版本\n");
}
#else
	#if 0   //条件编译
		void test_12()
		{
			printf("release版本1\n");
		}
	#else
		void test_12()
		{
			printf("release版本2\n");
		}
	#endif

#endif // DEBUG

//特殊的宏
void test_03(int * p)
{
	if (p == NULL)
	{
		printf("文件：%s   的%d行出错了\n", __FILE__, __LINE__);
		printf("%s   %s\n", __DATE__, __TIME__);
		printf("timestamp = %s\n", __TIMESTAMP__);
		
	}
}

int main()
{

	printf("MAX = %d\n", MAX);
	test_12();
	//test_03(NULL);
	system("pause");
	return EXIT_SUCCESS;

	
}
#undef MAX
//卸载宏