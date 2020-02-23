
//1 不同类型的变量保存在内存的不同区域
// 2 内存四区。 程序运行前：代码区和全局区 程序运行后：栈区和堆区（C++中实现）
#include <string>
#include <iostream>
#include "myheader.h"
using namespace std;


// 全局变量
int g_a = 20;
int g_b = 200;
// 全局常量
const int c_g_a = 200;
const int c_g_b = 2000;
//// 全局静态变量
//static int s_g_a = 100;
//static int s_g_b = 1000;
void test_1()
{
	int l_a = 10;
	int l_b = 100;
	cout << "局部变量地址：" << &l_a << endl;
	cout << "局部变量地址：" << &l_b << endl;

	//const and local
	const int c_l_a = 200;
	const int c_l_b = 2000;

	cout << "局部常量地址：" << &c_l_a << endl;
	cout << "局部常量地址：" << &c_l_b << endl;
	cout << endl;
	cout << "全局变量地址: " << &g_a << endl;
	cout << "全局变量地址: " << &g_b << endl;

	//staitc var
	static int s_l_a = 100;
	static int s_l_b = 1000;
	cout << "局部静态变量：" << &s_l_a << endl;
	cout << "局部静态变量：" << &s_l_b << endl;

	//cout << "全局静态变量：" << &s_g_a << endl;
	//cout << "全局静态变量：" << &s_g_b << endl;


	cout << "全局常量地址：" << &c_g_a << endl;
	cout << "全局常量地址：" << &c_g_b << endl;

	cout << "字符串常量地址：" << &"hello,world!" << endl;//?

	cout << endl;
	int * p1 = new int(10);
	int * p2 = new int(20);
	cout << "动态内存分配地址：" << p1 << endl;
	cout << "动态内存分配地址：" << p2 << endl;



}
// 栈区
// 局部变量和形参地址均由编译器自动分配，函数执行结束后，内存空间释放
void test_stack(int val)
{
	int b = 100;
	cout << "局部变量地址：" << &b << endl;
	cout << "形参变量地址：" << &val << endl;
}
void test_3()
{
	test_stack(10);
}

//  堆区
// new and delete
void test_5()
{
	int * arr = new int[10];
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl; // 不会初始化为0,乱码
		arr[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	delete[]arr;
}

 

extern "C" void test_08();
extern "C" void test_09();

int  main()
{
    //test_02();
	//test_07();
	//test_08();
	test_09();
	system("pause");
}


// 总结
//静态变量
// 1 只初始化一次，在编译阶段就分配内存，属于内部链接属性，只能在当前文件中使用
// 2 static + 任何变量，就是静态变量，声明周期从编译开始，到程序结束 

// const修饰的变量
//1 const+全局变量，无法修改，受全局常量区保护
//2 const+ 局部变量， 分配到栈上，直接修改编译错误，间接修改成功，在C语言下，是伪常量，所以不能初始化数组

// 字符串常量
// ANSI并没有统一标准，有些编译器可以修改字符串常量有些不可以。
//而且，有些编译器把相同的多个相同内容字符串常量看成是同一个，优化内存空间，地址一致







