#include <iostream>
#include "QuadraticProbing.h"
using namespace std;

namespace {
void TestIntHashTable() {
  HashTable<int> h1;
  HashTable<int> h2;
  
  const int numbers = 400000;
  const int gap  =   37;
  int i;
  
  cout << "Checking... (no more output means success)" << endl;
  
  for (i = gap; i != 0; i = (i + gap) % numbers)
    h1.Insert(i);
  
  h2 = h1;
  
  for (i = 1; i < numbers; i += 2)
    h2.Remove(i);
  
  for (i = 2; i < numbers; i += 2)
    if (!h2.Contains(i))
      cout << "Contains fails " << i << endl;
  
  for (i = 1; i < numbers; i += 2) {
    if (h2.Contains(i))
      cout << "Shouldn't happen" <<  i << endl;
  }
}
  
void TestStringHashTable() {
  HashTable<string> a_hash_table;
  const vector<string> some_strings = {"string1", "string2", "hello", "there"};
  for (auto x : some_strings)
    a_hash_table.Insert(x);
  for (auto x : some_strings)
    if (!a_hash_table.Contains(x)) cerr << "SERIOUS PROBLEM WITH TestStringHashTable" << endl;
}

}  // namespace


// Overload hash function for strings.
template <>
struct hash<string> {
  size_t operator()(const string &key) {
    size_t hash_value = 0;
    for (char ch: key)
      hash_value = 37 * hash_value + ch;
    return hash_value;
  }
};

int main() {
  TestIntHashTable();
  TestStringHashTable();
  return 0;
}
