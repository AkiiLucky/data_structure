#ifndef _HUFFMAN_TREE_
#define _HUFFMAN_TREE_

#include "String.h"
#include "DbLinkList.h"


/* ������������� */
template<class WeightType>
struct HuffmanTreeNode
{
public:
	WeightType weight;								//Ȩֵ
	unsigned int parent, leftChild, rightChild;		//˫�ף����Һ�����

	HuffmanTreeNode();
	HuffmanTreeNode(WeightType w, int p, int lChild, int rChild);	
};

template<class WeightType>
HuffmanTreeNode<WeightType>::HuffmanTreeNode()
{
	weight = -1;
	parent = -1;
	leftChild = -1;
	rightChild = -1;
}

template<class WeightType>
HuffmanTreeNode<WeightType>::HuffmanTreeNode(WeightType w, int p, int lChild, int rChild)
{
	weight = w;
	parent = p;
	leftChild = lChild;
	rightChild = rChild;
}



/* ���������� */
template<class CharType,class WeightType>
class HuffmanTree
{
protected:
	HuffmanTreeNode<WeightType>* nodes;				//�洢�����Ϣ��nodes[0]δ��
	CharType* LeafChars;							//Ҷ����ַ���Ϣ
	String* LeafCharCodes;							//Ҷ����ַ�������Ϣ
	int curPos;										//����ʱ�Ӹ���㵽Ҷ���·���ĵ�ǰ���
	int num;										//Ҷ������

	void Select(int cur, int& r1, int& r2);			//nodes[1~cur]��ѡ��˫��Ϊ 0��Ȩֵ��С���������

public:
	HuffmanTree(CharType ch[], WeightType w[], int n);		//���ַ���Ȩֵ���ַ����������������
	virtual ~HuffmanTree();
	String EnCode(CharType ch);								//����
	DbLinkList<CharType> DeCode(String strCode);			//����

};


template<class CharType, class WeightType>
void HuffmanTree<CharType, WeightType>::Select(int cur, int& r1, int& r2)
{
	for (int i = 1; i <= cur; i++) {
		if (nodes[i].parent == -1) {		//������Щ��û�й�Ϊһ�����Ľڵ�
			r1 = i;
			break;
		}
	}
	for (int i = 1; i <= cur; i++)			//Ѱ��Ȩֵ��С�Ľ��
	{
		if (nodes[i].parent == -1 && nodes[i].weight < nodes[r1].weight)
		{
			r1 = i;
		}
	}

	for (int i = 1; i <= cur; i++) {
		if (nodes[i].parent == -1 && i != r1) {
			r2 = i;
			break;
		}
	}
	for (int i = 1; i <= cur; i++)			//Ѱ��Ȩֵ�ڶ�С�Ľ��
	{
		if (nodes[i].parent == -1 && nodes[i].weight < nodes[r2].weight && i != r1)
		{
			r2 = i;
		}
	}
}


template<class CharType, class WeightType>
HuffmanTree<CharType, WeightType>::HuffmanTree(CharType ch[], WeightType w[], int n)
{
	num = n;					//Ҷ������
	int m = 2 * n - 1;			//������

	nodes = new HuffmanTreeNode<WeightType>[m + 1]();		//nodes[0]δ��
	LeafChars = new CharType[n + 1];						//CharType[0]δ��
	LeafCharCodes = new String[n + 1];						//String[0]δ��

	int pos;
	for (pos = 1; pos <= n; pos++)							//�洢Ҷ�����Ϣ
	{
		nodes[pos].weight = w[pos - 1];						//Ȩֵ
		LeafChars[pos] = ch[pos - 1];						//�ַ�
	}

	for (pos = n + 1; pos <= m; pos++)						//������������
	{
		int r1, r2;
		Select(pos - 1, r1, r2);

		
		nodes[r1].parent = nodes[r2].parent = pos;			//r1,r2 ��˫��Ϊ pos
		nodes[pos].leftChild = r1;							//r1 Ϊ pos ������
		nodes[pos].rightChild = r2;							//r2 Ϊ pos ���Һ���
		nodes[pos].weight = nodes[r1].weight + nodes[r2].weight;	//pos��ȨΪ r1,r2 ��Ȩֵ֮��
	}

	for (pos = 1; pos <= n; pos++)											//�� n ��Ҷ����ַ��ı���
	{
		DbLinkList<char> charCode;											//�ݴ�Ҷ�����Ϣ
		for (unsigned int child = pos, parent = nodes[child].parent; parent != -1; child = parent, parent = nodes[child].parent)
		{
			char t_0 = '0', t_1 = '1';
			if (nodes[parent].leftChild == child) charCode.Insert(0, t_0);	//���֧����Ϊ '0'
			else charCode.Insert(0, t_1);									//�ҷ�֧����Ϊ '1'
		}

		char chTmp;
		char* strTmp = new char[charCode.Length()+1];
		for (int j = 1; j <= charCode.Length(); j++)
		{
			charCode.GetElem(j, chTmp);
			strTmp[j-1] = chTmp;
		}
		strTmp[charCode.Length()] = '\0';
		LeafCharCodes[pos] = String(strTmp);		//���ַ����뱣��
		delete strTmp;
		strTmp = NULL;
	}

	curPos = m;			//����ʱ�Ӹ���㿪ʼ��m Ϊ��
}


template<class CharType, class WeightType>
HuffmanTree<CharType, WeightType>::~HuffmanTree()
{
	delete []nodes;
	nodes = NULL;
	delete []LeafChars;
	LeafChars = NULL;
	delete []LeafCharCodes;
	LeafCharCodes = NULL;
}


template<class CharType, class WeightType>
String HuffmanTree<CharType, WeightType>::EnCode(CharType ch)
{
	int pos;
	for (pos = 1; pos <= num; pos++)
	{
		if (LeafChars[pos] == ch) break;	//�ҵ��ַ����˳�ѭ��
	}
	if (pos <= num)
	{
		return LeafCharCodes[pos];			//�õ�����
	}
	else
	{
		cerr << "�Ƿ��ַ����޷����룡" << endl;
		exit(1);
	}
}

template<class CharType, class WeightType>
DbLinkList<CharType> HuffmanTree<CharType, WeightType>::DeCode(String strCode)
{
	DbLinkList<CharType> charList;		///����ǰ���ַ��ֶ�
	curPos = 511;
	for (int pos = 0; pos < strCode.Length(); pos++)
	{
		if (strCode.CStr()[pos] == '0') curPos = nodes[curPos].leftChild;	//'0'�����֧
		else curPos = nodes[curPos].rightChild;								//'1'���ҷ�֧

		if (nodes[curPos].leftChild == -1 && nodes[curPos].rightChild == -1)
		{
			charList.Insert(charList.Length(), LeafChars[curPos]);
			curPos = 2 * num - 1;
		}
	}
	return charList;				//���ر���ǰ���ַ�����
}

#endif 


