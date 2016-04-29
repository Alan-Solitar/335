#include <cstdlib>
#include <ctime>
#include "AdjacencyList.h"

using namespace std;

srand(time(0)); //use current time as seed for random generator
const int maximum_value = 1000;
const int i1 = rand() % maximum_value + 1;
const int i2 = rand() % maximum_value + 1;
graph.AddEdge(i1,i2,0);
graph.AddEdge(i2,i,0);





int main(int argc, char **argv) {
	if (argc != 2) {
		cout << "Usage: " << argv[0] << " <maximum_number_of_nodes>" << endl;
		return 0;
	}
	const int MAX_NODES = argv[1];
	AdjacencyList graph;
	graph.CreateVertices(MAX_NODES);