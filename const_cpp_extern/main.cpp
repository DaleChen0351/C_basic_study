#include <string>
#include <iostream>
using namespace std;
//（const )全局变量在C++中默认为是内部链接属性，需要在定义的位置增加前缀 "extern" 
// 而在C语言中，默认为外部链接属性，不需要显式定义extern 前缀
void test_01()
{
	extern int g_a;
	extern const int const_g_val;
	cout << "g_a = " << g_a << endl;
	cout << " const_g_val = " << const_g_val << endl;
}
// 在C++中，const修饰的局部变量所形成的常量，是真正的常量，不可以被直接或者间接修改。
// 利用的方式是一种“符号表”的形式。
// 可作为定义数组中的常数
void test_02()
{
	const int c_l_num = 5;
	int* p = (int*)&c_l_num;
	*p = 6;
	int arr[c_l_num] = {};
	cout << "sizeof(arr) = " << sizeof arr << endl;
	cout << "len(arr) = " << sizeof(arr) / sizeof(int) << endl;// 长度为5

}
//const 分配内存
// 对局部常量取地址会造成系统在栈上分配临时变量的内存空间
void test_03()
{
	const int num = 20;
	int* p = (int*)&num;// 会复制生成一个临时变量temp,并返回此变量的地址
	*p = 300;// 故修改的值为temp的值，所以原值num不变
	cout << "num = " << num << endl;// 修改失败

}
// 使用其他的变量来初始化const修饰的变量也会分配内存
void test_04()
{
	int a = 3;
	const int num = a;
	int* p = (int*)&num;// 
	*p = 300;//
	cout << "num = " << num << endl;// 修改成功
}
// const 修饰的自定义类型的局部变量，可通过指针间接修改其值
struct Person
{
	int age;
	string name;
};
void test_05()
{
	const Person p = {22,"Joyce"};
	cout << p.age << " " << p.name << endl;
	// 修改
	Person* ptr = (Person*)&p;
	ptr->age = 30;
	ptr->name = "Bob";
	cout << p.age << " " << p.name << endl;// 修改成功

}
// extern + const int num = 100 全局常量也会分配内存，通过指针修改可通过编译，语法正确，但会造成运行错误
// 原因在于被const修饰的全局变量内存分配在全局区中的常量取，受到写保护
int main()
{
	//test_01();
	//test_02();
	//test_03();
	//test_04();
	test_05();
	system("pause");
}