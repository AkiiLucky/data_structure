#ifndef __LINK_STACK__
#define __LINK_STACK__

#include <iostream>
#define SUCCESS 1;
#define ERROR 0;
#define OVER_FLOW 0;
#define UNDER_FLOW 0;
typedef bool Status;

using namespace std;

template <class ElemType>
struct Node
{
	ElemType data;
	Node<ElemType>* next;

	Node();
	Node(ElemType item, Node<ElemType>* link = NULL);
};

template <class ElemType>
Node<ElemType>::Node()
{
	next = NULL;
}

template <class ElemType>
Node<ElemType>::Node(ElemType item, Node<ElemType>* link)
{
	data = item;
	next = link;
}

template <class ElemType>
class LinkStack
{
protected:
	Node<ElemType>* top;

public:
	LinkStack();
	virtual ~LinkStack();
	Status Push(const ElemType& e);
	Status Pop(ElemType& e);
	Status Top(ElemType& e) const;

};

template <class ElemType>
LinkStack<ElemType>::LinkStack()
{
	top = NULL;
}

template <class ElemType>
LinkStack<ElemType>::~LinkStack()
{
	ElemType tmpElem;
	while (top != NULL)
	{
		Pop(tmpElem);
	}
}

template <class ElemType>
Status LinkStack<ElemType>::Push(const ElemType& e)
{
	Node<ElemType>* new_top = new Node<ElemType>(e, top);
	if (new_top == NULL)
	{
		return OVER_FLOW; //ÄÚ´æ²»×ã
	}
	else
	{
		top = new_top;
		return SUCCESS;
	}
}

template <class ElemType>
Status LinkStack<ElemType>::Pop(ElemType& e)
{
	if (top == NULL)
	{
		return UNDER_FLOW; //¿ÕÕ»
	}
	else
	{
		e = top->data;
		Node<ElemType>* old_top = top;
		top = old_top->next;
		delete old_top;
		return SUCCESS;
	}

}

template <class ElemType>
Status LinkStack<ElemType>::Top(ElemType& e) const
{
	if (top == NULL)
	{
		return UNDER_FLOW; //¿ÕÕ»
	}
	else
	{
		e = top->data;
		return SUCCESS;
	}
}

#endif 

