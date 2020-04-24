#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>


using namespace std::string_literals;

typedef struct {
	std::string firstname;
	std::string lastname;
	int grade;
} grade_t;


void writeFile(std::vector<int>& data, const std::string& filename);
void readFile(std::vector<int>& data, const std::string& filename);

int main() {

	// Default data
	std::vector<int> v;
	for (int i = 1; i < 30; i+=2) {
		v.push_back(i);
	}

	// Write to file
	std::cout << "Write to file" << '\n';
	writeFile(v, "odd.txt");

	// Read from file
	std::cout << "Read from file\n";
	v.clear(); // first clear the data
	readFile(v, "odd.txt");

	// Check file content
	copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));


	std::cout << "Done\n";

	return 0;
}


void writeFile(std::vector<int>& data, const std::string& filename) {
	
	std::ofstream output;

	output.open(filename);

	for (auto d : data) {
		output << d << '\n';
	}

	copy(data.begin(), data.end(), std::ostream_iterator<int>(output, " "));
	std::cout << "File created\n" << '\n';

	output.close();
}

void readFile(std::vector<int>& data, const std::string& filename) {
	
	std::ifstream input(filename);
	if (input.fail()) {
		std::cout << "Cannot open file" << '\n';
		return;
	}

	copy(std::istream_iterator<int>(input), std::istream_iterator<int>(), back_inserter(data));

	input.close();
}