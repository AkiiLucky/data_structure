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




/* 广度优先搜索 */
bool visited[MaxVertexNum];						//创建标记数组  
void BFS(MGraph G, int v);
void BFSTraverse(MGraph G)
{
	for (int i=0; i<G.vexnum; ++i)				//初始化标记数组 
	{
		visited[i] = false;
	}
	
	for (int i=0; i<G.vexnum; ++i) 
	{
		if (!visited[i])						//对每个连通分量调用一次 BFS 
		{
			BFS(G, i);
		}
	}
}
void BFS(MGraph G, int v)
{
	visit(G, v);						    	//访问初始顶点 v
	visited[v] = true;
	LinkQueue Q;                                //辅助队列
	InitQueue(Q);								//初始化辅助队列 
	EnQueue(Q, v);								//顶点 v 入队列
	while (!IsEmpty(Q))
	{
		DeQueue(Q, v);							//顶点 v 出队列 
		for (int w=FirstNeighbor(G, v); w>=0; w=NextNeighbor(G, v, w))
		{
			if (!visited[w])
			{
				visit(G, w);			    	//访问顶点 w 
				visited[w] = true;
				EnQueue(Q, w);					//顶点 w 入队列 
			}
		}
	}
} 



/* BFS求解单源最短路径 */
void BFS_MIN_Distance(MGraph G, int u)
{
	int d[G.vexnum];				
	for (int i=0; i<G.vexnum; ++i)
	{
		d[i] = 65535;							//d[i]表示从 u 到 i 结点的最短路径，初始化为无穷远 
	}
	visited[u] = true;
	d[u] = 0;
	LinkQueue Q;                                //辅助队列
	InitQueue(Q);								//初始化辅助队列 
	EnQueue(Q, u);								//顶点 u 入队列
	while (!IsEmpty(Q)) 
	{
		DeQueue(Q, u);
		for (int w=FirstNeighbor(G, u); w>=0; w=NextNeighbor(G, u, w))
		{
			if (!visited[w])
			{
				visited[w] = true;
				d[w] = d[u] + 1;
				EnQueue(Q, w);					//顶点 w 入队列 
			}
		}
	}
}



int main()
{
	return 0;
}

