#pragma once
#include <stdio.h>

// ���뺯��(ֻ���ڵ�ǰdll��ʹ�õĺ�����
void printResult(int num);
//��������
__declspec(dllexport) int mySub(int a, int b);
