#include "UnionFind.h"
#include <iostream>
#include <stdexcept>


UnionFind::UnionFind(int max_vertices) {
	number_of_sets_ = max_vertices;
	for(int i=0;i<=max_vertices;++i) {
		vertices_.push_back(-1);
	}
}
int UnionFind::find(int x) {
	if(vertices_[x] < 0 || vertices_[x] == x)
		return x;
	else if(vertices_[x] < (int)vertices_.size())
		return vertices_[x] = find(vertices_[x]);
	else
		throw std::invalid_argument( "invalid index" );
}

void UnionFind::Union(int vert1, int vert2) {
	int root1 = find(vert1);
	int root2 = find(vert2);
	cout << "set:" <<number_of_sets_<<endl;
	number_of_sets_--;
	if(vertices_[root1] < vertices_[root2]) {
		vertices_[root1] = root2;
		
	}
	else {
		if(vertices_[root1] ==vertices_[root2]) {
			vertices_[root1]--;	
		}
		vertices_[root2] = root1;
	}
}

int UnionFind::GetNumberOfSets() {
		return number_of_sets_;
}
