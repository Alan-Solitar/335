#include "BinomialQueue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>

using namespace std;
enum Routine {ROUTINE_A,ROUTINE_B, ROUTINE_C};

void TestFlagZero(const string input_filename, BinomialQueue<int> &q, Routine r) {

  
  ifstream reader(input_filename);
  int  num = 0;
  if(r == ROUTINE_A) {
    while(reader >>num) {
      q.Insert(num);
   //cout<<"Inserted " <<num <<endl;
    }
  } else if (r==ROUTINE_B) {
      while(reader >>num) {
      q.InsertEfficiently(num);
   //cout<<"Inserted " <<num <<endl;
    }

  }
}


void ContinualDelete(BinomialQueue<int> &q, int flag) {
    int num=0;
    cout << "flag is " <<flag;
    if(flag==0) {
      while(!q.IsEmpty()) {
        num = q.FindMin();
        q.DeleteMin();
        cout << "Deleted " <<num<<endl;
     }
    } else {
      int i=0, counter=10;
        while(i++ < counter) {
        num= q.FindMin();
        q.DeleteMin();
        cout << "Deleted " <<num<<endl;
        }
     } 
    }
   
void TestFlagOne(const string input_filename, BinomialQueue<int> &q, Routine r) {
  string line; 
  int number_of_lines;
  int num =0;
  ifstream reader(input_filename);
  while (getline(reader, line))
    ++number_of_lines;
  //make reader point to first line again
  reader.clear();
  reader.seekg(0,ios::beg);
  BinomialQueue<int> bq1;
  BinomialQueue<int> bq2;
  if(r==ROUTINE_A) {
    for(size_t i=0; i <number_of_lines/4; ++i) {
      reader >> num;
      bq1.Insert(num);
    }
    while(reader >> num) {
      bq2.Insert(num);
    } 
  } else if (r==ROUTINE_B) {
    for(size_t i=0; i <number_of_lines/4; ++i) {
      reader >> num;
      bq1.InsertEfficiently(num);
    }
    while(reader >> num) {
      bq2.InsertEfficiently(num);
    } 

  } 
  bq1.Merge(bq2);
  q = bq1;
  
}

template<typename function>
void TestTime(const string input_filename, function func, BinomialQueue<int> &q,Routine r) {
  cout << "Test Timing" << endl;
  const auto begin = chrono::high_resolution_clock::now();
  func(input_filename, q, r);
  const auto end = chrono::high_resolution_clock::now();
    
  cout << chrono::duration_cast<chrono::nanoseconds>(end-begin).count() << "ns" << endl;
  cout << chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "ms" << endl;
}


// Sample main for program CreateAndTestHash
int main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <input_file_to_create_queue> <flag>" << endl;
    cout << "    flag should be either 0 or 1" << endl;
    return 0;
  }
  
  const string input_filename(argv[1]);
  const int flag = atoi(argv[2]);
  cout << "\nInput is " << input_filename << endl;
  cout << "Flag is " << flag << "\n"<< endl;

  if(flag==0) {
    //A
    cout<<"Route A"<<endl;
    BinomialQueue<int> input_queue;
    TestTime(input_filename, TestFlagZero, input_queue, ROUTINE_A);
    ContinualDelete(input_queue,flag);
    //B
    cout <<"\nRoute B" <<endl;
    BinomialQueue<int> input_queue1;
    TestTime(input_filename,TestFlagZero,input_queue1,ROUTINE_B);
    ContinualDelete(input_queue1,flag);
  } else {
    BinomialQueue<int> input_queue;
    TestTime(input_filename, TestFlagOne, input_queue, ROUTINE_A);
    ContinualDelete(input_queue,flag);
    //B
    BinomialQueue<int> input_queue1;
    TestTime(input_filename, TestFlagOne, input_queue1, ROUTINE_B);
    ContinualDelete(input_queue1,flag);

  }
  //TestTime(input_filename, flag);
  return 0;
}
