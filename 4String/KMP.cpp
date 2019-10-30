#include <iostream>
using namespace std;

void kmpnext(char *s, int *next)
{
	int i = 1, j = 0;
	next[1] = 0;
	next[0] = 0;
	while (i < s[0])
	{
		if (j == 0 || s[i] == s[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}

int index_kmp(char *s, char *t, int pos)
{
	int *next = new int[t[0] + 1];
	kmpnext(t, next);
	int i = pos;
	int j = 1;
	while (i <= s[0] && j <= t[0])
	{
		if (j==0 || s[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}

	}
	if (j > t[0])
	{
		return i - t[0];
	}
	else
	{
		return 0;
	}


}

int main()
{
	char *s = new char[10];
	s[0] = 9;
	for (int i = 1; i <= s[0]; i++)
	{
		cin >> s[i];
	}
	int *next = new int[10];
	kmpnext(s, next);
	for (int i = 0; i < 10; i++)
	{
		cout << next[i];
	}
	cout<<endl;
	char t[4]={3,'b','a','b'};
	cout<<index_kmp(s,t,1);
	delete[] next;
	delete[] s;
	system("pause");
	return 0;
}