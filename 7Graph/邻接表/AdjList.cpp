#include "AdjList.h"
#include<iostream>
#include<string>
#include<queue>
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
		double z;
		cout << "请分别输入插入的起始节点和终止节点以及权值" << endl;
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
			cout << "这是一个连通集：" << endl;
			DFS(i, visited);
		}
	}
}

int Graph::Prim()
{
	if (graph.kind != UDN && graph.kind != UDG)
	{
		cout << "这不是无向图" << endl;
		return -1;
	}
	double dist[MaxVertexNum];//距离数组
	int parent[MaxVertexNum];//前驱数组
	double lowcost = 0;//累计的权值
	//初始化两个数组
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
	cout << "节点编号:" << 0 << "节点信息:" << graph.vertices[0].data << endl;
	while (true)
	{
		int t = findMin(dist);
		if (t == -1)//所有的节点都被改写/出现不连通的节点时退出
		{
			break;
		}
		lowcost += dist[t];
		cout << "节点编号:" << t << "节点信息:" << graph.vertices[t].data << "权值：" << dist[t] << endl;
		dist[t] = 0;
		auto p = graph.vertices[t].first;
		while (p != nullptr)
		{
			auto i = p->adjvex;
			if (p->info < dist[i])
			{
				parent[i] = t;//更改前驱
				dist[i] = p->info;//更改距离
			}
			p = p->next;
		}

	}

	for (int i = 1; i < graph.vexnum; i++)
	{
		cout << "当前节点：" << i << "的前驱节点为" << parent[i] << endl;
		if (dist[i] != 0)
		{
			cout << "这个图不连通" << endl;
		}
	}



	return lowcost;
}

//返回与父节点之间权值最小的节点
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