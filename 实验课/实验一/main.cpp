#include<iostream>
#include<string>
#include<sstream>
using namespace std;
typedef struct PolynomialNode
{
	int coef;
	int index;
	PolynomialNode* next;
}*node;
string intToString(int in)
{
	stringstream ss;
	string temp;
	ss << in;
	ss >> temp;
	return temp;
}
int main()
{
	int index, coef;
	node head = new PolynomialNode;
	head->next = nullptr;
	node p = head;
	//录入
	while (true)
	{
		cout << "请输入系数，输入0截止:";
		cin >> coef;
		if (coef == 0)
		{
			break;
		}
		cout << "请输入指数：";
		cin >> index;
		node temp = new PolynomialNode;
		temp->coef = coef;
		temp->index = index;
		temp->next = nullptr;
		p->next = temp;
		p = temp;
	}

	p = head->next;
	//求导
	while (p != nullptr)
	{
		p->coef = p->coef * p->index;
		p->index--;
		if (p->index == -1)
		{
			p->index = 0;
		}
		p = p->next;
	}
	p = head->next;
	//遍历
	string out;

	while (p != nullptr)
	{

		out = out + intToString(p->coef) + " " + intToString(p->index) + " ";
		p = p->next;

	}
	//使输出符合格式
	out = out.substr(0, out.size() - 1);
	cout << out.size() << endl;
	if (out.size() != 3 && out[out.size() - 1] == '0' && out[out.size() - 3] == '0')
	{

		out = out.substr(0, out.size() - 4);

	}

	cout << out << endl;
}