#pragma once
#include <stdio.h>

// 导入函数(只能在当前dll内使用的函数）
void printResult(int num);
//导出函数
__declspec(dllexport) int mySub(int a, int b);
