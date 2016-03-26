#include <iostream>
#include <chrono>

using namespace std;

int main() {
  cout << "Test Timing" << endl;

  const auto begin = chrono::high_resolution_clock::now();

  // code to benchmark
  int sum = 0;
  for (int i = 1; i < 10000; ++i) sum ++;

  const auto end = chrono::high_resolution_clock::now();
    
  cout << chrono::duration_cast<chrono::nanoseconds>(end-begin).count() << "ns" << endl;
  cout << chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "ms" << endl;


}
