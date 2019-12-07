#include <iostream>
#include <vector>
using namespace std;
int getTreeH(int N, vector<char> pre, vector<char> mid)
{
	if (N == 1) return 1;
	if (N == 0) return 0;
	int index = 0;
	for (int i = 0; i < N; ++i)
	{
		if (mid[i] == pre[0])
		{
			index = i;
			break;
		}
	}
	vector<char> newpre1;
	for (int i = 0; i < index; ++i)
	{
		newpre1.push_back(pre[i + 1]);
	}
	vector<char> newmid1;
	for (int i = 0; i < index; ++i)
	{
		newmid1.push_back(mid[i]);
	}
	vector<char> newpre2;
	for (int i = index + 1; i < N; ++i)
	{
		newpre2.push_back(pre[i]);
	}
	vector<char> newmid2;
	for (int i = index + 1; i < N; ++i)
	{
		newmid2.push_back(mid[i]);
	}
	return 1 + max(getTreeH(index, newpre1, newmid1), getTreeH(N - index - 1, newpre2, newmid2));
}
int main()
{
	int N;
	vector<char> pre;
	vector<char> mid;
	cin >> N;
	char ch;
	for (int i = 0; i < N; ++i)
	{
		cin >> ch;
		pre.push_back(ch);
	}
	for (int i = 0; i < N; ++i)
	{
		cin >> ch;
		mid.push_back(ch);
	}
	cout << getTreeH(N, pre, mid);
	return 0;
}
