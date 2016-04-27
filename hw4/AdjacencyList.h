#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#include <vector>
#include "Vertex.h"
#include <limits>


using namespace std;

class AdjacencyList {
private:
	vector<Vertex* > vertices_;
	Vertex v* = FindMinDistVertex();
public:
	const static int INFINITY = numeric_limits<int>::max();
	void CreateVertices(int num_vertices);
	void AddEdge(int origin_vertex, int dest_vertex, double weight);
	void CheckEdge(int origin_vertex, int dest_vertex);
	void Dijstra(int starting_vertex, int dest_vertex);
	size_t GetSize();
	
};

#endif