#ifndef CSCI335_LINEAR_PROBING_H_
#define CSCI335_LINEAR_PROBING_H_

#include <vector>
#include "QuadraticProbing.h"
using namespace std;

template <typename HashedObj>
class LinearHashTable: public HashTable<HashedObj> {

protected:
int FindPos(const HashedObj & x) override {
  int offset = 1;
  int current_pos = this->InternalHash(x);
  this->number_probes_=1;
  while (this->array_[current_pos].info_ != this->kEmpty &&
	this->array_[current_pos].element_ != x ) {
    // Compute ith probe.
    ++this->number_probes_;
    current_pos += offset;  
    if (current_pos >= this->array_.size())
    	current_pos -= this->array_.size( );
  }
  this->number_collisions_+=this->number_probes_-1;
  return current_pos;
}



};
#endif  // CSCI335_LINEARPROBING_H_