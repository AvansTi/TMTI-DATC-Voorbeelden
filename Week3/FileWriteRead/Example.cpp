#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>


using namespace std;
using namespace std::literals::string_literals;

typedef struct {
	string firstname;
	string lastname;
	int grade;
} grade_t;


void writeFile(vector<int>& data, const string& filename);
void readFile(vector<int>& data, const string& filename);

int main() {

	// Default data
	vector<int> v;
	for (int i = 1; i < 30; i+=2) {
		v.push_back(i);
	}

	// Write to file
	cout << "Write to file" << '\n';
	writeFile(v, "odd.txt");

	// Read from file
	cout << "Read from file" << endl;
	v.clear(); // first clear the data
	readFile(v, "odd.txt");

	// Check file content
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));


	cout << "Done" << endl;

	cin.get();

	return 0;
}


void writeFile(vector<int>& data, const string& filename) {
	
	ofstream output;

	output.open(filename);

	copy(data.begin(), data.end(), ostream_iterator<int>(output, " "));
	cout << "File created" << '\n';

	output.close();
}

void readFile(vector<int>& data, const string& filename) {
	
	ifstream input(filename);
	if (input.fail()) {
		cout << "Cannot open file" << '\n';
		return;
	}

	copy(istream_iterator<int>(input), istream_iterator<int>(), back_inserter(data));

	input.close();
}