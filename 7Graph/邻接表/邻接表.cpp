#include<iostream>	
#include<cmath>
using namespace std;
class Graph
{
private:
	const static int MaxVertexNum = 10;
	using VertexType = char;//�������������
	//�߱�ڵ�
	typedef struct ArcNode
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
	}VNode,AdjList[MaxVertexNum];
	//typedef struct,�о��Ѿ���װ��������û��Ҫ��
	AdjList vertices;//�ڽӱ�
	int vexnum, arcnum;//������������


};