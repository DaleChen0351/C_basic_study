#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkList.h"

void test_51()
{
	struct LinkNode* pHeader = init_LinkList_C();
	foreach_LinkList_C(pHeader);

}
int main()
{
	test_51();
	system("pause");
}