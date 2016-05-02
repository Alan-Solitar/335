#include "Vertex.h"
#include "AdjacencyList.h"
#include <iostream>

//Written by Alan Solitar

Vertex::Vertex(int label) {
	label_ = label;
	distance_known_ = false;
	visited_ = false;
	previous_=nullptr;
	previous_weight_ = 0;
	out_degree_=0;

}
bool Vertex::AddEdge(Vertex * vertex, double weight) {
	bool added = false;
	pair<Vertex *, double> edge(vertex, weight);
	adj_.push_back(edge);
	added=true;
	++out_degree_;
	return added;
}

void Vertex::SetVisted() {
	visited_=true;
}
void Vertex::SetKnown() {
	distance_known_=true;
}
void Vertex::ResetVertexBools() {
	distance_known_=false;
	visited_=false;
	previous_ = nullptr;
}

