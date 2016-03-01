#include <iostream>
#include <string>
#include "BinarySearchTree.h"
#include "AvlTree.h"
#include fstream;
using namespace std;

// Sample main for program testTrees
int
main(int argc, char **argv) {
  if (argc != 4) {
    cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename> <tree-type>" << endl;
    return 0;
  }
  string db_filename(argv[1]);
  string query_filename(argv[2]);
  string param_tree(argv[3]);
  cout << "Input file is " << db_filename << ", and query file is " << query_filename << endl;
  if (param_tree == "BST") 
  {
    cout << "I will run the BST code " << endl;
    // Insert code for testing a BST tree.
    // ...
	BinarySearchTree bTree();
	string db_line;
	size_t end;
	string sequence;
	ifstream reader(db_filename);
	while (getline(reader,db_line)) 
	{
		end = db_line.find("//");
		size_t split = db_line.find('/');
		string acronym = db_line.substr(0,split);
		for(int i=split;i<db_line.size();i++)
		{
			if(db_line[i]=='/')
			{
				//Because of this check we can treat '/' and "//"" the same way
				if(!sequence.empty())
				{
				SequenceMap new_sequence_map(sequence,acronym);
					bTree.insert(new_sequence_map);
				}
				sequence = "";
			}
			else
			{
				sequence+=i;
			}
		}
		
	
	} 
  else if (param_tree == "AVL")\
  {
    cout << "I will run the AVL code " << endl;
    // Insert code for testing an AVL tree.
    // ...
	AvlTree() aTree;
  } else {
    cout << "Uknown tree type " << param_tree << " (User should provide BST, or AVL)" << endl;
  }
  return 0;
}
