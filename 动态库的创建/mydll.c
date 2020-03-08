#include "mydll.h"
// 导入函数
void printResult(int num)
{
	printf("it is dynamic link library, the num = %d", num);
}

//导出函数
int mySub(int a, int b)
{
	int num = a - b;
	printResult(num);
	return num;
}