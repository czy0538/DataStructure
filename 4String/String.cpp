#define TRUE 1
#define OK 1
#define ERROR 0
#define FALSE 0
#define OVERFLOW -1
#include "stdio.h"
#include "stdlib.h"

typedef int Status;

//定义
typedef struct
{
	char* ch;
	int length;
} HString;

//生成串


Status StrAssign(HString& T, char* chars)
{
	int i, j;
	char* c;
	//	if(*T.ch)	free(*T.ch);				//释放原有空间(教材代码有错误）

	for (i = 0, c = chars; *c; ++i, ++c)
		; //求chars的长度

	if (!i)
	{
		T.ch = NULL;
		T.length = 0;
	}
	else
	{
		if (!(T.ch = (char*)malloc(i * sizeof(char))))
			exit(OVERFLOW);
		for (j = 0; j <= i - 1; j++)
			T.ch[j] = chars[j];
		T.length = i;
	}
	return OK;
}

//求串长
int StrLength(HString& S)
{
	return S.length;
}

//探空
Status StrEmpty(HString& S)
{
	if (S.length == 0)
		return TRUE;
	else
		return FALSE;
}

//比较
int StrCompare(HString& S, HString T)
{
	int i;
	for (i = 0; i < S.length && i < T.length; i++)
		if (S.ch[i] != T.ch[i])
			return S.ch - T.ch;
	return S.length - T.length;
}

//清空
Status ClearString(HString& S)
{
	if (S.ch)
	{
		free(S.ch);
		S.ch = NULL;
	}
	S.length = 0;
	return OK;
}

//连接
Status Concat(HString& T, HString& S1, HString& S2)
{
	int i, j;
	if (!T.ch)
		free(T.ch); //释放旧空间
	if (!(T.ch = (char*)malloc((S1.length + S2.length) * sizeof(char))))
		exit(OVERFLOW);
	for (i = 0; i <= S1.length; i++)
		T.ch[i] = S1.ch[i];
	T.length = S1.length + S2.length;
	for (i = S1.length, j = 0; i <= T.length && j <= S2.length; i++, j++)
		T.ch[i] = S2.ch[j];
	return OK;
}

//求子串
Status SubString(HString& Sub, HString& S, int pos, int len)
{
	int i, j;
	if (pos < 1 || pos > S.length || len < 0 || len > S.length - pos + 1)
		return ERROR;
	//if(Sub.ch)	free(Sub.ch);		//释放旧空间(教材代码有错误）
	if (!len) //空子串
	{
		Sub.ch = NULL;
		Sub.length = 0;
	}
	else
	{ //完整子串
		Sub.ch = (char*)malloc(len * sizeof(char));
		for (i = 0, j = pos - 1; i <= len - 1 && j <= pos + len - 2; i++, j++)
			Sub.ch[i] = S.ch[j];
		Sub.length = len;
	}
	return OK;
}

//插入
Status StrInsert(HString S, int pos, HString T)
{
	int i, j;
	if (pos < 1 || pos > S.length + 1)
		return ERROR; //pos不合法
	if (T.length)
	{ //T非空，则重新分配空间，插入T
		if (!(S.ch = (char*)realloc(S.ch, (S.length + T.length) * sizeof(char))))
			exit(OVERFLOW);
		for (i = S.length - 1; i >= pos - 1; --i)
			S.ch[i + T.length] = S.ch[i]; //为插入T腾出位置
		for (i = pos - 1, j = 0; i <= pos + T.length - 2, j <= T.length - 1; i++, j++)
			S.ch[i] = T.ch[j]; //插入T
		S.length += T.length;
	}
	return OK;
}

//删除
Status StrDelete(HString S, int pos, int len)
{
	int i;
	if (pos < 1 || pos > StrLength(S) - len + 1)
		return ERROR;
	for (i = pos - 1; i <= S.length; i++)
		S.ch[i] = S.ch[i + len];
	S.length -= len;
	return OK;
}

//模式匹配
Status Index(HString S, HString T, int pos)
{
	int i, n, m;
	HString sub;
	if (pos > 0)
	{
		n = StrLength(S);
		m = StrLength(T);
		i = pos;

		while (i <= n - m + 1)
		{
			SubString(sub, S, i, m);
			if (StrCompare(sub, T) != 0)
				++i;
			else
				return i; //返回子串在主串中的位置
		}                 //while
	}                     //if
	return 0;             //S中不存在与T相等的子串
}

//复制
Status StrCopy(HString S, HString S2)
{
	int i;
	if (S2.length == 0)
		return ERROR;
	S.ch = (char*)malloc(S2.length * sizeof(char));
	for (i = 0; i <= S2.length; i++)
		S.ch[i] = S2.ch[i];
	S.length = S2.length;
	return OK;
}

//替换
Status Replace(HString S, HString T, HString V)
{
	int i = 1;       //从串S的第一个字符起查找串T
	if (StrEmpty(T)) //T是空串
		return ERROR;

	do
	{
		i = Index(S, T, i);

		if (i) //串S中存在串T
		{
			StrDelete(S, i, StrLength(T));
			StrInsert(S, i, V);
			i += StrLength(V); //在插入的串V后面继续查找串T
		}
	} while (i);

	return OK;
}

//输出串
void PrintStr(HString T)
{
	int i;
	for (i = 0; i < T.length; i++)
		printf("%c", T.ch[i]);
	printf("\n");
}

//int main()
//{
//	HString S;
//	HString T;
//	HString V;
//	HString S2;
//	HString T2;
//	HString Sub;
//
//	//测试StrAssign()函数
//	StrAssign(S, (char*)"Hello");
//	StrAssign(T, (char*)"HelloWorld");
//	StrAssign(S2, (char*)"World");
//	StrAssign(V, (char*)"C++");
//	printf("PrintStr(S):");
//	PrintStr(S);
//
//	//测试StrLength()和StrCompare()函数
//	printf("StrLength(S):%d\n", StrLength(S));
//	printf("StrCompare(S,T):%d\n", StrCompare(S, T));
//
//	//测试StrEmpty()、ClearString()和StrCopy()函数
//	ClearString(S);
//	printf("ClearString(S):");
//	PrintStr(S);
//	printf("StrEmpty:%d\n", StrEmpty(S));
//	StrCopy(S, S2);
//	printf("StrCopy(S,S2):");
//	PrintStr(S);
//
//	//测试Concat()函数和SubString()函数
//	Concat(T2, S, S2);
//	printf("Concat(T2,S,S2):");
//	PrintStr(T2);
//	SubString(Sub, T2, 6, 5);
//	printf("SubString(Sub, T2, 6, 5):");
//	PrintStr(Sub);
//
//	//测试StrInsert()、StrDelete()和Index()函数
//	StrInsert(Sub, 1, T);
//	printf("StrInsert( Sub,1,T):");
//	PrintStr(Sub);
//	printf("Index( Sub,S2,1):%d\n", Index(Sub, S2, 1));
//	//printf("Index_basic( Sub,S2,1):%d\n", Index_basic(Sub, S2, 1));
//	StrDelete(Sub, 6, 5);
//	printf("StrDelete(S, 6, 5):");
//	PrintStr(Sub);
//
//	//测试Replace()函数
//	Replace(Sub, S, V);
//	printf("Replace(Sub,S, V):");
//	PrintStr(Sub);
//	system("pause");
//	return 0;
//}