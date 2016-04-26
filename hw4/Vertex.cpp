#include "Vertex.h"
#include "AdjacencyList.h"
#include <iostream>


Vertex::Vertex(int label) {
	label_ = label;
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