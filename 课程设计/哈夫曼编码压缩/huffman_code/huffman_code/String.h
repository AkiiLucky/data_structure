#ifndef _STRING_H__
#define _STRING_H__

#include <iostream>
#include <cstring>
#include "DbLinkList.h"

using namespace std;

class String
{
protected:
    mutable char* strVal;      //�ɱ����͵Ĵ�ֵ
    int length;                //����
public:
    String(const char* str = "\0");
    virtual ~String();
    const char* CStr() const;                                       //����ת���� C ���
    int Length();                                                   //�󴮳�
    bool Read(istream& input);                                      //�����������봮
    String& operator=(const String& copy);                          //���ظ�ֵ�����


    friend void Concat(String& addTo, const String& addOn);         //���� addOn ������ addTo ����
    friend void Copy(String& copy, const String& original, int n);  //���� original ���� n ���ַ������� copy
    friend int SimpleIndex(String& S, String& T, int pos);          //��ģʽƥ��
    friend int FrontRearIndex(String& T, String& P, int pos);       //ǰ��ģʽƥ��
};


String::String(const char* str)
{
    length = strlen(str);
    strVal = new char[length + 1];
    strcpy_s(strVal, length + 1, str);
    strVal[length] = '\0';
}

String::~String()
{
    //delete[]strVal;
    strVal = NULL;
}

const char* String::CStr() const
{
    return (const char*)strVal;
}

int String::Length()
{
    return length;
}

bool String::Read(istream& input)          //����������ȡһ���ַ���
{
    DbLinkList<char> tmp;                  //����һ����ʱ����洢ÿ���ַ�
    char c;
    for (int i = 0; (c = input.get()) != '\n'; i++)
    {
        if (c == EOF) return false;
        tmp.Insert(i, c);
    }

    delete[]strVal;                       //��ԭ�����������
    length = 0;
    strVal = new char[tmp.Length() + 1];  //�����µĿռ�
    for (int i = 1; i <= tmp.Length(); i++)
    {
        tmp.GetElem(i, strVal[i - 1]);
        length++;
    }
    strVal[length] = '\0';
    return true;
}

String& String::operator=(const String& copy)
{
    if (&copy != this)
    {
        //delete[]strVal;
        length = copy.length;
        strVal = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            strVal[i] = copy.strVal[i];
        }
        strVal[length] = '\0';
    }
    return *this;
}

void Concat(String& addTo, const String& addOn)         //���� addOn ������ addTo ����
{
    const char* cFirst = addTo.CStr();                  //ָ���һ����
    const char* cSecond = addOn.CStr();                 //ָ��ڶ�����
    char* copy = new char[strlen(cFirst) + strlen(cSecond) + 1]; //����ռ�
    strcpy_s(copy, strlen(cFirst) + 1, cFirst);         //���Ƶ�һ����
    strcat_s(copy, strlen(copy) + strlen(cSecond) + 1, cSecond); //���ӵڶ�����
    String tmp(copy);                                   //�� C ���Ĵ�ת��Ϊ String ����
    addTo = tmp;                                        //��ֵ
    delete[]copy;                                      //�ͷ� copy
}

void Copy(String& copy, const String& original, int n)  //����original���� n ���ַ�����copy
{
    const char* cFirst = copy.CStr();                   //ָ���һ����
    const char* cSecond = original.CStr();              //ָ��ڶ�����
    char* tmp = new char[n + 1];                        //����ռ�
    tmp[0] = '\0';
    for (int i = 0; i < n; i++)
    {
        tmp[i] = cSecond[i];                            //���� n ���ַ�
    }
    tmp[n] = '\0';                                      //ĩβ�� '\0'
    String tmp_s(tmp);                                  //�� C ���Ĵ�ת��Ϊ String ����
    copy = tmp_s;                                       //��ֵ
    delete[]tmp;                                       //�ͷ� copy
}

int SimpleIndex(String& T, String& P, int pos = 0)
{
    int i = pos, j = 0;
    int k = i;             //��k��¼ָ��ĳ�ʼλ��
    while (i < T.length && j < P.length)
    {
        if (T.strVal[i] == P.strVal[j])
        {
            i++;
            j++;
        }
        else
        {
            k++;
            i = k;
            j = 0;
        }
    }
    if (j >= P.length)
    {
        return k;
    }
    else
    {
        return -1;
    }
}

int FrontRearIndex(String& T, String& P, int pos = 0)  //ǰ��ָ��ģʽƥ��
{
    int T_left = pos;
    int k = T_left;           //��k��¼ָ��ĳ�ʼλ��
    int P_left = 0, P_right = P.length - 1;
    while ((k < (T.length - P.length + 1)) && (P_left <= P_right))
    {
        if ((T.strVal[T_left] == P.strVal[P_left]) && (T.strVal[k + P_right] == P.strVal[P_right]))
        {
            T_left++;
            P_left++;
            P_right--;
        }
        else
        {
            k++;
            T_left = k;
            P_left = 0;
            P_right = P.length - 1;
        }
    }
    if (P_left > P_right)
    {
        return k;
    }
    else
    {
        return -1;
    }
}

#endif
