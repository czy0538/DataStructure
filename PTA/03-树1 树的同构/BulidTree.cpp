#include<iostream>
#include<vector>
#include<algorithm>
#define Null -1
using namespace std;
struct TreeNode
{
	char element;
	int left = -1;
	int right = -1;
};

int bulidTree(vector<TreeNode>& tree)
{
	int n;
	cin >> n;
	vector<int> num;
	for (int i = 0; i < n; ++i)
	{
		TreeNode temp;
		char l, r;
		cin >> l;
		cin >> r;
		if (l == '-')
		{
			temp.left = -1;
		}
		else
		{
			temp.left = l - '0';//不要忘记减去
		}
		cin >> r;
		if (r == '-')
		{
			temp.right = -1;
		}
		else
		{
			temp.right = r - '0';
		}
		num.push_back(temp.left);
		num.push_back(temp.right);
		tree.push_back(temp);
	}
	for (int i = 0; i < n; i++)
	{
		if (find(num.begin(), num.end(), i) == num.end())
		{
			return i;
		}
	}
}



int main()
{
	char c;
	cin >> c;
	cout << c << endl;
	int b = c - '0';
	cout << b << endl;
	cin >> c;
}