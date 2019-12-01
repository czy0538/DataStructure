#include<iostream>	
#include<cmath>
using namespace std;
class Graph
{
private:
	using InfoType = string;
	const static int MaxVertexNum = 10;
	using VertexType = char;//�������������
	typedef enum
	{
		UDG, UDN, DG, DN//����ͼ��������������ͼ��������
	} GraphKind;//ͼ������
	//�߱�ڵ�
	struct ArcNode
	{
		int adjvex;//ָ��Ķ���
		ArcNode* next;//��һ������ָ��
		//InfoType info;//������Ϣ�������ı�Ȩֵ
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
		GraphKind kind;
	};

	ALGraph graph;
public:
	void creatGraph()
	{
		graph.kind = UDG;
		int VexNum, arcNum;
		cout << "���������� VexNum, arcNum" << endl;
		cin >> VexNum >> arcNum;
		graph.arcnum = arcNum;
		graph.vexnum = VexNum;
		//���������
		for (int i = 0; i < VexNum; i++)
		{
			cout << "�����뵱ǰ�ڵ������:";
			cin >> graph.vertices[i].data;
			graph.vertices[i].first = nullptr;
			//һ�ֹ����߱�ķ��������������ö���ȫ���ĳ���,����ͼ��Ҫ�����������Σ�
			while (true)
			{
				ArcNode* arcNode = new ArcNode;
				cout << "������ָ��Ķ��㣬��-1����" << endl;
				cin >> arcNode->adjvex;
				if (arcNode->adjvex == -1)
				{
					delete arcNode;
					break;
				}

				//ͷ�巨
				arcNode->next = graph.vertices[i].first;
				graph.vertices[i].first = arcNode;
			}
		}
		//����һ�ַ������ٴ����룬���ǰ����������뷨д������
		for (int i = 0; i < arcNum; i++)
		{
			int x, y;
			cout << "��ֱ�����������ʼ�ڵ����ֹ�ڵ�" << endl;
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