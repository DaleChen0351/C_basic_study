#define  _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
// �ַ������� 0 ����'\0'��β���ַ����飬���� 0  ���ַ� '\0' �ȼ�
void printStringInfo(char str[])
{
	int len = strlen(str);// strlen���ʵ�ʵ��ַ������ַ��Ķ���
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
	// һ���ַ���
	char str1[] = "helloworld";// ˫�����൱�������ַ�����ʼ������ô�����������ַ���β���Զ���� '\0'
	printStringInfo(str1);
	printf("sizeof str = %d\n", sizeof str1);
	printf("\n");
	//��д \n
	char str2[] = { 'h','e','l' ,'l','o' };// ��������룬ջ������ �̣�ֱ������� \n
	printStringInfo(str2);
	printf("sizeof str = %d\n", sizeof str2);// 5
	printf("\n");
	// ����100���ַ���
	char str3[100] = { 'h','e','l' ,'l','o' };// �Ὺ�ٳ�100�����ȵ��ַ����飬�ҳ�ʼֵĬ����Ϊ0
	printStringInfo(str3);
	printf("sizeof str = %d\n", sizeof str3);
	printf("\n");
	//���Ӹ� 0 
	char str4[] = { 'h','e','l' ,'l','o' , 0}; // or  '\0'
	printStringInfo(str4);
	printf("sizeof str = %d\n", sizeof str4);
	printf("\n");
}
// sizeof �����ַ����Ľ�����
// strlen ������
void test_02()
{
	char str1[] = "hello\0world";
	printf("str = %s\n", str1);
	printf("sizeof str = %d\n", sizeof str1);//12
	printf("strlen str = %d\n", strlen(str1));//5

	char str2[] = "hello\012world";// 012 �ǰ˽��Ƶ� 10 �� 0x0A �ڱ���δ���з�
	printf("str = %s\n", str2);
	printf("sizeof str = %d\n", sizeof str2);//12
	printf("strlen str = %d\n", strlen(str2));//11

	char str3[] = "hello\xAworld!";// 0\xA �س�
	printf("str = %s", str3);
}
// �ַ��������ֿ�����ʽ
// 1  ����[]
void copyString(char* dest, const char* source)
{
	int len = strlen(source);
	for (int i = 0; i < len; i++)// �ɴ�ӡ�������ַ�����
	{
		dest[i] = source[i];
	}
	dest[len] = 0;
}
//2 ָ���������
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
	char * const_str = "hello, world!";// ������VS���棬���ֳ�ʼ����ʽ����Ϊ�����ַ����ģ������޸ģ���������������в��� ��ȫ������
	char str[100] = "hello, world!";
	printf("const_str addr = %d\n", const_str);
	printf("str addr = %d\n", str);
	int temp = 0;
	printf("int temp addr = %d\n", &temp);
	printf("int g_val addr = %d\n", &g_val);
}
// �ַ�����ת 1 
void reverseString(char * str)
{
	int len = strlen(str);
	//��¼�±�
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
// �ַ�����ת2 ����ָ��
void reverseString2(char* str)
{
	int len = strlen(str);
	char* pstart = str;
	char* pend = str + len - 1;// ����λ�õ�ָ��
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
//sprintf()����
void test_06()
{
	// ��ӡ����
	char buf[100];
	memset(buf, 0, 100);

	sprintf(buf, "������%d��%d��%d��", 2020, 2, 13);
	// �ַ���ƴ��
	memset(buf, 0, 100);
	char str1[] = "hello";
	char str2[] = "world";
	int len =  sprintf(buf, "%s%s",str1,str2);
	// ����ת�ַ���
	int num = 100;
	memset(buf, 0, 100);
	len = sprintf(buf, "num = %d", num);
	// ���ÿ�� - ����ת�ַ���
	memset(buf, 0, 100);
	len = sprintf(buf, "%-8dA", num);//% -8d
	// ��ӡʮ������Сд
	memset(buf, 0, 100);
	len = sprintf(buf, "num = 0x%x", num);
	// ��ӡ�˽���
	memset(buf, 0, 100);
	len = sprintf(buf, "num = 0%o", num);

	//��ӡ
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

	char* str = "123";// �ַ��������������޸�
}