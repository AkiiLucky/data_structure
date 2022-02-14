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
	int vexNum, edgeNum;				//顶点个数和边数
	int** Matrix;						//邻接矩阵
	ElemType* elems;					//顶点元素

public:
	AdjMatrixDirGraph(ElemType os[], int vertexNum);
	~AdjMatrixDirGraph();
	StatusCode addEdge(ElemType e1, ElemType e2);		//增加一条从 elem1 指向 elem2 的有向边
	int FirstNeighbor(int v);							//求顶点 v 的第一个邻接点
	int NextNeighbor(int v, int w);						//求顶点 v 的除顶点 w 以外的下一个邻接点 
	void TopoSortAll(bool visited[], int indegree[], DbLinkList<char> ans, int &tag);
	void FindCircle();									//寻找回路
	StatusCode TopoSort();								//拓扑排序
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
StatusCode AdjMatrixDirGraph<ElemType>::addEdge(ElemType e1, ElemType e2)		//增加一条从 v1 指向 v2 的有向边
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
int AdjMatrixDirGraph<ElemType>::FirstNeighbor(int v)			//求顶点 v 指向的第一个邻接点
{
	for (int i = 0; i < vexNum; i++)
	{
		if (Matrix[v][i] == 1) return i;
	}
	return -1;		//没有邻接点返回-1
}


template <class ElemType>
int AdjMatrixDirGraph<ElemType>::NextNeighbor(int v, int w)		//求顶点 v 指向的除顶点 w 以外的下一个邻接点 
{
	for (int i = w + 1; i < vexNum; i++)
	{
		if (Matrix[v][i] == 1) return i;
	}
	return -1;		//没有邻接点返回-1
}


template <class ElemType>
void AdjMatrixDirGraph<ElemType>::TopoSortAll(bool visited[], int indegree[], DbLinkList<char> ans, int &tag)
{
	if (ans.Length() == vexNum)				//找到一种拓扑序列
	{
		if (tag != 1)
		{
			tag = 1;
			cout << "所有拓扑排序结果：" << endl;
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


			//访问一条分支后，把入度恢复
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
void AdjMatrixDirGraph<ElemType>::FindCircle()				//寻找回路
{
	
	int **path = new int* [vexNum];			//路径矩阵
	for (int i = 0; i < vexNum; i++)
	{
		path[i] = new int[vexNum];
	}
	for (int i = 0; i < vexNum; i++)
	{
		for (int j = 0; j < vexNum; j++)
		{
			if (Matrix[i][j] == 1) path[i][j] = i;	//初始化 path[][]
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
					Matrix[i][j] = 1;				//将邻接矩阵转换为可达性矩阵
					path[i][j] = path[k][j];		//记录路径上最后一个中继结点
				}
			}
		}
	}

	cout << "图中存在回路：" << endl;
	for (int i = 0; i < vexNum; i++)
	{
		if (Matrix[i][i] == 1)
		{
			cout << elems[i] << " <- ";			//输出终点
			int j = path[i][i];
			while (j != i)
			{
				cout << elems[j] << " <- ";		//反向输出中继点
				j = path[i][j];
			}
			cout << elems[i] << endl;			//输出起始点
		}
	}
}


template <class ElemType>
StatusCode AdjMatrixDirGraph<ElemType>::TopoSort()			//拓扑排序
{
	bool* visited = new bool[vexNum];						//记录各顶点是否被访问
	int* indegree = new int[vexNum];						//记录各顶点的入度	
	for (int i = 0; i < vexNum; i++)						//初始化
	{
		visited[i] = false;
		indegree[i] = 0;	
	}
	for (int j = 0; j < vexNum; j++)						//统计各顶点的入度
	{
		for (int i = 0; i < vexNum; i++)
		{
			if (Matrix[i][j] == 1) indegree[j]++;
		}
	}

	DbLinkList<char> ans;
	int tag = 0;
	TopoSortAll(visited, indegree, ans, tag);		//输出多组拓扑序列
	
	delete []visited;
	delete []indegree;

	if (tag != 1)
	{
		FindCircle();								//寻找回路
		return ERROR;								//排序失败，有向图中有回路 
	}
	else return SUCCESS;							//拓扑排序成功
}	





#endif 