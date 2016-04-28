#include <cstdlib>
#include <ctime>

using namespace std;

srand(time(0)); //use current time as seed for random generator
const int maximum_value = 1000;
while (true) {
const int random_variable = rand() % maximum_value + 1;
cout << random_variable << endl;
// break from loop based on a condition.
}

int main(int argc, char **argv) {
	if (argc != 2) {
		cout << "Usage: " << argv[0] << " <maximum_number_of_nodes>" << endl;
		return 0;
	}
	const int MAX_NODES = argv[1];