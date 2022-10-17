// ̰����.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
int start = 0, end = 0;//ͳ��ʱ��
int cunh = 0;//���ʱ��ͳ��
int i = 0;//������
int k = 3;//ͳ�ƻ��ж��ٻ���
int yxzsm = 0;//ͳ�ƻ���
static int summ = 0;//�ܷ�ͳ��
//������Ϸ�߶ȺͿ���
#define GAOD 10//��
#define KUAND 30//��
//������Ϸ���� x,y 
typedef struct _zuobiao
{
	int x;//x��
	int y;//y��
}ZUOB;
typedef struct shentixx
{
	ZUOB shenti[KUAND*GAOD];//����,�����ÿһ�����궼��ZUOB��
	int sdaxiao;//�ߵĴ�С
	ZUOB shiwu;//ʳ��
	COORD coord;//windows ����
	int dx;//�ߵ�x���ƶ�����
	int dy;//�ߵ�y���ƶ�����
	int fens;//����
	ZUOB weiba;//�ߵ�β��
	ZUOB zaw;//�ϰ���
	
}SHENTIXX;

void _shiwuchush(SHENTIXX *shedexx)
{

	
	srand((unsigned)time(NULL));//�������ʳ�������
	//��ʼ��ʳ������
	shedexx->shiwu.x = rand() % KUAND;
	shedexx->shiwu.y = rand() % GAOD;
}

void _genggaiyanshe(SHENTIXX *shedexx)
{
	//������ͷ��ɫ
	shedexx->shenti[0].x = system("color a");
	shedexx->shenti[0].y = system("color a");
	for (int i = shedexx->sdaxiao; i > 1; i--)
	{
		//����������ɫ
		shedexx->shenti[i].x = system("color c");
		shedexx->shenti[i].y = system("color c");
	}
}
void _chushihua(SHENTIXX *shedexx)
{

	//��ʼ����ͷ��������  (��ͼ�м�)
	shedexx->shenti[0].x = KUAND / 2;
	shedexx->shenti[0].y = GAOD / 2;
	//��ʼ����β��������  (��ͷ����)
	shedexx->shenti[1].x = KUAND / 2 - 1;
	shedexx->shenti[1].y = GAOD / 2;
	//��ʼ���ߵĴ�С
	shedexx->sdaxiao = 2;
	//��ʼ���ߵ�ʳ��
	_shiwuchush(shedexx);
	//��ʼ�����ƶ��ķ���
	shedexx->dx = 1;
	shedexx->dy = 0;
	//��ʼ������
	shedexx->fens = 0;
	
	//shedexx->fans1 = 0;
}
void xianhsishe(SHENTIXX *shedexx)
{
	for (int i = 0; i < shedexx->sdaxiao; i++)
	{

		//��ʾ�� ע�⣺ÿ����ʾ�� ��Ҫ���¶�����λ��
		shedexx->coord.X = shedexx->shenti[i].x;
		shedexx->coord.Y = shedexx->shenti[i].y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), shedexx->coord);//�˺���Ϊwin����
		if (0 == i)
		{
			printf("@");
           
		}
		else
			printf("*");
	}
	//��ʾʳ��
	shedexx->coord.X = shedexx->shiwu.x;
	shedexx->coord.Y = shedexx->shiwu.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), shedexx->coord);
	printf("#");
	//��β�����һ������ΪNULL
	shedexx->coord.X = shedexx->weiba.x;
	shedexx->coord.Y = shedexx->weiba.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), shedexx->coord);
	printf(" ");
}
void _sehdezuob(SHENTIXX *shedexx)
{
	//�����ߵ�β��
	shedexx->weiba.x = shedexx->shenti[shedexx->sdaxiao - 1].x;
	shedexx->weiba.y = shedexx->shenti[shedexx->sdaxiao - 1].y;
	for (int i = shedexx->sdaxiao-1; i > 0; i--)
	{
		//��������������
		shedexx->shenti[i] = shedexx->shenti[i - 1];
	}
	//������ͷ���ƶ�����
	shedexx->shenti[0].x += shedexx->dx;
	shedexx->shenti[0].y += shedexx->dy;
}
void _kongzfangxiang(SHENTIXX *shedexx)
{
	char kongz= 0 ;
	while (_kbhit())//�ж��Ƿ��¼�λ�����²�Ϊ0
	{
		kongz = _getch();
	}
	switch (kongz)//�����ߵķ���ǰ�����ң�
	{
	case 'a':
		shedexx->dx = -1;
		shedexx->dy = 0;
		break;
	case 'w':
		shedexx->dx = 0;
		shedexx->dy = -1;
		break;
	case 's':
		shedexx->dx = 0;
		shedexx->dy = 1;
		break;
	case 'd':
		shedexx->dx = 1;
		shedexx->dy = 0;
		break;
	}
}
void _youxijies(SHENTIXX *shedexx)
{
	time_t timep;
	struct tm *p;
	time(&timep);
	p = gmtime(&timep);
	FILE *q = NULL;
	FILE *q1 = NULL;
	FILE *q2 = NULL;
	FILE *q3 = NULL;
	FILE *q4 = NULL;
	FILE *q5 = NULL;
	FILE *q6 = NULL;
	FILE *q7 = NULL;
	FILE *q8 = NULL;
	FILE *q9 = NULL;
	FILE *q10 = NULL;
	FILE *q11 = NULL;
	FILE *q12 = NULL;
	if ((q = fopen("./���������¼.txt", "a+")) == NULL)
	{
		q = fopen("./���������¼.txt", "a+");
	}
	if ((q1 = fopen("./2021��1�·���Ϸ��¼.txt", "a+")) == NULL)
	{
		q1 = fopen("./2021��1�·���Ϸ��¼.txt", "a+");
	}
	if ((q2 = fopen("./2021��2�·���Ϸ��¼.txt", "a+")) == NULL)
	{
		q2 = fopen("./2021��2�·���Ϸ��¼.txt", "a+");
	}
	if ((q3 = fopen("./2021��3�·���Ϸ��¼.txt", "a+")) == NULL)
	{
		q3 = fopen("./2021��3�·���Ϸ��¼.txt", "a+");
	}
	if ((q4 = fopen("./2021��4�·���Ϸ��¼.txt", "a+")) == NULL)
	{
		q4 = fopen("./2021��4�·���Ϸ��¼.txt", "a+");
	}
	if ((q5 = fopen("./2021��5�·���Ϸ��¼.txt", "a+")) == NULL)
	{
		q5 = fopen("./2021��5�·���Ϸ��¼.txt", "a+");
	}
	if ((q6 = fopen("./2021��6�·���Ϸ��¼.txt", "a+")) == NULL)
	{
		q6 = fopen("./2021��6�·���Ϸ��¼.txt", "a+");
	}
	if ((q7 = fopen("./2021��7�·���Ϸ��¼.txt", "a+")) == NULL)
	{
		q7 = fopen("./2021��7�·���Ϸ��¼.txt", "a+");
	}
	if ((q8 = fopen("./2021��8�·���Ϸ��¼.txt", "a+")) == NULL)
	{
		q8 = fopen("./2021��8�·���Ϸ��¼.txt", "a+");
	}
	if ((q9 = fopen("./2021��9�·���Ϸ��¼.txt", "a+")) == NULL)
	{
		q9 = fopen("./2021��9�·���Ϸ��¼.txt", "a+");
	}
	if ((q10 = fopen("./2021��10�·���Ϸ��¼.txt", "a+")) == NULL)
	{
		q10 = fopen("./2021��10�·���Ϸ��¼.txt", "a+");
	}
	if ((q11 = fopen("./2021��11�·���Ϸ��¼.txt", "a+")) == NULL)
	{
		q11 = fopen("./2021��11�·���Ϸ��¼.txt", "a+");
	}
	if ((q12 = fopen("./2021��12�·���Ϸ��¼.txt", "a+")) == NULL)
	{
		q12 = fopen("./2021��12�·���Ϸ��¼.txt", "a+");
	}
	//������Ľ����λ�ø���
	//_jillsfens(shedexx, p);//��¼��ʷ����
	Sleep(2000);//�ӳ����������Ϸ
	//i++;
	
	/*if (i <3)
	{	
       system("cls");
	}*/

	if (i == 0)
	{
		shedexx->coord.X = 40;
		shedexx->coord.Y = 7;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), shedexx->coord);
		printf("�ܷ�Ϊ��%d\n", summ);
		if (1 + p->tm_mon == 1)
		{
			fprintf(q1, "����Ϊ:%d  ���ʱ��:%d��  ����:%d��.%d��.%dʱ.%d��\n", summ, cunh, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
			fprintf(q, "����Ϊ:%d  ���ʱ��:%d��  ����:%d��.%d��.%dʱ.%d��\n", summ, cunh, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
		}
		if (1 + p->tm_mon == 2)
		{
			fprintf(q, "����Ϊ:%d  ���ʱ��:%d��  ����:%d��.%d��.%dʱ.%d��\n", summ, cunh, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
			fprintf(q2, "����Ϊ:%d  ���ʱ��:%d��  ����:%d��.%d��.%dʱ.%d��\n", summ, cunh, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
		}
		if (1 + p->tm_mon == 3)
		{
			fprintf(q, "����Ϊ:%d  ���ʱ��:%d��  ����:%d��.%d��.%dʱ.%d��\n", summ, cunh, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
			fprintf(q3, "����Ϊ:%d  ���ʱ��:%d��  ����:%d��.%d��.%dʱ.%d��\n", summ, cunh, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
		}
		if (1 + p->tm_mon == 4)
		{
			fprintf(q, "����Ϊ:%d  ���ʱ��:%d��  ����:%d��.%d��.%dʱ.%d��\n", summ, cunh, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
			fprintf(q4, "����Ϊ:%d  ���ʱ��:%d��  ����:%d��.%d��.%dʱ.%d��\n", summ, cunh, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
		}
		if (1 + p->tm_mon == 5)
		{
			fprintf(q, "����Ϊ:%d  ���ʱ��:%d��  ����:%d��.%d��.%dʱ.%d��\n", summ, cunh, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
			fprintf(q5, "����Ϊ:%d  ���ʱ��:%d��  ����:%d��.%d��.%dʱ.%d��\n", summ, cunh, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
		}
		if (1 + p->tm_mon == 6)
		{
			fprintf(q, "����Ϊ:%d  ���ʱ��:%d��  ����:%d��.%d��.%dʱ.%d��\n", summ, cunh, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
			fprintf(q6, "����Ϊ:%d  ���ʱ��:%d��  ����:%d��.%d��.%dʱ.%d��\n", summ, cunh, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
		}
		if (1 + p->tm_mon == 7)
		{
			fprintf(q, "����Ϊ:%d  ���ʱ��:%d��  ����:%d��.%d��.%dʱ.%d��\n", summ, cunh, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
			fprintf(q7, "����Ϊ:%d  ���ʱ��:%d��  ����:%d��.%d��.%dʱ.%d��\n", summ, cunh, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
		}
		if (1 + p->tm_mon == 8)
		{
			fprintf(q, "����Ϊ:%d  ���ʱ��:%d��  ����:%d��.%d��.%dʱ.%d��\n", summ, cunh, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
			fprintf(q8, "����Ϊ:%d  ���ʱ��:%d��  ����:%d��.%d��.%dʱ.%d��\n", summ, cunh, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
		}
		if (1 + p->tm_mon == 9)
		{
			fprintf(q, "����Ϊ:%d  ���ʱ��:%d��  ����:%d��.%d��.%dʱ.%d��\n", summ, cunh, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
			fprintf(q9, "����Ϊ:%d  ���ʱ��:%d��  ����:%d��.%d��.%dʱ.%d��\n", summ, cunh, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
		}
		if (1 + p->tm_mon == 10)
		{
			fprintf(q, "����Ϊ:%d  ���ʱ��:%d��  ����:%d��.%d��.%dʱ.%d��\n", summ, cunh, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
			fprintf(q10, "����Ϊ:%d  ���ʱ��:%d��  ����:%d��.%d��.%dʱ.%d��\n", summ, cunh, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
		}
		if (1 + p->tm_mon == 11)
		{
			fprintf(q, "����Ϊ:%d  ���ʱ��:%d��  ����:%d��.%d��.%dʱ.%d��\n", summ, cunh, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
			fprintf(q11, "����Ϊ:%d  ���ʱ��:%d��  ����:%d��.%d��.%dʱ.%d��\n", summ, cunh, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
		}
		if (1 + p->tm_mon == 12)
		{
			fprintf(q, "����Ϊ:%d  ���ʱ��:%d��  ����:%d��.%d��.%dʱ.%d��\n", summ, cunh, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
			fprintf(q12, "����Ϊ:%d  ���ʱ��:%d��  ����:%d��.%d��.%dʱ.%d��\n", summ, cunh, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
		}
		Sleep(2000);
		char a;//���������������
		char d;//���������������
		char ch = 0;
		char b;
		char c=0;
		char zs[1024] = { 0 };
		printf("�Ƿ�鿴��Ϸ��¼��������\n");
		printf("�鿴��¼�밴����y�����ߡ�Y��\n");
		printf("���鿴��¼�밴�������������y��Y��\n");
		printf("������:\n");
		scanf_s("%c", &a);
		//����ı���������ʱ����
		if ( a =='y'|| a=='Y')
		{
			printf("������鿴�ڼ��·ݵļ�¼:\n");
			scanf_s("%d", &b);
			if (b == 1)
			{
				q1 = fopen("./2021��1�·���Ϸ��¼.txt", "r");
				fscanf(q1, "%c", &ch);
				c = fgetc(q1);
				if (c == EOF)//�жϵ��·��Ƿ���й���Ϸ���ж��ļ��Ƿ�Ϊ�գ�
				{
					printf("���·�û����Ϸ��¼!\n");
					printf("��Ϸ������������\n");
					Sleep(3000);
					exit(0);
				}
				while (!feof(q1))
				{
					putchar(ch);
					fscanf(q1, "%c", &ch);
				}
				FILE *q1 = fopen("2021��1�·���Ϸ��¼.txt", "r");
				while ((fgets(zs, 1024, q1)) != NULL)
				{
					yxzsm++;
				}
				printf("һ��������%d����Ϸ\n", yxzsm + 1);
				
				printf("��Ϸ������������\n");
				Sleep(3000);
				exit(0);//�������̣���Ϸ��
			}
			if (b  == 2)
			{
				q2 = fopen("./2021��2�·���Ϸ��¼.txt", "r");
				fscanf(q2, "%c", &ch);
				c = fgetc(q2);
				if (c == EOF)//�жϵ��·��Ƿ���й���Ϸ���ж��ļ��Ƿ�Ϊ�գ�
				{
					printf("���·�û����Ϸ��¼!\n");
					printf("��Ϸ������������\n");
					Sleep(3000);
					exit(0);
				}
				while (!feof(q2))
				{
					putchar(ch);
					fscanf(q2, "%c", &ch);
				}
				FILE *q2 = fopen("2021��2�·���Ϸ��¼.txt", "r");
				while ((fgets(zs, 1024, q2)) != NULL)
				{
					yxzsm++;
				}
				printf("һ��������%d����Ϸ\n", yxzsm+1);
				printf("��Ϸ������������\n");
				Sleep(3000);
				exit(0);//�������̣���Ϸ��
			}
			if (b == 3)
			{
				q3 = fopen("./2021��3�·���Ϸ��¼.txt", "r");
				fscanf(q3, "%c", &ch);
				c = fgetc(q3);
				if (c == EOF)//�жϵ��·��Ƿ���й���Ϸ���ж��ļ��Ƿ�Ϊ�գ�
				{
					printf("���·�û����Ϸ��¼!\n");
					printf("��Ϸ������������\n");
					Sleep(3000);
					exit(0);
				}
				while (!feof(q3))
				{
					putchar(ch);
					fscanf(q3, "%c", &ch);
				}
				FILE *q3 = fopen("2021��3�·���Ϸ��¼.txt", "r");
				while ((fgets(zs, 1024, q3)) != NULL)
				{
					yxzsm++;
				}
				printf("һ��������%d����Ϸ\n", yxzsm+1);
				printf("��Ϸ������������\n");
				Sleep(3000);
				exit(0);//�������̣���Ϸ��
			}
			if (b == 4)
			{
				q4 = fopen("./2021��4�·���Ϸ��¼.txt", "r");
				fscanf(q4, "%c", &ch);
				c = fgetc(q4);
				if (c == EOF)//�жϵ��·��Ƿ���й���Ϸ���ж��ļ��Ƿ�Ϊ�գ�
				{
					printf("���·�û����Ϸ��¼!\n");
					printf("��Ϸ������������\n");
					Sleep(3000);
					exit(0);
				}
				while (!feof(q4))
				{
					putchar(ch);
					fscanf(q4, "%c", &ch);
				}
				FILE *q4 = fopen("2021��4�·���Ϸ��¼.txt", "r");
				while ((fgets(zs, 1024, q4)) != NULL)
				{
					yxzsm++;
				}
				printf("һ��������%d����Ϸ\n", yxzsm+1);
				printf("��Ϸ������������\n");
				Sleep(3000);
				exit(0);//�������̣���Ϸ��
			}
			if (b  == 5)
			{
				q5 = fopen("./2021��5�·���Ϸ��¼.txt", "r");
				fscanf(q5, "%c", &ch);
				c = fgetc(q5);
				if (c == EOF)//�жϵ��·��Ƿ���й���Ϸ���ж��ļ��Ƿ�Ϊ�գ�
				{
					printf("���·�û����Ϸ��¼!\n");
					printf("��Ϸ������������\n");
					Sleep(3000);
					exit(0);
				}
				while (!feof(q5))
				{
					putchar(ch);
					fscanf(q5, "%c", &ch);
				}
				FILE *q5 = fopen("2021��5�·���Ϸ��¼.txt", "r");
				while ((fgets(zs, 1024, q5)) != NULL)
				{
					yxzsm++;
				}
				printf("һ��������%d����Ϸ\n", yxzsm+1);
				printf("��Ϸ������������\n");
				Sleep(3000);
				exit(0);//�������̣���Ϸ��
			}
			if (b  == 6)
			{
				q6 = fopen("./2021��6�·���Ϸ��¼.txt", "r");
				fscanf(q6, "%c", &ch);
				c = fgetc(q6);
				if (c == EOF)//�жϵ��·��Ƿ���й���Ϸ���ж��ļ��Ƿ�Ϊ�գ�
				{
					printf("���·�û����Ϸ��¼!\n");
					printf("��Ϸ������������\n");
					Sleep(3000);
					exit(0);
				}
				while (!feof(q6))
				{
					putchar(ch);
					fscanf(q6, "%c", &ch);
				}
				FILE *q6 = fopen("2021��6�·���Ϸ��¼.txt", "r");
				while ((fgets(zs, 1024, q6)) != NULL)
				{
					yxzsm++;
				}
				printf("һ��������%d����Ϸ\n", yxzsm+1);
				printf("��Ϸ������������\n");
				Sleep(3000);
				exit(0);//�������̣���Ϸ��
			}
			if (b  == 7)
			{
				q7 = fopen("./2021��7�·���Ϸ��¼.txt", "r");
				fscanf(q7, "%c", &ch);
				//fscanf(q7, "%c", &c);
				c = fgetc(q7);
				if (c == EOF)//�жϵ��·��Ƿ���й���Ϸ���ж��ļ��Ƿ�Ϊ�գ�
				{
					printf("���·�û����Ϸ��¼!\n");
					printf("��Ϸ������������\n");
					Sleep(3000);
					exit(0);
				}
				while (!feof(q7))
				{
					putchar(ch);
					fscanf(q7, "%c", &ch);
				}
				FILE *q7 = fopen("2021��7�·���Ϸ��¼.txt", "r");
				while ((fgets(zs, 1024, q7)) != NULL)
				{
					yxzsm++;
				}
				printf("һ��������%d����Ϸ\n", yxzsm+1);
				//printf("���롮y�����ߡ�Y����ֱ�ӿ�ʼ��һ����Ϸ\n���������ַ����˳���Ϸ\n");
				/*printf("������:\n");
				scanf_s("%c", &d);
				if (d == 'y' || d == 'Y')
				{
					_diyizhongyouxms();
				}
				else*/
				printf("��Ϸ������������\n");
				Sleep(3000);
				exit(0);//�������̣���Ϸ��
			}
			if (b  == 8)
			{
				q8 = fopen("./2021��8�·���Ϸ��¼.txt", "r");
				fscanf(q8, "%c", &ch);
				c = fgetc(q8);
				if (c == EOF)//�жϵ��·��Ƿ���й���Ϸ���ж��ļ��Ƿ�Ϊ�գ�
				{
					printf("���·�û����Ϸ��¼!\n");
					printf("��Ϸ������������\n");
					Sleep(3000);
					exit(0);
				}
				FILE *q8 = fopen("2021��8�·���Ϸ��¼.txt", "r");
				while ((fgets(zs, 1024, q8)) != NULL)
				{
					yxzsm++;
				}
				printf("һ��������%d����Ϸ\n", yxzsm+1);
				while (!feof(q8))
				{
					putchar(ch);
					fscanf(q8, "%c", &ch);
				}
				printf("��Ϸ������������\n");
				Sleep(3000);
				exit(0);//�������̣���Ϸ��
			}
			if (b  == 9)
			{
				q9 = fopen("./2021��9�·���Ϸ��¼.txt", "r");
				fscanf(q9, "%c", &ch);
				c = fgetc(q9);
				if (c == EOF)//�жϵ��·��Ƿ���й���Ϸ���ж��ļ��Ƿ�Ϊ�գ�
				{
					printf("���·�û����Ϸ��¼!\n");
					printf("��Ϸ������������\n");
					Sleep(3000);
					exit(0);
				}
				while (!feof(q9))
				{
					putchar(ch);
					fscanf(q9, "%c", &ch);
				}
				FILE *q9 = fopen("2021��9�·���Ϸ��¼.txt", "r");
				while ((fgets(zs, 1024, q9)) != NULL)
				{
					yxzsm++;
				}
				printf("һ��������%d����Ϸ\n", yxzsm+1);
				printf("��Ϸ������������\n");
				Sleep(3000);
				exit(0);//�������̣���Ϸ��
			}
			if (b  == 10)
			{
				q10 = fopen("./2021��10�·���Ϸ��¼.txt", "r");
				fscanf(q10, "%c", &ch);
				c = fgetc(q10);
				if (c == EOF)//�жϵ��·��Ƿ���й���Ϸ���ж��ļ��Ƿ�Ϊ�գ�
				{
					printf("���·�û����Ϸ��¼!\n");
					printf("��Ϸ������������\n");
					Sleep(3000);
					exit(0);
				}
				while (!feof(q10))
				{
					putchar(ch);
					fscanf(q10, "%c", &ch);
				}
				FILE *q10 = fopen("2021��10�·���Ϸ��¼.txt", "r");
				while ((fgets(zs, 1024, q10)) != NULL)
				{
					yxzsm++;
				}
				printf("һ��������%d����Ϸ\n", yxzsm+1);
				printf("��Ϸ������������\n");
				Sleep(3000);
				exit(0);//�������̣���Ϸ��
			}
			if (b  == 11)
			{
				q11 = fopen("./2021��11�·���Ϸ��¼.txt", "r");
				fscanf(q11, "%c", &ch);
				c = fgetc(q11);
				if (c == EOF)//�жϵ��·��Ƿ���й���Ϸ���ж��ļ��Ƿ�Ϊ�գ�
				{
					printf("���·�û����Ϸ��¼!\n");
					printf("��Ϸ������������\n");
					Sleep(3000);
					exit(0);
				}
				while (!feof(q11))
				{
					putchar(ch);
					fscanf(q11, "%c", &ch);
				}
				FILE *q11 = fopen("2021��11�·���Ϸ��¼.txt", "r");
				while ((fgets(zs, 1024, q11)) != NULL)
				{
					yxzsm++;
				}
				printf("һ��������%d����Ϸ\n", yxzsm+1);
				printf("��Ϸ������������\n");
				Sleep(3000);
				exit(0);//�������̣���Ϸ��
			}
			if (b  == 12)
			{
				q12 = fopen("./2021��12�·���Ϸ��¼.txt", "r");
				fscanf(q12, "%c", &ch);
				c = fgetc(q12);
				if (c == EOF)//�жϵ��·��Ƿ���й���Ϸ���ж��ļ��Ƿ�Ϊ�գ�
				{
					printf("���·�û����Ϸ��¼!\n");
					printf("��Ϸ������������\n");
					Sleep(3000);
					exit(0);
				}
				while (!feof(q12))
				{
					putchar(ch);
					fscanf(q12, "%c", &ch);
				}
				FILE *q12 = fopen("2021��12�·���Ϸ��¼.txt", "r");
				while ((fgets(zs, 1024, q12)) != NULL)
				{
					yxzsm++;
				}
				printf("һ��������%d����Ϸ\n", yxzsm+1);
				printf("��Ϸ������������\n");
				Sleep(3000);
				exit(0);//�������̣���Ϸ��
			}
		}
		else
			printf("��Ϸ������������\n");
            Sleep(3000);
                   exit(0);//�������̣���Ϸ��	        
	}
}
void _bunengchizij(SHENTIXX *shedexx)
{
	for (int i = 1; i < shedexx->sdaxiao; i++)
	{
		//��ͷ���ߵ�����Ƚϣ����ھ��ǳԵ����Լ�
		if (shedexx->shenti[0].x == shedexx->shenti[i].x&&shedexx->shenti[0].y == shedexx->shenti[i].y)
		{
			cunh = cunh + (end - start);//ͳ���ܵĴ��ʱ��
			summ += shedexx->fens;//ͳ���ܷ�
			_youxijies(shedexx);
		}
	}
}
void zawzb(SHENTIXX *shedexx)//�ϰ�������
{
	srand((unsigned)time(NULL));
	shedexx->zaw.x = rand() % GAOD;
	shedexx->zaw.y = rand() % GAOD;
}
void zawsw(SHENTIXX *shedexx)
{
	//�ϰ��ﲻ��������ʳ����
	while (shedexx->zaw.x == shedexx->shiwu.x&&
		shedexx->zaw.y == shedexx->shiwu.y)
	{
		zawzb(shedexx);//����һ������ʳ�������ϵ��ϰ���
	}
	for (int i = 0; i <= shedexx->sdaxiao; i++)//�ϰ��ﲻ��������������
	{
		if (shedexx->zaw.x == shedexx->shenti[i].x && shedexx->zaw.y == shedexx->shenti[i].y)
		{
			zawzb(shedexx);//����һ�����������ϵ��ϰ���
		}
	}
	//�ϰ������ɳɹ�
	shedexx->coord.X = shedexx->zaw.x;
	shedexx->coord.Y = shedexx->zaw.y;
	//��ת���ϰ�������λ��
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), shedexx->coord);
	printf("$");//�����ϰ���ͼ��
}
void zaw(SHENTIXX *shedexx)//����һ���ϰ���
{
	zawzb(shedexx);//�ϰ�������
	zawsw(shedexx); //�ϰ��ﲻ������ʳ����,
}
void _pengdaoswjiaycxsc(SHENTIXX *shedexx)
{
	static int k = 0;
	for (int i = 0; i < shedexx->sdaxiao; i++)
	{
		if (shedexx->shenti[0].x == shedexx->shiwu.x&&shedexx->shenti[0].y == shedexx->shiwu.y)
		{
			//�Ե�ʳ���������
			_shiwuchush(shedexx);
			//�����ӳ�
			shedexx->sdaxiao++;
			//�Ե�ʳ��ӷ���

			//-2Ϊ�������Լ��ĳ�ʼ����
			
				if (shedexx->sdaxiao - 2 < 2)
				{
					shedexx->fens += 15;
				}
				if (shedexx->sdaxiao - 2 >= 3)
				{
					shedexx->fens += 15;
				}
				if (shedexx->sdaxiao - 2 >= 5)
				{
					shedexx->fens += 20;
				}
			
				if (k == 3)
				{
					zaw(shedexx);//����һ���ϰ���
				}
				if (k == 6)
				{
					zaw(shedexx);//����һ���ϰ���
				}
				if (k == 9)
				{
					zaw(shedexx);//����һ���ϰ���
				}
				k++;
			
		}
	}
	//����ʳ�ﲻ���������ߵ�����
	for (int i = 0; i < shedexx->sdaxiao; i++)
	{
		if (shedexx->shenti[i].x == shedexx->shiwu.x&&shedexx->shenti[i].y == shedexx->shiwu.y)
		{

			_shiwuchush(shedexx);
		}
	}
}
void _kaishixy(SHENTIXX *shedexx)
{ 
	
	start = (int)time(NULL);//��ʼʱ��

	//��������ǽ
	while (shedexx->shenti[0].x<KUAND&&shedexx->shenti[0].x>-1 &&
		shedexx->shenti[0].y<GAOD&&shedexx->shenti[0].y>-1)
	{
		
		shedexx->coord.X = 40;
		shedexx->coord.Y = 7;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), shedexx->coord);
		printf("���ֵ÷�Ϊ��%d\n", shedexx->fens);
		shedexx->coord.X = 40;
		shedexx->coord.Y = 8;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), shedexx->coord);
		printf("��#������ʳ��,'$'���ϰ���\n");
		shedexx->coord.X = 40;
		shedexx->coord.Y = 9;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), shedexx->coord);
		printf("��ǰ�ߵĳ���Ϊ��%d",shedexx->sdaxiao);
		//ͷ����ײ���ϰ���
		if (shedexx->shenti[0].x == shedexx->zaw.x&&shedexx->shenti[0].y == shedexx->zaw.y)
		{
			summ += shedexx->fens;
			_youxijies(shedexx);
		}

		//�����ߵķ���
		_kongzfangxiang(shedexx);
		//�����ߵ�����
		_sehdezuob(shedexx);
		//����
		//system("cls");
		//��ʾ��
		xianhsishe(shedexx);
		//���ܳԵ��Լ�
		_bunengchizij(shedexx);
		//����ʳ�� �������һ��ʳ����ʧ�������µ�ʳ��
		_pengdaoswjiaycxsc(shedexx);
		
		if (shedexx->fens <= 50)
		{
			Sleep(300);//��ʱ
		}
		else
		if (shedexx->fens > 50 && shedexx->fens <= 100)
		{
			Sleep(200);//��ʱ
		}
		else
		if (shedexx->fens > 100 && shedexx->fens <= 200)
		{
			Sleep(200);//��ʱ
		}
		else
			Sleep(200);
		end = (int)time(NULL);//����ʱ��
		if (end - start <= 9999)
		{ 
			shedexx->coord.X = 25;//25��
			shedexx->coord.Y = 25;//25��
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), shedexx->coord);
			printf("������Ϸ����ʱ�䣺%3d��\n", end - start);//�������䶨��ָ��λ��
			
		}
		//��Ϸͨ������
		//��Ϸʧ������
		if (end - start > 60 && shedexx->fens <= 100)
		{
			_youxijies(shedexx);
		}
		//��Ϸͨ������
		if (end - start <= 60 && shedexx->fens > 1000)
		{
			system("cls");
			printf("��Ϸͨ��\n");
			exit(0);
		}
	}
	cunh = cunh + (end - start);//ͳ���ܵĴ��ʱ��
	summ += shedexx->fens;//ͳ���ܷ�
	_youxijies(shedexx);
}
void _dayinjiemian(SHENTIXX *shedexx)
{

	for (int i = 0; i <= GAOD; i++)
	{

		for (int j = 0; j <= KUAND; j++)
		{
			//���ñ߿�
			if (i == GAOD || j == KUAND)
			{
				printf("*");

			}
			else
				printf(" ");
		}
		printf("\n");
	}

}
void _yincangguangbiao()
{
	//����ϵͳ���
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}
//void _jillsfens(SHENTIXX *shedexx, FILE *p)
//{
//	p = fopen("./������ʷ��¼.txt", "a+");
//	{
//		fprintf(p, "��ʷ�ܷ�Ϊ:%d", summ);
//	}
//}
void _diyizhongyouxms()
{
	
	system("cls");
	while (i != 3)
	{
		_yincangguangbiao();//����ϵͳ���
		SHENTIXX *shedexx = (SHENTIXX *)malloc(sizeof(SHENTIXX));//���ռ�
		
		_genggaiyanshe(shedexx);//������ͷ ��������ɫ
		_dayinjiemian(shedexx);//����Χ��
		_chushihua(shedexx);//��ʼ���ߵ�����
		xianhsishe(shedexx);//��ʾ��
		//_zhangaiwushezs(shedexx);//�����ϰ���
		_kaishixy(shedexx);//��ʼ��Ϸ
		
	}
}

void _sehdezuobs(SHENTIXX *shedexx)//��Ϸģʽ2
{
	//�����ߵ�β��
	shedexx->weiba.x = shedexx->shenti[shedexx->sdaxiao - 1].x;
	shedexx->weiba.y = shedexx->shenti[shedexx->sdaxiao - 1].y;
	for (int i = 1; i <shedexx->sdaxiao; i++)
	{
		//��������������
		shedexx->shenti[i] = shedexx->shenti[i - 1];
	}
	//������ͷ���ƶ�����
	shedexx->shenti[0].x += shedexx->dx;
	shedexx->shenti[0].y += shedexx->dy;
}
void _kaishixy1(SHENTIXX *shedexx)//��Ϸģʽ2
{
	//��������ǽ
	while (shedexx->shenti[0].x<KUAND&&shedexx->shenti[0].x>-1 && shedexx->shenti[0].y<GAOD&&shedexx->shenti[0].y>-1)
	{
		//
		if (shedexx->shenti[0].x == shedexx->zaw.x&&shedexx->shenti[0].y == shedexx->zaw.y)
		{
			_youxijies(shedexx);
		}
		//�����ߵķ���
		_kongzfangxiang(shedexx);
		//�����ߵ�����
		_sehdezuobs(shedexx);
		//����
		//system("cls");
		//��ʾ��
		xianhsishe(shedexx);
		//���ܳԵ��Լ�
		_bunengchizij(shedexx);
		//����ʳ�� �������һ��ʳ����ʧ�������µ�ʳ��
		_pengdaoswjiaycxsc(shedexx);
		if (shedexx->fens <= 50)
		{
			Sleep(300);//��ʱ
		}
		else
		if (shedexx->fens > 50 && shedexx->fens <= 100)
		{
			Sleep(200);//��ʱ
		}
		else
		if (shedexx->fens > 100 && shedexx->fens <= 200)
		{
			Sleep(100);//��ʱ
		}
		else
			Sleep(50);

	}
	_youxijies(shedexx);
}

void _diergemos()//�ڶ�����Ϸģʽ
{
	
	system("cls");
	while (i != 3)
	{
		_yincangguangbiao();//����ϵͳ���
		SHENTIXX *shedexx = (SHENTIXX *)malloc(sizeof(SHENTIXX));//���ռ�
		//������ͷ ��������ɫ
		_genggaiyanshe(shedexx);
		_dayinjiemian(shedexx);
		_chushihua(shedexx);//��ʼ���ߵ�����
		xianhsishe(shedexx);//��ʾ��
		//_zhangaiwushezs(shedexx);//�����ϰ���
		_kaishixy1(shedexx);//��ʼ��Ϸ
		
	}
}
void jinajie()
{
	printf("******************************\n");
	printf("*���ߵ��ƶ�����Ϊ��wasd����  *\n");
	printf("*����ͬʱ���¡�ws����ad����*\n");
	printf("*ͨ������Ϊ��                *\n");
	printf("*��Ϸ����>=100��ʱ��<=0      *\n");
	printf("*�����ʼ��Ϸ              *\n");
	printf("******************************\n");
	printf("\n");
	printf("��Ϸ�����������Զ������ڶ�Ӧ���ļ���\n��ǰȥ�ļ��в鿴��Ҳ����ͨ������Ӧ�ġ����������в鿴");
	
	Sleep(5000);
}
int main()
{
	
	printf("*******************\n");
	printf("*����1������Ϸ1   *\n");
	printf("*����2������Ϸ2   *\n");
	printf("*����esc���˳���Ϸ*\n");
	printf("*******************\n");
	printf("�����룺");
	char mun = 0;
	while (1)
	{
		if (mun = _getch() == '1')
		{
			system("cls");
			jinajie();
			
			_diyizhongyouxms();
		}
		else if (mun = _getch() == '2')
		{
			_diergemos();
		}
		else  if (mun = _getch() == 27)//ASCII esc=27
		{
			exit(0);
		}
		else
			printf("���������������:\n");
			continue;
	}
}
