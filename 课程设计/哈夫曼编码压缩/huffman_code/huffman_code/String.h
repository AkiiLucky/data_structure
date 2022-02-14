#ifndef _STRING_H__
#define _STRING_H__

#include <iostream>
#include <cstring>
#include "DbLinkList.h"

using namespace std;

class String
{
protected:
    mutable char* strVal;      //可变类型的串值
    int length;                //串长
public:
    String(const char* str = "\0");
    virtual ~String();
    const char* CStr() const;                                       //将串转换成 C 风格串
    int Length();                                                   //求串长
    bool Read(istream& input);                                      //从输入流读入串
    String& operator=(const String& copy);                          //重载赋值运算符


    friend void Concat(String& addTo, const String& addOn);         //将串 addOn 连接在 addTo 后面
    friend void Copy(String& copy, const String& original, int n);  //将串 original 复制 n 个字符串到串 copy
    friend int SimpleIndex(String& S, String& T, int pos);          //简单模式匹配
    friend int FrontRearIndex(String& T, String& P, int pos);       //前后模式匹配
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

bool String::Read(istream& input)          //从输入流读取一行字符串
{
    DbLinkList<char> tmp;                  //利用一个临时链表存储每个字符
    char c;
    for (int i = 0; (c = input.get()) != '\n'; i++)
    {
        if (c == EOF) return false;
        tmp.Insert(i, c);
    }

    delete[]strVal;                       //将原来的数据清空
    length = 0;
    strVal = new char[tmp.Length() + 1];  //分配新的空间
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

void Concat(String& addTo, const String& addOn)         //将串 addOn 连接在 addTo 后面
{
    const char* cFirst = addTo.CStr();                  //指向第一个串
    const char* cSecond = addOn.CStr();                 //指向第二个串
    char* copy = new char[strlen(cFirst) + strlen(cSecond) + 1]; //分配空间
    strcpy_s(copy, strlen(cFirst) + 1, cFirst);         //复制第一个串
    strcat_s(copy, strlen(copy) + strlen(cSecond) + 1, cSecond); //连接第二个串
    String tmp(copy);                                   //将 C 风格的串转换为 String 类型
    addTo = tmp;                                        //赋值
    delete[]copy;                                      //释放 copy
}

void Copy(String& copy, const String& original, int n)  //将串original复制 n 个字符到串copy
{
    const char* cFirst = copy.CStr();                   //指向第一个串
    const char* cSecond = original.CStr();              //指向第二个串
    char* tmp = new char[n + 1];                        //分配空间
    tmp[0] = '\0';
    for (int i = 0; i < n; i++)
    {
        tmp[i] = cSecond[i];                            //复制 n 个字符
    }
    tmp[n] = '\0';                                      //末尾加 '\0'
    String tmp_s(tmp);                                  //将 C 风格的串转换为 String 类型
    copy = tmp_s;                                       //赋值
    delete[]tmp;                                       //释放 copy
}

int SimpleIndex(String& T, String& P, int pos = 0)
{
    int i = pos, j = 0;
    int k = i;             //用k记录指针的初始位置
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

int FrontRearIndex(String& T, String& P, int pos = 0)  //前后指针模式匹配
{
    int T_left = pos;
    int k = T_left;           //用k记录指针的初始位置
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
