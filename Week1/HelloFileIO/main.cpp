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

	int i;
	cin >> i;

	return 0;
}

void writeFile() {
	// Write to a file
	ofstream output;
	output.open("people.txt"); // Create a file

	// Write two lines
	output << "Etienne" << " " << "Goossens" << " " << 1990 << endl;
	output << "Johan" << " " << "Talboom" << " " << 1984 << endl;

	output.close();

	cout << "Done" << endl;
}

void readFile() {
	ifstream input;
	input.open("people.txt");

	if (!input.is_open()) {
		cout << "Cannot open file" << endl;
		return;
	}

	while (!input.eof()) {
		string line;
		getline(input, line);

		cout << "Readed line: " << line << endl;
	}

	cout << "Reading done!" << endl;
}
