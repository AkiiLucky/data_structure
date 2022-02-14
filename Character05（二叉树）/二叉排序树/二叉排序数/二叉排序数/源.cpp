#include <iostream>
#define ElemType int

using namespace std;

typedef struct BSTNode{
	int data;
	struct BSTNode* lchild, * rchild;
}BSTNode, *BSTree;

//在二叉排序树中查找值为 key 的结点
BSTNode* BST_Search(BSTree T, ElemType key)
{
	while (T != NULL && key != T->data)  //若数空或等于根结点值，则结束循环
	{
		if (key < T->data)               //小于，则在左子树上查找
		{
			T = T->lchild;
		}
		else
		{
			T = T->rchild;              //大于，则在右子树上查找
		}
	}
	return T;
}

//在二叉树中插入关键字为 key 的新结点（递归实现）
bool BST_Insert(BSTree& T, ElemType key)
{
	if (T == NULL)            //原树为空，新插入的结点作为根结点
	{
		T = (BSTree)malloc(sizeof(BSTNode));
		T->data = key;
		T->lchild = T->rchild = NULL;
		return true;
	}
	else if (key == T->data)
	{
		return false;        //树中存在相同关键字，插入失败
	}
	else if (key < T->data)  //插入到 T 的左子树
	{
		BST_Insert(T->lchild, key);
	}
	else                    //插入到 T 的右子树
	{
		BST_Insert(T->rchild, key);
	}
}

//按照 keys[] 中的关键字序列建立二叉排序树
void Create_BSTree(BSTree& T, ElemType keys[], int n)
{
	T = NULL;      //初始时 T 为空树
	int i = 0;
	while (i < n)  //依次将每个关键字插入到二叉排序树中
	{
		BST_Insert(T, keys[i]);  
		i++;
	}
}

void Print_BSTree(BSTree T) //二叉排序树的中序遍历是有序递增的
{
	if (T != NULL)
	{
		Print_BSTree(T->lchild);
		cout << T->data << ends;
		Print_BSTree(T->rchild);
	}
}

int main()
{
	BSTree T;
	int keys[10] = { 50, 36, 70, 23, 66, 55, 14, 12, 42, 10 };
	Create_BSTree(T, keys, 10); 
	Print_BSTree(T); //10 12 14 23 36 42 50 55 66 70  
	cout << endl;
	if (BST_Search(T, 10)->data == 10)
	{
		cout << "查找成功！" << endl;
	}
	else
	{
		cout << "查找失败！" << endl;
	}

	return 0;
}