#ifndef __BINARY_TREE__
#define __BINARY_TREE__

#include <iostream>


using namespace std;

/* ��������� */
template <class ElemType>
struct BinTreeNode
{
	ElemType data;								//������
	BinTreeNode<ElemType>* leftChild;			//����ָ��
	BinTreeNode<ElemType>* rightChild;			//�Һ���ָ��

	BinTreeNode();
	BinTreeNode(const ElemType& val, BinTreeNode<ElemType>* leftChild = NULL, BinTreeNode<ElemType>* rightChild = NULL);
};

template <class ElemType>
BinTreeNode<ElemType>::BinTreeNode()
{
	leftChild = rightChild = NULL;				//��ʼ�����Һ���ָ��Ϊ��
}

template <class ElemType>
BinTreeNode<ElemType>::BinTreeNode(const ElemType& val, BinTreeNode<ElemType>* leftChild, BinTreeNode<ElemType>* rightChild)
{
	data = val;
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}



/* �������� */
template <class ElemType>
class BinaryTree
{
protected:
	BinTreeNode<ElemType>* root;

	//��������
	void DestroyHelp(BinTreeNode<ElemType>*& r);									//������ r Ϊ���Ķ�����
	void PreOrderHelp(BinTreeNode<ElemType>* r, void (*Visit)(ElemType* r));		//�������	

public:
	BinaryTree();
	BinaryTree(BinTreeNode<ElemType>* r);
	virtual ~BinaryTree();
	BinTreeNode<ElemType>* GetRoot() const;											//���ض������ĸ�
	void PreOrder(void (*Visit)(ElemType* r));										//�Ӹ��ڵ㿪ʼ�����������										
	void InsertLeftChild(BinTreeNode<ElemType>* cur, const ElemType& e);			//��������
	void InsertRightChild(BinTreeNode<ElemType>* cur, const ElemType& e);			//�����Һ���


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
void ExchangeChild(BinTreeNode<ElemType>* root)			//����������ÿ���������Һ���
{
	BinTreeNode<ElemType>* tmp = NULL;
	if (root != NULL)
	{
		tmp = root->leftChild;							//�������Һ���ָ��
		root->leftChild = root->rightChild;
		root->rightChild = tmp;

		ExchangeChild(root->leftChild);					//�������������ڵ�����Һ���
		ExchangeChild(root->rightChild);				//�������������ڵ�����Һ���
	}
}


#endif 
