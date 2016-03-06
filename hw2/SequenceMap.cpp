	#include "SequenceMap.h"
	//constructors
	SequenceMap::SequenceMap(const string &a_rec_seq, const string &an_enz_acro):
	recognition_sequence_{a_rec_seq},enzyme_acronym_{an_enz_acro} {
		cout<<this->recognition_sequence_<<endl;
	}
	
	//boolean operator
	bool SequenceMap::operator<(const  SequenceMap &rhs) const
	{
		return (this->recognition_sequence_ < rhs.recognition_sequence_)? true:false;
	}
	//merge two sequences if equal
	void SequenceMap::Merge(const SequenceMap &other_sequence)
	{
		for(auto &i: other_sequence.enzyme_acronym_
)		{
			this->enzyme_acronym_.push_back(i);
		}
	}

	//print function to print contents of SequenceMap
	void SequenceMap::Print(ostream &out) const
	{
		out<< this->recognition_sequence_ << " : ";
		for(auto &i: enzyme_acronym_)
		{
			out<< " " <<i;
		}
		out<<"\n";
	}
	ostream& operator<<(ostream& out, const SequenceMap& rhs)
	{
    	rhs.Print(out);
    	return out;
	}