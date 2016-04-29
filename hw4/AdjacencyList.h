#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#include <vector>
#include "Vertex.h"
#include <limits>


using namespace std;

class AdjacencyList {
private:
	vector<Vertex* > vertices_;
	void PrintPath();
	struct compareVertex {
		bool operator()(const Vertex* lhs, const Vertex* rhs) const {
    	return lhs->distance_ > rhs->distance_ ;
  }
};

	
public:
	const static int INFINITY = numeric_limits<int>::max();
	void CreateVertices(int num_vertices);
	void AddEdge(int origin_vertex, int dest_vertex, double weight);
	void CheckEdge(int origin_vertex, int dest_vertex);
	void Dijkstras(int starting_vertex, int dest_vertex);
	void PrintPath(int starting_vertex, int dest_vertex);
	size_t GetSize();
	
};

#endif