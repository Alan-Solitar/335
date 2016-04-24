#include "AdjacencyList.h"

void AdjacenyList::CreateVertices(int num_vertices) {
	for(int i=0;i<num_vertices;++i) {
		int* vertex = new Vertex;
		vertices_.push_back(vertex);
	}

}

void AddEdge(int origin_vertex, int dest_vertex double weight) {
	Vertex * v1 = vertices[origin_vertex-1];
	Vertex * v2 = vertices[dest_vertex-1];
	v1->
}

void CheckEdge(int origin_vertex, int dest_vertex) {
	Vertex * vert = vertices_[origin_vertex + 1];
	for(auto &i: vert->adj_) {
		if(i.first->label_==dest_vertex) {
			cout << "Edge Exists: Weight = " <<i.second <<endl;
		}
	}
}