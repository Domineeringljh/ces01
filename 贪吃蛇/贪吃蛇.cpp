// 贪吃蛇.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
int i = 0;//三条命
int sum = 0;//总分统计
int k = 3;//统计还有多少机会
static int summ = 0;
//定义游戏高度和宽度
#define GAOD 10//高
#define KUAND 30//宽
//定义游戏坐标 x,y 
typedef struct _zuobiao
{
	int x;//宽
	int y;//高
}ZUOB;
typedef struct shentixx
{
	ZUOB shenti[KUAND*GAOD];//身体,身体的每一节坐标都是ZUOB型
	int sdaxiao;//蛇的大小
	ZUOB shiwu;//食物
	COORD coord;//windows 函数
	int dx;//蛇的x轴移动方向
	int dy;//蛇的y轴移动方向
	int fens;//分数
	ZUOB weiba;//蛇的尾巴
	ZUOB zaw;//障碍物
}SHENTIXX;

void _shiwuchush(SHENTIXX *shedexx)
{

	
	srand((unsigned)time(NULL));//定义随机食物的种子
	//初始化食物坐标
	shedexx->shiwu.x = rand() % KUAND;
	shedexx->shiwu.y = rand() % GAOD;
}

void _genggaiyanshe(SHENTIXX *shedexx)
{
	//更改蛇头颜色
	shedexx->shenti[0].x = system("color a");
	shedexx->shenti[0].y = system("color a");
	for (int i = shedexx->sdaxiao; i > 1; i--)
	{
		//更改蛇身颜色
		shedexx->shenti[i].x = system("color c");
		shedexx->shenti[i].y = system("color c");
	}
}
void _chushihua(SHENTIXX *shedexx)
{

	//初始化蛇头及出生地  (地图中间)
	shedexx->shenti[0].x = KUAND / 2;
	shedexx->shenti[0].y = GAOD / 2;
	//初始化蛇尾及出生地  (蛇头后面)
	shedexx->shenti[1].x = KUAND / 2 - 1;
	shedexx->shenti[1].y = GAOD / 2;
	//初始化蛇的大小
	shedexx->sdaxiao = 2;
	//初始化蛇的食物
	_shiwuchush(shedexx);
	//初始化蛇移动的方向
	shedexx->dx = 1;
	shedexx->dy = 0;
	//初始化分数
	shedexx->fens = 0;
	
	//shedexx->fans1 = 0;
}
void xianhsishe(SHENTIXX *shedexx)
{
	for (int i = 0; i < shedexx->sdaxiao; i++)
	{

		//显示蛇 注意：每次显示蛇 都要重新定义光标位置
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
	//显示食物
	shedexx->coord.X = shedexx->shiwu.x;
	shedexx->coord.Y = shedexx->shiwu.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), shedexx->coord);
	printf("#");
	//将尾巴最后一节设置为NULL
	shedexx->coord.X = shedexx->weiba.x;
	shedexx->coord.Y = shedexx->weiba.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), shedexx->coord);
	printf(" ");
}
void _sehdezuob(SHENTIXX *shedexx)
{
	//设置蛇的尾巴
	shedexx->weiba.x = shedexx->shenti[shedexx->sdaxiao - 1].x;
	shedexx->weiba.y = shedexx->shenti[shedexx->sdaxiao - 1].y;
	for (int i = shedexx->sdaxiao-1; i > 0; i--)
	{
		//更新蛇身体坐标
		shedexx->shenti[i] = shedexx->shenti[i - 1];
	}
	//更新蛇头（移动方向）
	shedexx->shenti[0].x += shedexx->dx;
	shedexx->shenti[0].y += shedexx->dy;
}
void _kongzfangxiang(SHENTIXX *shedexx)
{
	char kongz= 0 ;
	while (_kbhit())//判断是否按下键位，按下不为0
	{
		kongz = _getch();
	}
	switch (kongz)//控制蛇的方向（前后左右）
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

	//将输出的结果的位置更改
	
	Sleep(3000);//延迟三秒结束游戏
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
		printf("总分为：%d\n", summ);
		Sleep(3000);
      exit(0);//结束进程（游戏）
	}
	

}
void _bunengchizij(SHENTIXX *shedexx)
{
	for (int i = 1; i < shedexx->sdaxiao; i++)
	{
		//用头跟蛇的身体比较，等于就是吃到了自己
		if (shedexx->shenti[0].x == shedexx->shenti[i].x&&shedexx->shenti[0].y == shedexx->shenti[i].y)
		{
			_youxijies(shedexx);
		}
	}
}
void zawzb(SHENTIXX *shedexx)//障碍物坐标
{
	srand((unsigned)time(NULL));
	shedexx->zaw.x = rand() % GAOD;
	shedexx->zaw.y = rand() % GAOD;
}
void zawsw(SHENTIXX *shedexx)
{
	//障碍物不能生成在食物上
	while (shedexx->zaw.x == shedexx->shiwu.x&&
		shedexx->zaw.y == shedexx->shiwu.y)
	{
		zawzb(shedexx);//生成一个不在食物坐标上的障碍物
	}
	for (int i = 0; i <= shedexx->sdaxiao; i++)//障碍物不能生成在蛇身上
	{
		if (shedexx->zaw.x == shedexx->shenti[i].x && shedexx->zaw.y == shedexx->shenti[i].y)
		{
			zawzb(shedexx);//生成一个不在蛇身上的障碍物
		}
	}
	//障碍物生成成功
	shedexx->coord.X = shedexx->zaw.x;
	shedexx->coord.Y = shedexx->zaw.y;
	//跳转至障碍物坐标位置
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), shedexx->coord);
	printf("$");//生成障碍物图标
}
void zaw(SHENTIXX *shedexx)//生成一个障碍物
{
	zawzb(shedexx);//障碍物坐标
	zawsw(shedexx); //障碍物不能生在食物上,
}
void _pengdaoswjiaycxsc(SHENTIXX *shedexx)
{
	static int k = 0;
	for (int i = 0; i < shedexx->sdaxiao; i++)
	{
		if (shedexx->shenti[0].x == shedexx->shiwu.x&&shedexx->shenti[0].y == shedexx->shiwu.y)
		{
			//吃到食物，重新生成
			_shiwuchush(shedexx);
			//蛇身加长
			shedexx->sdaxiao++;
			//吃到食物加分数

			//-2为减掉蛇自己的初始长度
			
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
					zaw(shedexx);//生成一个障碍物
				}
				if (k == 6)
				{
					zaw(shedexx);//生成一个障碍物
				}
				if (k == 9)
				{
					zaw(shedexx);//生成一个障碍物
				}
				k++;
			
		}
	}
	//设置食物不能生成在蛇的身上
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
	start = (int)time(NULL);//开始时间

	//不能碰到墙
	while (shedexx->shenti[0].x<KUAND&&shedexx->shenti[0].x>-1 &&
		shedexx->shenti[0].y<GAOD&&shedexx->shenti[0].y>-1)
	{
		
		shedexx->coord.X = 40;
		shedexx->coord.Y = 7;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), shedexx->coord);
		printf("总分为：%d\n", summ);
		shedexx->coord.X = 40;
		shedexx->coord.Y = 8;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), shedexx->coord);
		printf("第%d局本局得分为：%d\n",i+1, shedexx->fens);
		
		//头不能撞上障碍物
		if (shedexx->shenti[0].x == shedexx->zaw.x&&shedexx->shenti[0].y == shedexx->zaw.y)
		{
			summ += shedexx->fens;
			_youxijies(shedexx);
		}

		//控制蛇的方向
		_kongzfangxiang(shedexx);
		//更新蛇的坐标
		_sehdezuob(shedexx);
		//清屏
		//system("cls");
		//显示蛇
		xianhsishe(shedexx);
		//不能吃到自己
		_bunengchizij(shedexx);
		//碰到食物 蛇身体加一，食物消失，产生新的食物
		_pengdaoswjiaycxsc(shedexx);
		
		if (shedexx->fens <= 50)
		{
			Sleep(300);//延时
		}
		else
		if (shedexx->fens > 50 && shedexx->fens <= 100)
		{
			Sleep(200);//延时
		}
		else
		if (shedexx->fens > 100 && shedexx->fens <= 200)
		{
			Sleep(100);//延时
		}
		else
			Sleep(50);
		end = (int)time(NULL);//结束时间
		if (end - start <= 60)
		{ 
			shedexx->coord.X = 25;//25列
			shedexx->coord.Y = 25;//25行
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), shedexx->coord);
			printf("本局游戏进行时间：%3d秒\n", end - start);//将输出语句定在指定位置
		}
		//游戏通关条件
		//游戏失败条件
		if (end - start > 60 && shedexx->fens <= 100)
		{
			_youxijies(shedexx);
		}
		//游戏通关条件
		if (end - start <= 60 && shedexx->fens > 1000)
		{
			system("cls");
			printf("游戏通关\n");
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
			//设置边框
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
	//隐藏系统光标
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
		_yincangguangbiao();//隐藏系统光标
		SHENTIXX *shedexx = (SHENTIXX *)malloc(sizeof(SHENTIXX));//开空间
		//更改蛇头 蛇身体颜色
		_genggaiyanshe(shedexx);
		_dayinjiemian(shedexx);
		_chushihua(shedexx);//初始化蛇的身体
		xianhsishe(shedexx);//显示蛇
		//_zhangaiwushezs(shedexx);//设置障碍物
		_kaishixy(shedexx);//开始游戏
	}
}
void _xiangmujies()
{
	
	printf("*******************\n");
	printf("*输入1进入游戏1   *\n");
	printf("*输入2进入游戏2   *\n");
	printf("*输入esc键退出游戏*\n");
	printf("*******************\n");
	
	
}
void _sehdezuobs(SHENTIXX *shedexx)//游戏模式2
{
	//设置蛇的尾巴
	shedexx->weiba.x = shedexx->shenti[shedexx->sdaxiao - 1].x;
	shedexx->weiba.y = shedexx->shenti[shedexx->sdaxiao - 1].y;
	for (int i = 1; i <shedexx->sdaxiao; i++)
	{
		//更新蛇身体坐标
		shedexx->shenti[i] = shedexx->shenti[i - 1];
	}
	//更新蛇头（移动方向）
	shedexx->shenti[0].x += shedexx->dx;
	shedexx->shenti[0].y += shedexx->dy;
}
void _kaishixy1(SHENTIXX *shedexx)//游戏模式2
{
	//不能碰到墙
	while (shedexx->shenti[0].x<KUAND&&shedexx->shenti[0].x>-1 && shedexx->shenti[0].y<GAOD&&shedexx->shenti[0].y>-1)
	{
		//
		if (shedexx->shenti[0].x == shedexx->zaw.x&&shedexx->shenti[0].y == shedexx->zaw.y)
		{
			_youxijies(shedexx);
		}
		//控制蛇的方向
		_kongzfangxiang(shedexx);
		//更新蛇的坐标
		_sehdezuobs(shedexx);
		//清屏
		//system("cls");
		//显示蛇
		xianhsishe(shedexx);
		//不能吃到自己
		_bunengchizij(shedexx);
		//碰到食物 蛇身体加一，食物消失，产生新的食物
		_pengdaoswjiaycxsc(shedexx);
		if (shedexx->fens <= 50)
		{
			Sleep(300);//延时
		}
		else
		if (shedexx->fens > 50 && shedexx->fens <= 100)
		{
			Sleep(200);//延时
		}
		else
		if (shedexx->fens > 100 && shedexx->fens <= 200)
		{
			Sleep(100);//延时
		}
		else
			Sleep(50);

	}
	_youxijies(shedexx);
}

void _diergemos()//第二种游戏模式
{
	system("cls");
	while (i != 3)
	{
		_yincangguangbiao();//隐藏系统光标
		SHENTIXX *shedexx = (SHENTIXX *)malloc(sizeof(SHENTIXX));//开空间
		//更改蛇头 蛇身体颜色
		_genggaiyanshe(shedexx);
		_dayinjiemian(shedexx);
		_chushihua(shedexx);//初始化蛇的身体
		xianhsishe(shedexx);//显示蛇
		//_zhangaiwushezs(shedexx);//设置障碍物
		_kaishixy1(shedexx);//开始游戏
		free(shedexx);
	}
}
void _youxcaozjians()
{
	printf("******************************\n");
	printf("*本蛇的移动控制为“wasd”键  *\n");
	printf("*不能同时按下“ws”或“ad”键*\n");
	printf("*通关条件为▼                *\n");
	printf("*游戏分数>=100并时间<=0      *\n");
	printf("******************************\n");
}
int main()
{
	_xiangmujies();
	printf("请输入对应数字:");
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
			printf("输入错误，重新输入:\n");
			continue;
	}
	
}
