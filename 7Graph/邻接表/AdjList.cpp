#include "AdjList.h"
#include<iostream>
#include<string>
#include<queue>
using namespace std;

void Graph::insertArc(int i, int j)
{
	ArcNode* arcNode = new ArcNode;
	arcNode->next = graph.vertices[i].first;
	arcNode->adjvex = j;
	graph.vertices[i].first = arcNode;
}
void Graph::creatGraph()
{
	graph.kind = UDG;
	int VexNum, arcNum;
	cout << "���������� VexNum, arcNum" << endl;
	cin >> VexNum >> arcNum;
	graph.arcnum = arcNum;
	graph.vexnum = VexNum;
	//���������
	for (int i = 0; i < VexNum; i++)
	{
		cout << "�����뵱ǰ�ڵ������:";
		cin >> graph.vertices[i].data;
		graph.vertices[i].first = nullptr;
		//һ�ֹ����߱�ķ��������������ö���ȫ���ĳ���,����ͼ��Ҫ�����������Σ�
		//while (true)
		//{
		//	ArcNode* arcNode = new ArcNode;
		//	cout << "������ָ��Ķ��㣬��-1����" << endl;
		//	cin >> arcNode->adjvex;
		//	if (arcNode->adjvex == -1)
		//	{
		//		delete arcNode;
		//		break;
		//	}

		//	//ͷ�巨
		//	arcNode->next = graph.vertices[i].first;
		//	graph.vertices[i].first = arcNode;
		//}
	}
	//����һ�ַ������ٴ����룬���ǰ����������뷨д������
	for (int i = 0; i < arcNum; i++)
	{
		int x, y;
		cout << "��ֱ�����������ʼ�ڵ����ֹ�ڵ�" << endl;
		cin >> x >> y;
		switch (graph.kind)
		{
		case UDG:
		case UDN:
			insertArc(x, y);
			insertArc(y, x);
			break;
		case DG:
		case DN:
			insertArc(x, y);
			break;
		}

	}

}
void Graph::BFSTraverse()
{
	bool visited[MaxVertexNum];
	for (int i = 0; i < graph.vexnum; i++)
	{
		visited[i] = false;
	}
	queue<int> wait;
	for (int i = 0; i < graph.vexnum; i++)
	{
		if (!visited[i])
		{
			cout << "����һ����ͨ����" << endl;
			BFS(i, wait, visited);
		}
	}

}

void Graph::BFS(int v, queue<int>& q, bool visited[])
{
	visit(v);
	visited[v] = true;
	q.push(v);
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		auto p = graph.vertices[v].first;
		while (p != nullptr)
		{
			int t = p->adjvex;
			if (!visited[t])
			{
				visit(t);
				visited[t] = true;
				q.push(t);
			}
			p = p->next;
		}
	}

}

void Graph::visit(int i)
{
	cout << "���Ϊ" << i << "�Ľڵ���ϢΪ:" << graph.vertices[i].data << endl;
}

void Graph::DFS(int v, bool visited[])
{
	visit(v);
	visited[v] = true;
	auto p = graph.vertices[v].first;
	while (p != nullptr)
	{
		int t = p->adjvex;
		if (!visited[t])
		{
			DFS(t,visited);
		}
		p = p->next;
	}
	
}

void Graph::DFSTraverse()
{
	bool visited[MaxVertexNum];
	for (int i = 0; i < graph.vexnum; i++)
	{
		visited[i] = false;
	}
	for (int i = 0; i < graph.vexnum; i++)
	{
		if (!visited[i])
		{
			cout << "����һ����ͨ����" << endl;
			DFS(i, visited);
		}
	}
}

