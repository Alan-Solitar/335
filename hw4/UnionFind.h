#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <vector>
#include "Vertex.h"
using namespace std;

class UnionFind {
private:
	vector<int> vertices_;
public:
	int find(int x);
	void Union(int vert1, int vert2);

	
};

#endif