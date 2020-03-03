#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkQueue.h"

struct Person
{
	void* addr;
	char name[64];
	int age;
};

void test_01()
{
	struct Person p1 = {NULL, "aaa",111 };
	struct Person p2 = {NULL, "bbb",222 };
	struct Person p3 = {NULL, "ccc",333 };
	struct Person p4 = {NULL, "ddd",444 };
	struct Person p5 = {NULL, "eee",555 };



	LinkQueue queue = init_LinkQueue();
	push_LinkQueue(queue, &p1);
	push_LinkQueue(queue, &p2);
	push_LinkQueue(queue, &p3);
	push_LinkQueue(queue, &p4);
	push_LinkQueue(queue, &p5);

	while (size_LinkQueue(queue) > 0)
	{
		struct Person* frontP = front_LinkQueue(queue);
		struct Person* backP = back_LinkQueue(queue);

		printf("FRONT name = %s   age = %d\n", frontP->name, frontP->age);
		printf("BACK   name = %s   age = %d\n", backP->name, backP->age);
		printf("\n");
		pop_LinkQueue(queue);
	}
	destroy_LinkQueue(queue);
	queue = NULL;
}

int main()
{
	test_01();
}