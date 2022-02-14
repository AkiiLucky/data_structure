#ifndef __BINARY_TREE__
#define __BINARY_TREE__

#include <iostream>


using namespace std;

/* 二叉树结点 */
template <class ElemType>
struct BinTreeNode
{
	ElemType data;								//数据域
	BinTreeNode<ElemType>* leftChild;			//左孩子指针
	BinTreeNode<ElemType>* rightChild;			//右孩子指针

	BinTreeNode();
	BinTreeNode(const ElemType& val, BinTreeNode<ElemType>* leftChild = NULL, BinTreeNode<ElemType>* rightChild = NULL);
};

template <class ElemType>
BinTreeNode<ElemType>::BinTreeNode()
{
	leftChild = rightChild = NULL;				//初始化左右孩子指针为空
}

template <class ElemType>
BinTreeNode<ElemType>::BinTreeNode(const ElemType& val, BinTreeNode<ElemType>* leftChild, BinTreeNode<ElemType>* rightChild)
{
	data = val;
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}



/* 二叉树类 */
template <class ElemType>
class BinaryTree
{
protected:
	BinTreeNode<ElemType>* root;

	//辅助函数
	void DestroyHelp(BinTreeNode<ElemType>*& r);									//销毁以 r 为根的二叉树
	void PreOrderHelp(BinTreeNode<ElemType>* r, void (*Visit)(ElemType* r));		//先序遍历	

public:
	BinaryTree();
	BinaryTree(BinTreeNode<ElemType>* r);
	virtual ~BinaryTree();
	BinTreeNode<ElemType>* GetRoot() const;											//返回二叉树的根
	void PreOrder(void (*Visit)(ElemType* r));										//从根节点开始进行先序遍历										
	void InsertLeftChild(BinTreeNode<ElemType>* cur, const ElemType& e);			//插入左孩子
	void InsertRightChild(BinTreeNode<ElemType>* cur, const ElemType& e);			//插入右孩子


};


template <class ElemType>
void BinaryTree<ElemType>::DestroyHelp(BinTreeNode<ElemType>*& r)
{
	if (r != NULL)
	{
		DestroyHelp(r->leftChild);
		DestroyHelp(r->rightChild);
		delete r;
		r = NULL;
	}
}

template <class ElemType>
void BinaryTree<ElemType>::PreOrderHelp(BinTreeNode<ElemType>* r, void (*Visit)(ElemType* r))
{
	if (r != NULL)
	{
		(*Visit)(r->data);
		PreOrderHelp(r->leftChild);
		PreOrderHelp(r->rightChild);
	}
}


template <class ElemType>
BinaryTree<ElemType>::BinaryTree()
{
	root = NULL;
}

template <class ElemType>
BinaryTree<ElemType>::BinaryTree(BinTreeNode<ElemType>* r)
{
	root = r;
}

template <class ElemType>
BinaryTree<ElemType>::~BinaryTree()
{
	DestroyHelp(root);
}

template <class ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::GetRoot() const
{
	return root;
}

template <class ElemType>
void BinaryTree<ElemType>::PreOrder(void (*Visit)(ElemType* r))
{
	PreOrderHelp(root, Visit);
}




template <class ElemType>
void DisplayBTWithTreeShape(BinTreeNode<ElemType>* bt, int n)
{
	int t = n;
	if (bt != NULL)
	{
		DisplayBTWithTreeShape(bt->rightChild, n+1);
		while (t--) cout << "   ";
		cout << bt->data << endl;
		DisplayBTWithTreeShape(bt->leftChild, n+1);
	}
}



template <class ElemType>
void ExchangeChild(BinTreeNode<ElemType>* root)			//交换二叉树每个结点的左右孩子
{
	BinTreeNode<ElemType>* tmp = NULL;
	if (root != NULL)
	{
		tmp = root->leftChild;							//交换左右孩子指针
		root->leftChild = root->rightChild;
		root->rightChild = tmp;

		ExchangeChild(root->leftChild);					//交换左子树根节点的左右孩子
		ExchangeChild(root->rightChild);				//交换右子树根节点的左右孩子
	}
}


#endif 
