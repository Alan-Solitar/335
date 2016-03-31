#ifndef CSCI335_HASHING_SEPARATE_CHAINING_H_
#define CSCI335_HASHING_SEPARATE_CHAINING_H_


#include <vector>
#include <list>
#include <algorithm>
using namespace std;


// Unnamed namespace for stand-alone functions.
// Place them in cpp file when using one.

namespace {
// Internal method to test if a positive number is prime.
// Not an efficient algorithm.
/*
bool IsPrime(int n) {
  if (n == 2 || n == 3)
    return true;
  if (n == 1 || n % 2 == 0)
    return false;
  for (int i = 3; i * i <= n; i += 2)
    if( n % i == 0 )
      return false;
  return true;
}

// Internal method to return a prime number at least as large as n.
// Assumes n > 0.
int NextPrime(int n) {
    if (n % 2 == 0) ++n;
    for( ;!IsPrime(n); n += 2) ;
    return n;
}
*/

}  // namespace


// SeparateChaining Hash table class. 
// Assumes that there is a class hash<HashedObj> that overloads
// the () operator returning a size_t.
// Sample usage:
//  SeparateHashTable<string> a_hash_table;
//  while (..getting string a_string..)
//    a_hash_table.Insert(a_string);
//  const b_string = "A given string";
//  if (a_hash_table.Contains(b_string))
//     cout << b_string << " in table " << endl;
//  else
//     cout << b_string << " not in table " << endl;
//  const c_string = "Another string";
// if (a_hash_table.Remove(c_string))
//    cout << "Removed " << c_string << endl;
// else
//    cout << c_string << " Not in the table" << endl;
// a_hash_table.MakeEmpty();  // Clears everything.
template <typename HashedObj>
class SeparateHashTable {
 public:
  explicit SeparateHashTable(int size = 101) : current_size_{0} 
  { MakeEmpty(); the_lists_.resize(101); }

  SeparateHashTable(const SeparateHashTable &a_hash_table) = default;
  SeparateHashTable(SeparateHashTable &&a_hash_table) = default;
  SeparateHashTable &operator=(const SeparateHashTable &a_hash_table) = default;
  SeparateHashTable &operator=(SeparateHashTable &&a_hash_table) = default;
  ~SeparateHashTable() = default;
  
  // @param x: A given item.
  // @return true if item is in the hash table and false otherwise.
  bool Contains(const HashedObj &x);

  // Empties the hash table.
  void MakeEmpty();

  // @param x: Item to insert.
  // @return true if insertion was succesfull, false otherwise
  //   (i.e. when x is already in the hash table).
  // Insertion may lead to rehashing.
  bool Insert(const HashedObj & x);

  // Same as above Insert for x being an rvalue reference.
  bool Insert(HashedObj && x);

  // @param x: Item to be removed.
  // @return true if succesfull, false if x is not found in the
  //   hash table.
  bool Remove(const HashedObj & x);
  unsigned int Size();
  unsigned int TableSize();
  unsigned int getCollisions();
  unsigned int getProbes();
 private:
  // The vector of lists. 
  // TableSize is the_lists_.size().
  vector<list<HashedObj>> the_lists_;   
  // The number of elements in the hash table.
  unsigned int  current_size_;
  unsigned int number_collisions_;
  unsigned int number_probes_;

  // Performs rehashing by creating a new hash table having
  // size being equal to the next prime greater than or equal
  // to the double of the current table size.
  // Note that table size is _array.size();
  void Rehash();

  // @param x: a given item.
  // Returns the hash value of x.
  // Assumes that a class hash<HashedObj> has been defined,
  // with an overloaded () operator.
  size_t InternalHash(const HashedObj & x) const {
    static hash<HashedObj> hf;
    return hf(x) % the_lists_.size( );
  }

  template<class InputIterator, class T, class H>
  friend InputIterator FindAndCountProbes (H &hashtable, InputIterator first, InputIterator last, const T& val) {
    hashtable.number_probes_ = 1;
    while (first!=last) {
      if (*first==val) 
        return first;
      ++first;
      ++hashtable.number_collisions_;
      ++hashtable.number_probes_;
  }
    return last;  
  }
  
};

#include "SeparateChaining.cpp"  // For template compilation.
#endif  // CSCI335_HASHING_SEPARATE_CHAINING_H_
