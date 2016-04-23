#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#include <vector>
#include "Vertex.h"

using namespace std;

class AdjacencyList {
private:
	vector<Vertex> vertices_;
public:
	void CreateVertices(int num_vertices);
	void add_edge(int vertex_label, double weight);
	
};

#endif