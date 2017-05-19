#ifndef CSCI335_HOMEWORK1_CHAIN_
#define CSCI335_HOMEWORK1_CHAIN_
#include <cstddef>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Place comments that provide a brief explanation of the class.
template<typename Object>
class Chain 
{
 //friend functions
 template <typename Object1>
 friend ostream &operator<<(ostream &out, const Chain<Object1> &rhs);
 template <typename Object1>
 friend Chain<Object1> operator+(const Chain<Object1> &lhs, const Chain<Object1> &rhs);
 template <typename Object1>
 friend Chain<Object1> operator+( const Object &s);

 public:
  // Default "big five" -- you have to alter them for your assignment.
  // That means that you will remove the "= default" statement.
  Chain();
  Chain(Object value);
  Chain(const Chain &rhs)=default;
  Chain& operator=(const Chain &rhs);
  Chain(Chain<Object> &&rhs);
  Chain<Object>& operator=(Chain &&rhs);
  // Here you have to add more methods.
  size_t Size() const;
  void Print(ostream &out) const;
  void ReadChain();
  Object &operator[](const size_t index);
 private:
  size_t size_;
  Object *array_;


};
template<typename Object1> 
ostream &operator<<(ostream &out, const Chain<Object1> &rhs)
{
	rhs.Print(out);
	return out;
}
template <typename Object1>
Chain<Object1> operator+(const Chain<Object1> &lhs, const Chain<Object1> &rhs)
{
	Chain<Object1> temp;
	size_t size = temp.size_ = lhs.size_ + rhs.size_;
	size_t mid = size - rhs.size_; 
	temp.array_ = new Object1[size];
	for(int i=0;i<mid;++i)
	{
		temp.array_[i] = lhs.array_[i];
	}
	for(int i =0;i<rhs.size_;++i)
	{
	temp.array_[mid++] = rhs.array_[i];
	}
	return temp;
}
template <typename Object1>
Chain<Object1> operator+( const Object &s)
{
	Chain<Object1> temp(s);
	cout<<temp;
	return this* + temp;


	/*
	temp.size_ = lhs.size_+1;
	temp.array_ = new Object1[temp.size_];	
	for(int i=0;i<lhs.size;i++)
	{
		temp.array_[i] = lhs.array_[i];
	}
	temp.array_[lhs.size]=s;
	return temp;
*/
}

#include "Chain.hpp"
#endif // CSCI_335_HOMEWORK1_CHAIN_

