#include<iostream>	
#include<cmath>
using namespace std;
class Graph
{
private:
	using InfoType = string;
	const static int MaxVertexNum = 10;
	using VertexType = char;//顶点的数据类型
	typedef enum
	{
		UDG, UDN, DG, DN//无向图，无向网，有向图，有向网
	} GraphKind;//图的类型
	//边表节点
	struct ArcNode
	{
		int adjvex;//指向的顶点
		ArcNode* next;//下一个弧的指针
		//InfoType info;//其他信息，如网的边权值
	};
	//顶点表
	typedef struct VNode
	{
		VertexType data;//顶点信息
		ArcNode* first;//头结点
	}VNode, AdjList[MaxVertexNum];

	struct ALGraph
	{
		AdjList vertices;//邻接表
		int vexnum, arcnum;//顶点数，弧数
		GraphKind kind;
	};

	ALGraph graph;
public:
	void creatGraph()
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
			while (true)
			{
				ArcNode* arcNode = new ArcNode;
				cout << "请输入指向的顶点，按-1结束" << endl;
				cin >> arcNode->adjvex;
				if (arcNode->adjvex == -1)
				{
					delete arcNode;
					break;
				}

				//头插法
				arcNode->next = graph.vertices[i].first;
				graph.vertices[i].first = arcNode;
			}
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
			}

		}

	}
	void insertArc(int i, int j)
	{
		ArcNode* arcNode = new ArcNode;
		arcNode->next = graph.vertices[i].first;
		arcNode->adjvex = j;
		graph.vertices[i].first = arcNode;

	}

};

int main()
{
	Graph g;
	g.creatGraph();
	return 0;
}