// ̰����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
int i = 0;//������
int sum = 0;//�ܷ�ͳ��
int k = 3;//ͳ�ƻ��ж��ٻ���
static int summ = 0;
//������Ϸ�߶ȺͿ��
#define GAOD 10//��
#define KUAND 30//��
//������Ϸ���� x,y 
typedef struct _zuobiao
{
	int x;//��
	int y;//��
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
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), shedexx->coord);
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

	//������Ľ����λ�ø���
	
	Sleep(3000);//�ӳ����������Ϸ
	i++;
	
	if (i <3)
	{	
		
       system("cls");
	}

	if (i == 3)
	{
		shedexx->coord.X = 40;
		shedexx->coord.Y = 7;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), shedexx->coord);
		printf("�ܷ�Ϊ��%d\n", summ);
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
			//����ӳ�
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
	int start = 0, end = 0;
	start = (int)time(NULL);//��ʼʱ��

	//��������ǽ
	while (shedexx->shenti[0].x<KUAND&&shedexx->shenti[0].x>-1 &&
		shedexx->shenti[0].y<GAOD&&shedexx->shenti[0].y>-1)
	{
		
		shedexx->coord.X = 40;
		shedexx->coord.Y = 7;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), shedexx->coord);
		printf("�ܷ�Ϊ��%d\n", summ);
		shedexx->coord.X = 40;
		shedexx->coord.Y = 8;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), shedexx->coord);
		printf("��%d�ֱ��ֵ÷�Ϊ��%d\n",i+1, shedexx->fens);
		
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
			Sleep(100);//��ʱ
		}
		else
			Sleep(50);
		end = (int)time(NULL);//����ʱ��
		if (end - start <= 60)
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
	summ += shedexx->fens;
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
void _diyizhongyouxms()
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
		_kaishixy(shedexx);//��ʼ��Ϸ
	}
}
void _xiangmujies()
{
	
	printf("*******************\n");
	printf("*����1������Ϸ1   *\n");
	printf("*����2������Ϸ2   *\n");
	printf("*����esc���˳���Ϸ*\n");
	printf("*******************\n");
	
	
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
		free(shedexx);
	}
}
void _youxcaozjians()
{
	printf("******************************\n");
	printf("*���ߵ��ƶ�����Ϊ��wasd����  *\n");
	printf("*����ͬʱ���¡�ws����ad����*\n");
	printf("*ͨ������Ϊ��                *\n");
	printf("*��Ϸ����>=100��ʱ��<=0      *\n");
	printf("******************************\n");
}
int main()
{
	_xiangmujies();
	printf("�������Ӧ����:");
	system("cls");
	_youxcaozjians();
	char mun = 0;
	
	while (1)
	{
		if (mun = _getch() == '1')
		{
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
