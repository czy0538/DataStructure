#pragma once
#include<iostream>
#include<queue>
#include<string>
class Graph
{
private:
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
	void creatGraph();
	void BFSTraverse();
	void BFS(int v, std::queue<int>& q, bool visited[]);
	void visit(int i);
	void DFS(int v, bool visited[]);
	void DFSTraverse();
	
};