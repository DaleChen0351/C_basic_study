#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// ָ��Խ��
void test_11()
{
	char str[3] = "who";//��ʵ���ĸ��ַ���������һ��\0, ����ֻcopy��ǰ������ĸ
	printf("%s", str);// ��һ��ʲôʱ�����

}
// ָ����ӻ��޸�ָ��ָ��
void test_12()
{
	char* p = malloc(sizeof(char) * 100);
	// �������ʽ�Ƕ���һ����ʱ����ָ�룬������ʱ����ȥ������ֵ
	char *p2 = p;
	for (size_t i = 0; i < 10; i++)
	{
		p[i] = i + 97;// abcde...
		printf("%c", p[i]);
		p++;//��ַ�����ӣ�
	}
	//����û��Ȩ���ͷţ���Ϊ��������ڴ���׵�ַ
	free(p);
	p = NULL;
}
//�����ͷ�ָ��(�����ͷ�Ұָ�룩
void test_13()
{
	char* p = NULL;
	p = malloc(50);
	strcpy(p, "abcdef");
	if (p != NULL)
	{
		free(p);
	}
	//����ǰ���ͷ����ڴ�֮��û�и�ֵΪ�գ������ٴα��ͷţ���ɱ���
	//���ԣ�һ��Ҫ��free ֮�� ��p = null��
	if (p != NULL)
	{
		free(p);
	}
}

