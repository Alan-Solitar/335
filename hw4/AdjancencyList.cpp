#include "AdjacencyList.h"

void AdjacenyList::CreateVertices(int num_vertices) {
	for(int i=0;i<num_vertices;++i) {
		int* vertex = new Vertex;
		vertices_.push_back(vertex);
	}

}

void add_edge(int origin_vertex, int dest_vertex double weight) {
	Vertex * v1 = vertices[origin_vertex-1];
	Vertex * v2 = vertices[dest_vertex-1];
	v1->


}