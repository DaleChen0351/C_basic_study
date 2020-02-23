#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h> // offsetof()


// void* ָ��
void test_01()
{
	void* p = NULL;
	int *pint = NULL;
	char *pchar = NULL;

	pchar = p;//����ָ�룬����Ҫǿ������ת���Ϳ��Ը��Ⱥ���߸�ֵ
	printf("sizeof p = %d\n", sizeof p);
	printf("sizeof pint = %d\n ", sizeof pint);
}
// �Զ�����������ͨ��ָ���޸�ֵ
struct Person {
	char a;
	int b;
	char c;
	int d;
};
// �Զ����������� ͨ��ָ���޸�
void test_02()
{
	struct Person p = { 'a', 1,'c',10 };
	//��ʽһ
	struct Person*pp = NULL;
	pp = &p;
	pp->d = 1000;
	printf("d = %d\n", pp->d);

	// ��ʽ�� ͨ����ַƫ��
	char* pchar = NULL;
	pchar = pp;
	*(int*)(pchar + 12) = 2000;// �ڴ����

	printf("d = %d\n", pp->d);

	// ��ʽ�� ͨ����ַƫ��
	int* pint = pp;
	*(pint + 3) = 3000;
	printf(" d = %d\n", pp->d);
	// int*


}

// �������������û�и�ָ������ڴ棬����������ͬ����ָ�����޷��޸����������е�ָ�������ָ��ģ�ֻ���޸ĺ������βΣ�
// ����ָ��
typedef char* PCHAR;
void allocateSpace(PCHAR* pp)
{
	PCHAR temp = malloc(100);
	memset(temp, 0, 100);
	strcpy(temp, "hello,world!");
	for (int i = 0; i < 20; i++)
	{
		printf("%c", temp[i]);
	}
	*pp = temp;
}
void test_03()
{
	PCHAR p = NULL;
	allocateSpace(&p);
	printf("%s\n", p);
	free(p);
	p = NULL;
}

// 
//��ָ��
//��������NULL �ͷǷ���ַ�����ڴ�
void test_04()
{
	//char *p = NULL;
	char* p = 0x1122;
	strcpy(p, "1111");//�ڴ���ʳ�ͻ
	printf("%s", *p);
}
//Ұָ��
//1 ������δ��ʼ����ָ��
//2 malloc��free�ͷ��ڴ棬����ָ��û���ÿգ�Ȼ�������
//3 ָ��Ĳ�����Խ������������
void test_05()
{
	//char* p = NULL;
	//printf("%s", *p);//������δ��������쳣:��ȡ����Ȩ�޳�ͻ�� 	p �� nullptr��
    
	int* pc = malloc(sizeof(int));
	*pc = 20;
	printf("pc = %d\n", *pc);
	free(pc);
		//pc = NULL; //��ʹ����ָ��һ��Ҫָ��NULL�������Ļ����������������ʹ���˴�ָ������˽����ò����������ֱ�ӱ����������������������ֵ
	printf("pc = %d\n", *pc);//�˴���ֵ���������
}
//�ͷſ�ָ�룬�ǿ��Ե�
//Ұָ�벻�����ظ��ͷ�
//�ͷ�֮����ڴ棬�Ѿ�û��Ȩ�޽��в�������������ȥfree���൱������ȥ����,�ᱼ��

//ָ��Ĳ���
	//1 ָ����� +1֮�� ��Ծ���ֽ�����
void test_06()
{
	char* p1 = NULL;
	printf("p1 addr = %d\n", p1);
	p1++;
	printf("p1 addr = %d\n", p1);

	float* p2 = NULL;
	printf("p2 addr = %d\n", p2);
	printf("p2 addr = %d\n", p2+1);
	printf("p2 addr = %d\n", p2 + 2);

	int num = 0xaabbccdd;
	unsigned char* pp = &num;//����밴���ֽ�ȡ����һ��Ҫ��unsigned char*
	printf("%x\n", *(pp+3));// ���λ aa
	printf("%x\n", *pp);// ���λdd

}
	// 2.1�����õ�ʱ��ȡ���ֽ��� 
void test_07()
{
	int a = 1000;
	char* p = &a;
	printf("a = %d", *(int*)p);
}
struct Student
{
	char group;
	int age;
	char name[64];
	int size;
};
	//2.2 �Զ�����������
		//����ṹ�������Ե�ƫ������offsetof(struct name, feature name);  #include <stddef.h>
void test_08()
{
	printf("sizeof stu = %d\n", sizeof(struct Student));// 76 Ҳ����˵��sizeof�������ʵ�ʷ�����ڴ��С���ڴ���뵼�µ��˷�ҲҪ����
	//����ṹ���ƫ����
	printf("int size ��ƫ���� = %d\n", offsetof(struct Student, size));// 72

	struct Student stu = { "A",22,"hello,world!",100 };
	char* p = &stu;
	printf("stu.size = %d\n", *(int*)(p + offsetof(struct Student, size)));
}
// ָ��ļ�Ӹ�ֵ��1 һ��ָ����� һ����ͨ���� 2 ������ϵ 3 ����* �Ž����ø�ֵ
	//ͨ������
	//ͨ����ַ
		// ��Qt�п��ԣ�*(int*)268464 = 1000;// ���ڴ��ַ intֵǿ��ת����һ��ָ��

//�༶ָ��
void test_09()
{
	int a = 10;
	int *q = &a;
	int **t = &q;
	int ***m = &t;
	//��������ָ��m�޸�a��ֵΪ1000;
	int **t2 = *m;
	int *q2 = *t2;
	*q2 = 1000;
	printf("a = %d", *q2);
}
//ָ������������
	//ָ���������������߱�������������
		//�������ԣ����������з����ڴ棬����������ʹ���ڴ�(ջ�ϺͶ��϶�����)
		//������ԣ����������з����ڴ棬����������ʹ���ڴ�
			// �������������û�и�ָ������ڴ棬����������ͬ����ָ�����޷��޸����������е�ָ�������ָ��ģ�ֻ���޸ĺ������βΣ�
void myprintf(char* s)
{
	printf("string = %s\n",s);
}
//��������
void test_A()
{
	//���䵽ջ��
	char name[64];
	memset(name, 0, 64);
	strcpy(name, "hello,world!");
	myprintf(name);
	//���䵽����
	char* p = malloc(sizeof(char) * 64);
	memset(p, 0, 64);
	strcpy(p, "who is your sister?");
	myprintf(p);
	free(p);
	p = NULL;

}
//�������

void allocatSpace(char** p)
{
	char* temp = malloc(64);
	memset(temp, 0, 64);
	strcpy(temp, "this is good!");
	*p = temp;//temp��ָ��ֵΪnameָ�룬ͨ��ָ�봫��
}
int DirectAddress()
{
	char* temp = malloc(64);
	memset(temp, 0, 64);
	strcpy(temp, "DirectAddress,this is good!");
	
	return (unsigned int)temp;
}

void test_B()
{
	char* name = NULL;//��Ҫ�ı�char*��ֵ
	allocatSpace(&name);
	printf("%s\n", name);
	// ����˵��ָ����Ǳ��ֵĵ�ֵַ��������uint��ʾ��ֵ���ѣ�ûʲô���ص�
	char* addr = NULL;
	unsigned int ret = DirectAddress();
	addr = (char*)ret;
	printf("%s\n", addr);
}



int main()
{
	//test_01();
	//test_03();
	//test_04();
	//test_05();
	//test_06();
	//test_07();
	//test_08();
	//test_09();
	//test_10();
	//test_B();

	//test_11();
	//test_12();
	//test_13();
}