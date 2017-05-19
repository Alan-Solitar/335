#include <iostream>
#include <algorithm>

//Regular constructor
template<typename Object>
Chain<Object>::Chain(): size_(0), array_(nullptr) {}

//constructor with one param
template<typename Object>
Chain<Object>::Chain(Object value): size_(1) 
{
	array_ = new Object{value};
}
//move constructor
template<typename Object>
Chain<Object>::Chain(Chain<Object> &&rhs)
{
	size_ = std::move(rhs.size_);
	array_ = std::move(rhs.array_);
	rhs.array_= nullptr;
	rhs.size_=0;
}

//move assignment operator
template<typename Object>
Chain<Object>& Chain<Object>::operator=(Chain<Object> &&rhs)
{
	swap(size_, rhs.size_);
	swap(array_, rhs.array_);
	return *this;
}

//copy constructor
template<typename Object>
Chain<Object>& Chain<Object>::operator=(const Chain &rhs)
{
	if(this!=&rhs)
	{
		delete array_;
		size_ = rhs.size_;
		for(int i=0;i<size_;i++)
		{
			array_[i]=rhs.array_[i];
		}
	}
	return *this;
}
//Size function
template<typename Object>
size_t Chain<Object>::Size() const
{
	return size_;
}

//Print function to be called when << operator is used
template<typename Object>
void Chain<Object>::Print(ostream &out) const
{
	out<<endl << "[";
	for(int i=0;i<size_;i++)
	{
		out<<array_[i]<<" ";
	}
	out <<"]" <<endl;
}
template<typename Object>
void Chain<Object>::ReadChain()
{
	string input = "";
	cout<<endl;
	getline(cin,input);
	size_t opening,closing;
	if(input!="")
	{
		opening = input.find('[');
		closing = input.find(']');
	}

	//Make that both '[' and ']' were found
	if(opening!=string::npos && closing!=string::npos )
	{
		input = input.substr(opening+1,closing-opening-1);
	}
	
	if(array_!=nullptr)
	{
	delete array_;
	}
	
	//check how large the array needs to be
	//quick loop to check number of spaces
	size_t sizeCounter=0;
	for(char& i:input)
	{
		if(i==' ')
		{
			++sizeCounter;
		}
	}
	size_ = sizeCounter+1;
 	Object current;
	array_ = new Object[size_];
	stringstream stream1(input);
	//add values from stream into array
	for(int i=0;i<size_;++i)
	{
		if(stream1 >>current)
			array_[i] = current;
	}

}
template <typename Object>
Object & Chain<Object>::operator[](const size_t index)
{
	return  array_[index];
}

/*
template<typename Object>
ostream &operator<<(ostream &out, const Chain<Object> &rhs)
{
	rhs->Print(out);
	return out;
}
*/
