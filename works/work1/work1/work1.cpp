#include "pch.h"
#include <iostream>
typedef int InfoType;
#define MAXV 12

typedef struct ANode
{
	int adjvex;						//边的邻接点编号
	struct ANode *nextarc;  //指向下一条边的指针
	int weight;						//边的权值
}ArcNode;//边结点的类型

typedef struct Vnode
{
	InfoType info;//结点所含信息
	ArcNode *firstarc;//指向第一个边结点
}VNode;

typedef struct
{
	VNode adjlist[MAXV];//头节点数组
	int n;//图中顶点数
	int e;//图中边数
}AdjGraph;

bool visited[MAXV];
void DFS(AdjGraph *G, int v)//深度优先遍历算法
{
	ArcNode *p;
	visited[v] = true;//将v结点置为已访问
	printf("%d ", v);//输出结点序列
	p = G->adjlist[v].firstarc;//p指向v的第一个邻接点
	while (p != NULL)
	{
		if (visited[p->adjvex] == false)
		{
			DFS(G, p->adjvex);
		}
		p = p->nextarc;
	}
}

void CreatAdj(AdjGraph *&G, int A[MAXV][MAXV], int n, int e)//将图转换为邻接表形式
{
	ArcNode *p;
	G = (AdjGraph *)malloc(sizeof(AdjGraph));
	for (int i = 0; i < n; i++)
	{
		G->adjlist[i].firstarc = NULL;
	}//初始化图

	for(int i=0;i<n;i++)
		for (int j = n - 1; j >=0; j--)
		{
			if (A[i][j] != 0 && A[i][j] != INFINITY)
			{
				p = (ArcNode *)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->weight = A[i][j];
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
		}//建立图


	G->n = n;
	G->e = e;
}

void DestroyAdj(AdjGraph *&G)//销毁图
{
	int i;
	ArcNode *p;
	ArcNode *pre;
	for (int i = 0; i < G->n; i++)
	{
		pre= G->adjlist[i].firstarc;
		if (pre != NULL)
		{
			p = pre->nextarc;
			while (p != NULL)
			{
				free(pre);
				pre = p;
				p = p->nextarc;
			}
			free(pre);
		}
	}
	free(G);
}


int main()
{
	//创建图
	/*int A[11][11] = {
		{0,0,1,1,1,0,0,0,0,0,1},
		{0,0,1,0,0,0,1,0,0,0,0},
		{1,1,0,0,1,1,1,0,0,0,0},
		{1,0,0,0,1,0,0,0,1,0,0},
		{1,0,1,1,0,1,0,0,1,1,0},
		{0,0,1,0,1,0,1,0,0,1,0},
		{0,1,1,0,0,1,0,0,0,1,0},
		{0,0,0,0,0,0,0,0,1,1,1},
		{0,0,0,1,1,0,0,1,0,0,0},
		{0,0,0,0,1,1,1,1,0,0,1},
		{1,0,0,0,0,0,0,1,0,1,0},
	};*/
	int A[12][12] = {
		{0,0,1,1,1,0,0,0,0,0,1,1},
		{0,0,1,0,0,0,1,0,0,0,0,0},
		{0,1,0,0,1,1,1,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,1,0,0,0},
		{0,0,1,1,0,1,0,0,1,1,0,0},
		{0,0,1,0,1,0,1,0,0,1,0,0},
		{0,0,1,0,0,1,0,0,0,1,0,0},
		{0,0,0,0,0,0,0,0,1,1,1,0},
		{0,0,0,1,1,0,0,1,0,0,0,0},
		{0,0,0,0,0,1,1,1,0,0,1,0},
		{0,0,0,0,0,0,0,1,0,1,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0}
	};
	AdjGraph *G;
	CreatAdj(G, A, 12, 22);
	DFS(G, 0);
	DestroyAdj(G);

	
}