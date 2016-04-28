#include "AdjacencyList.h"
#include <iostream>
#include <queue>


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

void AdjacencyList::Dijkstras(int starting_vertex, int dest_vertex) {
	//initialize all vertices
	for(auto &i:vertices_) {
		i->visited_=false;
		i->distance_=INFINITY;
	}
	Vertex* start = vertices_[starting_vertex-1];
	//need some sort of outer loop
	start->distance_ = 0;
	start->visited_=true;
	start->distance_known_=true;

	priority_queue<Vertex*> vertex_queue;
	vertex_queue.push(start);
	
	for(; ;) {
		Vertex * v;
		//find smallest unkown distance vertex
		bool success = false;    
		while(!vertex_queue.empty() && !success) {
		v=vertex_queue.top();
		vertex_queue.pop();    
		if(!v->distance_known_)   
		success=true;    
		}    
		if(!success) break;  

		for(auto &i: v->adj_) {
			if(v->distance_ + i.second < i.first->distance_) {
				i.first->distance_ = v->distance_ + i.second; 
				vertex_queue.push(i.first);
				i.first->previous_ = v;
			}
		}
	}  
	PrintPath(starting_vertex,dest_vertex);
}
void AdjacencyList::PrintPath(int starting_vertex, int dest_vertex) {
	vector<int> path;
	Vertex * current = vertices_[dest_vertex-1];
	path.push_back(dest_vertex);
	while(current->label_ != starting_vertex) {
		path.push_back(current->label_);
		cout << current->label_;
		current = current->previous_;
	}
	cout << endl;
	
}
