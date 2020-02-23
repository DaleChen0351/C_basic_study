#include "myheader.h"

//ջ��ע������ 
// ��Ҫ���ؾֲ������ĵ�ַ
char* getString()
{
	char str[] = "hello,world!";// �����ַ�����ջ��
	return str;
}
void test_02()
{
	char* p = NULL;
	p = getString();
	printf("%s\n", p);// ���������� ��0xCC����
	//����
	char* mp = malloc(20);
	printf("%s\n", mp);// �������������������ͣ�0xCD��
}
// �ַ�������������ȫ�������ַ���������
char* getStringHeap()
{
	char* mp = "hello,world!";// �ַ���������ȫ�����е��ַ���������������ָ�룬�õ�ַ������Ϊ�������ý�������ʧ
	return mp;

}
void test_04()
{
	char* p = NULL;
	p = getStringHeap();
	printf("%s\n", p);
}
//Heap �ı�׼����
int* getIntArray()
{
	int* p = malloc(sizeof(int) * 5);
	if (p == NULL)// �ж��Ƿ�ɹ����뵽�ڴ�ռ�
	{
		return NULL;
	}
	for (int i = 0; i < 5; i++)
	{
		p[i] = i + 100;// ���������ݿռ䣬�ɵ���������Դ����ʿ�����[]����
	}
	return p;
}
void test_06()
{
	int *p = getIntArray();
	if (p != NULL)
	{
		for (int i = 0; i < 5; i++)
		{
			printf("%d\n", p[i]);
		}
	}
	free(p);
	p = NULL;

}

// ANSI��û��ͳһ��׼����Щ�����������޸��ַ���������Щ�����ԡ�
//���ң���Щ����������ͬ�Ķ���ַ�������������ͬһ�����Ż��ڴ�ռ�
void test_07()
{
	char* p1 = "hello,world!";// �ַ����������� ȫ�������ַ���������
	char* p2 = "hello,world!";
	printf("%d\n", p1);
	printf("%d\n", p2);
	printf("%d\n", &"hello,world!");// �ڴ��ַ����ͬ
	// �޸�
	//p1[0] = 'z'; // �����޸ģ��޸Ļᱨ��
	printf("%c\n", p1[0]);
}


//calloc and realloc
	// malloc ����ʼ�����������ݣ���calloc����ʼ��Ϊ0, �Ҳ���Ϊ����
	// �ͷŲ�����һ�µ�
void test_08()
{
	int * p = malloc(sizeof(int) * 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", p[i]);
	}
	int *p2 = calloc(10, sizeof(int));
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", p2[i]);
	}
	free(p);
	free(p2);
	p = NULL;
	p2 = NULL;

}

//realloc�Ļ���
//�����ԭ�����ڴ�Ҫ�� �����ַ��������
//1 ���ԭ���Ŀռ�������㹻��Ŀ��пռ䣬��ôֱ���ں�����������ڴ棬����ԭ�е��׵�ַ
//2 ������ôϵͳ��ֱ�ӷ���һ���µĿռ䣬����¿ռ������Ҫ���ڴ��С�ռ䣬
//  ���ң���ԭ���ռ��µ����ݿ������¿ռ��£����ҽ�ԭ�еĿռ��ͷţ������¿ռ���׵�ַ
void test_09()
{
	int * p = malloc(sizeof(int) * 10);
	printf("point  addr = %d\n", p);
	for (int idx = 0; idx < 10; idx++)
	{
		p[idx] = idx + 1;
	}
	int * newp = realloc(p, 20 * sizeof(int));// 11 ���εĵ�ַ��һ�µģ�20�ǲ�һ����
	printf("new point  addr = %d\n", newp);//
	printf("\n");
	for (int idx = 0; idx < 20; idx++) // ����realloc���ٵĿռ䣬δʹ�õĲ��ֺ�malloc���ٿռ���һ�µģ��������������
	{
		printf("%d\n", newp[idx]);
	}
}