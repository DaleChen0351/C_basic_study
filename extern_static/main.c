#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include "test.h" // ��ʽ��

//extern test
void test_01()
{
	// ��ʽһ
	extern int g_b; // ���߱���������������Ǹ��ⲿ���ӵı��������뵱ǰ�ļ���ʱ��Ҫ����
	printf("%d\n", g_b);
	extern const const_val;
	printf("%d\n", const_val);
}
// static
static int s_c = 10;
//void test_02()
//{
//	static int l_s_c = 20;
//	int number = 200;
//	printf("%d\n", s_c);
//	printf("�ֲ���̬�����ĵ�ַ�ǣ� %d\n", &l_s_c);
//	printf("ȫ�־�̬�����ĵ�ַ�ǣ� %d\n", &s_c);
//	printf("ȫ�ֱ����ĵ�ַ��  ��%d\n", &g_b);
//	printf("һ��ֲ������ĵ�ַ�ǣ�%d\n", &number);
//}

int main()
{
	test_01();
	//test_02();
	system("pause");
}