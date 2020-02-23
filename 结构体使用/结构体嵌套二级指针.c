#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//�ṹ��Ƕ�׶���ָ����ϰ
struct Teacher
{
	char* name;
	char** pstudenet;
};
//���ٿռ�
void allocateTeacherSpace(struct Teacher*** pp)
{
	struct Teacher** teacher = malloc(sizeof(struct Teacher*) * 3);
	//����ʦ�ṹ�����ռ�
	for (int i = 0; i < 3; i++)
	{
		teacher[i] = malloc(sizeof(struct Teacher));
		//����ʦ��name���Է�������ռ䲢��ֵ
		teacher[i]->name = malloc(sizeof(char) * 64);
		sprintf(teacher[i]->name, "Teacher_%d", i + 1);// strcmpҲ����

		//����ʦ����ѧ�����������ռ�
		teacher[i]->pstudenet = malloc(sizeof(char*) * 4);
		//���ĸ�ѧ����name����ռ䣬���Ҹ�ֵ
		for (int j = 0; j < 4; j++)
		{
			teacher[i]->pstudenet[j] = malloc(sizeof(char) * 64);
			sprintf(teacher[i]->pstudenet[j], "%s_student_%d", teacher[i]->name, j + 1);
		}

	}
	//����
	*pp = teacher;
}
//��ӡ��Ϣ
void printTeacherInfo(const struct Teacher** p)//���޸�ָ�룬ֻʹ�� 
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
//�ͷſռ�
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
	allocateTeacherSpace(&pArr);//����ָ��
	printTeacherInfo(pArr);
	freeTeacherSpace(pArr);
	pArr = NULL;
}

void main_04()
{
	test_41();
}
