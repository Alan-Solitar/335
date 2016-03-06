template <typename TreeType>
void query( TreeType &a_tree, const string &query_filename) {
  string db_line;
  int recursion_counter=0, sucessful_queries=0;
  ifstream reader(query_filename);
  while(getline(reader,db_line, '\n')) {
    SequenceMap new_sequence_map(db_line,"");
    //cout << db_line<<endl;
    bool is_found = a_tree.contains(&new_sequence_map,recursion_counter);
    if(is_found)
      ++sucessful_queries;
  }
  cout<< "Recursion Counter: "<<recursion_counter<<endl;
  cout<< "sucessful_queries: "<<sucessful_queries<<endl;
}

bool contains( const Comparable & x, int &recursion_counter ) const {
        return contains( x, root_ ,recursion_counter);
    }
	
	  bool contains( const Comparable & x, BinaryNode *t, int &recursion_counter ) const {
        if( t == nullptr )
            return false;
        else if( x < t->element_ ) {
             ++recursion_counter;
            return contains( x, t->left_ ,recursion_counter);
        }
        else if( t->element_ < x ) {
             ++recursion_counter;
            return contains( x, t->right_ ,recursion_counter);
        }
        else
        {
            return true;
            cout<<"match"<<endl;   // Match
        }
    }