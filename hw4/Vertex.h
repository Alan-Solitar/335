#ifndef VERTEX_H
#define VERTEX_H

#include <utility>
#include <vector>

using namespace std;
class AdjacencyList; //forward delcaration
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
	//reset booleans to default values
	void ResetVertexBools();

};
#include "Vertex.cpp"

#endif