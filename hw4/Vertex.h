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
	double distance;
	bool visited_;
	bool distance_known_;

public:
	Vertex(int label);
	bool AddEdge(Vertex * vertex, double weight);
	//void setLabel(int label);

};

#endif