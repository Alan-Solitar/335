// Implements Quadratic Probing.

template <typename HashedObj>
bool HashTable<HashedObj>::Contains(const HashedObj & x) {
  return IsActive(FindPos(x));
}

template <typename HashedObj>
void HashTable<HashedObj>::MakeEmpty() {
  current_size_ = 0;
  for (auto & entry : array_)
    entry.info_ = kEmpty;
}

template <typename HashedObj>
bool HashTable<HashedObj>::Insert(const HashedObj & x) {
  // Insert x as active.
  int current_pos = FindPos(x);
  if (IsActive(current_pos))
    return false;
  
  array_[current_pos].element_ = x;
  array_[current_pos].info_ = kActive;
  
  // Rehash; see Section 5.5.
  if (++current_size_ > array_.size() / 2)
    Rehash();
  
  return true;
}
    
template <typename HashedObj>
bool HashTable<HashedObj>::Insert(HashedObj && x) {
  // Insert x as active.
  int current_pos = FindPos(x);
  if (IsActive(current_pos))
    return false;
  
  array_[current_pos] = std::move(x);
  array_[current_pos].info_ = kActive;
  
  // Rehash; see Section 5.5.
    if (++current_size_ > array_.size() / 2)
      Rehash();
    
    return true;
}

template <typename HashedObj>
int HashTable<HashedObj>::Size() {
  return current_size_;
}

template <typename HashedObj>
int HashTable<HashedObj>::TableSize() {
  return array_.capacity();
}
template<typename HashedObj>
int HashTable<HashedObj>::getCollisions() {
  return number_collisions_;
}
template<typename HashedObj>
int HashTable<HashedObj>::getProbes() {
  return number_probes_;
}
template <typename HashedObj>
bool HashTable<HashedObj>::Remove(const HashedObj & x) {
  int current_pos = FindPos(x);
  if (!IsActive(current_pos))
    return false;
  
  array_[current_pos].info_ = kDeleted;
  return true;
}

template <typename HashedObj>
int HashTable<HashedObj>::FindPos(const HashedObj & x) {
  int offset = 1;
  int current_pos = InternalHash(x);
  bool isCollision = false;
  number_probes_=1;
  while (array_[current_pos].info_ != kEmpty &&
	 array_[current_pos].element_ != x ) {
    // Compute ith probe.
    ++number_probes_;
    isCollision=true;
    current_pos += offset;  
    offset += 2;
    if (current_pos >= array_.size())
	   current_pos -= array_.size( );
    }
  if(isCollision)
    ++number_collisions_;
  return current_pos;
}

template <typename HashedObj>
void HashTable<HashedObj>::Rehash() {
  int collisions_temp = number_collisions_;
  vector<HashEntry> old_array = array_;
  // Create new double-sized, empty table.
  array_.resize(NextPrime(2 * old_array.size()));
  for (auto & entry : array_)
    entry.info_ = kEmpty;
  
  // Copy table over.
  current_size_ = 0;
  for (auto & entry : old_array)
    if (entry.info_ == kActive)
      Insert(std::move(entry.element_));
  number_collisions_ = collisions_temp;
}
