#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void writeFile();
void readFile();

int main() {
	
	writeFile();
	readFile();

	return 0;
}

void writeFile() {
	// Write to a file

	ofstream output;
	output.open("people.txt"); // Create a file

	// Write two lines
	output << "Marcel" << " " << "Vissers" << " " << 1974 << '\n';
	output << "Johan" << " " << "Talboom" << " " << 1984 << '\n';

	output.close();

	cout << "Done" << endl;
}

void readFile() {
	ifstream input;
	input.open("people.txt");

	if (!input.is_open()) {
		cout << "Cannot open file" << '\n';
		return;
	}

	while (!input.eof()) {
		string line;
		getline(input, line);

		cout << "Readed line: " << line << '\n';
	}

	cout << "Reading done!" << '\n';
}
