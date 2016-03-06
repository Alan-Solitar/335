//function to query for the sequences in sequences.txt
template <typename TreeType>
void query( TreeType &a_tree, const string &query_filename) {
  string db_line="";
  int recursion_counter=0, sucessful_queries=0;
  ifstream reader(query_filename);
  while(getline(reader,db_line)) {
    SequenceMap new_sequence_map(db_line," ");
    //cout << "db_line: "<<db_line<<endl;
    bool is_found = a_tree.contains(new_sequence_map,recursion_counter);
    if(is_found)
      ++sucessful_queries;
  }
  cout<< "Recursion Counter(Contains): "<<recursion_counter<<endl;
  cout<< "Sucessful Queries: "<<sucessful_queries<<endl;
}