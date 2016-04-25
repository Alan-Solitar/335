#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#include <vector>
#include "Vertex.h"

using namespace std;

class AdjacencyList {
private:
	vector<Vertex* > vertices_;
public:
	void CreateVertices(int num_vertices);
	void AddEdge(int origin_vertex, int dest_vertex, double weight);
	void CheckEdge(int origin_vertex, int dest_vertex);
	size_t GetSize();
	
};

#endif