#include "BinomialQueue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>

using namespace std;


void TestBinomialQueue(const string input_filename, int flag) {
  cout << "Input is " << input_filename << endl;
  cout << "Flag is" << flag << "\n"<< endl;

  ifstream reader(input_filename);
  int  num = 0;
  if(flag == 0) {
    BinomialQueue<int> input_queue;
    while(reader >>num) {
      input_queue.Insert(num);
      cout<<"Inserted " <<num <<endl;
    }
    
    while(!input_queue.IsEmpty()) {
      num = input_queue.FindMin();
      input_queue.DeleteMin();
      cout << "Deleted " <<num<<endl;
    }
  } else if(flag==1) {
    
  string line; 
  int number_of_lines;
  while (getline(reader, line))
    ++number_of_lines;

  //make reader point to first line again
  reader.clear();
  reader.seekg(0,ios::beg);
  BinomialQueue<int> bq1;
  BinomialQueue<int> bq2;
  for(size_t i=0; i <number_of_lines/4; ++i) {
    reader >> num;
    bq1.Insert(num);
  }
  while(reader >> num) {
    bq2.Insert(num);
  } 
  bq1.Merge(bq2);
  int i=0, counter=10;
  while(i++ < counter) {
    num= bq1.FindMin();
    bq1.DeleteMin();
    cout << "Deleted " <<num<<endl;
  }

}

}

void TestTime(const string input_filename, int flag) {
  cout << "Test Timing" << endl;
  const auto begin = chrono::high_resolution_clock::now();
  TestBinomialQueue(input_filename,flag);
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
  TestTime(input_filename, flag);
  return 0;
}
