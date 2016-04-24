#ifndef VERTEX_H
#define VERTEX_H

#include <utility>
#include <vector>
#include "AdjacencyList.h"

using namespace std;

class Vertex {

friend class AdjacencyList;
private:
	vector<pair<Vertex * vertex, double>> adj_;
	int label_;
	bool visited_;
	bool known_;
public:
	bool AddEdge(Vertex *, double weight);
	void setLabel(int label);

};

#endif