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
bool visited[MaxVertexNum];						//�����������  
void BFS(MGraph G, int v);
void BFSTraverse(MGraph G)
{
	for (int i=0; i<G.vexnum; ++i)				//��ʼ��������� 
	{
		visited[i] = false;
	}
	
	for (int i=0; i<G.vexnum; ++i) 
	{
		if (!visited[i])						//��ÿ����ͨ��������һ�� BFS 
		{
			BFS(G, i);
		}
	}
}
void BFS(MGraph G, int v)
{
	visit(G, v);						    	//���ʳ�ʼ���� v
	visited[v] = true;
	LinkQueue Q;                                //��������
	InitQueue(Q);								//��ʼ���������� 
	EnQueue(Q, v);								//���� v �����
	while (!IsEmpty(Q))
	{
		DeQueue(Q, v);							//���� v ������ 
		for (int w=FirstNeighbor(G, v); w>=0; w=NextNeighbor(G, v, w))
		{
			if (!visited[w])
			{
				visit(G, w);			    	//���ʶ��� w 
				visited[w] = true;
				EnQueue(Q, w);					//���� w ����� 
			}
		}
	}
} 



/* BFS��ⵥԴ���·�� */
void BFS_MIN_Distance(MGraph G, int u)
{
	int d[G.vexnum];				
	for (int i=0; i<G.vexnum; ++i)
	{
		d[i] = 65535;							//d[i]��ʾ�� u �� i �������·������ʼ��Ϊ����Զ 
	}
	visited[u] = true;
	d[u] = 0;
	LinkQueue Q;                                //��������
	InitQueue(Q);								//��ʼ���������� 
	EnQueue(Q, u);								//���� u �����
	while (!IsEmpty(Q)) 
	{
		DeQueue(Q, u);
		for (int w=FirstNeighbor(G, u); w>=0; w=NextNeighbor(G, u, w))
		{
			if (!visited[w])
			{
				visited[w] = true;
				d[w] = d[u] + 1;
				EnQueue(Q, w);					//���� w ����� 
			}
		}
	}
}



int main()
{
	return 0;
}

