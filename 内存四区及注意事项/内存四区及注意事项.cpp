
//1 ��ͬ���͵ı����������ڴ�Ĳ�ͬ����
// 2 �ڴ������� ��������ǰ����������ȫ���� �������к�ջ���Ͷ�����C++��ʵ�֣�
#include <string>
#include <iostream>
#include "myheader.h"
using namespace std;


// ȫ�ֱ���
int g_a = 20;
int g_b = 200;
// ȫ�ֳ���
const int c_g_a = 200;
const int c_g_b = 2000;
//// ȫ�־�̬����
//static int s_g_a = 100;
//static int s_g_b = 1000;
void test_1()
{
	int l_a = 10;
	int l_b = 100;
	cout << "�ֲ�������ַ��" << &l_a << endl;
	cout << "�ֲ�������ַ��" << &l_b << endl;

	//const and local
	const int c_l_a = 200;
	const int c_l_b = 2000;

	cout << "�ֲ�������ַ��" << &c_l_a << endl;
	cout << "�ֲ�������ַ��" << &c_l_b << endl;
	cout << endl;
	cout << "ȫ�ֱ�����ַ: " << &g_a << endl;
	cout << "ȫ�ֱ�����ַ: " << &g_b << endl;

	//staitc var
	static int s_l_a = 100;
	static int s_l_b = 1000;
	cout << "�ֲ���̬������" << &s_l_a << endl;
	cout << "�ֲ���̬������" << &s_l_b << endl;

	//cout << "ȫ�־�̬������" << &s_g_a << endl;
	//cout << "ȫ�־�̬������" << &s_g_b << endl;


	cout << "ȫ�ֳ�����ַ��" << &c_g_a << endl;
	cout << "ȫ�ֳ�����ַ��" << &c_g_b << endl;

	cout << "�ַ���������ַ��" << &"hello,world!" << endl;//?

	cout << endl;
	int * p1 = new int(10);
	int * p2 = new int(20);
	cout << "��̬�ڴ�����ַ��" << p1 << endl;
	cout << "��̬�ڴ�����ַ��" << p2 << endl;



}
// ջ��
// �ֲ��������βε�ַ���ɱ������Զ����䣬����ִ�н������ڴ�ռ��ͷ�
void test_stack(int val)
{
	int b = 100;
	cout << "�ֲ�������ַ��" << &b << endl;
	cout << "�βα�����ַ��" << &val << endl;
}
void test_3()
{
	test_stack(10);
}

//  ����
// new and delete
void test_5()
{
	int * arr = new int[10];
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl; // �����ʼ��Ϊ0,����
		arr[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	delete[]arr;
}

 

extern "C" void test_08();
extern "C" void test_09();

int  main()
{
    //test_02();
	//test_07();
	//test_08();
	test_09();
	system("pause");
}


// �ܽ�
//��̬����
// 1 ֻ��ʼ��һ�Σ��ڱ���׶ξͷ����ڴ棬�����ڲ��������ԣ�ֻ���ڵ�ǰ�ļ���ʹ��
// 2 static + �κα��������Ǿ�̬�������������ڴӱ��뿪ʼ����������� 

// const���εı���
//1 const+ȫ�ֱ������޷��޸ģ���ȫ�ֳ���������
//2 const+ �ֲ������� ���䵽ջ�ϣ�ֱ���޸ı�����󣬼���޸ĳɹ�����C�����£���α���������Բ��ܳ�ʼ������

// �ַ�������
// ANSI��û��ͳһ��׼����Щ�����������޸��ַ���������Щ�����ԡ�
//���ң���Щ����������ͬ�Ķ����ͬ�����ַ�������������ͬһ�����Ż��ڴ�ռ䣬��ַһ��







