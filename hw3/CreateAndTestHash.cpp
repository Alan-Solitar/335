#include "QuadraticProbing.h"
#include "LinearProbing.h"
#include "DoubleHashing.h"
#include "SeparateChaining.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


template <typename HashTableType> 
void CreateHashTable(HashTableType &hash_table, const string &words_filename, const string &query_filename) {
  ifstream reader(words_filename);
  string line = "";
  int total_inserts=0;
  while(getline(reader,line)) {
    hash_table.Insert(line);
    ++total_inserts;
  }
  cout << total_inserts <<endl;
  /*
  for(auto &i: hash_table) {
    cout << i <<endl;
  }
  */
  reader.close();
}
template <typename HashTableType> 
void QueryTable(HashTableType &hash_table, const string &words_filename, const string &query_filename) {
  ifstream reader(query_filename);
  string line = "";
  bool found = false;
  int total_inserts=0;
  while(getline(reader,line)) {
    found = hash_table.Contains(line);
    cout << "Probes" <<hash_table.getProbes()<<endl;
    if(found)
      cout<<"found"<<endl;
    else
      cout<<"not found" <<endl;
  }
  //cout << total_inserts <<endl;
  /*
  for(auto &i: hash_table) {
    cout << i <<endl;
  }
  */
  reader.close();
}
template <typename HashTableType> 
void PrintStatistics(HashTableType &hash_table) {
    int elements = hash_table.Size(), table_size = hash_table.TableSize();
    int collisions = hash_table.getCollisions();
    cout << "Number of Elements in Table: " <<elements<<endl;
    cout << "Table Size: " <<table_size<<endl;
    cout << "Load Factor: " <<double(elements)/table_size << endl;
    cout << "Collisions: " << collisions << endl;
    cout << "Average Collisions: " << double(collisions)/elements;

}

template <typename HashTableType>
void TestFunctionForHashTable(HashTableType &hash_table, const string &words_filename, const string &query_filename) {
  cout << "TestFunctionForHashTables..." << endl;
  cout << "Words filename: " << words_filename << endl;
  cout << "Query filename: " << query_filename << endl;
  hash_table.MakeEmpty();  // Do not have to do it if you pass empty hash table.
  // Test it...
}

// Sample main for program CreateAndTestHash
int main(int argc, char **argv) {
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
    CreateHashTable(linear_probing_table,words_filename,query_filename);
    PrintStatistics(linear_probing_table);
    QueryTable(linear_probing_table,words_filename,query_filename);
    // Run the linear table.
  } else if (param_flag == "quadratic") {
    cout << "I will run the quadratic hashing code " << endl;
    HashTable<string> quadratic_probing_table;
    CreateHashTable(quadratic_probing_table,words_filename,query_filename);
    PrintStatistics(quadratic_probing_table);
    QueryTable(quadratic_probing_table,words_filename,query_filename);
    //TestFunctionForHashTable(quadratic_probing_table, words_filename, query_filename);    
  } else if (param_flag == "double") {
    cout << "I will run the double hashing code " << endl;
    DoubleHashTable<string> double_hashing_table;
    CreateHashTable(double_hashing_table,words_filename,query_filename);
    PrintStatistics(double_hashing_table);

    // ..code for double Hash
    // ..By calling TestFunctionForHashTable()
  } else if (param_flag == "chaining") {
    cout << "I will run the seperate chaining hashing code " << endl;
    SeparateHashTable<string> separate_hashing_table;
    CreateHashTable(separate_hashing_table,words_filename,query_filename);
    PrintStatistics(separate_hashing_table);
    QueryTable(separate_hashing_table,words_filename,query_filename);
  } else {
    cout << "Uknown tree type " << param_flag << " (User should provide linear, quadratic, or double)" << endl;
  }
  return 0;
}
