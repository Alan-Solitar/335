#include "AdjacencyList.h"
#include <iostream>

using namespace std;
void AdjacencyList::CreateVertices(int num_vertices) {
	for(int i=0;i<num_vertices;++i) {
		Vertex* vertex = new Vertex(i+1);
		this->vertices_.push_back(vertex);
	}

}

void AdjacencyList::AddEdge(int origin_vertex, int dest_vertex, double weight) {
	Vertex * v1 = vertices_[origin_vertex-1];
	Vertex * v2 = vertices_[dest_vertex-1];
	v1->AddEdge(v2, weight);
}

void AdjacencyList::CheckEdge(int origin_vertex, int dest_vertex) {
	Vertex * vert = vertices_[origin_vertex + 1];
	for(auto &i: vert->adj_) {
		if(i.first->label_==dest_vertex) {
			cout << "Edge Exists: Weight = " << i.second << endl;
		}
	}
}

size_t AdjacencyList::GetSize() {
	return vertices_.size();
}