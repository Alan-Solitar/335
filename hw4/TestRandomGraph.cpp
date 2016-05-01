#include <cstdlib>
#include <ctime>
#include "AdjacencyList.h"
#include "UnionFind.h"
#include <iostream>

using namespace std;

void GenerateAndAdd(AdjacencyList &graph, UnionFind &disjoint,const int maximum_value) {
	srand(time(0)); //use current time as seed for random generator
	while(disjoint.GetNumberOfSets() > 1) {
		const int i1 = rand() % maximum_value + 1;
		const int i2 = rand() % maximum_value + 1;
		if(!graph.HasEdge(i1,i2) && i1!=i2) {
			graph.AddEdge(i1,i2,0);
			graph.AddEdge(i2,i1,0);
			cout<<"did it fault"<<endl;
			disjoint.Union(i1,i2);
		}
		cout<< i1 << " " <<i2 <<" still running for some reason: " <<disjoint.GetNumberOfSets()<<endl;
	}
}
void PrintStatistics(AdjacencyList &graph) {
	cout << "Number Of Edges: " <<graph.GetNumEdges()/2 <<endl;
	cout << "Smallest Out Degree: " << graph.GetMinOutDegree()/2 << endl;
	cout << "Largest Out Degree: " << graph.GetMaxOutDegree()/2 << endl;
	cout << "Average Out Degree: " << graph.GetAverageOutDegree()/2 << endl;
}


int main(int argc, char **argv) {
	if (argc != 2) {
		cout << "Usage: " << argv[0] << " <maximum_number_of_nodes>" << endl;
		return 0;
	}
	const int MAX_NODES = atoi(argv[1]);
	AdjacencyList graph;
	graph.CreateVertices(MAX_NODES);
	UnionFind disjoint(MAX_NODES);
	GenerateAndAdd(graph,disjoint,MAX_NODES);
	PrintStatistics(graph);
}