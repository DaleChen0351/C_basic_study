#define _CRT_SECURE_NO_WARNINGS
#include "dynamicArray.h"


//Person
struct Person
{
	char name[64];
	int age;
};

// 回调函数
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
	struct Person p1 = { "赵云",24 };
	struct Person p2 = { "吕布",24 };
	struct Person p3 = { "张飞",34 };
	struct Person p4 = { "关羽",24 };
	struct Person p5 = { "马超",54 };
	struct Person p6 = { "典韦",22 };

	struct dynamicArray* dp =  init_DynamicArray(5);
	
	printf("capacity = %d\n", dp->m_capacity);
	insert_dynamicArray(dp, 0, &p1);//
	insert_dynamicArray(dp, 0, &p2);
	insert_dynamicArray(dp, 0, &p3);
	insert_dynamicArray(dp, 2, &p4);
	insert_dynamicArray(dp, 10, &p5);
	insert_dynamicArray(dp, 1, &p6);
	//张飞 典韦 吕布 关羽 赵云 马超
	//printf("capacity = %d\n ", dp->m_capacity);
	for_each_dynamicArray(dp, Myprint);
	//
	printf("按照位置删除元素，pos =1 \n");
	removeByPos_dynamicArray(dp, 1);
	for_each_dynamicArray(dp, Myprint);

	struct Person d_data = { "马超",54 };
	printf("按照值删除元素 ：\n");
	removeByValue_dynamicArray(dp, &d_data, MyCompare);
	for_each_dynamicArray(dp, Myprint);

	destory_dynamicArray(dp);

}

int main()
{
	test_01();
	system("pause");
}
