#include "AdjacencyList.h";
#include "Vertex.h"
#include <queue>
#include <fstream>
#include <sstream>


Dijkstra() {
}
RunAll() {

}
void CreateGraph(AdjacencyList &graph, const string &graph_filename) {
  ifstream reader(graph_filename);
  string line = "";
  int num_vertices=0;
  reader >> num_vertices;
  graph.CreateVertices(num_vertices);
  int vertex_label, adj_vertex_label, edge_weight;
  while(getline(reader,line)) {
    stringstream stream(line);
    stream >> vertex_label;
    while(stream >> adj_vertex_label) {
    	stream >> edge_weight;
    	graph.AddEdge(vertex_label, adj_vertex_label,edge_weight);
    } 
  }
  reader.close();
}

int main() {
	AdjacencyList graph;
	G
}