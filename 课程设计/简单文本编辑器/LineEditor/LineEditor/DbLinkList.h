#ifndef _DBLINKLIST_H__
#define _DBLINKLIST_H__



#include <iostream>

#define StatusCode bool
#define OK 1
#define ERROR 0
#define RANGE_ERROR 0





template<class ElemType>
struct DblNode
{
	//���ݳ�Ա
	ElemType data;
	DblNode<ElemType>* back;  //ָ��ǰ����ָ��
	DblNode<ElemType>* next;  //ָ���̵�ָ��

//���캯��ģ��
	DblNode();
	DblNode(ElemType item, DblNode<ElemType>* linkback, DblNode<ElemType>* linknext); //��֪�������ָ���򹹽��ṹ
};

template<class ElemType>
DblNode<ElemType>::DblNode()
{
	next = NULL;
	back = NULL;
}

template<class ElemType>
DblNode<ElemType>::DblNode(ElemType item, DblNode<ElemType>* linkback, DblNode<ElemType>* linknext)
{
	data = item;
	back = linkback;
	next = linknext;
}







template<class ElemType>
class DbLinkList  //����˫��ѭ��������
{
protected:
	DblNode<ElemType>* head;   //ͷ���ָ��

//��������
	DblNode<ElemType>* GetElemPtr(int i) const; //����ָ��� i ������ָ��

public:
	DbLinkList();
	virtual ~DbLinkList();
	int Length() const;
	bool Empty() const;
	void Clear();
	StatusCode GetElem(int i, ElemType& e) const;
	StatusCode SetElem(int i, const ElemType& e);
	StatusCode Delete(int i, ElemType& e);
	StatusCode Insert(int i, ElemType &e);
};


template<class ElemType>
DblNode<ElemType>* DbLinkList<ElemType>::GetElemPtr(int i) const
{
	if (i == 0)
	{
		return head;
	}
	DblNode<ElemType>* tmp = head->next;
	int curPosition = 1;   //tmp��ָ����λ��
	while (tmp->next != head && curPosition < i)
	{
		tmp = tmp->next;
		curPosition++;
	}
	if (curPosition == i)
	{
		return tmp;
	}
	else
	{
		return NULL;
	}
}

template<class ElemType>
DbLinkList<ElemType>::DbLinkList()
{
	head = new DblNode<ElemType>;
	head->back = head->next = head;
}

template<class ElemType>
DbLinkList<ElemType>::~DbLinkList()
{
	Clear();
	delete head;
}

template<class ElemType>
int DbLinkList<ElemType>::Length() const
{
	int count = 0;
	DblNode<ElemType>* tmp = head->next;
	while (tmp != head)
	{
		count++;
		tmp = tmp->next;
	}
	return count;
}

template<class ElemType>
bool DbLinkList<ElemType>::Empty() const
{
	return head->next == head;
}

template<class ElemType>
void DbLinkList<ElemType>::Clear()
{
	DblNode<ElemType>* p = head->next;
	DblNode<ElemType>* q = head->next;
	while (p != head)
	{
		q = p->next;
		delete p;
		p = q;
	}
	head->back = head->next = head;
}

template<class ElemType>
StatusCode DbLinkList<ElemType>::GetElem(int i, ElemType& e) const
{
	if (i > Length() || i < 1)
	{
		return RANGE_ERROR;
	}
	else
	{
		DblNode<ElemType>* p = GetElemPtr(i);
		e = p->data;
		return OK;
	}
}


template<class ElemType>
StatusCode DbLinkList<ElemType>::SetElem(int i, const ElemType &e)
{
	if (i > Length() || i < 1)
	{
		return RANGE_ERROR;
	}
	else
	{
		DblNode<ElemType>* p = GetElemPtr(i);
		p->data = e;
		return OK;
	}
}

template<class ElemType>
StatusCode DbLinkList<ElemType>::Delete(int i, ElemType& e)
{
	if (i > Length() || i < 1)
	{
		return RANGE_ERROR;
	}
	else
	{
		DblNode<ElemType>* p = GetElemPtr(i);
		e = p->data;
		p->back->next = p->next;
		p->next->back = p->back;
		delete p;
		return OK;
	}
}

template<class ElemType>
StatusCode DbLinkList<ElemType>::Insert(int i, ElemType &e)  //�� i �����λ�ú������һ��ֵΪ e �Ľ��
{
	if ((i > Length()) || i < 0)
	{
		return RANGE_ERROR;
	}
	else
	{
		DblNode<ElemType>* p = GetElemPtr(i);
		DblNode<ElemType>* q = new DblNode<ElemType>;
		q->data = e;
		q->next = p->next;
		q->back = p;
		p->next->back = q;
		p->next = q;
		return OK;
	}
}


#endif