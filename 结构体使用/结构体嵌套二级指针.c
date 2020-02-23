#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//结构体嵌套二级指针练习
struct Teacher
{
	char* name;
	char** pstudenet;
};
//开辟空间
void allocateTeacherSpace(struct Teacher*** pp)
{
	struct Teacher** teacher = malloc(sizeof(struct Teacher*) * 3);
	//给老师结构体分配空间
	for (int i = 0; i < 3; i++)
	{
		teacher[i] = malloc(sizeof(struct Teacher));
		//给老师的name属性分配堆区空间并赋值
		teacher[i]->name = malloc(sizeof(char) * 64);
		sprintf(teacher[i]->name, "Teacher_%d", i + 1);// strcmp也可以

		//给老师带的学生的数组分配空间
		teacher[i]->pstudenet = malloc(sizeof(char*) * 4);
		//给四个学生的name分配空间，并且赋值
		for (int j = 0; j < 4; j++)
		{
			teacher[i]->pstudenet[j] = malloc(sizeof(char) * 64);
			sprintf(teacher[i]->pstudenet[j], "%s_student_%d", teacher[i]->name, j + 1);
		}

	}
	//返回
	*pp = teacher;
}
//打印信息
void printTeacherInfo(const struct Teacher** p)//不修改指针，只使用 
{
	for (int i = 0; i < 3; i++)
	{
		printf("name = %s\n", p[i]->name);
		for (int j = 0; j < 4; j++)
		{
			printf("             name = %s\n", p[i]->pstudenet[j]);
		}
	}
}
//释放空间
void freeTeacherSpace(struct Teacher** p)
{
	for (int i = 0; i < 3; i++)
	{
		if (p[i]->name != NULL)
		{
			free(p[i]->name);
			p[i]->name = NULL;
		}

		for (int j = 0; j < 4; j++)
		{
			if (p[i]->pstudenet[j] != NULL)
			{
				free(p[i]->pstudenet[j]);
				p[i]->pstudenet[j] = NULL;
			}
		}
		free(p[i]->pstudenet);
		p[i]->pstudenet = NULL;

		free(p[i]);
		p[i] = NULL;
	}
	free(p);
	p = NULL;
}
void test_41()
{
	struct Teacher** pArr = NULL;
	allocateTeacherSpace(&pArr);//三级指针
	printTeacherInfo(pArr);
	freeTeacherSpace(pArr);
	pArr = NULL;
}

void main_04()
{
	test_41();
}
