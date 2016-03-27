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
  int offset = hash2(x,this->TableSize());
  int current_pos = this->InternalHash(x);
  int start_pos = current_pos;
  bool isCollision=false;
  while (this->array_[current_pos].info_ != this->kEmpty &&
	this->array_[current_pos].element_ != x ) {
    // Compute ith probe.
    isCollision=true;
    current_pos += offset;  
      if (current_pos >= this->array_.size())
	current_pos -= this->array_.size( );
    }
  if(isCollision)
      ++this->number_collisions_;
  if(current_pos==start_pos) {
  	this->Rehash();
  }
  return current_pos;
}
private:
	int hash2(const string &key, int table_size) {
		size_t hash_value = 0;
		for (char ch : key)
			hash_value = 37 * hash_value + ch;
		return hash_value % table_size;
	}
 	


};
#endif  // CSCI335_DOUBLE_HASHING