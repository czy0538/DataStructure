#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

class Graph
{
private:
	using Vertextype = char;//顶点的数据类型
	using EdgeAdjvexType = double;
	using InfoType = string;//边消息的数据类型
	const static int MAX_VERTEX_NUM = 10;//顶点数目的最大值
	typedef enum
	{
		UDG, UDN, DG, DN//无向图，无向网，有向图，有向网
	} GraphKind;//图的类型
	struct EdgeType
	{
		double adjvex;
		InfoType info;
	};
	typedef struct
	{
		GraphKind kind;
		Vertextype vex[MAX_VERTEX_NUM];//顶点表
		EdgeType edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//邻接矩阵
		int vexnum, arcnum;//图当前的定点和弧数
	}MGraph;
protected:
	MGraph graph;
public:
	void creatGraph()
	{
		cout << "请依次输入图的顶点和边数以及图的类型" << endl;
		cin >> graph.vexnum >> graph.arcnum;
		graph.kind = DG;
		for (int i = 0; i < graph.vexnum; i++)
		{
			cout << "请输入图的第" << i << "个订点的值:";
			cin >> graph.vex[i];
		}
		//初始化整个图
		for (int i = 0; i < graph.vexnum; i++)
		{
			for (int j = 0; j < graph.vexnum; j++)
			{
				graph.edge[i][j].adjvex = INFINITY;
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
};
int main()
{
	Graph graph;
	graph.creatGraph();
}