#include "QuadraticProbing.h"
#include "LinearProbing.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



template <typename HashTableType>
void
TestFunctionForHashTable(HashTableType &hash_table, const string &words_filename, const string &query_filename) {
  cout << "TestFunctionForHashTables..." << endl;
  cout << "Words filename: " << words_filename << endl;
  cout << "Query filename: " << query_filename << endl;
  hash_table.MakeEmpty();  // Do not have to do it if you pass empty hash table.
  // Test it...
}

// Sample main for program CreateAndTestHash
int
main(int argc, char **argv) {
  if (argc != 4) {
    cout << "Usage: " << argv[0] << " <wordsfilename> <queryfilename> <flag>" << endl;
    return 0;
  }
  
  const string words_filename(argv[1]);
  const string query_filename(argv[2]);
  const string param_flag(argv[3]);
  cout << "Input words file is " << words_filename << ", and query file is " << query_filename << endl;
  if (param_flag == "linear") {
    cout << "I will run the linear hashing code " << endl;
    LinearHashTable<string> linear_probing_table;
    // Run the linear table.
  } else if (param_flag == "quadratic") {
    cout << "I will run the quadratic hashing code " << endl;
    HashTable<string> quadratic_probing_table;
    TestFunctionForHashTable(quadratic_probing_table, words_filename, query_filename);    
  } else if (param_flag == "double") {
    cout << "I will run the double hashing code " << endl;
    // ..code for double Hash
    // ..By calling TestFunctionForHashTable()
  } else if (param_flag == "chaining") {
    cout << "I will run the seperate chaining hashing code " << endl;
  } else {
    cout << "Uknown tree type " << param_flag << " (User should provide linear, quadratic, or double)" << endl;
  }
  return 0;
}
