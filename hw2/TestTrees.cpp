#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include "SequenceMap.h"
#include "BinarySearchTree.h"
#include "AvlTree.h"

using namespace std;

template <typename TreeType>
void TestQueryTree( const TreeType &a_tree, const string &db_filename) {
  // Code for testing
  a_tree.printTree();
}

template <typename TreeType>
void RemoveSequences( TreeType &a_tree, const string &query_filename)
{
  string db_line;
  int recursion_counter=0, successful_removals=0;
  ifstream reader(query_filename);
  while(reader >>db_line) {
    if(reader>>db_line) {
      SequenceMap new_sequence_map(db_line," ");
      //cout << "db_line: "<<db_line<<endl;
      bool is_found = a_tree.remove(new_sequence_map,recursion_counter);
      if(is_found)
        ++successful_removals;
    }
  }
  cout<< "Recursion Counter(Remove): "<<recursion_counter<<endl;
  cout<< "Successful Removals: "<<successful_removals<<endl;
}

//function to query for the sequences in sequences.txt
template <typename TreeType>
void query( TreeType &a_tree, const string &query_filename) {
  string db_line;
  int recursion_counter=0, successful_queries=0;
  ifstream reader(query_filename);
  while(reader>>db_line) {

    SequenceMap new_sequence_map(db_line," ");
    //cout<<new_sequence_map;
    cout << "db_line: "<<db_line<<endl;
    bool is_found = a_tree.contains(new_sequence_map,recursion_counter);
    if(is_found)
      ++successful_queries;
  }
  cout<< "Recursion Counter(Contains): "<<recursion_counter<<endl;
  cout<< "Sucessful Queries: "<<successful_queries<<endl;
}

//function to Calculate the Average Depth.
template <typename TreeType>
void CalculateAverageDepth(TreeType &a_tree) {
  int nodes = a_tree.CalculateNodes();
  cout<<"Nodes: "<<nodes<<endl;
  int total_depth = a_tree.CalculateDepth();
  cout <<"Total Depth: "<< total_depth<<endl;
  double average_depth = (double)total_depth/nodes;
  cout<<"Average Depth: "<<average_depth<<endl;
  double log_two = log2(nodes);
  cout<<"Log2(Nodes): "<<log_two<<endl;
  double depth_to_log2 = average_depth/log_two; 
  cout<<"Average Depth to Log2(Nodes): "<<depth_to_log2<<endl;
}

template <typename TreeType>
void ParseAndBuild(TreeType &a_tree, string &db_filename) {
  string db_line="";
  ifstream reader(db_filename);
  int i=0;
  //skip the header
  while(++i<=10){
    getline(reader,db_line);
  }

  while (getline(reader,db_line)) {
    size_t split = db_line.find('/');
    string acronym = db_line.substr(0,split);
    string sequence = "";
    for(size_t i=split+1;i<db_line.size();i++){
      if(db_line[i]=='/'){
        //Because of this check we can treat '/' and "//"" the same way
        if(!sequence.empty()){
          SequenceMap new_sequence_map(sequence,acronym);
          a_tree.insert(new_sequence_map);
        }
        sequence = "";
      }else {
        sequence+=db_line[i];
      }
    }
  }
  reader.close(); 
}
// Sample main for program testTrees
int main(int argc, char **argv) {
  if (argc != 4) {
    cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename> <tree-type>" << endl;
    return 0;
  }
  string db_filename(argv[1]);
  string query_filename(argv[2]);
  string param_tree(argv[3]);
  cout << "Input file is " << db_filename << ", and query file is " << query_filename << endl;
  if (param_tree == "BST") {
    cout << "I will run the BST code " << endl;
    // Insert code for testing a BST tree.
    BinarySearchTree<SequenceMap> a_tree;
    ParseAndBuild(a_tree,db_filename);
    CalculateAverageDepth(a_tree);
    query(a_tree,query_filename);
    RemoveSequences(a_tree,query_filename);
	} else if (param_tree == "AVL"){
    cout << "I will run the AVL code " << endl;
    // Insert code for testing an AVL tree.
    AvlTree<SequenceMap> a_tree;
    ParseAndBuild(a_tree,db_filename);
    //TestQueryTree(a_tree, db_filename);
    CalculateAverageDepth(a_tree);
    query(a_tree,query_filename);
    RemoveSequences(a_tree,query_filename);
  } else {
    cout << "Uknown tree type " << param_tree << " (User should provide BST, or AVL)" << endl;
  }
  return 0;
}

