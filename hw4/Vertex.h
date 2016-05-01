#ifndef VERTEX_H
#define VERTEX_H

#include <utility>
#include <vector>

using namespace std;
class AdjacencyList;
class Vertex {

friend class AdjacencyList;
private:
	vector<pair<Vertex *, double>> adj_;
	int label_;
	double distance_;
	bool visited_;
	bool distance_known_;
	int out_degree_;
	Vertex * previous_;
	double previous_weight_;

public:
	Vertex(int label);
	bool AddEdge(Vertex * vertex, double weight);
	void SetVisted();
	void SetKnown();
	void ResetVertexBools();
	bool operator >(const Vertex &other);

};
#include "Vertex.cpp"

#endif