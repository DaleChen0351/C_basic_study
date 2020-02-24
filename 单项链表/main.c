#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkList.h"

void test_51()
{
	struct LinkNode* pHeader = init_LinkList_C();
	foreach_LinkList_C(pHeader);
	printf("\n");
	insert_LinkList_C(pHeader,10,100);
	insert_LinkList_C(pHeader, 20, 200);
	insert_LinkList_C(pHeader, -1, 300);
	foreach_LinkList_C(pHeader);
	//100 10 200 20 30 300

	remove_LinkList_C(pHeader, 10);
	remove_LinkList_C(pHeader, 300);
	remove_LinkList_C(pHeader, 310);
	printf("删除一些值后：\n");
	foreach_LinkList_C(pHeader);//100  200 20 30 

	clear_LinkList_C(pHeader);
	printf("清空链表后：\n");
	foreach_LinkList_C(pHeader);
	insert_LinkList_C(pHeader, 111, 111);
	insert_LinkList_C(pHeader, 222, 222);
	insert_LinkList_C(pHeader, 333, 333);
	printf("清空后重新插入新值：\n");
	foreach_LinkList_C(pHeader);
	destroy_LinkList(pHeader);
	pHeader = NULL;


}
int main()
{
	test_51();
	system("pause");
}