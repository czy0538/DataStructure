#include<string>
#include<vector>
#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
constexpr int MAXNUMBER = 1000;

int c;
struct Node
{
	int id, sc;
	string name;
}Data[MAXNUMBER];

bool Compare(Node a, Node b)
{
	switch (c)
	{
	case 1:
		return a.id <= b.id; break;
	case 2:
		if (a.name == b.name)
			return a.id <= b.id;
		return a.name <= b.name;
		break;
	case 3:
		if (a.sc == b.sc)
			return a.id <= b.id;
		return a.sc <= b.sc;
		break;
	default:
		exit(-1);
	}
}

void Sort(Node lst[], int head, int tail, bool (fun(Node a, Node b)))
{

	if (head >= tail) return;

	int i = head, j = tail;

	Node pivot = lst[head];  // ͨ��ȡ��һ����Ϊ��׼

	while (i < j)
	{ // i,j �������˳�ѭ��
		while (i < j && !fun(lst[j], pivot)) j--;
		lst[i] = lst[j];    // ��������ɨ�裬���Ȼ�׼С��������
		while (i < j &&fun(lst[i] , pivot) )i++;
		lst[j] = lst[i];    //  ��������ɨ�裬���Ȼ�׼�������ұ�
	}

	lst[i] = pivot; // �� ��׼�� ���

	Sort(lst, head, i - 1, Compare);    // �Ի�׼��Ϊ�����ҷ���
	Sort(lst, j + 1, tail, Compare);
}

int main()
{
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; ++i)
	{
		cin >> Data[i].id >> Data[i].name >> Data[i].sc;
	}
	Sort(Data, 0, n, Compare);
	for (int i = 0; i < n; ++i)
		cout <<  Data[i].id << " " << Data[i].name << " " << Data[i].sc << endl;
	return 0;
}

