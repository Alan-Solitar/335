#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>



//Written by Alan Solitar

using namespace std;

vector<double> GenerateRandomNumbers(int n) {
	vector<double> rand_numbers;
	srand(time(0)); //use current time as seed for random generator
	for (int i = 0; i < n; ++i) {
		const double random_variable = rand() / (double)RAND_MAX;
		cout <<"number: " <<random_variable <<endl;
		// Push it into the vector of random numbers.
		rand_numbers.push_back(random_variable);
	}
	return rand_numbers;
}
int NextFitBinPacking(vector<double> random_numbers) {
	double current_capacity = 0;
	int number_of_bins = 1;
	if(random_numbers.size()==0) {
		return 0;
	}
	//try to add number to bin
	//if you cannot, put it in a new bin
	for(auto &num: random_numbers) {
		if(num + current_capacity > 1) {
			current_capacity=num;
			++number_of_bins;
		}
		else {
			current_capacity+=num;
		}
	}
	return number_of_bins;
}
int FirstFitBinPacking(vector<double> &random_numbers) {
	//each cell holds capacity of bin
	vector<double> bins;
	//initialize first bin
	bins.push_back(0);
	bool placed = false;

	if(random_numbers.size()==0) {
		return 0;
	}
	//for each number go through bins until a spot is found
	for(auto&num: random_numbers) {
		for(auto &bin:bins) {
			if(bin +num < 1) {
				bin+=num;
				placed = true;
			}
		}
		//no spot found - create new bin
		if(!placed) {
			bins.push_back(num);
			}
			placed = false;
	}
	return bins.size();
}


int main(int argc, char **argv) {
	if (argc != 2) {
		cout << "Usage: " << argv[0] << " <Number of random values>" << endl;
		return 0;
	}
	const int N = atoi(argv[1]);
	// Generate a vector of N random numbers in the range [0.0, 1.0];
	vector<double> random_numbers = GenerateRandomNumbers(N);
	const int number_of_bins_next_fit = NextFitBinPacking(random_numbers);
	const int number_of_bins_first_fit = FirstFitBinPacking(random_numbers);
	// Sort the random_numbers from larger to smaller
	std::sort(random_numbers.begin(), random_numbers.end(), std::greater<double>());
	const int number_of_bins_first_fit_decreasing = FirstFitBinPacking(random_numbers);

	cout << "Numberofbins:" << endl;
	cout << "Next Fit: " << number_of_bins_next_fit<< endl;
	cout << "First Fit: "<< number_of_bins_first_fit << endl;
	cout << "First Fit Decreasing: " <<number_of_bins_first_fit_decreasing <<endl; 
}