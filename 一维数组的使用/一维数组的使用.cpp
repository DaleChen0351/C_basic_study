#include <iostream>
#include <string>
using namespace std;

//���������׵�ַ
void test_05()
{
	int arry[10] = {};
	cout << sizeof(arry) << endl;
	cout << "�����׵�ַ" << endl;
	cout << arry << endl;
	cout << &arry[0] << endl;
	cout << "�ڶ���Ԫ�صĵ�ַ" << endl;
	cout << arry + 1 << endl; // �ڶ���Ԫ�صĵ�ַ // ע�⣬����+n ���ǲ�����++ ��
	cout << &arry[1] << endl;
}

// һά������ֵ
void test_10()
{
	int pigs[5] = { 101,92,83,104,105 };
	int max = 0;
	for (int i = 0; i < 5; i++)
	{
		if (pigs[i] > max)
		{
			max = pigs[i];
		}

	}
	cout << max << endl;
}

// һά��������Ԫ��
void test_11()
{
	int arr[] = { 1,3,2,5,4,7,8 };
	int start = 0;
	int end = sizeof(arr) / sizeof(arr[0]) - 1;

	for (int i = 0; i < 7; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	while (start < end)
	{
		int temp = 0;
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;

		start++;
		end--;
	}
	cout << "���ú�" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

}
// ð������
void test_12()
{
	int arr[9] = { 4,2,8,0,5,7,1,3,9 };
	for (int i = 0; i < 9 - 1; i++)// �ִ� 8
	{
		for (int j = 0; j < 9 - 1 - i; j++) // ÿ����Ҫ�����Ĵ���
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = 0;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < 9; i++)
	{
		cout << arr[i] << " ";
	}
}
// ð������ ���������
void test_13()
{
	const int num = 20;
	int arr[num];
	for (int i = 0; i < num; i++)
	{
		arr[i] = rand() % 10 + 1; // 1-10
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = 0;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//ð�����򷨵ĺ���ʵ��
void bubullSort(int* arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void test_03()
{
	int arr[9] = { 4,2,8,0,5,7,1,3,9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	bubullSort(arr, len);
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//����������Ϊ����������ʱ�򣬻��˻���Ϊ����ָ�룬ָ�������еĵ�һ��Ԫ��
// sizeof ����ͳ������ĳ���
void calculateArray(int arr[])// int arr[] �ȼ��� int* arr. ���� int arr[] �ɶ��Ը��ã����ߵ����ߣ���Ҫ�������һ���������һ����ָͨ��
{
	printf("arr �����鳤�� = %d\n", sizeof arr);//�������������Ĳ������˻�Ϊ��ָͨ��   4 
}
void test_04()
{
	int arry[] = { 1,2,3,4,5 };
	printf("arr �����鳤�� = %d\n", sizeof arry);// ������������ 20
	calculateArray(arry);
}

void  main_01()
{

}

extern "C" void main_02();
extern "C" void main_03();
int main()
{
	//main_02();
	main_03();
}