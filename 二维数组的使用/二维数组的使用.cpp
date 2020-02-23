
#include <iostream>
#include <string>
using namespace std;


//二维数组遍历 1
void test_01()
{
	int arr[][3] =
	{
		{1,2,3},
		{4,5,6},
	};
	cout << "二维数组的地址：" << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << &arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "arr + 1= " << *(*(arr + 1) + 1) << endl;
	cout << "行指针的遍历" << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << *(arr + i) << endl;
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << *(*(arr + i) + j) << " ";
		}
		cout << endl;
	}

}
// 方式一 传入行指针数组
void print2Darr_01(int(*p)[3]) // why ?
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << *(*(p + i) + j) << " ";
		}
		cout << endl;
	}
}
// 方式二 传入行指针二
void print2Darr_02(int p[][3])
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << *(*(p + i) + j) << " ";
		}
		cout << endl;
	}
}
// 方式三 传入首地址
void print2Darr_03(int* p)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << *(p + i * 3 + j) << " ";
		}
		cout << endl;
	}
}

void test_02()
{
	int arr[][3] =
	{
		{1,2,3},
		{4,5,6},
	};
	// 
	cout << "方式1" << endl;
	print2Darr_01(arr);
	cout << endl;
	cout << "方式2" << endl;
	print2Darr_02(arr);
	cout << endl;
	cout << "方式3" << endl;

	int * p = &arr[0][0];
	print2Darr_03(p);

}

//二维数组
void test_06()
{
	int mat[2][3] =
	{
		{1,2,3},
		{4,5,6}
	};

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}

}
void test_07()
{
	int mat[][3] =   // 行数定义时候可以省略，列数不可以省略
	{
		{1,2,3},
		{4,5,6},
	};

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}

}
// 二维数组的地址查看
void test_08()
{
	int mat[2][3] = {};// 和一维数组一样，默认为0

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << "二维数组首地址: " << (int)mat << endl;
	cout << "第一行元素首地址: " << (int)mat[0] << endl;
	cout << "第二行元素首地址: " << (int)mat[1] << endl;
	cout << "第二行元素首地址：" << (int)(mat + 1) << endl;// 加一行地址
}
//二维数组遍历求和
void test_09()
{
	int scores[4][3] =
	{
		{100,100,100},
		{90,100,60},
		{100,80,100},
		{60,70,100}
	};
	string names[4] = { "Dale", "Susan","Linda","Bob" };

	for (int i = 0; i < 4; i++)
	{
		int sum = 0;
		for (int j = 0; j < 3; j++)
		{
			sum += scores[i][j];
		}

		cout << names[i] << "的总分为   " << sum << endl;

	}
}
extern "C" void main_02();
extern "C" void main_03();
int main()
{
	std::cout << "Hello World!\n";
	//test_02();
	//main_02();
	main_03();
}

