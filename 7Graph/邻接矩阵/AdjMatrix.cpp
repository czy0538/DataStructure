#include "AdjMatrix.h"
#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

void Graph::creatGraph()
{
	cout << "����������ͼ�Ķ���ͱ���" << endl;
	cin >> graph.vexnum >> graph.arcnum;
	graph.kind = UDG;
	for (int i = 0; i < graph.vexnum; i++)
	{
		cout << "������ͼ�ĵ�" << i << "�������ֵ:";
		cin >> graph.vex[i];
	}
	//��ʼ������ͼ
	for (int i = 0; i < graph.vexnum; i++)
	{
		for (int j = 0; j < graph.vexnum; j++)
		{
			graph.edge[i][j].adjvex = HUGE_VAL;
			graph.edge[i][j].info = "";
		}
	}

	//��ʼ��Ȩֵ
	for (int i = 0; i < graph.arcnum; i++)
	{
		cout << "����������㣬�յ㣬Ȩ��:";
		int x, y;
		EdgeAdjvexType t;
		cin >> x >> y >> t;

		switch (graph.kind)
		{
		case UDG:
		case UDN:
			graph.edge[x][y].adjvex = graph.edge[y][x].adjvex = t;
			break;
		case DN:
		case DG:
			graph.edge[x][y].adjvex = t;
			break;
		}
	}

}

void Graph::BFSTraverse()
{
	bool visited[MAX_VERTEX_NUM];
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

void Graph::BFS(int v, std::queue<int> & q, bool visited[])
{
	visit(v);
	visited[v] = true;
	q.push(v);
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		
		for (int i = 0; i < graph.vexnum; i++)
		{
			if (!isinf(graph.edge[v][i].adjvex))
			{
				if (!visited[i])
				{
					visited[i] = true;
					visit(i);
					q.push(i);
				}
			}
		}
	}

}

void Graph::visit(int i)
{
	cout << "������:"<<i<<",������Ϣ:" << graph.vex[i] << endl;
}

void Graph::DFS(int v, bool visited[])
{
	visit(v);
	visited[v] = true;
	for (int i = 0; i < graph.vexnum; i++)
	{
		if (!isinf(graph.edge[v][i].adjvex))
		{
			if (!visited[i])
			{
				DFS(i, visited);
			}
		}
	}
}

void Graph::DFSTraverse()
{
	bool visited[MAX_VERTEX_NUM];
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
