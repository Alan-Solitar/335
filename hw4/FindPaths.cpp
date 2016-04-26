#include "AdjacencyList.h"
#include "Vertex.h"
#include <queue>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>



Dijkstra(int starting_vertex, AdjacencyList &graph ) {
	

}
RunAll() {

}
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
	cout << AdjacencyList::INFINITY;
}