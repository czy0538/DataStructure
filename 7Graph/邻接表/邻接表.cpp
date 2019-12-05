#include<iostream>	
#include<cmath>
#include"AdjList.h"
using namespace std;



int main()
{
	Graph g;
	g.creatGraph();
	g.BFSTraverse();
	g.DFSTraverse();
	return 0;
}