#include "AdjacencyList.h"
#include "Vertex.h"
#include <queue>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>


//Run Dijktras on a graph for all destination vertices
RunDijkstras(AdjacencyList &graph, int starting_vertex ) {
	priority_queue<Vertex *> vertex_queue;
	Vertex* current = vertices_[starting_vertex-1];
	int size = graph.Size();
	if(size == 0 {
		cout << "Graph is empty: Please create a graph before running Dijkstras" << endl;
	} 
	else {
		for(int i=1;i<=size;++i) {
			//i is destination vertex
			graph.Dijkstras(starting_vertex, i)
		}

	}
}

//Create graph object from file
void CreateGraph(AdjacencyList &graph, const string &graph_filename) {
  ifstream reader(graph_filename);
  string line = "";
  int num_vertices=0;
  reader >> num_vertices;
  graph.CreateVertices(num_vertices);
  int vertex_label, adj_vertex_label;
  double edge_weight;
  while(getline(reader,line)) {
    stringstream stream(line);
    stream >> vertex_label;
    while(stream >> adj_vertex_label) {
    	stream >> edge_weight;
    	graph.AddEdge(vertex_label, adj_vertex_label,edge_weight);
    } 
  }
  reader.close();
  cout <<"we're done creating"<<endl;
}

int main(int argc, char **argv) {
	if (argc != 3) {
		cout << "Usage: " << argv[0] << " <graphfilename> <starting_vertex>" << endl;
		return 0;
	}
	const string graph_filename = argv[1];
	const int starting_vertex = atoi(argv[2]);
	AdjacencyList graph;
	CreateGraph(graph, graph_filename);
	RunDijkstras(graph,starting_vertex);
}