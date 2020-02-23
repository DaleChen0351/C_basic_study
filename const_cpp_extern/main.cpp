#include <string>
#include <iostream>
using namespace std;
//��const )ȫ�ֱ�����C++��Ĭ��Ϊ���ڲ��������ԣ���Ҫ�ڶ����λ������ǰ׺ "extern" 
// ����C�����У�Ĭ��Ϊ�ⲿ�������ԣ�����Ҫ��ʽ����extern ǰ׺
void test_01()
{
	extern int g_a;
	extern const int const_g_val;
	cout << "g_a = " << g_a << endl;
	cout << " const_g_val = " << const_g_val << endl;
}
// ��C++�У�const���εľֲ��������γɵĳ������������ĳ����������Ա�ֱ�ӻ��߼���޸ġ�
// ���õķ�ʽ��һ�֡����ű�����ʽ��
// ����Ϊ���������еĳ���
void test_02()
{
	const int c_l_num = 5;
	int* p = (int*)&c_l_num;
	*p = 6;
	int arr[c_l_num] = {};
	cout << "sizeof(arr) = " << sizeof arr << endl;
	cout << "len(arr) = " << sizeof(arr) / sizeof(int) << endl;// ����Ϊ5

}
//const �����ڴ�
// �Ծֲ�����ȡ��ַ�����ϵͳ��ջ�Ϸ�����ʱ�������ڴ�ռ�
void test_03()
{
	const int num = 20;
	int* p = (int*)&num;// �Ḵ������һ����ʱ����temp,�����ش˱����ĵ�ַ
	*p = 300;// ���޸ĵ�ֵΪtemp��ֵ������ԭֵnum����
	cout << "num = " << num << endl;// �޸�ʧ��

}
// ʹ�������ı�������ʼ��const���εı���Ҳ������ڴ�
void test_04()
{
	int a = 3;
	const int num = a;
	int* p = (int*)&num;// 
	*p = 300;//
	cout << "num = " << num << endl;// �޸ĳɹ�
}
// const ���ε��Զ������͵ľֲ���������ͨ��ָ�����޸���ֵ
struct Person
{
	int age;
	string name;
};
void test_05()
{
	const Person p = {22,"Joyce"};
	cout << p.age << " " << p.name << endl;
	// �޸�
	Person* ptr = (Person*)&p;
	ptr->age = 30;
	ptr->name = "Bob";
	cout << p.age << " " << p.name << endl;// �޸ĳɹ�

}
// extern + const int num = 100 ȫ�ֳ���Ҳ������ڴ棬ͨ��ָ���޸Ŀ�ͨ�����룬�﷨��ȷ������������д���
// ԭ�����ڱ�const���ε�ȫ�ֱ����ڴ������ȫ�����еĳ���ȡ���ܵ�д����
int main()
{
	//test_01();
	//test_02();
	//test_03();
	//test_04();
	test_05();
	system("pause");
}