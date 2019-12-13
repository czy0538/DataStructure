#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
class Graph
{
public:
	using Vertextype = char;//�������������
	using EdgeAdjvexType = double;
	using InfoType = std::string;//����Ϣ����������
	const static int MAX_VERTEX_NUM = 10;//������Ŀ�����ֵ
	typedef enum
	{
		UDG, UDN, DG, DN//����ͼ��������������ͼ��������
	} GraphKind;//ͼ������
	struct EdgeType
	{
		double adjvex;//Ȩֵ
		InfoType info;
	};
	typedef struct
	{
		GraphKind kind;
		Vertextype vex[MAX_VERTEX_NUM];//�����
		EdgeType edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�ڽӾ���
		int vexnum, arcnum;//ͼ��ǰ�Ķ���ͻ���
	}MGraph;
	MGraph graph;
	void creatGraph();
};

void Graph::creatGraph()
{
	cout << "����������ͼ�Ķ���ͱ���" << endl;
	cin >> graph.vexnum >> graph.arcnum;
	//ͼ����������
	graph.kind = DN;
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
	int s, d;//��㣬�յ�
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

