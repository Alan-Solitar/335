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
	Vertex * vert = vertices_[origin_vertex - 1];
	bool edge_found = false;
	for(auto &i: vert->adj_) {
		if(i.first->label_==dest_vertex) {
			edge_found = true;
			cout << "Edge " <<origin_vertex << " " <<dest_vertex <<
				" Found: Weight = " << i.second << endl;
		}
	}
	if(!edge_found) {
		cout << "Edge " <<origin_vertex << " " <<dest_vertex << " Not Found"<<endl;
	}
}

size_t AdjacencyList::GetSize() {
	return vertices_.size();
}

void AdjacencyList::Dijkstra(int starting_vertex, int dest_vertex) {

	for(auto &i:vertices_) {
		i.visited_=false;
		i.distance=INFINITY;
	}
	Vertex* current = vertices_[starting_vertex-1];
	//need some sort of outer loop
	current->distance = 0;
	current->visited_=true;
	current->distance_known_=true;

	priority_queue<Vertex*> vertex_queue;
	vertex_queue.insert(starting_vertex);
	
for(; ;) {
	Vertex v*;
	bool success = false;    
	while(!vertex_queue.isEmpty()&& !success) {
	v=vertex_queue.deleteMin();    
    if(!v->distance_known_)   
     success=true;    
}    
if(!sucess) break;  

	for(auto &i: v->adj_) {
		if(v.distance_ + i.second < i.distance_) {
			i.first->distance_ = v.distance_ + i.second; 
			vertex_queue.insert(i);
		}
	}
}
       
if(!found_known) break;    

Vertex* AdjacencyList::FindMinDistVertex() {

}