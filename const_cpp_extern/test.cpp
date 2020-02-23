
// C语言中默认前面添加extern，即(const)全局变量 具有外部链接属性。而C++中默认是有内部链接属性

extern int g_a = 99;
extern const int const_g_val = 999;