template<typename Object>
size_t Chain::Size() const
{
	return size_;
}
//copy assignment operator
template<typename Object>
Chain::&operator=(const Chain &rhs)
{
	if(this!=&rhs)
	{
		delete array_;
		this.size_ = rhs.size_;
		for(int i=0;i<this.size_;i++)
		{
			array_[i]=rhs.array_[i];
		}
	}
}

//copy constructor
template<typename Object>
Chain::Chain(const Chain &rhs)
{
	this.size_ = rhs.size_;
	array_ = new Object[];
	for(int i=0;i<this.size;i++)
		{
			array_[i]=rhs.array_[i];
		}
}
template<typename Object>
Chain(Chain &&rhs)
{
 
}
template<typename Object>
void Chain::Print(ostream &out)
{
	out << "[";
	for(auto &i:array_)
	{
		out<<i<<" ";
	}
	out<<"]";
}
template<typename Object>
ostream &operator<<(ostream &out, const Chain &rhs)
{
	rhs.Print(out);
	return out;
}
