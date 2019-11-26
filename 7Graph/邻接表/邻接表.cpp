#include<iostream>	
#include<cmath>
using namespace std;
class Graph
{
private:
	const static int MaxVertexNum = 10;
	using VertexType = char;//顶点的数据类型
	//边表节点
	typedef struct ArcNode
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
	}VNode,AdjList[MaxVertexNum];
	//typedef struct,感觉已经封装在类中了没必要了
	AdjList vertices;//邻接表
	int vexnum, arcnum;//顶点数，弧数


};