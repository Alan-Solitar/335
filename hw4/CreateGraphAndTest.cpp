#include "AdjacencyList.h";
#include <iostream>
#include <fstream>
#include <sstream>



void CreateGraph(AdjacencyList graph, const string &words_filename {
  ifstream reader(words_filename);
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
    } 

  }
  reader.close();
}
int main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <graphfilename> <queryfilename>" << endl;
    return 0;
 
  AdjacencyList graph;
 }