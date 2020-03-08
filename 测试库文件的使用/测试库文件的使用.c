#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mydll.h"

#pragma comment(lib,"./mydll.lib")
int main()
{
	int add = myAdd(10, 20);
	printf("add = %d\n", add);
	int num = mySub(20, 10);
	printf("ceshi num  = %d\n", num);

}