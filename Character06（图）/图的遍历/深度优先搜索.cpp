#include <stdio.h>
#include "LinkQueue.cpp"

#define MaxVertexNum 100                          //������Ŀ�����ֵ 
#define VertexType int


/* �ڽӾ���洢 */
typedef struct {
	VertexType Vex[MaxVertexNum];				//����� 
	int Edge[MaxVertexNum][MaxVertexNum];		//�ڽӾ��󣬱߱� 
	int vexnum, arcnum;						    //ͼ�ĵ�ǰ�������ͱ���/���� 
}MGraph;

//�������� 
int FirstNeighbor(MGraph G, int v)       		//�󶥵� v �ĵ�һ���ڽӵ�
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
int NextNeighbor(MGraph G, int v, int w)    	//�󶥵� v �ĳ����� w �������һ���ڽӵ� 
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
void visit(MGraph G, int v) 					//����ͼ G �еĶ��� v 
{
	printf("%d\n", G.Vex[v]);
} 


/* ����������� */
bool visited[MaxVertexNum];
void DFS(MGraph G, int v);						
void DFSTraverse(MGraph G)
{
	for (int i=0; i<G.vexnum; ++i)
	{
		visited[i] = false;						//��ʼ��������� 
	}
	for (int i=0; i<G.vexnum; ++i)
	{
		if (!visited[i])						//����ͼ G ��ÿ����ͨ���� 
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
