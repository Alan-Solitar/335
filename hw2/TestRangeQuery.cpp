#include <iostream>
#include <string>
#include <fstream>
#include "AvlTree.h"

using namespace std;
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

int main(int argc, char **argv) {
  if (argc != 4) {
    cout << "Usage: " << argv[0] << " <databasefilename> <string> <string2>" << endl;
    return 0;
  }
  string db_filename(argv[1]);
  string str1(argv[2]);
  string str2(argv[3]);
  cout << "Input file is " << db_filename << " ";
  cout << "String 1 is " << str1 << "   and string 2 is " << str2 << endl;
  AvlTree<SequenceMap> a_tree;
  ParseAndBuild(a_tree, db_filename);
  a_tree.PrintRange(str1, str2);

  return 0;
}
