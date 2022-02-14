#include <iostream>
#include "BinaryTree.h"
#include "LinkStack.h"

using namespace std;

template <class ElemType>
void DisplayBTWithTreeShape(BinTreeNode<ElemType>* bt, int n);

/* 表达式的二叉树表示类 */
class FigureExprByBiTree
{
//辅助函数
	static bool IsOperator(char ch);			//判断 ch 是否为运算符
	static int leftPri(char op);				//获取左边运算符的优先级
	static int RightPri(char op);				//获取右边运算符的优先级

public:
	FigureExprByBiTree() {};					
	virtual ~FigureExprByBiTree() {};
	static void Run();							//将从键盘输入的中缀表达式用二叉树表示
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
	LinkStack<BinTreeNode<char>*> biTr;			//二叉树栈
	LinkStack<char> optr;						//操作符栈
	char ch, optrTop, theta;					//输入的字符 ch, 操作符栈栈顶操作符 optrTop, 操作符 theta
	BinTreeNode<char>* r = NULL;				//指向二叉树结构的指针
	optr.Push('=');								//向栈中压入一个操作符 '='
	optr.Top(optrTop);							//获取操作符栈的栈顶操作符
	ch = getchar();								//从输入流获取一个字符
	while (optrTop != '=' || ch !=  '=')
	{
		if (!IsOperator(ch))
		{
			r = new BinTreeNode<char> (ch);		//生成只含一个结点的二叉树
			biTr.Push(r);						//r 进 biTr 栈
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
					cerr << "表达式有错！" << endl; 		//异常处理
					break;
				}
				if (biTr.Pop(leftr) == 0)
				{
					cerr << "表达式有错！" << endl;			//异常处理
					break;
				}
				optr.Pop(theta);										//从 optr 弹出一个操作符
				r = new BinTreeNode<char>(theta, leftr, rightr);		//生成新二叉树
				biTr.Push(r);											//把 r 压入操作数栈
			}
			else if (leftPri(optrTop) == RightPri(ch) && ch == ')')
			{
				optr.Pop(ch);								//从操作符栈退出栈顶的 '('
				ch = getchar();
			}
		}
		optr.Top(optrTop);
	}
	biTr.Pop(r);								//r 为生成的二叉树的根
	BinaryTree<char> bt(r);						//生成二叉树
	DisplayBTWithTreeShape(bt.GetRoot(), 0);	//显示二叉树

}

int main()
{
	char ch;
	do
	{
		cout << "输入表达式 : " ;
		FigureExprByBiTree::Run();
		cout << "是否继续? y/n : ";
		cin >> ch;
		if (ch != 'y' && ch != 'n')
		{
			do
			{
				cout << "请用 y 或 n 回答 : ";
				cin >> ch;
			}while (ch != 'y' && ch != 'n');
		}
	} while (ch != 'n');
	return 0;
}