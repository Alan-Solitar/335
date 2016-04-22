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
  while(getline(reader,line)) {
    sstream stream(line);
  }
  reader.close();
}
int main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <graphfilename> <queryfilename>" << endl;
    return 0;
 
  AdjacencyList graph;
 }