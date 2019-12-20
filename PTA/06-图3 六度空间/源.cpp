//顶点数众多 而边数少 故采用邻接表 
#include <iostream>
#include <cstdio>
#include <cstdlib> 
#include <queue>
using namespace std;

#define MaxVertexNum 10000    /* 最大顶点数设为100 */
typedef int Vertex;         /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;        /* 边的权值设为整型 */
typedef char DataType;        /* 顶点存储的数据类型设为字符型 */

/* 边的定义 */
typedef struct ENode* PtrToENode;
struct ENode
{
	Vertex V1, V2;      /* 有向边<V1, V2> */
};
typedef PtrToENode Edge;

/* 邻接点的定义 */
typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode
{
	Vertex AdjV;        /* 邻接点下标 */
	PtrToAdjVNode Next;    /* 指向下一个邻接点的指针 */
};

/* 顶点表头结点的定义 */
typedef struct Vnode
{
	PtrToAdjVNode FirstEdge;/* 边表头指针 */
} AdjList[MaxVertexNum];    /* AdjList是邻接表类型 */

/* 图结点的定义 */
typedef struct GNode* PtrToGNode;
struct GNode
{
	int Nv;     /* 顶点数 */
	int Ne;     /* 边数   */
	AdjList G;  /* 邻接表 */
};
typedef PtrToGNode LGraph; /* 以邻接表方式存储的图类型 */
bool Visited[MaxVertexNum] = { false };

LGraph CreateGraph(int VertexNum);
void InsertEdge(LGraph Graph, Edge E);
LGraph BuildGraph();
void Visit(Vertex V);
void InitVisited();
int BFS(LGraph Graph, Vertex V, void (*Visit)(Vertex));

LGraph CreateGraph(int VertexNum)
{ /* 初始化一个有VertexNum个顶点但没有边的图 */
	Vertex V;
	LGraph Graph;

	Graph = (LGraph)malloc(sizeof(struct GNode)); /* 建立图 */
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	/* 初始化邻接表头指针 */
	/* 注意：这里默认顶点编号从0开始，到(Graph->Nv - 1) */
	for (V = 0; V < Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;

	return Graph;
}

void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;

	/* 插入边 <V1, V2> */
	/* 为V2建立新的邻接点 */
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	/* 将V2插入V1的表头 */
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;

	/* 若是无向图，还要插入边 <V2, V1> */
	/* 为V1建立新的邻接点 */
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V1;
	/* 将V1插入V2的表头 */
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph()
{
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	scanf("%d", &Nv);   /* 读入顶点个数 */
	Graph = CreateGraph(Nv); /* 初始化有Nv个顶点但没有边的图 */

	scanf("%d", &(Graph->Ne));   /* 读入边数 */
	if (Graph->Ne != 0)
	{ /* 如果有边 */
		E = (Edge)malloc(sizeof(struct ENode)); /* 建立边结点 */
		/* 读入边，格式为"起点 终点"，插入邻接矩阵 */
		for (i = 0; i < Graph->Ne; i++)
		{
			scanf("%d %d", &E->V1, &E->V2);
			InsertEdge(Graph, E);
		}
	}

	return Graph;
}

//初始化 Visited[] = false
void InitVisited()
{
	for (int i = 0; i < MaxVertexNum; i++)
		Visited[i] = false;
}

int BFS(LGraph Graph, Vertex V)
{
	queue<Vertex> Q;
	Vertex W;
	int count = 1;
	int level = 0;
	Vertex last = V, tail;
	Visited[V] = true; /* 标记V已访问 */
	Q.push(V);

	while (!Q.empty())
	{
		W = Q.front();
		Q.pop();
		for (PtrToAdjVNode tempV = Graph->G[W].FirstEdge; tempV; tempV = tempV->Next) /* 对W的每个邻接点tempV->AdjV */
			if (!Visited[tempV->AdjV])
			{
				Visited[tempV->AdjV] = true;
				Q.push(tempV->AdjV);
				count++;
				tail = tempV->AdjV;
			}
		if (W == last)
		{
			level++;
			last = tail;
		}
		if (level == 6)
			break;
	}
	return count;
}


int main()
{
	LGraph graph;
	graph = BuildGraph();
	for (int i = 1; i <= graph->Nv; i++)
	{
		InitVisited();
		int count = BFS(graph, i);
		printf("%d: %.2f%%\n", i, count * 100.0 / graph->Nv);
	}
	return 0;
}