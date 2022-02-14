#include <stdio.h>
#include "LinkQueue.cpp"

#define MaxVertexNum 100                          //顶点数目的最大值 
#define VertexType int


/* 邻接矩阵存储 */
typedef struct {
	VertexType Vex[MaxVertexNum];				//顶点表 
	int Edge[MaxVertexNum][MaxVertexNum];		//邻接矩阵，边表 
	int vexnum, arcnum;						    //图的当前顶点数和边数/弧数 
}MGraph;

//辅助函数 
int FirstNeighbor(MGraph G, int v)       		//求顶点 v 的第一个邻接点
{
	for (int i=0; i<G.vexnum; ++i)
	{
		if (G.Edge[v][i] == 1)
		{
			return i;
		}
	}
	return -1; 
} 
int NextNeighbor(MGraph G, int v, int w)    	//求顶点 v 的除顶点 w 以外的下一个邻接点 
{
	for (int i=w; i<G.vexnum; ++i)
	{
		if (G.Edge[v][i] == 1)
		{
			return i;
		}
	}
	return -1;
}
void visit(MGraph G, int v) 					//访问图 G 中的顶点 v 
{
	printf("%d\n", G.Vex[v]);
} 


/* 深度优先搜索 */
bool visited[MaxVertexNum];
void DFS(MGraph G, int v);						
void DFSTraverse(MGraph G)
{
	for (int i=0; i<G.vexnum; ++i)
	{
		visited[i] = false;						//初始化标记数组 
	}
	for (int i=0; i<G.vexnum; ++i)
	{
		if (!visited[i])						//访问图 G 的每个连通分量 
		{
			DFS(G, i);
		}
	}
} 
void DFS(MGraph G, int v)
{
	visit(G, v);
	visited[v] = true;
	for (int w=FirstNeighbor(G, v); w>=0; w=NextNeighbor(G, v, w))
	{
		if (!visited[w])
		{
			visit(G, w);
			DFS(G, w);
		}
	}
}



int main()
{
	return 0;
}
