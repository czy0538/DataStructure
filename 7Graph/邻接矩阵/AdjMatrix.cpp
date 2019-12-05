#include "AdjMatrix.h"
#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

void Graph::creatGraph()
{
	cout << "请依次输入图的顶点和边数" << endl;
	cin >> graph.vexnum >> graph.arcnum;
	graph.kind = UDG;
	for (int i = 0; i < graph.vexnum; i++)
	{
		cout << "请输入图的第" << i << "个顶点的值:";
		cin >> graph.vex[i];
	}
	//初始化整个图
	for (int i = 0; i < graph.vexnum; i++)
	{
		for (int j = 0; j < graph.vexnum; j++)
		{
			graph.edge[i][j].adjvex = HUGE_VAL;
			graph.edge[i][j].info = "";
		}
	}

	//初始化权值
	for (int i = 0; i < graph.arcnum; i++)
	{
		cout << "依次输入起点，终点，权重:";
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
			cout << "这是一个连通集：" << endl;
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
	cout << "顶点编号:"<<i<<",顶点信息:" << graph.vex[i] << endl;
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
			cout << "这是一个连通集：" << endl;
			DFS(i, visited);
		}
	}
}
