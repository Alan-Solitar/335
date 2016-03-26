#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "BinomialQueue.h"
using namespace std;

namespace {

void TestProgram1() {
  BinomialQueue<int> test_heap;
  for (int i = 0; i < 200; ++i) {
    test_heap.Insert(rand() % 1000);
  }
  while (!test_heap.IsEmpty()) {
    cout << test_heap.FindMin() << " ";
    test_heap.DeleteMin();
  }
  cout << endl << "Heap should be empty now: " << test_heap.IsEmpty() << endl;
}

void TestProgram2() {
  BinomialQueue<int> test_heap;
  for (int i = 0; i < 200; ++i) {
    int a_value = rand() % 1000;
    test_heap.Insert(std::move(a_value));
  }
  while (!test_heap.IsEmpty()) {
    cout << test_heap.FindMin() << " ";
    test_heap.DeleteMin();
  }
  cout << endl << "Heap should be empty now: " << test_heap.IsEmpty() << endl;
}

void TestProgram3() {
  BinomialQueue<int> test_heap_1;
  for (int i = 0; i < 200; ++i) {
    const int a_value = rand() % 1000;
    test_heap_1.Insert(a_value);
  }
  BinomialQueue<int> test_heap_2;
  for (int i = 0; i < 200; ++i) {
    const int a_value = rand() % 1000;
    test_heap_2.Insert(a_value);
  }

  test_heap_1.Merge(test_heap_2);
  cout << endl << "Heap 2 should be empty after merge: " << test_heap_2.IsEmpty() << endl;
  while (!test_heap_1.IsEmpty()) {
    cout << test_heap_1.FindMin() << " ";
    test_heap_1.DeleteMin();
  }
  cout << endl << "Heap 1 should be empty now: " << test_heap_1.IsEmpty() << endl;

}

} // namepace


int main() {
  TestProgram1();
  TestProgram2();
  TestProgram3();
  return 0;
}
