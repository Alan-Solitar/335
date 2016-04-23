#ifndef VERTEX_H
#define AVERTEX_H
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
	bool add_edge(Vertex *, double weight);


};

#endif