#include "AdjMatrix.h"
#include<iostream>
#include<queue>
#include<cmath>
#include<stack>
#define GRAPH_KIND DN;
using namespace std;

void Graph::creatGraph()
{
	cout << "����������ͼ�Ķ���ͱ���" << endl;
	cin >> graph.vexnum >> graph.arcnum;
	//ͼ����������
	graph.kind = GRAPH_KIND;
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

void Graph::BFS(int v, std::queue<int>& q, bool visited[])
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
	cout << "������:" << i << ",������Ϣ:" << graph.vex[i] << endl;
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

void Graph::creatTree(int vexNum, int arcNum)
{
	MGraph tree;
	tree.arcnum = arcNum;
	tree.vexnum = vexNum;
	tree.kind = UDN;
}
double Graph::Prim()
{
	if (graph.kind != UDN && graph.kind != UDG)
	{
		cout << "�ⲻ������ͼ" << endl;
		return -1;
	}
	double dist[MAX_VERTEX_NUM];//��������
	int parent[MAX_VERTEX_NUM];//ǰ������
	double lowcost = 0;//�ۼƵ�Ȩֵ
	//��ʼ����������
	dist[0] = 0;
	parent[0] = -1;
	for (int i = 1; i < graph.vexnum; i++)
	{
		dist[i] = graph.edge[0][i].adjvex;
		parent[i] = 0;
	}
	cout << "�ڵ���:" << 0 << "�ڵ���Ϣ:" << graph.vex[0] << endl;
	while (true)
	{
		int t = findMin(dist);
		if (t == -1)//���еĽڵ㶼����д/���ֲ���ͨ�Ľڵ�ʱ�˳�
		{
			break;
		}
		lowcost += dist[t];
		cout << "�ڵ���:" << t << "�ڵ���Ϣ:" << graph.vex[t] << "Ȩֵ��" << dist[t] << endl;
		dist[t] = 0;

		for (int i = 1; i < graph.vexnum; i++)
		{
			//t�ڵ㵽ĳ���ڵ����
			if (graph.edge[t][i].adjvex < dist[i])
			{
				parent[i] = t;//����ǰ��
				dist[i] = graph.edge[t][i].adjvex;//���ľ���
			}
		}
	}

	for (int i = 1; i < graph.vexnum; i++)
	{
		cout << "��ǰ�ڵ㣺" << i << "��ǰ���ڵ�Ϊ" << parent[i] << endl;
		if (dist[i] != 0)
		{
			cout << "���ͼ����ͨ" << endl;
		}
	}



	return lowcost;
}

//�����븸�ڵ�֮��Ȩֵ��С�Ľڵ�
int Graph::findMin(double dist[])
{
	double min = HUGE_VAL;
	int vex = -1;
	for (int i = 1; i < graph.vexnum; i++)
	{
		if (dist[i] < min && dist[i] != 0)
		{
			min = dist[i];
			vex = i;
		}
	}
	cout << vex << endl;
	return vex;
}

void Graph::topologicalSort()
{
	stack<int> vec;
	//�����������
	int indegree[MAX_VERTEX_NUM];
	for (int i = 0; i < graph.vexnum; i++)
	{
		indegree[i] = countIndegree(i);
		if (indegree[i] == 0)
		{
			//���������Ϊ0�Ķ���ק��ջ����
			vec.push(i);
		}
	}
	int count = 0;
	while (!vec.empty())
	{
		auto t = vec.top();
		vec.pop();
		cout << "����" << t << ":" << graph.vex[t] << endl;
		count++;
		//ɾ���ö��㣬���ö���ĺ�����-1
		for (int i = 0; i < graph.vexnum; i++)
		{
			if (!isinf(graph.edge[t][i].adjvex))
			{
				
				if ((--indegree[i]) == 0)
				{
					vec.push(i);
				}
			}
		}
	}
	if (count < graph.vexnum)
	{
		cout << "�л�·����ֹ����" << endl;
	}
	else
	{
		cout << "�����������" << endl;
	}
	
	
}

int Graph::countIndegree(int v)
{
	int num = 0;
	for (int i = 0; i < graph.vexnum; i++)
	{
		if (!isinf(graph.edge[i][v].adjvex))
		{
			num++;
		}
	}
	
	
	return num;
}
