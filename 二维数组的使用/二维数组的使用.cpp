
#include <iostream>
#include <string>
using namespace std;


//��ά������� 1
void test_01()
{
	int arr[][3] =
	{
		{1,2,3},
		{4,5,6},
	};
	cout << "��ά����ĵ�ַ��" << endl;
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
	cout << "��ָ��ı���" << endl;
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
// ��ʽһ ������ָ������
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
// ��ʽ�� ������ָ���
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
// ��ʽ�� �����׵�ַ
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
	cout << "��ʽ1" << endl;
	print2Darr_01(arr);
	cout << endl;
	cout << "��ʽ2" << endl;
	print2Darr_02(arr);
	cout << endl;
	cout << "��ʽ3" << endl;

	int * p = &arr[0][0];
	print2Darr_03(p);

}

//��ά����
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
	int mat[][3] =   // ��������ʱ�����ʡ�ԣ�����������ʡ��
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
// ��ά����ĵ�ַ�鿴
void test_08()
{
	int mat[2][3] = {};// ��һά����һ����Ĭ��Ϊ0

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << "��ά�����׵�ַ: " << (int)mat << endl;
	cout << "��һ��Ԫ���׵�ַ: " << (int)mat[0] << endl;
	cout << "�ڶ���Ԫ���׵�ַ: " << (int)mat[1] << endl;
	cout << "�ڶ���Ԫ���׵�ַ��" << (int)(mat + 1) << endl;// ��һ�е�ַ
}
//��ά����������
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

		cout << names[i] << "���ܷ�Ϊ   " << sum << endl;

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

