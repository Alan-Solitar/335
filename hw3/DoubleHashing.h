#ifndef CSCI335_DOUBLE_HASHING
#define CSCI335_DOUBLE_HASHING

#include <vector>
#include <string>
#include "QuadraticProbing.h"
using namespace std;

template <typename HashedObj>
class DoubleHashTable: public HashTable<HashedObj> {

protected:

int FindPos(const HashedObj & x) override {
  int R=13; //13 worked the best in my tests
  int offset = hash2(x,R);
  int current_pos = this->InternalHash(x);
  this->number_probes_=1;
  while (this->array_[current_pos].info_ != this->kEmpty &&
	this->array_[current_pos].element_ != x ) {
  // Compute ith probe.
  current_pos += offset;
  ++this->number_probes_; 
  if (current_pos >= this->array_.size())
	   current_pos -= this->array_.size( );
  }
  this->number_collisions_+=this->number_probes_-1;
  return current_pos;

}
private:
	int hash2(const string &key, int R) {
    static hash<HashedObj> hf;
    return R - (hf(key) % R);
	}
 	


};
#endif  // CSCI335_DOUBLE_HASHING