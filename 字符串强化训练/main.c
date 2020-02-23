#define  _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
// 字符串是以 0 或者'\0'结尾的字符数组，数字 0  和字符 '\0' 等价
void printStringInfo(char str[])
{
	int len = strlen(str);// strlen获得实际的字符串中字符的多少
	char temp[100];
	for (int i = 0; i < len; i++)
	{
		temp[i] = str[i];
	}
	temp[len] = 0;
	
	printf("str = %s\n", temp);
	printf("strlen str = %d\n", strlen(temp));	
}
void test_01()
{
	// 一般字符串
	char str1[] = "helloworld";// 双引号相当于是以字符串初始化，那么编译器会在字符串尾部自动添加 '\0'
	printStringInfo(str1);
	printf("sizeof str = %d\n", sizeof str1);
	printf("\n");
	//不写 \n
	char str2[] = { 'h','e','l' ,'l','o' };// 会出现乱码，栈区会变成 烫，直到后面的 \n
	printStringInfo(str2);
	printf("sizeof str = %d\n", sizeof str2);// 5
	printf("\n");
	// 开辟100个字符串
	char str3[100] = { 'h','e','l' ,'l','o' };// 会开辟出100个长度的字符数组，且初始值默认设为0
	printStringInfo(str3);
	printf("sizeof str = %d\n", sizeof str3);
	printf("\n");
	//最后加个 0 
	char str4[] = { 'h','e','l' ,'l','o' , 0}; // or  '\0'
	printStringInfo(str4);
	printf("sizeof str = %d\n", sizeof str4);
	printf("\n");
}
// sizeof 包含字符串的结束符
// strlen 不包含
void test_02()
{
	char str1[] = "hello\0world";
	printf("str = %s\n", str1);
	printf("sizeof str = %d\n", sizeof str1);//12
	printf("strlen str = %d\n", strlen(str1));//5

	char str2[] = "hello\012world";// 012 是八进制的 10 即 0x0A 在表中未换行符
	printf("str = %s\n", str2);
	printf("sizeof str = %d\n", sizeof str2);//12
	printf("strlen str = %d\n", strlen(str2));//11

	char str3[] = "hello\xAworld!";// 0\xA 回车
	printf("str = %s", str3);
}
// 字符串的三种拷贝方式
// 1  利用[]
void copyString(char* dest, const char* source)
{
	int len = strlen(source);
	for (int i = 0; i < len; i++)// 可打印出来的字符个数
	{
		dest[i] = source[i];
	}
	dest[len] = 0;
}
//2 指针遍历拷贝
void copyString2(char* dest, const char* source)
{
	while (*source !=  0)
	{
		*dest = *source;
		dest++;
		source++;
	}
	*dest = 0;
}
//3 while
void copyString3(char* dest, const char* source)
{
	while (*dest++ = *source++) {};
}
void test_03()
{
	char* str = "hello world!";
	char buf[100];
	copyString(buf,str);
	printf("buf1 = %s\n", buf);

	copyString2(buf, str);
	printf("buf2= %s\n", buf);

	copyString3(buf, str);
	printf("buf3= %s\n", buf);
}

int g_val = 0;
void test_04()
{
	char * const_str = "hello, world!";// 至少在VS里面，这种初始化方式，是为常量字符串的，不能修改，所以在这个问题中不用 在全局区的
	char str[100] = "hello, world!";
	printf("const_str addr = %d\n", const_str);
	printf("str addr = %d\n", str);
	int temp = 0;
	printf("int temp addr = %d\n", &temp);
	printf("int g_val addr = %d\n", &g_val);
}
// 字符串翻转 1 
void reverseString(char * str)
{
	int len = strlen(str);
	//记录下标
	int start = 0;
	int end = len - 1;
	while (start < end)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;

		start++;
		end--;
	}
}
// 字符串翻转2 利用指针
void reverseString2(char* str)
{
	int len = strlen(str);
	char* pstart = str;
	char* pend = str + len - 1;// 结束位置的指针
	while (pstart < pend)
	{
		char temp = *pstart;
		*pstart = *pend;
		*pend = temp;

		pstart++;
		pend--;
	}

}
void test_05()
{
	char str[100] = "hello,world!";
	printf("str = %s\n", str);
	reverseString2(str);
	printf("str = %s\n", str);
}
//sprintf()函数
void test_06()
{
	// 打印日期
	char buf[100];
	memset(buf, 0, 100);

	sprintf(buf, "今天是%d年%d月%d日", 2020, 2, 13);
	// 字符串拼接
	memset(buf, 0, 100);
	char str1[] = "hello";
	char str2[] = "world";
	int len =  sprintf(buf, "%s%s",str1,str2);
	// 数字转字符串
	int num = 100;
	memset(buf, 0, 100);
	len = sprintf(buf, "num = %d", num);
	// 设置宽度 - 数字转字符串
	memset(buf, 0, 100);
	len = sprintf(buf, "%-8dA", num);//% -8d
	// 打印十六进制小写
	memset(buf, 0, 100);
	len = sprintf(buf, "num = 0x%x", num);
	// 打印八进制
	memset(buf, 0, 100);
	len = sprintf(buf, "num = 0%o", num);

	//打印
	printf("len = %d\n", len);
	printf("%s\n", buf);

}
int main()
{
	test_01();
	//test_02();
	//test_03();
	//test_04();
	//test_05();
	//test_06();
	system("pause");

	char* str = "123";// 字符串常量不可以修改
}