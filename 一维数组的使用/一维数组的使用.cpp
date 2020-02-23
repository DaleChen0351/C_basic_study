#include <iostream>
#include <string>
using namespace std;

//数组名是首地址
void test_05()
{
	int arry[10] = {};
	cout << sizeof(arry) << endl;
	cout << "数组首地址" << endl;
	cout << arry << endl;
	cout << &arry[0] << endl;
	cout << "第二个元素的地址" << endl;
	cout << arry + 1 << endl; // 第二个元素的地址 // 注意，可以+n 但是不可以++ ？
	cout << &arry[1] << endl;
}

// 一维数组求极值
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

// 一维数组逆置元素
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
	cout << "逆置后：" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

}
// 冒泡排序法
void test_12()
{
	int arr[9] = { 4,2,8,0,5,7,1,3,9 };
	for (int i = 0; i < 9 - 1; i++)// 轮次 8
	{
		for (int j = 0; j < 9 - 1 - i; j++) // 每轮需要交换的次数
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
// 冒泡排序法 随机数排序
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

//冒泡排序法的函数实现
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

//当数组名作为函数参数的时候，会退化作为函数指针，指向数组中的第一个元素
// sizeof 可以统计数组的长度
void calculateArray(int arr[])// int arr[] 等价于 int* arr. 但是 int arr[] 可读性更好，告诉调用者，需要传入的是一个数组而非一个普通指针
{
	printf("arr 的数组长度 = %d\n", sizeof arr);//数组名做函数的参数，退化为普通指针   4 
}
void test_04()
{
	int arry[] = { 1,2,3,4,5 };
	printf("arr 的数组长度 = %d\n", sizeof arry);// 数组名做变量 20
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