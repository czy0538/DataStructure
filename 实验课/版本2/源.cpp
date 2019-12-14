#include<iostream>
#include<sstream>
#include<string>
using namespace std;
typedef struct PolynomialNode
{
	int coef;
	int index;
	PolynomialNode* next;
}*node;

//�ͷ�����ռ�
void clean(node head)
{
	node p = head->next;
	while (true)
	{
		delete head;
		head = p;
		if (p->next == nullptr)
		{
			delete p;
			return;
		}
		else
		{
			p = p->next;
		}
	}
}
int main()
{
	string data;
	getline(cin, data);
	stringstream ss;
	ss << data;
	node head, p;
	head = new PolynomialNode;
	p = head;
	head->next = nullptr;
	int count = 0;
	while (!ss.eof())
	{
		int coef, index;
		ss >> coef;
		ss >> index;
		node temp = new PolynomialNode;
		//ֱ����
		temp->coef = coef * index;
		temp->index = index - 1;
		//����index==0
		if (temp->index == -1)
		{
			delete temp;
			break;
		}
		temp->next = nullptr;
		p->next = temp;
		p = temp;
		++count;
	}
	//��� ֻ��һ��Ԫ�����󵼽��Ϊ0
	if (head->next == nullptr)
	{
		cout << 0 << " " << 0;
		return 0;
	}
	//���ģ��
	p = head->next;
	for (int i = 0; i < count - 1; i++)
	{
		cout << p->coef << " " << p->index << " ";
		p = p->next;
	}
	//������һ����Ī�Ŀո�
	cout << p->coef << " " << p->index;
	clean(head);

	return 0;

}

