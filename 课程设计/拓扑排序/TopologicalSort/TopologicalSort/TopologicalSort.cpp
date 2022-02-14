#include <iostream>
#include "AdjMatrixDirGraph.h"
#define MAXVEXNUM 100
using namespace std;

int main()
{
	char os[MAXVEXNUM];
	int len = 0;
	cout << "����ͼ��㣨�ö��Ÿ�������β���У���" << endl;
	char ch = getchar();
	while (ch != '\n')
	{
		if (ch != ',') os[len++] = ch;
		ch = getchar();
	}
	AdjMatrixDirGraph<char> G(os, len);		//���ݽ�����ݳ�ʼ��ͼ G

	cout << "���˹�ϵ������ ��END�� ��ʾ��������" << endl;
	char tmpStr[256];
	fgets(tmpStr, sizeof(tmpStr), stdin);
	while (strcmp(tmpStr, "END\n") != 0)	//��ͼ G �����������
	{
		if (!G.addEdge(tmpStr[0], tmpStr[2]))
		{
			cout << "��������" << endl;
			exit(1);
		}
		fgets(tmpStr, sizeof(tmpStr), stdin);
	}

	if (!G.TopoSort())
	{
		cout << "��������ʧ�ܣ�" << endl;
	}
	else
	{
		cout << "��������ɹ���" << endl;
	}
	
	return 0;
}