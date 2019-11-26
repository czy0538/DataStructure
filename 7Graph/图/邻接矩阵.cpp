#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

class Graph
{
private:
	using Vertextype = char;//�������������
	using EdgeAdjvexType = double;
	using InfoType = string;//����Ϣ����������
	const static int MAX_VERTEX_NUM = 10;//������Ŀ�����ֵ
	typedef enum
	{
		UDG, UDN, DG, DN//����ͼ��������������ͼ��������
	} GraphKind;//ͼ������
	struct EdgeType
	{
		double adjvex;
		InfoType info;
	};
	typedef struct
	{
		GraphKind kind;
		Vertextype vex[MAX_VERTEX_NUM];//�����
		EdgeType edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�ڽӾ���
		int vexnum, arcnum;//ͼ��ǰ�Ķ���ͻ���
	}MGraph;
protected:
	MGraph graph;
public:
	void creatGraph()
	{
		cout << "����������ͼ�Ķ���ͱ����Լ�ͼ������" << endl;
		cin >> graph.vexnum >> graph.arcnum;
		graph.kind = DG;
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
				graph.edge[i][j].adjvex = INFINITY;
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
};
int main()
{
	Graph graph;
	graph.creatGraph();
}