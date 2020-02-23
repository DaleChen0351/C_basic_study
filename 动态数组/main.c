#define _CRT_SECURE_NO_WARNINGS
#include "dynamicArray.h"


//Person
struct Person
{
	char name[64];
	int age;
};

// �ص�����
void Myprint(void* val)
{
	struct Person* p = val;
	printf("name = %s   age = %d\n", p->name, p->age);
}

//MyCompare
int MyCompare(void* d1, void* d2)
{
	struct Person* p1 = d1;
	struct Person* p2 = d2;
	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

void test_01()
{
	struct Person p1 = { "����",24 };
	struct Person p2 = { "����",24 };
	struct Person p3 = { "�ŷ�",34 };
	struct Person p4 = { "����",24 };
	struct Person p5 = { "��",54 };
	struct Person p6 = { "��Τ",22 };

	struct dynamicArray* dp =  init_DynamicArray(5);
	
	printf("capacity = %d\n", dp->m_capacity);
	insert_dynamicArray(dp, 0, &p1);//
	insert_dynamicArray(dp, 0, &p2);
	insert_dynamicArray(dp, 0, &p3);
	insert_dynamicArray(dp, 2, &p4);
	insert_dynamicArray(dp, 10, &p5);
	insert_dynamicArray(dp, 1, &p6);
	//�ŷ� ��Τ ���� ���� ���� ��
	//printf("capacity = %d\n ", dp->m_capacity);
	for_each_dynamicArray(dp, Myprint);
	//
	printf("����λ��ɾ��Ԫ�أ�pos =1 \n");
	removeByPos_dynamicArray(dp, 1);
	for_each_dynamicArray(dp, Myprint);

	struct Person d_data = { "��",54 };
	printf("����ֵɾ��Ԫ�� ��\n");
	removeByValue_dynamicArray(dp, &d_data, MyCompare);
	for_each_dynamicArray(dp, Myprint);

	destory_dynamicArray(dp);

}

int main()
{
	test_01();
	system("pause");
}
