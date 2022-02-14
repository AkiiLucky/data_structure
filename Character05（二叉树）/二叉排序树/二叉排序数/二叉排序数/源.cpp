#include <iostream>
#define ElemType int

using namespace std;

typedef struct BSTNode{
	int data;
	struct BSTNode* lchild, * rchild;
}BSTNode, *BSTree;

//�ڶ����������в���ֵΪ key �Ľ��
BSTNode* BST_Search(BSTree T, ElemType key)
{
	while (T != NULL && key != T->data)  //�����ջ���ڸ����ֵ�������ѭ��
	{
		if (key < T->data)               //С�ڣ������������ϲ���
		{
			T = T->lchild;
		}
		else
		{
			T = T->rchild;              //���ڣ������������ϲ���
		}
	}
	return T;
}

//�ڶ������в���ؼ���Ϊ key ���½�㣨�ݹ�ʵ�֣�
bool BST_Insert(BSTree& T, ElemType key)
{
	if (T == NULL)            //ԭ��Ϊ�գ��²���Ľ����Ϊ�����
	{
		T = (BSTree)malloc(sizeof(BSTNode));
		T->data = key;
		T->lchild = T->rchild = NULL;
		return true;
	}
	else if (key == T->data)
	{
		return false;        //���д�����ͬ�ؼ��֣�����ʧ��
	}
	else if (key < T->data)  //���뵽 T ��������
	{
		BST_Insert(T->lchild, key);
	}
	else                    //���뵽 T ��������
	{
		BST_Insert(T->rchild, key);
	}
}

//���� keys[] �еĹؼ������н�������������
void Create_BSTree(BSTree& T, ElemType keys[], int n)
{
	T = NULL;      //��ʼʱ T Ϊ����
	int i = 0;
	while (i < n)  //���ν�ÿ���ؼ��ֲ��뵽������������
	{
		BST_Insert(T, keys[i]);  
		i++;
	}
}

void Print_BSTree(BSTree T) //������������������������������
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
		cout << "���ҳɹ���" << endl;
	}
	else
	{
		cout << "����ʧ�ܣ�" << endl;
	}

	return 0;
}