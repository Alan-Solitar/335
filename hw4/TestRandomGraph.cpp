#include <cstdlib>
#include <ctime>
#include "AdjacencyList.h"
#include "UnionFind.h"
#include <iostream>

using namespace std;

void GenerateAndAdd(AdjacencyList &graph, UnionFind &disjoint,const int maximum_value) {
	srand(time(0)); //use current time as seed for random generator
	const int i1 = rand() % maximum_value + 1;
	const int i2 = rand() % maximum_value + 1;
	while(disjoint.GetNumberOfSets() > 1)
		if(!graph.HasEdge(i1,i2)) {
			graph.AddEdge(i1,i2,0);
			graph.AddEdge(i2,i1,0);
			disjoint.Union(i1,i2);
	}

void PrintStatistics(AdjacencyList &graph) {
	cout << "Number Of Edges: " <<graph.num_edges <<endl;
	cout << "Smallest Out Degree: " << graph.GetMinOutDegree() << endl;
	cout << "Smallest Out Degree: " << graph.GetMinOutDegree() << endl;
	cout << "Largest Out Degree: " << graph.GetMaxOutDegree() << endl;
	cout << "Average Out Degree: " << graph.GetAverageOutDegree() << endl;
}


int main(int argc, char **argv) {
	if (argc != 2) {
		cout << "Usage: " << argv[0] << " <maximum_number_of_nodes>" << endl;
		return 0;
	}
	const int MAX_NODES = argv[1];
	AdjacencyList graph;
	graph.CreateVertices(MAX_NODES);
	UnionFind disjoint(MAX_NODES);
}