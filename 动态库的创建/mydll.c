#include "mydll.h"
// ���뺯��
void printResult(int num)
{
	printf("it is dynamic link library, the num = %d", num);
}

//��������
int mySub(int a, int b)
{
	int num = a - b;
	printResult(num);
	return num;
}