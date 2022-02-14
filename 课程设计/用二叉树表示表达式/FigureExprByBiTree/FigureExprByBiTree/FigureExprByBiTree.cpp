#include <iostream>
#include "BinaryTree.h"
#include "LinkStack.h"

using namespace std;

template <class ElemType>
void DisplayBTWithTreeShape(BinTreeNode<ElemType>* bt, int n);

/* ���ʽ�Ķ�������ʾ�� */
class FigureExprByBiTree
{
//��������
	static bool IsOperator(char ch);			//�ж� ch �Ƿ�Ϊ�����
	static int leftPri(char op);				//��ȡ�������������ȼ�
	static int RightPri(char op);				//��ȡ�ұ�����������ȼ�

public:
	FigureExprByBiTree() {};					
	virtual ~FigureExprByBiTree() {};
	static void Run();							//���Ӽ����������׺���ʽ�ö�������ʾ
};


bool FigureExprByBiTree::IsOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == '=')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int FigureExprByBiTree::leftPri(char op)
{
	int result;					
	if (op == '=') result = 0;
	else if (op == '(') result = 1;
	else if (op == '*' || op == '/') result = 5;
	else if (op == '+' || op == '-') result = 3;
	else if (op == ')') result = 6;
	return result;
}

int FigureExprByBiTree::RightPri(char op)
{
	int result;
	if (op == '=') result = 0;
	else if (op == '(') result = 6;
	else if (op == '*' || op == '/') result = 4;
	else if (op == '+' || op == '-') result = 2;
	else if (op == ')') result = 1;
	return result;
}


void FigureExprByBiTree::Run()
{
	LinkStack<BinTreeNode<char>*> biTr;			//������ջ
	LinkStack<char> optr;						//������ջ
	char ch, optrTop, theta;					//������ַ� ch, ������ջջ�������� optrTop, ������ theta
	BinTreeNode<char>* r = NULL;				//ָ��������ṹ��ָ��
	optr.Push('=');								//��ջ��ѹ��һ�������� '='
	optr.Top(optrTop);							//��ȡ������ջ��ջ��������
	ch = getchar();								//����������ȡһ���ַ�
	while (optrTop != '=' || ch !=  '=')
	{
		if (!IsOperator(ch))
		{
			r = new BinTreeNode<char> (ch);		//����ֻ��һ�����Ķ�����
			biTr.Push(r);						//r �� biTr ջ
			ch = getchar();
		}
		else
		{
			if (leftPri(optrTop) < RightPri(ch))
			{
				optr.Push(ch);
				ch = getchar();
			}
			else if (leftPri(optrTop) > RightPri(ch))
			{
				BinTreeNode<char>* leftr, * rightr;
				if (biTr.Pop(rightr) == 0)
				{
					cerr << "���ʽ�д�" << endl; 		//�쳣����
					break;
				}
				if (biTr.Pop(leftr) == 0)
				{
					cerr << "���ʽ�д�" << endl;			//�쳣����
					break;
				}
				optr.Pop(theta);										//�� optr ����һ��������
				r = new BinTreeNode<char>(theta, leftr, rightr);		//�����¶�����
				biTr.Push(r);											//�� r ѹ�������ջ
			}
			else if (leftPri(optrTop) == RightPri(ch) && ch == ')')
			{
				optr.Pop(ch);								//�Ӳ�����ջ�˳�ջ���� '('
				ch = getchar();
			}
		}
		optr.Top(optrTop);
	}
	biTr.Pop(r);								//r Ϊ���ɵĶ������ĸ�
	BinaryTree<char> bt(r);						//���ɶ�����
	DisplayBTWithTreeShape(bt.GetRoot(), 0);	//��ʾ������

}

int main()
{
	char ch;
	do
	{
		cout << "������ʽ : " ;
		FigureExprByBiTree::Run();
		cout << "�Ƿ����? y/n : ";
		cin >> ch;
		if (ch != 'y' && ch != 'n')
		{
			do
			{
				cout << "���� y �� n �ش� : ";
				cin >> ch;
			}while (ch != 'y' && ch != 'n');
		}
	} while (ch != 'n');
	return 0;
}