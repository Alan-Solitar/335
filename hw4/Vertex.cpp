#include "Vertex.h"
#include "AdjacencyList.h"
#include <iostream>


Vertex::Vertex(int label) {
	label_ = label;
	distance_known_ = false;
	visited_ = false;
}
bool Vertex::AddEdge(Vertex * vertex, double weight) {
	cout << "adding" <<this->label_ <<" "<< vertex->label_ << " "<<weight<<endl;
	pair<Vertex *, double> edge(vertex, weight);
	adj_.push_back(edge);
}
/*
void Vertex::SetLabel(int label) {
	label_ = label;
}
*/
void Vertex::SetVisted() {
	visited_=true;
}
void Vertex::SetKnown() {
	distance_known_=true;
}
void ResetVertexBools() {
	distance_known_=false;
	visited_=false;
	previous_ = nullptr;
}