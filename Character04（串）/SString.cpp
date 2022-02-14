#include <stdio.h>

#define MaxSize 255
typedef struct {
	char ch[MaxSize];
	int length;
}SString;

int StrLength(SString S)
{
	return S.length;
}

bool SubString(SString &Sub, SString S, int pos, int len) //�� Sub ���ش� S �е� pos ���ַ��𳤶�Ϊ len ���ִ� 
{
	if (pos + len -1 > S.length)
	{
		return false;
	}
	else
	{
		for (int i = pos; i < pos +len; i++)
		{
			Sub.ch[i-pos+1] = S.ch[i]; 
		}
		Sub.length = len;
		return true;
	}
}

int StrCompare(SString S, SString T) //�Ƚϲ������� S > T, ����ֵ > 0; �� S < T, ����ֵ < 0;�� S = T, ����ֵ = 0;
{
	for (int i=1; i<=S.length && i<=T.length; i++)
	{
		if (S.ch[i] != T.ch[i])
		{
			return S.ch[i] - T.ch[i];
		}
	}
	return S.length - T.length;
}

int Index(SString S, SString T) //������ S �д����봮 T ��ͬ���Ӵ����򷵻��������� S �е�һ�γ��ֵ�λ�ã����򷵻� 0 
{
	int i = 1, n = StrLength(S), m = StrLength(T);
	SString sub;
	while (i < n - m + 1)
	{
		SubString(sub, S, i, m);
		if (StrCompare(sub, T) != 0)
		{
			i++;
		}
		else
		{
			return i;
		}
	}	
	return 0;
}

int main()
{
	return 0;
}
