#ifndef SEQUENCEMAP_H
#define SEQUENCEMAP_H
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SequenceMap
{
public:
	//constructors
	SequenceMap();
	SequenceMap(const string &a_rec_seq, const string &an_enz_acro);
	//all default
	SequenceMap(const SequenceMap &rhs)=default;
	SequenceMap& operator=(const SequenceMap &rhs)=default;
	SequenceMap(SequenceMap &&rhs)=default;
	SequenceMap &operator=(SequenceMap &&rhs)=default;
	~SequenceMap() =default;

	friend ostream &operator<<(ostream &out, const SequenceMap &rhs);

	bool operator<(const  SequenceMap &rhs) const;
	void merge(SequenceMap &other_sequence);

	//print function to print contents of SequenceMap
	void print(ostream &out) const;

private:
	string recognition_sequence_;
	vector<string> enzyme_acronym_;
};

#endif


