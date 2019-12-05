#pragma once
#include<iostream>
#include<string>
#include<queue>
class Graph
{
private:
	using InfoType = std::string;
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
	void creatGraph();
	void insertArc(int i, int j);
	void BFSTraverse();
	void BFS(int v, std::queue<int>& q, bool visited[]);
	void visit(int i);
	void DFS(int v, bool visited[]);
	void DFSTraverse();
};