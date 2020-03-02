#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "seqQueue.h" //ֻ��Ҫ��������ͺã�����Ҫ������̬�����ͷ�ļ�


//������һ����������޵����Ա�
//����ֻ������һ�˽��в��룬������һ�˽���ɾ�����������Ա�
//FIFO
//��ͷ(front) ������(pop)        ��β(back) ����� (push)
//ֻ�ж�ͷ�Ͷ�βԪ�ؿ��Ա����ʵ�������Ԫ�ض�������

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