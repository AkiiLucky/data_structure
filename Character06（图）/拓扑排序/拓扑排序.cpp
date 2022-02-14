#include <stdio.h>
#include "SqStack.cpp"

#define MaxVertexNum 100                          //������Ŀ�����ֵ 
#define VertexType int



/* �ڽӱ�洢 */
typedef struct ArcNode {						//�߱��� 
	int adjvex;									//�û�ָ��Ķ����λ�� 
	struct ArcNode *next;						//ָ����һ������ָ�� 
	//InfoNode info;							//���ı�Ȩֵ 
}ArcNode;

typedef struct VNode {							//������� 
	VertexType data;							//������Ϣ 
	ArcNode *first;								//ָ���һ�������ö���Ļ���ָ�� 
}VNode, AdjList[MaxVertexNum]; 

typedef struct {
	AdjList vertices;							//�ڽӱ� 
	int vexnum, arcnum;							//ͼ�ĵ�ǰ�������ͱ���/���� 
} ALGraph;										//ALGraph �����ڽӱ�洢��ͼ����


/* AOV������������ */ 
bool TopologicalSort(ALGraph G)
{
	SqStack S;									//����һ��ջ�����ڴ洢��Ϊ 0 �Ľ�� 
	InitStack(S);
	int indegree[G.vexnum]; 					//��¼������������ (δ��ʼ��) 
	int print[G.vexnum];						//��¼��������
	
	for (int i=0; i<G.vexnum; i++)
	{
		if (indegree[i] == 0) 
		{
			Push(S, i);							//���������Ϊ 0 �Ķ�����ջ
		} 
	} 
	
	int count = 0;								//��������¼��ǰ�Ѿ�����Ķ����� 
	while (!IsEmpty(S))
	{
		int i;
		Pop(S, i);
		print[count++] = i;
		for (ArcNode *p=G.vertices[i].first; p != NULL; p=p->next)
		{
			int v = p->adjvex;					// p ָ�򶥵� i �ı߽�� 
			--indegree[v];						//������ i ָ������ж������ȼ� 1 
			if (indegree[v] == 0)
			{
				Push(S, v);						//���Ϊ 0 ������ջ 
			}
		}
	}
	
	if (count < G.vexnum) return false;			//����ʧ�ܣ�����ͼ���л�· 
	else return true;							//��������ɹ� 
} 

int main()
{
	ALGraph G;
	return 0;
}
