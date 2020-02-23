#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//需求：从文件中读取数据，并且将数据存放到一个堆区的一个数组中 malloc(sizeof(char*)*len)

//问题：文本文件读到的每一行结尾是什么？换行符肯定有，那么还有没有 '\0'呢？

//获取有效行数
int getFileLen(FILE* f)
{
	if (f == NULL)
	{
		return -1;
	}
	char buf[1024];//？需要初始化么？
	int num = 0;
	while (fgets(buf, 1024, f))//这里会修改指针光标，遍历文件时，文件光标会移动
	{
		num++;
	}
	//注意：将文件光标 置为文件首
	fseek(f, 0, SEEK_SET);//从文件头部，偏移0个位置

	return num;
}
//读取文件数据
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
	char buf[1024];//？需要初始化么？
	int index = 0;
	while (fgets(buf, 1024, f))
	{
		int currentLen = strlen(buf) + 1;// 
		char* currentP = malloc(sizeof(char)*currentLen);
		//将读到的数据拷贝到堆区内存中
		strcpy(currentP, buf);//相关与
		p[index++] = currentP;
		//清空缓存区
		memset(buf, 0, 1024);
	}
	
}
//打印数据
void printFile(char** p, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("第%d行的数据为：%s", i + 1, p[i]);
	}
}
//释放空间
void freeSpace(char** p, int len)
{
	//先释放每个字符串的堆区空间
	for (int i = 0; i < len; i++)
	{
		if (p[i] != NULL)
		{
			free(p[i]);
		}
	}
	//再释放存放子字符串首地址的空间
	free(p);
	p = NULL;//栈区上的变量，函数结束后，系统会自动回收的，也不可以不写这行代码
}
void test_21()
{
	FILE* file;
	file= fopen("a.txt", "r");
	int len = getFileLen(file);
	//
	char** pLine = malloc(sizeof(char*)*len);
	//将文件中的数据，读取后放到pLine中
	readFile(pLine, len,file);
	//打印数据
	printFile(pLine, len);
	//释放空间
	freeSpace(pLine, len);
	pLine = NULL;//防止变成野指针
	



}

