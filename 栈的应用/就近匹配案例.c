#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "seqlist.h"



//是否是左括号
int isLeft(char ch)
{
	return ch == '(';
}
//是否是右括号
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
		//如果遇到了左括号则入栈
		if (isLeft(*p))
		{
			push_SeqStack(stack, p);
		}
		//如果是右括号，弹出栈中栈顶元素
		if (isRight(*p))
		{
			if (isEmpty_SeqStack(stack))
			{
				printError(str, "没有左括号可以匹配右括号", p);//传入出错位置字符的地址
				return;
			}
			else
			{
				//配对成功
				pop_SeqStack(stack);
			}
		}
		p++;

	}

	//判断是否为空，如果为空则匹配成功，否则失败
	if (size_SeqStack(stack) == 0)
	{
		printf("全部匹配成功！\n");
	}
	else
	{
		while (!isEmpty_SeqStack(stack))
		{
			printError(str, "没有右括号可以匹配左括号", top_SeqStack(stack));//传入出错位置的地址
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


//中缀表达式 人类用
//后缀表达式 计算器用
//	符号越往前，优先级越高，反之