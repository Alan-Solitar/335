#include <cstdlib>
#include <ctime>
#include "AdjacencyList.h"
#include "UnionFind.h"
#include <iostream>

using namespace std;

GenerateAndAdd() {
	srand(time(0)); //use current time as seed for random generator
	const int i1 = rand() % maximum_value + 1;
	const int i2 = rand() % maximum_value + 1;
	if(!graph.HasEdge(i1,i2)) {
		graph.AddEdge(i1,i2,0);
		graph.AddEdge(i2,i,0);
		disjoint.Union(i1,i2);
}

PrintStatistics() {
	cout << "Number of Edges: " <<graph.num_edges <<endl;
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