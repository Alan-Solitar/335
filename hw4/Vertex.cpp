#include "Vertex.h"
#include "AdjacencyList.h"

Vertex::Vertex(int label) {
	label_ = label;
}
bool Vertex::AddEdge(Vertex * vertex, double weight) {
	pair<Vertex *, double> edge(vertex, weight);
}
/*
void Vertex::SetLabel(int label) {
	label_ = label;
}
*/