#include <string>
#include <iostream>
using namespace std;

// 函数指针定义
int func(float val)
{
	cout << val << endl;
	return val;
}
void func2(int i)
{
	cout << i << endl;
}
	// 1 直接定义
void test_05()
{
	int(*p1)(float) = func;
	p1(10);
}
	// 2 typedef 定义函数指针
void test_06()
{
	typedef  int(*F1)(float);
	F1 f1 = func;
	f1(20);

	typedef void(F2)(int);
	F2* f2 = func2;
	f2(50);

}
// 函数指针数组
class hero
{
public:
	string name;
};
bool run(const hero& h)
{
	cout << h.name << " is running" << endl;
	return true;
}
bool eat(const hero& h)
{
	cout << h.name << " is eating" << endl;
	return true;
}
bool sleep(const hero& h)
{
	cout << h.name << " is sleeping" << endl;
	return true;
}

// 函数指针
int test_07()
{
	// hero
	hero h;
	h.name = "DB";
	//函数指针数组
	bool(*act[3])(const hero&) = { run,eat,sleep };

	string actcmd[4] = { "run","eat","sleep" ,"exit" };
	while (true)
	{
		string cmd = "";
		cout << "请输入指令：" << endl;
		cin >> cmd;
		for (int i = 0; i < 4; i++)
		{
			if (actcmd[i] == cmd)
			{
				if (i == 3)
				{
					system("pause");
					return 0;
				}
				else
				{
					act[i](h);
					break;
				}

			}
		}

	}


}

// 回调函数
bool myCompar(int a, int b)
{
	return (a % 10) > (b % 10);
}


void func(int* arr, int len, bool(*p)(int a, int b))
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (p(arr[j], arr[j + 1]))
			{
				int temp = 0;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void test_08()
{
	int arr[9] = { 14,2,28,1,5,17,11,43,9 };
	func(arr, 9, myCompar);
	for (int i = 0; i < 9; i++)
	{
		cout << arr[i] << endl;
	}
}


int main()
{
	//test_fopen();
}