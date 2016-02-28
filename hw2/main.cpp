#include "SequenceMap.h"
#include <iostream>
#include <string>
int main()
{
	string s = "a";
	string s2 = "b";
	SequenceMap s3(s,s2);
	SequenceMap s5(s2,s);
	std::cout<<s3;
	std::cout<<(s3<s5);
	std::cout<<endl;
	s3.merge(s5);
	std::cout<<s3;

}