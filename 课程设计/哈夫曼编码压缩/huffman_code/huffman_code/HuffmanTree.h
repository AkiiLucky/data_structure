#ifndef _HUFFMAN_TREE_
#define _HUFFMAN_TREE_

#include "String.h"
#include "DbLinkList.h"


/* 哈夫曼树结点类 */
template<class WeightType>
struct HuffmanTreeNode
{
public:
	WeightType weight;								//权值
	unsigned int parent, leftChild, rightChild;		//双亲，左右孩子域

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



/* 哈夫曼树类 */
template<class CharType,class WeightType>
class HuffmanTree
{
protected:
	HuffmanTreeNode<WeightType>* nodes;				//存储结点信息，nodes[0]未用
	CharType* LeafChars;							//叶结点字符信息
	String* LeafCharCodes;							//叶结点字符编码信息
	int curPos;										//译码时从根结点到叶结点路径的当前结点
	int num;										//叶结点个数

	void Select(int cur, int& r1, int& r2);			//nodes[1~cur]中选择双亲为 0，权值最小的两个结点

public:
	HuffmanTree(CharType ch[], WeightType w[], int n);		//由字符，权值和字符个数构造哈夫曼树
	virtual ~HuffmanTree();
	String EnCode(CharType ch);								//编码
	DbLinkList<CharType> DeCode(String strCode);			//译码

};


template<class CharType, class WeightType>
void HuffmanTree<CharType, WeightType>::Select(int cur, int& r1, int& r2)
{
	for (int i = 1; i <= cur; i++) {
		if (nodes[i].parent == -1) {		//先找那些还没有归为一颗树的节点
			r1 = i;
			break;
		}
	}
	for (int i = 1; i <= cur; i++)			//寻找权值最小的结点
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
	for (int i = 1; i <= cur; i++)			//寻找权值第二小的结点
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
	num = n;					//叶结点个数
	int m = 2 * n - 1;			//结点个数

	nodes = new HuffmanTreeNode<WeightType>[m + 1]();		//nodes[0]未用
	LeafChars = new CharType[n + 1];						//CharType[0]未用
	LeafCharCodes = new String[n + 1];						//String[0]未用

	int pos;
	for (pos = 1; pos <= n; pos++)							//存储叶结点信息
	{
		nodes[pos].weight = w[pos - 1];						//权值
		LeafChars[pos] = ch[pos - 1];						//字符
	}

	for (pos = n + 1; pos <= m; pos++)						//构建哈夫曼树
	{
		int r1, r2;
		Select(pos - 1, r1, r2);

		
		nodes[r1].parent = nodes[r2].parent = pos;			//r1,r2 的双亲为 pos
		nodes[pos].leftChild = r1;							//r1 为 pos 的左孩子
		nodes[pos].rightChild = r2;							//r2 为 pos 的右孩子
		nodes[pos].weight = nodes[r1].weight + nodes[r2].weight;	//pos的权为 r1,r2 的权值之和
	}

	for (pos = 1; pos <= n; pos++)											//求 n 个叶结点字符的编码
	{
		DbLinkList<char> charCode;											//暂存叶结点信息
		for (unsigned int child = pos, parent = nodes[child].parent; parent != -1; child = parent, parent = nodes[child].parent)
		{
			char t_0 = '0', t_1 = '1';
			if (nodes[parent].leftChild == child) charCode.Insert(0, t_0);	//左分支编码为 '0'
			else charCode.Insert(0, t_1);									//右分支编码为 '1'
		}

		char chTmp;
		char* strTmp = new char[charCode.Length()+1];
		for (int j = 1; j <= charCode.Length(); j++)
		{
			charCode.GetElem(j, chTmp);
			strTmp[j-1] = chTmp;
		}
		strTmp[charCode.Length()] = '\0';
		LeafCharCodes[pos] = String(strTmp);		//将字符编码保存
		delete strTmp;
		strTmp = NULL;
	}

	curPos = m;			//译码时从根结点开始，m 为根
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
		if (LeafChars[pos] == ch) break;	//找到字符，退出循环
	}
	if (pos <= num)
	{
		return LeafCharCodes[pos];			//得到编码
	}
	else
	{
		cerr << "非法字符，无法编码！" << endl;
		exit(1);
	}
}

template<class CharType, class WeightType>
DbLinkList<CharType> HuffmanTree<CharType, WeightType>::DeCode(String strCode)
{
	DbLinkList<CharType> charList;		///编码前的字符字段
	curPos = 511;
	for (int pos = 0; pos < strCode.Length(); pos++)
	{
		if (strCode.CStr()[pos] == '0') curPos = nodes[curPos].leftChild;	//'0'是左分支
		else curPos = nodes[curPos].rightChild;								//'1'是右分支

		if (nodes[curPos].leftChild == -1 && nodes[curPos].rightChild == -1)
		{
			charList.Insert(charList.Length(), LeafChars[curPos]);
			curPos = 2 * num - 1;
		}
	}
	return charList;				//返回编码前的字符序列
}

#endif 


