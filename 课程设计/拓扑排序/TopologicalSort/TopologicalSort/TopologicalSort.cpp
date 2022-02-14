#include <iostream>
#include "AdjMatrixDirGraph.h"
#define MAXVEXNUM 100
using namespace std;

int main()
{
	char os[MAXVEXNUM];
	int len = 0;
	cout << "有向图结点（用逗号隔开，结尾换行）：" << endl;
	char ch = getchar();
	while (ch != '\n')
	{
		if (ch != ',') os[len++] = ch;
		ch = getchar();
	}
	AdjMatrixDirGraph<char> G(os, len);		//根据结点数据初始化图 G

	cout << "拓扑关系（输入 “END” 表示结束）：" << endl;
	char tmpStr[256];
	fgets(tmpStr, sizeof(tmpStr), stdin);
	while (strcmp(tmpStr, "END\n") != 0)	//向图 G 中增加有向边
	{
		if (!G.addEdge(tmpStr[0], tmpStr[2]))
		{
			cout << "输入有误！" << endl;
			exit(1);
		}
		fgets(tmpStr, sizeof(tmpStr), stdin);
	}

	if (!G.TopoSort())
	{
		cout << "拓扑排序失败！" << endl;
	}
	else
	{
		cout << "拓扑排序成功！" << endl;
	}
	
	return 0;
}