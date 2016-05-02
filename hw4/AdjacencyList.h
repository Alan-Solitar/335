#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#include <vector>
#include "Vertex.h"
#include <limits>


using namespace std;

//Written by Alan Solitar

class AdjacencyList {
private:
	vector<Vertex* > vertices_;
	int num_edges_;
	int num_vertices_;
	int min_out_degree_;
	int max_out_degree_;
	void PrintPath();
	struct compareVertex {
		bool operator()(const Vertex* lhs, const Vertex* rhs) const {
    	return lhs->distance_ > rhs->distance_ ;
  }
};

	
public:
	const static int INFINITY = numeric_limits<int>::max();
	//intialize vertices
	void CreateVertices(int num_vertices);
	void AddEdge(int origin_vertex, int dest_vertex, double weight);
	//Function to check edges and print out corresponding weights
	void CheckEdge(int origin_vertex, int dest_vertex);
	bool HasEdge(int origin_vertex, int dest_vertex);
	//run priority queue without decrease key dijkstras
	void Dijkstras(int starting_vertex, int dest_vertex);
	//print out the min path found by dijkstras
	void PrintPath(int starting_vertex, int dest_vertex);
	//return number of vertices in graph
	size_t GetSize();
	//various functions to get out degrees and number of edges
	int GetMinOutDegree();
	int GetMaxOutDegree();
	double GetAverageOutDegree();
	int GetNumEdges();
	
};
#include "AdjacencyList.cpp"
#endif