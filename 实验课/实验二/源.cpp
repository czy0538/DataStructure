#include <iostream>
#include <vector>
#include<algorithm>
#define ERROR -1
using namespace std;
int getTreeH(int N, vector<char>& pre, vector<char>& mid)
{
	if (N == 1) return 1;
	if (N == 0) return 0;
	int index = 0; 
	int i = 0;
	for (i = 0; i < N; ++i)
	{
		if (mid[i] == pre[0])
		{
			index = i;
			break;
		}
	}
	if (i == N)
	{
		cout << "ÐòÁÐÊäÈë´íÎó" << endl;
		return -1;
		exit(0);
	}
	vector<char> newpre1;
	for (int i = 1; i <= index; ++i)
	{
		newpre1.push_back(pre[i]);
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
	int num;
	vector<char> pre;
	vector<char> mid;
	cin >> num;
	char ch;
	for (int i = 0; i < num; ++i)
	{
		cin >> ch;
		pre.push_back(ch);
	}
	for (int i = 0; i < num; ++i)
	{
		cin >> ch;
		mid.push_back(ch);
	}
	cout << getTreeH(num, pre, mid);
	return 0;
}
