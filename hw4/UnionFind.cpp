#include "UnionFind.h"

UnionFind::UnionFind(max_vertices) {
	for(int i=0;i<=max_vertices;++=i) {
		vertices_.push_back(-1);
	}
}
int UnionFind::find(int x) {
	if(s[x] <0)
		return x;
	else
		return s[x] = find(s[x]);
}

void UnionFind::Union(int vert1, int vert2) {
	if(vertices_[vert1] < vertices_[vert2]) {
		vertices_[vert1] = vert2;
	}
	else {
		if(vertices_[root1] ==vertices_[root2]) {
			vertices_[root1]--;	
		}
		vertices_[root2] = root1;
	}
}