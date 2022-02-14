#ifndef __AdjMatrixDirGraph__
#define __AdjMatrixDirGraph__

#include <iostream>
#include "DbLinkList.h"

using namespace std;

typedef bool StatusCode;
#define SUCCESS 1
#define ERROR 0
#define RANGE_ERROR 0


template <class ElemType>
class AdjMatrixDirGraph 
{
protected:
	int vexNum, edgeNum;				//��������ͱ���
	int** Matrix;						//�ڽӾ���
	ElemType* elems;					//����Ԫ��

public:
	AdjMatrixDirGraph(ElemType os[], int vertexNum);
	~AdjMatrixDirGraph();
	StatusCode addEdge(ElemType e1, ElemType e2);		//����һ���� elem1 ָ�� elem2 �������
	int FirstNeighbor(int v);							//�󶥵� v �ĵ�һ���ڽӵ�
	int NextNeighbor(int v, int w);						//�󶥵� v �ĳ����� w �������һ���ڽӵ� 
	void TopoSortAll(bool visited[], int indegree[], DbLinkList<char> ans, int &tag);
	void FindCircle();									//Ѱ�һ�·
	StatusCode TopoSort();								//��������
};



template <class ElemType>
AdjMatrixDirGraph<ElemType>::AdjMatrixDirGraph(ElemType os[], int vertexNum)
{
	elems = new ElemType[vertexNum];
	for (int i = 0; i < vertexNum; i++)
	{
		elems[i] = os[i];
	}

	Matrix = new int*[vertexNum];
	for (int i = 0; i < vertexNum; i++)
	{
		Matrix[i] = new int[vertexNum];
	}
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			Matrix[i][j] = 0;
		}
	}

	vexNum = vertexNum;
	edgeNum = 0;
}


template <class ElemType>
AdjMatrixDirGraph<ElemType>::~AdjMatrixDirGraph()
{
	delete []elems;

	for (int i = 0; i < vexNum; i++)
	{
		delete []Matrix[i];
	}
	delete []Matrix;
}


template <class ElemType>
StatusCode AdjMatrixDirGraph<ElemType>::addEdge(ElemType e1, ElemType e2)		//����һ���� v1 ָ�� v2 �������
{
	int e1_pos = -1, e2_pos = -1;
	for (int i = 0; i < vexNum; i++)
	{
		if (elems[i] == e1) e1_pos = i;
		if (elems[i] == e2) e2_pos = i;
	}
	if (e1_pos == -1 || e2_pos == -1)
	{
		return ERROR;
	}
	else
	{
		Matrix[e1_pos][e2_pos] = 1;
		edgeNum++;
		return SUCCESS;
	}
}


template <class ElemType>
int AdjMatrixDirGraph<ElemType>::FirstNeighbor(int v)			//�󶥵� v ָ��ĵ�һ���ڽӵ�
{
	for (int i = 0; i < vexNum; i++)
	{
		if (Matrix[v][i] == 1) return i;
	}
	return -1;		//û���ڽӵ㷵��-1
}


template <class ElemType>
int AdjMatrixDirGraph<ElemType>::NextNeighbor(int v, int w)		//�󶥵� v ָ��ĳ����� w �������һ���ڽӵ� 
{
	for (int i = w + 1; i < vexNum; i++)
	{
		if (Matrix[v][i] == 1) return i;
	}
	return -1;		//û���ڽӵ㷵��-1
}


template <class ElemType>
void AdjMatrixDirGraph<ElemType>::TopoSortAll(bool visited[], int indegree[], DbLinkList<char> ans, int &tag)
{
	if (ans.Length() == vexNum)				//�ҵ�һ����������
	{
		if (tag != 1)
		{
			tag = 1;
			cout << "����������������" << endl;
		}
		char ch;
		for (int i = 0; i < vexNum; i++)
		{
			ans.GetElem(i + 1, ch);
			cout << ch << ends;
		}
		cout << endl;
		return ;
	}


	for (int v = 0; v < vexNum; v++)
	{
		if (indegree[v] == 0 && !visited[v])
		{
			for (int w = FirstNeighbor(v); w != -1; w = NextNeighbor(v, w))
			{
				indegree[w]--;
			}

			visited[v] = true;
			ans.Insert(ans.Length(), elems[v]);

			TopoSortAll(visited, indegree, ans, tag);


			//����һ����֧�󣬰���Ȼָ�
			for (int w = FirstNeighbor(v); w != -1; w = NextNeighbor(v, w))
			{
				indegree[w]++;
			}
			visited[v] = false;
			char t;
			ans.Delete(ans.Length(), t);
		}
	}

}


template <class ElemType>
void AdjMatrixDirGraph<ElemType>::FindCircle()				//Ѱ�һ�·
{
	
	int **path = new int* [vexNum];			//·������
	for (int i = 0; i < vexNum; i++)
	{
		path[i] = new int[vexNum];
	}
	for (int i = 0; i < vexNum; i++)
	{
		for (int j = 0; j < vexNum; j++)
		{
			if (Matrix[i][j] == 1) path[i][j] = i;	//��ʼ�� path[][]
			else path[i][j] = -1;				
			
		}
	}

	for (int k = 0; k < vexNum; k++)
	{
		for (int i = 0; i < vexNum; i++)
		{
			for (int j = 0; j < vexNum; j++)
			{
				if (Matrix[i][j] == 0 && Matrix[i][k] == 1 && Matrix[k][j] == 1)
				{
					Matrix[i][j] = 1;				//���ڽӾ���ת��Ϊ�ɴ��Ծ���
					path[i][j] = path[k][j];		//��¼·�������һ���м̽��
				}
			}
		}
	}

	cout << "ͼ�д��ڻ�·��" << endl;
	for (int i = 0; i < vexNum; i++)
	{
		if (Matrix[i][i] == 1)
		{
			cout << elems[i] << " <- ";			//����յ�
			int j = path[i][i];
			while (j != i)
			{
				cout << elems[j] << " <- ";		//��������м̵�
				j = path[i][j];
			}
			cout << elems[i] << endl;			//�����ʼ��
		}
	}
}


template <class ElemType>
StatusCode AdjMatrixDirGraph<ElemType>::TopoSort()			//��������
{
	bool* visited = new bool[vexNum];						//��¼�������Ƿ񱻷���
	int* indegree = new int[vexNum];						//��¼����������	
	for (int i = 0; i < vexNum; i++)						//��ʼ��
	{
		visited[i] = false;
		indegree[i] = 0;	
	}
	for (int j = 0; j < vexNum; j++)						//ͳ�Ƹ���������
	{
		for (int i = 0; i < vexNum; i++)
		{
			if (Matrix[i][j] == 1) indegree[j]++;
		}
	}

	DbLinkList<char> ans;
	int tag = 0;
	TopoSortAll(visited, indegree, ans, tag);		//���������������
	
	delete []visited;
	delete []indegree;

	if (tag != 1)
	{
		FindCircle();								//Ѱ�һ�·
		return ERROR;								//����ʧ�ܣ�����ͼ���л�· 
	}
	else return SUCCESS;							//��������ɹ�
}	





#endif 