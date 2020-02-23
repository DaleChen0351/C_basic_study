#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 宏函数 要保证运算的完整性才可以
//宏函数 在一定程度上，会比普通函数效率高，普通函数有入栈和出栈的时间开销
//我们通常将比较频繁和短小的函数封装成宏函数
//优点，以空间换时间，源码替换

#define MYADD(x,y) (x+y)

void test_01()
{
	int num = MYADD(1, 2);
	printf("num = %d\n", num);
}
// 调用惯例
//主调函数和被调函数都必须有一致的约定，才可以正确的调用函数，这个约定叫做调用惯例
//调用惯例的内容 出栈方，参数的传递顺序，和名字修饰
void __cdecl test_02()
{
	printf("默认的调用惯例\n");
}

//栈 stack frame中保存的内容
	//函数的返回地址：
	//函数的参数
	//临时变量
	//函数上下文


//变量的生命周期的问题 // 变量的传递
	//全局区变量、堆区开辟的变量（未释放情况下） 在任何函数中都可以使用
	//局部变量只在作用域内可以被使用，其主调方也不可以使用，因为主调方想使用的时候，局部变量已经被释放了

//栈的生长方向及内存的存储方式
	//栈的生长方向
		//栈底是高地址
		//栈顶是低地址
void test_03()
{
	int a = 10;
	int b = 20;
	int c = 30;
	printf("a addr = %d\n", &a); //先入栈 栈底  -> 高地址
	printf("b addr = %d\n", &b);
	printf("c addr = %d\n", &c);//后入栈 栈顶-> 低地址
}

//内存的存储方式
	//高位字节数据 高地址 //低位字节数据 低地址
		//1 小端对齐
		//2 linux可能是大端对齐
void test_04()
{
	int val = 0xaabbccdd;
	//point
	unsigned  char * p = &val;
	printf("%x\n", *p);// dd      低位字节数据 低地址
	printf("%x\n", *(p+1));//  cc
	printf("%x\n", *(p + 2));// 
	printf("%x\n", *(p + 3));// aa 高位字节数据 高地址

}

int main()
{
	/*test_01();
	test_02();*/
	/*test_03();*/
	test_04();
}