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
//�꺯��
//�궨�岻����������
//�����û����������
void test_11()
{
#define MAX 1024//�����п�ʼ��һֱ���ļ�β���겻����������
	

}
//��������
#define DEBUG

#ifndef DEBUG    //ifdef
void test_12()
{
	printf("debug�汾\n");
}
#else
	#if 0   //��������
		void test_12()
		{
			printf("release�汾1\n");
		}
	#else
		void test_12()
		{
			printf("release�汾2\n");
		}
	#endif

#endif // DEBUG

//����ĺ�
void test_03(int * p)
{
	if (p == NULL)
	{
		printf("�ļ���%s   ��%d�г�����\n", __FILE__, __LINE__);
		printf("%s   %s\n", __DATE__, __TIME__);
		printf("timestamp = %s\n", __TIMESTAMP__);
		
	}
}

int main()
{

	printf("MAX = %d\n", MAX);
	test_12();
	//test_03(NULL);
	system("pause");
	return EXIT_SUCCESS;

	
}
#undef MAX
//ж�غ�