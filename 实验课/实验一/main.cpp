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
	//¼��
	while (true)
	{
		cout << "������ϵ��������0��ֹ:";
		cin >> coef;
		if (coef == 0)
		{
			break;
		}
		cout << "������ָ����";
		cin >> index;
		node temp = new PolynomialNode;
		temp->coef = coef;
		temp->index = index;
		temp->next = nullptr;
		p->next = temp;
		p = temp;
	}

	p = head->next;
	//��
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
	//����
	string out;

	while (p != nullptr)
	{

		out = out + intToString(p->coef) + " " + intToString(p->index) + " ";
		p = p->next;

	}
	//ʹ������ϸ�ʽ
	out = out.substr(0, out.size() - 1);
	cout << out.size() << endl;
	if (out.size() != 3 && out[out.size() - 1] == '0' && out[out.size() - 3] == '0')
	{

		out = out.substr(0, out.size() - 4);

	}

	cout << out << endl;
}