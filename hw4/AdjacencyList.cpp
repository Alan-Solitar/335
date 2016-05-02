#include "AdjacencyList.h"
#include <iostream>
#include <queue>

//Written by Alan Solitar

using namespace std;
void AdjacencyList::CreateVertices(int num_vertices) {
	//initialize
	num_edges_ = 0;
	num_vertices_ = num_vertices;
	min_out_degree_=0;
	max_out_degree_ = 0;
	for(int i=0;i<num_vertices;++i) {
		Vertex* vertex = new Vertex(i+1);
		this->vertices_.push_back(vertex);
	}

}

void AdjacencyList::AddEdge(int origin_vertex, int dest_vertex, double weight) {
	Vertex * v1 = vertices_[origin_vertex-1];
	Vertex * v2 = vertices_[dest_vertex-1];
	v1->AddEdge(v2, weight);
	++num_edges_;
	if(v1->out_degree_ > max_out_degree_) {
		max_out_degree_ = v1->out_degree_;
	}
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

bool AdjacencyList::HasEdge(int origin_vertex, int dest_vertex) {
	Vertex * vert = vertices_[origin_vertex - 1];
	bool edge_found = false;
	for(auto &i: vert->adj_) {
		if(i.first->label_==dest_vertex) {
			edge_found = true;
		}
	}
	return edge_found;
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
	start->distance_known_=false;

	priority_queue<Vertex*, vector<Vertex*>, compareVertex> vertex_queue;
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
				i.first->previous_weight_ = i.second;
			}
		}
	}  

	PrintPath(starting_vertex,dest_vertex);
}
void AdjacencyList::PrintPath(int starting_vertex, int dest_vertex) {
	vector<int> path;
	Vertex * current = vertices_[dest_vertex-1];
	path.push_back(dest_vertex);
	double path_weight=0;
	while(current!=nullptr) {
		path.push_back(current->label_);
		path_weight+=current->previous_weight_;
		current = current->previous_;
	
	}
	cout << dest_vertex << ": ";
	for(int i = path.size()-1; i>0;--i) {
		cout << path[i] << ",";
	}
	cout << " Weight: " <<path_weight << endl;
	
}

int AdjacencyList::GetMinOutDegree() {
	min_out_degree_ = vertices_[0]->out_degree_;
	cout<<"min: " <<min_out_degree_<<endl; 
	for(auto &i: vertices_) {
		cout <<i->label_ << " " <<i->out_degree_<<endl;
		if(i->out_degree_ < min_out_degree_) {
			cout <<i->label_ << " " <<i->out_degree_<<endl;
			min_out_degree_ = i->out_degree_;
		}
	}
	return min_out_degree_;
}

int AdjacencyList::GetMaxOutDegree() {
	return max_out_degree_;
}

double AdjacencyList::GetAverageOutDegree() {
	int sum = 0;
	for(auto &i:vertices_) {
			sum+=i->out_degree_;
	}
	return sum/num_vertices_;
}

int AdjacencyList::GetNumEdges() {
	return num_edges_;
}
