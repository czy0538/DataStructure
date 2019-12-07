#include "AdjList.h"
#include<iostream>
#include<string>
#include<queue>
#include<cmath>
using namespace std;

void Graph::insertArc(int i, int j, double z)
{
	ArcNode* arcNode = new ArcNode;
	arcNode->next = graph.vertices[i].first;
	arcNode->adjvex = j;
	arcNode->info = z;
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
		double z;
		cout << "��ֱ�����������ʼ�ڵ����ֹ�ڵ��Լ�Ȩֵ" << endl;
		cin >> x >> y >> z;
		switch (graph.kind)
		{
		case UDG:
		case UDN:
			insertArc(x, y, z);
			insertArc(y, x, z);
			break;
		case DG:
		case DN:
			insertArc(x, y, z);
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
			DFS(t, visited);
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

double Graph::Prim()
{
	if (graph.kind != UDN && graph.kind != UDG)
	{
		cout << "�ⲻ������ͼ" << endl;
		return -1;
	}
	double dist[MaxVertexNum];//��������
	int parent[MaxVertexNum];//ǰ������
	double lowcost = 0;//�ۼƵ�Ȩֵ
	//��ʼ����������
	dist[0] = 0;
	parent[0] = -1;
	for (int i = 1; i < graph.vexnum; i++)
	{
		dist[i] = HUGE_VAL;
		parent[i] = 0;
	}
	auto p = graph.vertices[0].first;
	while (p != nullptr)
	{
		auto i = p->adjvex;
		dist[i] = p->info;
		p = p->next;
	}
	cout << "�ڵ���:" << 0 << "�ڵ���Ϣ:" << graph.vertices[0].data << endl;
	while (true)
	{
		int t = findMin(dist);
		if (t == -1)//���еĽڵ㶼����д/���ֲ���ͨ�Ľڵ�ʱ�˳�
		{
			break;
		}
		lowcost += dist[t];
		cout << "�ڵ���:" << t << "�ڵ���Ϣ:" << graph.vertices[t].data << "Ȩֵ��" << dist[t] << endl;
		dist[t] = 0;
		auto p = graph.vertices[t].first;
		while (p != nullptr)
		{
			auto i = p->adjvex;
			if (p->info < dist[i])
			{
				parent[i] = t;//����ǰ��
				dist[i] = p->info;//���ľ���
			}
			p = p->next;
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

double Graph::Kruskal()
{
	if (graph.kind != UDN && graph.kind != UDG)
	{
		cout << "�ⲻ������ͼ" << endl;
		return -1;
	}
	bool isSelected[MaxVertexNum];
	for (int i = 0; i < MaxVertexNum; i++)
	{
		isSelected[i] = false;
	}
	auto graph = this->graph;
	int n = graph.vexnum;
	double lowcost = 0;
	//
	while (n > 1)
	{
		int x = 0, y = 0;
		double mincost = HUGE_VAL;
		for (int i = 0; i < graph.vexnum; i++)
		{
			auto p = graph.vertices[i].first;
			while (p != nullptr)
			{
				if (isSelected[i] && isSelected[p->adjvex])//�жϷ���������
				{
					//p->info = HUGE_VAL;
					p = p->next;
					continue;
				}
				if (p->info < mincost)
				{
					x = i;
					y = p->adjvex;
					mincost = p->info;
				}
				p = p->next;
			}

		}
		isSelected[x] = true;
		isSelected[y] = true;
		lowcost += mincost;
		cout << "���" << x << "," << y << "֮��ı�,ȨֵΪ" << mincost << endl;
		auto p = graph.vertices[x].first;
		while (p != nullptr)
		{
			if (p->adjvex == y)
			{
				p->info = HUGE_VAL;
				break;
			}
			p = p->next;
		}

		auto q = graph.vertices[y].first;
		while (q != nullptr)
		{
			if (q->adjvex == x)
			{
				q->info = HUGE_VAL;
				break;
			}
			q = q->next;
		}
		n--;
	}
	return lowcost;
}
