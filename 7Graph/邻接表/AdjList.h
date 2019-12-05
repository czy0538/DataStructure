#pragma once
#include<iostream>
#include<string>
#include<queue>
class Graph
{
private:
	using InfoType = std::string;
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
	void creatGraph();
	void insertArc(int i, int j);
	void BFSTraverse();
	void BFS(int v, std::queue<int>& q, bool visited[]);
	void visit(int i);
	void DFS(int v, bool visited[]);
	void DFSTraverse();
};