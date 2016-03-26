#include "BinomialQueue.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void
TestBinomialQueue(const string input_filename, int flag) {
  cout << "Input is " << input_filename << endl;
  cout << "Flag is " << flag << endl;
  BinomialQueue<int> input_queue;
}

// Sample main for program CreateAndTestHash
int
main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <input_file_to_create_queue> <flag>" << endl;
    cout << "    flag should be either 0 or 1" << endl;
    return 0;
  }
  
  const string input_filename(argv[1]);
  const int flag = atoi(argv[2]);
  TestBinomialQueue(input_filename, flag);
  return 0;
}
