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
int main()
{
	//test_02();
	//test_03();
	//test_04();
	//test_05();
	//test_06();
	//test_07();
	test_08();
	system("pause");
	return EXIT_SUCCESS;
	
	
}