#include "AdjMatrix.h"
#include<iostream>
#include<queue>
#include<cmath>
#include<stack>
#define GRAPH_KIND DN;
using namespace std;

void Graph::creatGraph()
{
	cout << "请依次输入图的顶点和边数" << endl;
	cin >> graph.vexnum >> graph.arcnum;
	//图的类型设置
	graph.kind = GRAPH_KIND;
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
	cout << "顶点编号:" << i << ",顶点信息:" << graph.vex[i] << endl;
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
		cout << "这不是无向图" << endl;
		return -1;
	}
	double dist[MAX_VERTEX_NUM];//距离数组
	int parent[MAX_VERTEX_NUM];//前驱数组
	double lowcost = 0;//累计的权值
	//初始化两个数组
	dist[0] = 0;
	parent[0] = -1;
	for (int i = 1; i < graph.vexnum; i++)
	{
		dist[i] = graph.edge[0][i].adjvex;
		parent[i] = 0;
	}
	cout << "节点编号:" << 0 << "节点信息:" << graph.vex[0] << endl;
	while (true)
	{
		int t = findMin(dist);
		if (t == -1)//所有的节点都被改写/出现不连通的节点时退出
		{
			break;
		}
		lowcost += dist[t];
		cout << "节点编号:" << t << "节点信息:" << graph.vex[t] << "权值：" << dist[t] << endl;
		dist[t] = 0;

		for (int i = 1; i < graph.vexnum; i++)
		{
			//t节点到某个节点更近
			if (graph.edge[t][i].adjvex < dist[i])
			{
				parent[i] = t;//更改前驱
				dist[i] = graph.edge[t][i].adjvex;//更改距离
			}
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

void Graph::topologicalSort()
{
	stack<int> vec;
	//构建入度数组
	int indegree[MAX_VERTEX_NUM];
	for (int i = 0; i < graph.vexnum; i++)
	{
		indegree[i] = countIndegree(i);
		if (indegree[i] == 0)
		{
			//将所有入度为0的顶点拽到栈里面
			vec.push(i);
		}
	}
	int count = 0;
	while (!vec.empty())
	{
		auto t = vec.top();
		vec.pop();
		cout << "顶点" << t << ":" << graph.vex[t] << endl;
		count++;
		//删除该顶点，跟该顶点的后继入度-1
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
		cout << "有回路，终止交易" << endl;
	}
	else
	{
		cout << "拓扑排序结束" << endl;
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
