#define _CRT_SECURE_ NO_WARNINGS

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h> //offsetof




struct Cat
{
	char a;
	int b;
};
//ƫ�����ļ���
	//��������offsetof������ṹ���е�����ƫ��
	//�������Եĵ�ַ - �ṹ��ĵ�ַȻ��ǿ��ת��Ϊ(int) ����������
void test_51()
{
	struct Cat cat = { 'h',17 };
	//��ʽһ��offsetof
	printf("b����ƫ����Ϊ: %d\n", offsetof(struct Cat, b));
	//��ʽ�������Եĵ�ַ - �ṹ����׵�ַ
	int offset = (int)&cat.b - (int)&cat;
	printf("b����ƫ����Ϊ: %d\n", offset);

}


//ͨ��ƫ���� ��õ�����
void test_52()
{
	struct Cat cat = { 'h',17 };
	char* p = (char*)&cat;
	printf("cat b = %d\n", *((int*)(p + offsetof(struct Cat, b))));
	printf("cat b = %d\n", *((int*)&cat + 1));
}
 
//�ṹ��Ƕ�׽ṹ��
struct Cat2
{
	char c;
	int d;
	struct Cat cat;
};
//���ʣ�����չ������
void test_53()
{
	struct Cat2 cat2 = { 'h',17,'e',20 };
	//����offsetof����ƫ����
	int offset1 = offsetof(struct Cat2,cat);
	int offset2 = offsetof(struct Cat, b);
	printf("cat b = %d\n", *((int*)((char*)&cat2 + offset1 + offset2)));// 20
	printf("cat b = %d\n", ((struct Cat*)((char*)&cat2 + offset1))->b);
}


void main_05()
{
	//test_51();
	//test_52();
	test_53();
}