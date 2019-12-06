#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include"AdjMatrix.h"
using namespace std;


int main()
{
	Graph graph;
	graph.creatGraph();
	graph.BFSTraverse();
	graph.DFSTraverse();
	cout << graph.Prim() << endl;
	return 0;
}