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
	cout << "请依次输入 VexNum, arcNum" << endl;
	cin >> VexNum >> arcNum;
	graph.arcnum = arcNum;
	graph.vexnum = VexNum;
	//构建顶点表
	for (int i = 0; i < VexNum; i++)
	{
		cout << "请输入当前节点的数据:";
		cin >> graph.vertices[i].data;
		graph.vertices[i].first = nullptr;
		//一种构建边表的方法，即构建出该顶点全部的出边,无向图需要重新输入两次；
		//while (true)
		//{
		//	ArcNode* arcNode = new ArcNode;
		//	cout << "请输入指向的顶点，按-1结束" << endl;
		//	cin >> arcNode->adjvex;
		//	if (arcNode->adjvex == -1)
		//	{
		//		delete arcNode;
		//		break;
		//	}

		//	//头插法
		//	arcNode->next = graph.vertices[i].first;
		//	graph.vertices[i].first = arcNode;
		//}
	}
	//还有一种方法是再次输入，我们把它当作插入法写在这里
	for (int i = 0; i < arcNum; i++)
	{
		int x, y;
		cout << "请分别输入插入的起始节点和终止节点" << endl;
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
			cout << "这是一个连通集：" << endl;
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
	cout << "编号为" << i << "的节点信息为:" << graph.vertices[i].data << endl;
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
			cout << "这是一个连通集：" << endl;
			DFS(i, visited);
		}
	}
}

