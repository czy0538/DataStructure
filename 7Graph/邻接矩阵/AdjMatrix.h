#pragma once
#include<iostream>
#include<queue>
#include<string>
class Graph
{
private:
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
	void creatGraph();
	void BFSTraverse();
	void BFS(int v, std::queue<int>& q, bool visited[]);
	void visit(int i);
	void DFS(int v, bool visited[]);
	void DFSTraverse();
	
};