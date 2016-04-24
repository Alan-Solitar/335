#include <iostream>
#include <fstream>
#include <sstream>
#include "AdjacencyList.h"

using namespace std;

void CreateGraph(AdjacencyList &graph, const string &graph_filename) {
  ifstream reader(graph_filename);
  string line = "";
  int num_vertices=0;
  reader >>num_vertices;
  graph.CreateVertices(num_vertices);
  int vertex_label=0;
  while(getline(reader,line)) {
    sstream stream(line);
    int vertex_label << stream;
    int adj_vertex_label;
    int edge_weight;
    while(adj_vertex_label << stream) {
    	edge_weight << stream;
    	graph.AddEdge(vertex_label, adj_vertex_label,edge_weight);
    } 

  }
  reader.close();
}

void QueryGraph(AdjacencyList &graph, const string &query_filename ) {
	ifstream reader(query_filename);
	int origin_label, dest_label;
	while(reader >> origin_label) {
		reader >> dest_label;
	}
	reader.close();
}
int main(int argc, char **argv) {
	if (argc != 3) {
		cout << "Usage: " << argv[0] << " <graphfilename> <queryfilename>" << endl;
		return 0;
	}
	const string graph_filename = argv[1];
	const string query_filename = argv[2];
  	AdjacencyList graph;
  	CreateGraph(graph,graph_filename);
  	QueryGraph(graph,query_filename);
 }