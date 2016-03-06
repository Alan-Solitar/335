#include "BinarySearchTree.h"
#include "SequenceMap.h"
#include "AvlTree.h"
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

template <typename TreeType>
void TestQueryTree( const TreeType &a_tree, const string &db_filename) {
  // Code for testing
  a_tree.printTree();
}
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
  cout<<"Average Depth to Log2(Nodes): "<<depth_to_log2;
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
		for(size_t i=split;i<db_line.size();i++){
			if(db_line[i]=='/'){
				//Because of this check we can treat '/' and "//"" the same way
				if(!sequence.empty()){
				  SequenceMap new_sequence_map(sequence,acronym);
				  a_tree.insert(new_sequence_map);
          //cout<<new_sequence_map;
				}
				sequence = "";
			}else {
				sequence+=db_line[i];
			}
		}
	} 
}
// Sample main for program queryTrees
int main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <databasefilename> <tree-type>" << endl;
    return 0;
  }
  string db_filename(argv[1]);
  string param_tree(argv[2]);
  cout << "Input filename is " << db_filename << endl;
  
  if (param_tree == "BST") {
    cout << "I will run the BST code" << endl;
    // Insert code for testing a BST tree.
    BinarySearchTree<SequenceMap> a_tree;
    ParseAndBuild(a_tree,db_filename);
    TestQueryTree(a_tree, db_filename);
    //double average_depth = a_tree.CalculateAverageDepth();
    //cout<<average_depth;
    CalculateAverageDepth(a_tree);
  } 
  else if (param_tree == "AVL") {
    cout << "I will run the AVL code" << endl;
    //Insert code for testing an AVL tree.
    AvlTree<SequenceMap> a_tree;
    ParseAndBuild(a_tree,db_filename);
    TestQueryTree(a_tree, db_filename);
    //double average_depth = a_tree.CalculateAverageDepth();
    //cout<<average_depth;
    CalculateAverageDepth(a_tree);
  }
  else {
    cout << "Uknown tree type " << param_tree << " (User should provide BST, or AVL)" << endl;
  }
  
  return 0;
}
