//�������ڶ� �������� �ʲ����ڽӱ� 
#include <iostream>
#include <cstdio>
#include <cstdlib> 
#include <queue>
using namespace std;

#define MaxVertexNum 10000    /* ��󶥵�����Ϊ100 */
typedef int Vertex;         /* �ö����±��ʾ����,Ϊ���� */
typedef int WeightType;        /* �ߵ�Ȩֵ��Ϊ���� */
typedef char DataType;        /* ����洢������������Ϊ�ַ��� */

/* �ߵĶ��� */
typedef struct ENode* PtrToENode;
struct ENode
{
	Vertex V1, V2;      /* �����<V1, V2> */
};
typedef PtrToENode Edge;

/* �ڽӵ�Ķ��� */
typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode
{
	Vertex AdjV;        /* �ڽӵ��±� */
	PtrToAdjVNode Next;    /* ָ����һ���ڽӵ��ָ�� */
};

/* �����ͷ���Ķ��� */
typedef struct Vnode
{
	PtrToAdjVNode FirstEdge;/* �߱�ͷָ�� */
} AdjList[MaxVertexNum];    /* AdjList���ڽӱ����� */

/* ͼ���Ķ��� */
typedef struct GNode* PtrToGNode;
struct GNode
{
	int Nv;     /* ������ */
	int Ne;     /* ����   */
	AdjList G;  /* �ڽӱ� */
};
typedef PtrToGNode LGraph; /* ���ڽӱ�ʽ�洢��ͼ���� */
bool Visited[MaxVertexNum] = { false };

LGraph CreateGraph(int VertexNum);
void InsertEdge(LGraph Graph, Edge E);
LGraph BuildGraph();
void Visit(Vertex V);
void InitVisited();
int BFS(LGraph Graph, Vertex V, void (*Visit)(Vertex));

LGraph CreateGraph(int VertexNum)
{ /* ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */
	Vertex V;
	LGraph Graph;

	Graph = (LGraph)malloc(sizeof(struct GNode)); /* ����ͼ */
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	/* ��ʼ���ڽӱ�ͷָ�� */
	/* ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) */
	for (V = 0; V < Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;

	return Graph;
}

void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;

	/* ����� <V1, V2> */
	/* ΪV2�����µ��ڽӵ� */
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	/* ��V2����V1�ı�ͷ */
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;

	/* ��������ͼ����Ҫ����� <V2, V1> */
	/* ΪV1�����µ��ڽӵ� */
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V1;
	/* ��V1����V2�ı�ͷ */
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph()
{
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	scanf("%d", &Nv);   /* ���붥����� */
	Graph = CreateGraph(Nv); /* ��ʼ����Nv�����㵫û�бߵ�ͼ */

	scanf("%d", &(Graph->Ne));   /* ������� */
	if (Graph->Ne != 0)
	{ /* ����б� */
		E = (Edge)malloc(sizeof(struct ENode)); /* �����߽�� */
		/* ����ߣ���ʽΪ"��� �յ�"�������ڽӾ��� */
		for (i = 0; i < Graph->Ne; i++)
		{
			scanf("%d %d", &E->V1, &E->V2);
			InsertEdge(Graph, E);
		}
	}

	return Graph;
}

//��ʼ�� Visited[] = false
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
	Visited[V] = true; /* ���V�ѷ��� */
	Q.push(V);

	while (!Q.empty())
	{
		W = Q.front();
		Q.pop();
		for (PtrToAdjVNode tempV = Graph->G[W].FirstEdge; tempV; tempV = tempV->Next) /* ��W��ÿ���ڽӵ�tempV->AdjV */
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