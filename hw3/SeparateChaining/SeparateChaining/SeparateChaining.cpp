// Implements Separate Chaining.

template <typename HashedObj>
bool HashTable<HashedObj>::Contains(const HashedObj &x) const {
  // Find the appropriate list.
  auto &which_list = the_lists_[InternalHash(x)];
  // Search within the list.
  return find(begin(which_list), end(which_list), x) != end(which_list);
}
  
template <typename HashedObj>
void HashTable<HashedObj>::MakeEmpty() {
  for (auto &this_list : the_lists_)
    this_list.clear();
}
  
template <typename HashedObj>
bool HashTable<HashedObj>::Insert(const HashedObj & x) {
  // Find the appropriate list.
  auto &which_list = the_lists_[InternalHash(x)];
  // Search within the list.
  if (find(begin(which_list), end(which_list), x) != end(which_list))
    return false;
  // Insert at the end of the list.
  which_list.push_back(x);
  // Rehash; see Section 5.5
  if (++current_size_ > the_lists_.size())
    Rehash();
    return true;
}
    
template <typename HashedObj>
bool HashTable<HashedObj>::Insert(HashedObj && x) {
  // Find the appropriate list.
  auto &which_list = the_lists_[InternalHash(x)];
  // Search within the list.
  if (find(begin(which_list), end(which_list), x) != end(which_list))
    return false;
  // Insert at the end of the list, using rvalue reference.
  which_list.push_back(std::move(x));
  // Rehash; see Section 5.5
  if (++current_size_ > the_lists_.size())
    Rehash();
  return true;
}

template <typename HashedObj>
bool HashTable<HashedObj>::Remove(const HashedObj & x) {
  // Find the appropriate list.
  auto &which_list = the_lists_[InternalHash(x)];
  // Search within the list.
  auto itr = find(begin(which_list), end(which_list), x);
  if (itr == end(which_list))
    return false;
  // Remove.
  which_list.erase(itr);
  --current_size_;
  return true;
}

template <typename HashedObj>
void HashTable<HashedObj>::Rehash() {
  vector<list<HashedObj>> old_lists = the_lists_;
  // Create new double-sized, empty table.
  the_lists_.resize(NextPrime(2 * the_lists_.size()));
  for (auto & this_list: the_lists_)
    this_list.clear();
  
  // Initialize number of elements in hash table to 0.
  current_size_ = 0;
  // Copy from current table to larger table.
  for (auto & this_list : old_lists) {
    for (auto & x : this_list )
      Insert(std::move(x));
  }
}
