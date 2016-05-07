#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>


//Written by Alan Solitar

using namespace std;

vector<double> GenerateRandomNumbers(int n) {
srand(time(0)); //use current time as seed for random generator
for (int i = 0; i < N; ++i) {
	const 
	double
	random_variable = (double) rand() % (double)RAND_MAX;
	// Push it into the vector of random numbers.
}

int number_of_bins_next_fit(vector<double> random_numbers) {
	double current_capacity = 0;
	int number_of_bins = 1;
	if(random_numbers.size()==0) {
		return 0;
	}
	for(auto &num: random_numbers) {
		if(num+=current_capacity > 1) {
			current_capacity=num;
			++number_of_bins;
		}
		else {
			current_capacity+=num;
		}
	}
	return number_of_bins;
}
int number_of_bins_first_fit(vector<double> random_numbers) {
	vector<double> bins;
	bins.push_back(0);
	bool placed = false;

	if(random_numbers.size()==0) {
		return 0;
	}
	for(auto&num: random_numbers) {
		for(&bin:bins) {
			if(bin +num < 1) {
				bin+=num;
				placed = true;
			}
		}
		if(!placed) {
			bins.push_back(num);
		}
	}

}


int main() {
	// Generate a vector of N random numbers in the range [0.0, 1.0];
	vector<double> random_numbers = GenerateRandomNumbers(N);
	const int number_of_bins_next_fit = NextFitBinPacking(random_numbers);
	const int number_of_bins_first_fit = FirstFitBinPacking(random_numbers);
	// Sort the random_numbers from larger to smaller
	std::sort(random_numbers.begin(), random_numbers.end(), std::greater<double>());
	const int number_of_bins_first_fit_decreasing =   FirstFitBinPacking(random_numbers);

	cout << “Numberofbins:” << endl;
	cout << “Next Fit: “ << number_of_bins_next_fit<< endl;
	cout << “First Fit: “ << number_of_bins_first_fit<< endl;
	cout << “First Fit Decreasing: “ 
	<< number_of_bins_first_fit_decreasing << endl;
}