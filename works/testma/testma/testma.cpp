#include "pch.h"
#include <iostream>
constexpr auto N = 6;

void test(int ,int,bool map[N][N],int col[8],int row[8], int cols[N*N], int rows[N*N], int& n);

int main()
{
	int a, b;//棋子的起始位置
	int c = N;
	int col[8] = { 1,1,2,2,-1,-1,-2,-2 };
	int row[8] = { 2,-2,1,-1,2,-2,1,-1 };//棋子移动的方向数组
	int cols[N*N];
	int rows[N*N];//记录棋子的移动路径
	int n = 0;//记录棋子的移动步数，
	bool map[N][N];//地图
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map[N][N] = true;//初始化地图
	printf("当前棋盘的长宽为：%d\n", c);
	do
	{
		printf("请输入棋子的起始位置的横坐标\n");
		scanf_s("%d", &a);
		printf("请输入棋子的起始位置的纵坐标\n");
		scanf_s("%d", &b);
	} while (a >=N||b>=N);//输入信息

	test(a, b, map,col,row,cols,rows,n);
	printf("所有可能路线输出完毕!");
}

void push(int c, int r, int cols[N*N], int rows[N*N], bool map[N][N], int &n)
{
	n++;
	cols[n - 1] = c;
	rows[n - 1] = r;
	map[c][ r] = false;
}//入栈

void pop(int c, int r, bool map[N][N], int &n)
{
	map[c][r] = true;
	n--;
}//出栈

void test(int c, int r, bool map[N][N],int col[8],int row[8],int cols[N*N],int rows[N*N],int &n)
{

	if (c>=0&&c < N &&r>= 0&&r < N && map[c][r])
	{
		push(c, r, cols, rows, map, n);
		if (n == N * N)
		{
			for (int i = 0; i < N*N; i++)
			{
				printf("(%d,%d)", cols[i], rows[i]);
			}
			printf("\n\n");
		}
		else
		{
			for (int i = 0; i < 8; i++)
			{
				test(col[i] + c, row[i] + r, map, col, row, cols, rows, n);
			}
		}
		pop(c, r, map, n);
	}
	
}
