#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//���󣺴��ļ��ж�ȡ���ݣ����ҽ����ݴ�ŵ�һ��������һ�������� malloc(sizeof(char*)*len)

//���⣺�ı��ļ�������ÿһ�н�β��ʲô�����з��϶��У���ô����û�� '\0'�أ�

//��ȡ��Ч����
int getFileLen(FILE* f)
{
	if (f == NULL)
	{
		return -1;
	}
	char buf[1024];//����Ҫ��ʼ��ô��
	int num = 0;
	while (fgets(buf, 1024, f))//������޸�ָ���꣬�����ļ�ʱ���ļ������ƶ�
	{
		num++;
	}
	//ע�⣺���ļ���� ��Ϊ�ļ���
	fseek(f, 0, SEEK_SET);//���ļ�ͷ����ƫ��0��λ��

	return num;
}
//��ȡ�ļ�����
void readFile(char** p, int len, FILE* f)
{
	if (p == NULL)
	{
		return;
	}
	if (len <= 0)
	{
		return;
	}
	if (f == NULL)
	{
		return;
	}
	char buf[1024];//����Ҫ��ʼ��ô��
	int index = 0;
	while (fgets(buf, 1024, f))
	{
		int currentLen = strlen(buf) + 1;// 
		char* currentP = malloc(sizeof(char)*currentLen);
		//�����������ݿ����������ڴ���
		strcpy(currentP, buf);//�����
		p[index++] = currentP;
		//��ջ�����
		memset(buf, 0, 1024);
	}
	
}
//��ӡ����
void printFile(char** p, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("��%d�е�����Ϊ��%s", i + 1, p[i]);
	}
}
//�ͷſռ�
void freeSpace(char** p, int len)
{
	//���ͷ�ÿ���ַ����Ķ����ռ�
	for (int i = 0; i < len; i++)
	{
		if (p[i] != NULL)
		{
			free(p[i]);
		}
	}
	//���ͷŴ�����ַ����׵�ַ�Ŀռ�
	free(p);
	p = NULL;//ջ���ϵı���������������ϵͳ���Զ����յģ�Ҳ�����Բ�д���д���
}
void test_21()
{
	FILE* file;
	file= fopen("a.txt", "r");
	int len = getFileLen(file);
	//
	char** pLine = malloc(sizeof(char*)*len);
	//���ļ��е����ݣ���ȡ��ŵ�pLine��
	readFile(pLine, len,file);
	//��ӡ����
	printFile(pLine, len);
	//�ͷſռ�
	freeSpace(pLine, len);
	pLine = NULL;//��ֹ���Ұָ��
	



}

