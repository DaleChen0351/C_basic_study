#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// �ṩ�����һ����
typedef long long INT; // long long => int
void test_01()
{
	typedef char* PCHAR;
	PCHAR P1, P2;

	char* p1, p2;// p2 ��char����


}




// �꺯��
// Ҫ��֤����������Բſ���
// �꺯����һ���̶��ϣ�����ͨ����Ч�ʸߣ���ͨ����������ջ�ͳ�ջʱ���ϵĿ���
// ����ͨ����һЩ�Ƚ�Ƶ�� ��С�ĺ�����װΪ�꺯��
#define MYADD(x,y)    ((x)+(y))
void test_08()
{
	printf("Myadd = %d\n", MYADD(1, 2));
}
int main()
{
	//test_02();
	//test_03();
	//test_04();
	//test_05();
	//test_06();
	//test_07();
	test_08();
	system("pause");
	return EXIT_SUCCESS;
	
	
}