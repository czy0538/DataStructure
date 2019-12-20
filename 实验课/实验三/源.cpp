#include<iostream>
#include<iomanip>
#include<string>
#include<queue>
#include<sstream>
#include<algorithm>
using namespace std;
class Graph
{
private:
	using InfoType = string;
	const static int MaxVertexNum = 104;
	using VertexType = int;//�������������

	//�߱�ڵ�
	struct ArcNode
	{
		int adjvex;//ָ��Ķ���
		ArcNode* next;//��һ������ָ��
		double info;//Ȩֵ

	};
	//�����
	typedef struct VNode
	{
		VertexType data;//������Ϣ
		ArcNode* first;//ͷ���
	}VNode, AdjList[MaxVertexNum];

	struct ALGraph
	{
		AdjList vertices;//�ڽӱ�
		int vexnum, arcnum;//������������
	};

	ALGraph graph;
public:
	void insertArc(int i, int j, double z)
	{
		ArcNode* arcNode = new ArcNode;
		arcNode->next = graph.vertices[i].first;
		arcNode->adjvex = j;
		arcNode->info = z;
		graph.vertices[i].first = arcNode;
	}
	void creatGraph()
	{
		int VexNum, arcNum;
		cin >> VexNum >> arcNum;
		graph.arcnum = arcNum;
		graph.vexnum = VexNum;
		//���������
		for (int i = 0; i < VexNum; i++)
		{
			graph.vertices[i].data = i + 1;
			graph.vertices[i].first = nullptr;
		}
		for (int i = 0; i < arcNum; i++)
		{
			int x, y;
			cin >> x >> y;
			insertArc(x - 1, y - 1, 1);
			insertArc(y - 1, x - 1, 1);


		}
	}
	void BFSTraverse()
	{
		bool visited[MaxVertexNum];

		for (int i = 0; i < graph.vexnum; i++)
		{
			for (int i = 0; i < graph.vexnum; i++)
			{
				visited[i] = false;
			}
			int count = BFS(i, visited);
			cout << i + 1 << ": " << fixed << setprecision(2) << (double)count / (double)graph.vexnum * 100 << "%" << endl;
		}
	}



	int BFS(int v, bool visited[])
	{
		queue<int> q;
		int count = 1;
		int level = 0;
		VertexType last = v;
		VertexType tail = -1;
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
					visited[t] = true;
					++count;
					tail = t;
					q.push(t);

				}
				p = p->next;
			}
			if (v == last)
			{
				level++;
				last = tail;
			}
			if (level == 6)
				break;
		}
		return count;
	}

};

int main()
{
	Graph g;
	g.creatGraph();
	g.BFSTraverse();
	return 0;
}