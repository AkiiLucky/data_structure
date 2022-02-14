#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 255

typedef struct {
	char *ch;
	int length;
}SString;

void InitString(SString &S, const char *str)
{
	S.ch = (char *)malloc(sizeof(char)*(strlen(str) + 1));
	S.length = strlen(str);
	for (int i = 1; i <= S.length; i++)
	{
		S.ch[i] = str[i-1];
	}
}

void PrintString(SString S)
{
	for (int i = 1; i <= S.length; i++)
	{
		printf("%c", S.ch[i]);
	}
	printf("\n");
}

int Index(SString S, SString T) //朴素模式匹配 
{
	int k = 1;
	int i = k, j = 1;
	while (k <= S.length && j <= T.length)
	{
		if (S.ch[i] == T.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			k++;
			i = k;
			j = 1;
		}
	}
	if (j > T.length)
	{
		return k;
	}
	else
	{
		return 0;
	}
}

void get_next(SString &T, int next[])
{
	int i = 1, j = 0;
	next[1] = 0;
	while (i < T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

void Print_next(int next[])
{
	for (int i = 1; i <= 5; i++)
	{
		printf("%d ", next[i]);
	}
	printf("\n");
}

int Index_KMP(SString S, SString T) //这个有问题？？ 
{
	
	int i = 1, j = 1; 
	int next[T.length + 1];
	get_next(T, next);
	Print_next(next);
	while (i < (S.length - T.length + 1) && j <= T.length)
	{
		if (j == 0 || S.ch[i] == T.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j > T.length)
	{
		return i - j;
	}
	else
	{
		return 0;
	}
	
}
int main()
{
	SString S, T;
	//printf("%d\n", sizeof(char));
	InitString(S, "abcabcd");
	PrintString(S);
	InitString(T, "ca");
	PrintString(T);
	
	printf("%d\n", Index(S, T));
	printf("%d\n", Index_KMP(S, T));
	return 0;
}
