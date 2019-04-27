#include "pch.h"
#include <iostream>
constexpr auto M = 5;//障碍棋子数
constexpr auto N = 6;

void test(int, int, int map[N][N], int col[8], int row[8], int cols[N*N], int rows[N*N], int& n,int,int);

int main()
{
	int a, b;//棋子的起始位置
	int c = N;
	int col[8] = { 1,1,2,2,-1,-1,-2,-2 };
	int row[8] = { 2,-2,1,-1,2,-2,1,-1 };//棋子移动的方向数组
	int cols[N*N];
	int rows[N*N];//记录棋子的移动路径
	int n = 0;//记录棋子的移动步数，
	int map[N][N] = {
		{0,-1,-1,-1,-1,-1},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		//{0,0,0,0,0,0,0}
	};//地图初始化
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map[N][N] = 0;//初始化地图
	printf("当前棋盘的长宽为：%d\n", c);
	do
	{
		printf("请输入棋子的起始位置的横坐标\n");
		scanf_s("%d", &a);
		printf("请输入棋子的起始位置的纵坐标\n");
		scanf_s("%d", &b);
	} while (a >= N || b >= N);//输入信息

	test(a, b, map, col, row, cols, rows, n,a,b);
	printf("所有可能路线输出完毕!");
}

void push(int c, int r, int cols[N*N], int rows[N*N], int map[N][N], int &n)
{
	n++;
	cols[n - 1] = c;
	rows[n - 1] = r;
	map[c][r] = 1;
}//入栈

void pop(int c, int r, int map[N][N], int &n)
{
	map[c][r] = 0;
	n--;
}//出栈


void test(int c, int r, int map[N][N], int col[8], int row[8], int cols[N*N], int rows[N*N], int &n,int lc,int lr)
////输入参数依次为 测试横坐标，纵坐标，地图数组，移动方向数组，储存移动路径的横纵数组，移动步数，之前的横纵坐标
{
	bool go = false;
	if (c - lc == -2 && map[lc - 1][lr] != -1) go = true;
	else if (c - lc == 2 && map[lc +1][lr] != -1) go = true;
	else if (r- lr == -2 && map[lc][lr - 1] != -1) go = true;
	else if (r- lr == 2 && map[lc][lr + 1] != -1) go = true;
	else if (c - lc == 0 && r - lr == 0) go = true;//用于启动


	if (c >= 0 && c < N &&r >= 0 && r < N && map[c][r]==0&&go)//如果当前位置可以走
	{
		//push(c, r, cols, rows,map,n);
		push(c, r, cols, rows, map, n);//入栈

		if (n == (N * N)-M)
		{
			for (int i = 0; i < N*N-M; i++)
			{
				printf("(%d,%d)", cols[i], rows[i]);
			}
			printf("\n\n");//如果遍历完毕则输出路径
		}
		else
		{
			for (int i = 0; i < 8; i++)
			{
				test(col[i] + c, row[i] + r, map, col, row, cols, rows, n,c,r);
			}//否则开始选择下一个前进方向
		}
		pop(c, r, map, n);//测试当前所有位置后出栈
	}

}
