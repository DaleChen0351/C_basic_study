#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "seqQueue.h" //只需要包含这个就好，不需要包含动态数组的头文件


//队列是一种特殊的受限的线性表
//队列只允许在一端进行插入，而在另一端进行删除操作的线性表。
//FIFO
//队头(front) 出队列(pop)        队尾(back) 入队列 (push)
//只有队头和队尾元素可以被访问到，其他元素都不可以

struct Person
{
	char name[64];
	int age;
};

void test_01()
{
	struct Person p1 = { "aaa",111 };
	struct Person p2= { "bbb",222 };
	struct Person p3= { "ccc",333 };
	struct Person p4 = { "ddd",444 };
	struct Person p5 = { "eee",555 };
	
	
	
	SeqQueue sq = init_SeqQueue();
	push_SeqQueue(sq, &p1);
	push_SeqQueue(sq, &p2);
	push_SeqQueue(sq, &p3);
	push_SeqQueue(sq, &p4);
	push_SeqQueue(sq, &p5);

	while (size_SeqQueue(sq) > 0)
	{
		struct Person* frontP = front_SeqQueue(sq);
		struct Person* backP = back_SeqQueue(sq);

		printf("FRONT name = %s   age = %d\n", frontP->name, frontP->age);
		printf("BACK   name = %s   age = %d\n", backP->name, backP->age);
		printf("\n");
		pop_SeqQueue(sq);
	}
	destroy_SeqQueue(sq);
	sq = NULL;
}

int main()
{
	test_01();
}