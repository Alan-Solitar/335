#ifndef VERTEX_H
#define AVERTEX_H
#include <utility>
#include <vector>

using namespace std;

class Vertex {

private:
	vector<pair<Vertex, double>> adj_;
	bool visited_;
	bool known_;
public:
	bool add_edge(int vertex_index, double weight);


};

#endif