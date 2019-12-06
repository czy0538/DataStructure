//#include "String.cpp"
//#include <stdlib.h>
//#include <stdio.h>
//#include<iostream>
//#include<string>
//using namespace std;
//
////o(n^2)
//
//
//Status Index_basic(HString &S, HString &T, int pos)
//{
//	char *strS = S.ch;
//	int lenS = S.length;
//	char *strT = T.ch;
//	int lenT = T.length;
//	if (pos >= lenS || lenT > lenS - pos)
//	{
//		return FALSE;
//	}
//	for (int i = pos; i < lenS - lenT + 2; i++)
//	{
//		int j;
//		int k = i;
//		for (j = 0; j < lenT; j++)
//		{
//
//			if (strS[k] == strT[j])
//			{
//				k++;
//			}
//			else
//				break;
//		}
//		if (j == lenT)
//		{
//			return i;
//		}
//	}
//	return FALSE;
//}
//
//
//int* next(const string & s)
//{
//	int* next = new int[s.length];
//	*next = 0;
//	for (int i = 1; i < s.length; i++)
//	{
//
//	}
//}
//int main()
//{
//	HString s1;
//	HString s2;
//	StrAssign(s1, (char *)"yinglerenniubi");
//	StrAssign(s2, (char *)"niubi");
//
//	printf("%d", Index_basic(s1, s2, 0));
//
//	return 0;
//}