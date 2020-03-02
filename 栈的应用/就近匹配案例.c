#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "seqlist.h"



//�Ƿ���������
int isLeft(char ch)
{
	return ch == '(';
}
//�Ƿ���������
int isRight(char ch)
{
	return ch == ')';
}
void printError( char* ori, char* errCode, char* pos)
{
	printf("Error: %s\n", errCode);
	printf("%s\n", ori);
	int numSpace = (int)(pos - ori);
	for (int i = 0; i < numSpace; i++)
	{
		printf(" ");
	}
	printf("|\n");
}

void test_01()
{
	SeqStack stack = init_SeqStack();
	char* str = "5+5*(6)+9/3*1-(1+3(";
	char* p = str;


	while (*p != 0)
	{
		//�������������������ջ
		if (isLeft(*p))
		{
			push_SeqStack(stack, p);
		}
		//����������ţ�����ջ��ջ��Ԫ��
		if (isRight(*p))
		{
			if (isEmpty_SeqStack(stack))
			{
				printError(str, "û�������ſ���ƥ��������", p);//�������λ���ַ��ĵ�ַ
				return;
			}
			else
			{
				//��Գɹ�
				pop_SeqStack(stack);
			}
		}
		p++;

	}

	//�ж��Ƿ�Ϊ�գ����Ϊ����ƥ��ɹ�������ʧ��
	if (size_SeqStack(stack) == 0)
	{
		printf("ȫ��ƥ��ɹ���\n");
	}
	else
	{
		while (!isEmpty_SeqStack(stack))
		{
			printError(str, "û�������ſ���ƥ��������", top_SeqStack(stack));//�������λ�õĵ�ַ
			pop_SeqStack(stack);
		}
		return;
		
	}
	destroy_SeqStack(stack);
	stack = NULL; 
}


int main()
{
	test_01();
}


//��׺���ʽ ������
//��׺���ʽ ��������
//	����Խ��ǰ�����ȼ�Խ�ߣ���֮