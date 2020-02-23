#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// 指针越界
void test_11()
{
	char str[3] = "who";//其实是四个字符，还隐含一个\0, 但是只copy了前三个字母
	printf("%s", str);// 不一定什么时候结束

}
// 指针叠加会修改指针指向
void test_12()
{
	char* p = malloc(sizeof(char) * 100);
	// 合理的形式是定义一个临时变量指针，利用临时变量去操作赋值
	char *p2 = p;
	for (size_t i = 0; i < 10; i++)
	{
		p[i] = i + 97;// abcde...
		printf("%c", p[i]);
		p++;//地址会增加！
	}
	//这里没有权限释放，因为非申请的内存的首地址
	free(p);
	p = NULL;
}
//两次释放指针(不能释放野指针）
void test_13()
{
	char* p = NULL;
	p = malloc(50);
	strcpy(p, "abcdef");
	if (p != NULL)
	{
		free(p);
	}
	//由于前面释放了内存之后，没有赋值为空，导致再次被释放，造成奔溃
	//所以，一定要在free 之后 令p = null；
	if (p != NULL)
	{
		free(p);
	}
}

