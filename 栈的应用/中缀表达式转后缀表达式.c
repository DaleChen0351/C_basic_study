#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "seqlist.h"
#include "chararray.h"

//外部函数和变量
extern int isLeft(char ch);
extern int isRight(char ch);

//全局变量
CharArray c_arr = NULL;
SeqStack stack = NULL;
SeqStack stack2 = NULL;


//辅助函数
int isNumber(char ch)
{
	return 1;
}
int isSignal(char ch)
{
	return 1;
}
//优先级比较·
int SignalCompare(char a, char b)
{
	return 1;
}

//中缀表达式转后缀表达式
void test_11()
{
	stack = init_SeqStack();
	char* str = "8+(3-1)*5";
	char* pos = str;
	c_arr = init_CharArray();
	
	while (*pos != 0)
	{
		if (isNumber(*pos))
		{
			push_CharArray(c_arr,pos);
		}
		else
		{
			if (isLeft(*pos))
			{
				push_SeqStack(stack, pos);
			}
			else
			{
				if (isSignal(*pos))
				{
					//还需验证不为空栈
					char *temp = top_SeqStack(stack);
					//若栈顶元素优先级低，则此符号进栈
					if (SignalCompare(*pos, *temp))
					{
						push_SeqStack(stack, pos);
					}
					else
					{
						push_CharArray(c_arr, pop_SeqStack(stack));
					}
				}
				else
				{
					if (isRight(*pos))
					{
						while ('(' != pop_SeqStack(stack)){}
					}
				}
			}
		}

		pos++;
	}

	while (!isEmpty_SeqStack(stack))
	{
		push_CharArray(c_arr, pop_SeqStack(stack));
	}
	
}

char SignalCalcu(char* left, char*right)
{
	return (*left + *right);
}
void MyCalculat(char c)
{
	if (isNumber(c))
	{
		//入栈
		push_SeqStack(stack2, &c);
	}
	else
	{
		if (isSignal(c))
		{
			char* right = pop_SeqStack(stack2);
			char* left = pop_SeqStack(stack2);
			char temp = SignalCalcu(left, right);
			push_SeqStack(stack2, &temp);
		}
	}

}
void test_12()
{
	stack2 = init_CharArray();
	int len = size_CharArray(c_arr);
	foreach_CharArray(c_arr, MyCalculat);
	char end = top_SeqStack(stack2);
}