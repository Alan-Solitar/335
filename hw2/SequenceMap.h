#ifndef SEQUENCE_MAP_H
#define SEQUENCE_MAP_H
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Written by Alan Solitar
class SequenceMap {
public:
	//constructors
	SequenceMap(const string &a_rec_seq, const string &an_enz_acro);
	//all default
	SequenceMap(const SequenceMap &rhs)=default;
	SequenceMap& operator=(const SequenceMap &rhs)=default;
	SequenceMap(SequenceMap &&rhs)=default;
	SequenceMap &operator=(SequenceMap &&rhs)=default;
	~SequenceMap() =default;

	friend ostream &operator<<(ostream &out, const SequenceMap &rhs);

	bool operator<(const  SequenceMap &rhs) const;
	void Merge(const SequenceMap &other_sequence);

	//print function to print contents of SequenceMap
	void Print(ostream &out) const;

private:
	string recognition_sequence_;
	vector<string> enzyme_acronym_;
};

#include "SequenceMap.cpp"
#endif