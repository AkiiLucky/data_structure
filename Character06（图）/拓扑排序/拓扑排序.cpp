#include <stdio.h>
#include "SqStack.cpp"

#define MaxVertexNum 100                          //顶点数目的最大值 
#define VertexType int



/* 邻接表存储 */
typedef struct ArcNode {						//边表结点 
	int adjvex;									//该弧指向的顶点的位置 
	struct ArcNode *next;						//指向下一条弧的指针 
	//InfoNode info;							//网的边权值 
}ArcNode;

typedef struct VNode {							//顶点表结点 
	VertexType data;							//顶点信息 
	ArcNode *first;								//指向第一条依附该顶点的弧的指针 
}VNode, AdjList[MaxVertexNum]; 

typedef struct {
	AdjList vertices;							//邻接表 
	int vexnum, arcnum;							//图的当前顶点数和边数/弧数 
} ALGraph;										//ALGraph 是以邻接表存储的图类型


/* AOV网的拓扑排序 */ 
bool TopologicalSort(ALGraph G)
{
	SqStack S;									//定义一个栈，用于存储度为 0 的结点 
	InitStack(S);
	int indegree[G.vexnum]; 					//记录各个顶点的入度 (未初始化) 
	int print[G.vexnum];						//记录拓扑序列
	
	for (int i=0; i<G.vexnum; i++)
	{
		if (indegree[i] == 0) 
		{
			Push(S, i);							//将所有入度为 0 的顶点入栈
		} 
	} 
	
	int count = 0;								//计数，记录当前已经输出的顶点数 
	while (!IsEmpty(S))
	{
		int i;
		Pop(S, i);
		print[count++] = i;
		for (ArcNode *p=G.vertices[i].first; p != NULL; p=p->next)
		{
			int v = p->adjvex;					// p 指向顶点 i 的边结点 
			--indegree[v];						//将顶点 i 指向的所有顶点的入度减 1 
			if (indegree[v] == 0)
			{
				Push(S, v);						//入度为 0 ，则入栈 
			}
		}
	}
	
	if (count < G.vexnum) return false;			//排序失败，有向图中有回路 
	else return true;							//拓扑排序成功 
} 

int main()
{
	ALGraph G;
	return 0;
}
