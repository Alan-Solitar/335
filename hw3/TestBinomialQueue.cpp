#include "BinomialQueue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>

using namespace std;
enum Routine {ROUTINE_A,ROUTINE_B, ROUTINE_C, ROUTINE_GENERAL};

void TestFlagZero(const string input_filename, BinomialQueue<int> &q, Routine r) {

  
  ifstream reader(input_filename);
  int  num = 0;
  if(r == ROUTINE_A) {
    while(reader >>num) {
      q.Insert(num);
   //cout<<"Inserted " <<num <<endl;
    }
  } else if (r==ROUTINE_B) {
    while(reader >> num) {
    q.InsertEfficiently(num);
   //cout<<"Inserted " <<num <<endl;
    }
  } else {
    while(reader >> num) {
      q.InsertMerge2(num);
    }

  }
  reader.close();
}


void ContinualDelete(BinomialQueue<int> &q, int flag, Routine r = ROUTINE_GENERAL) {
  int num=0;
  if(r ==ROUTINE_GENERAL) {
      if(flag==0) {
        while(!q.IsEmpty()) {
          num = q.FindMin();
          q.DeleteMin();
          cout << "Deleted " <<num<<endl;
          }
      } else {
        int i=0, counter=10;
        cout <<"Size: " <<q.getSize()<<endl;
        while(i++ < counter && !q.IsEmpty()) {
            num= q.FindMin();
            q.DeleteMin();
            cout << "Deleted " <<num<<endl;
        }
      } 
    } else if (r==ROUTINE_C) {
      if(flag==0) {
          while(!q.IsEmpty()) {
          num = q.FindMin();
          q.DeleteMinTwo();
          cout << "Deleted " <<num<<endl;
          }
      } else {
        cout<< q.getSize();
        int i=0, counter=10;
        while(i++ < counter && !q.IsEmpty()) {
            num= q.FindMin();
            q.DeleteMinTwo();
            cout << "Deleted " <<num<<endl;
        }
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
  //Part A
  if(r==ROUTINE_A) {
    for(int i=0; i <number_of_lines/4; ++i) {
      reader >> num;
      bq1.Insert(num);
    }
    while(reader >> num) {
      bq2.Insert(num);
    } 
    bq1.Merge(bq2);
    q = bq1;
    //Part B
  } else if (r==ROUTINE_B) {
    for(int i=0; i <number_of_lines/4; ++i) {
      reader >> num;
      bq1.InsertEfficiently(num);
    }
    while(reader >> num) {
      bq2.InsertEfficiently(num);
    } 
    bq1.Merge(bq2);
    q = bq1;

    //Part c
  } else {

     for(int i=0; i <number_of_lines/4; ++i) {
      reader >> num;
      bq1.InsertMerge2(num);
    }
    while(reader >> num) {
      bq2.InsertMerge2(num);
    }
    bq2.MergeTwo(bq1);
    q = bq2; 
    }
    reader.close();
}
//will call any function passed to it
template<typename function>
void TestTime(const string input_filename, function func, BinomialQueue<int> &q,Routine r) {
  cout << "Test Timing" << endl;
  const auto begin = chrono::high_resolution_clock::now();
  func(input_filename, q, r);
  const auto end = chrono::high_resolution_clock::now();
    
  cout << chrono::duration_cast<chrono::nanoseconds>(end-begin).count() << "ns" << endl;
  cout << chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "ms\n" << endl;
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
    cout << "Part A" << endl;
    BinomialQueue<int> input_queue;
    TestTime(input_filename, TestFlagZero, input_queue, ROUTINE_A);
    ContinualDelete(input_queue,flag);
    //B
    cout <<"\nPart B" << endl;
    BinomialQueue<int> input_queue1;
    TestTime(input_filename,TestFlagZero,input_queue1,ROUTINE_B);
    ContinualDelete(input_queue1,flag);
    //C
    cout << "Part C" <<  endl;
    BinomialQueue<int> input_queue2;
    TestTime(input_filename,TestFlagZero,input_queue2,ROUTINE_C);
    ContinualDelete(input_queue2,flag);
     
  } else {
    //A
    cout <<"Part A" <<endl;
    BinomialQueue<int> input_queue;
    TestTime(input_filename, TestFlagOne, input_queue, ROUTINE_A);
    ContinualDelete(input_queue,flag);
    //B
    cout <<"\nPart B" <<endl;
    BinomialQueue<int> input_queue1;
    TestTime(input_filename, TestFlagOne, input_queue1, ROUTINE_B);
    ContinualDelete(input_queue1,flag);
    //C
    cout << "Part C" <<  endl; 
    BinomialQueue<int> input_queue2;
    TestTime(input_filename,TestFlagOne,input_queue2,ROUTINE_C);
    ContinualDelete(input_queue2,flag);

  }
  //TestTime(input_filename, flag);
  return 0;
}
