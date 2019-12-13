#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
class Graph
{
public:
	using Vertextype = char;//顶点的数据类型
	using EdgeAdjvexType = double;
	using InfoType = std::string;//边消息的数据类型
	const static int MAX_VERTEX_NUM = 10;//顶点数目的最大值
	typedef enum
	{
		UDG, UDN, DG, DN//无向图，无向网，有向图，有向网
	} GraphKind;//图的类型
	struct EdgeType
	{
		double adjvex;//权值
		InfoType info;
	};
	typedef struct
	{
		GraphKind kind;
		Vertextype vex[MAX_VERTEX_NUM];//顶点表
		EdgeType edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//邻接矩阵
		int vexnum, arcnum;//图当前的定点和弧数
	}MGraph;
	MGraph graph;
	void creatGraph();
};

void Graph::creatGraph()
{
	cout << "请依次输入图的顶点和边数" << endl;
	cin >> graph.vexnum >> graph.arcnum;
	//图的类型设置
	graph.kind = DN;
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

int findMin(vector<double>& dist,Graph::MGraph graph)
{
	double min = HUGE_VAL;
	int vex = -1;
	for (int i = 0; i < graph.vexnum; i++)
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
int main()
{
	Graph graph;
	graph.creatGraph();
	auto g = graph.graph;
	vector<double> dist;
	queue<int> path;
	int s, d;//起点，终点
	cin >> s >> d;
	path.push(s);
	for (int i = 0; i < g.vexnum; i++)
	{
		if (i == s)
		{
			dist.push_back(0);
		}
		dist.push_back(g.edge[s][i].adjvex);
	}
	while (true)
	{
		auto t = findMin(dist, g);
		if (t == -1)
		{
			cout << path.size() << " " << dist[d];
			return 0;
		}
		if (t == d)
		{
			cout << path.size() << " " << dist[d];
			return 0;
		}
		for (int i = 0; i < g.vexnum; i++)
		{
			
			if (i == t)
			{
				dist[i] = 0;
			}
			if (!isinf(g.edge[t][i].adjvex) && dist[t] + g.edge[t][i].adjvex < dist[i])
			{
				dist[i] = dist[t] + g.edge[t][i].adjvex;
				if (i == s)
				{
					path.push(i);
				}
			}
		}
	}

	return 0;
}

