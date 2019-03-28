#include <iostream>


using namespace std;

void printArray(const int* list, const int size);
int* reverse(int* list, int size);

int main() {

	int count = 5;
	int* pCount = &count;

	cout << "The value of count is " << count << endl;
	cout << "The address of count is " << &count << endl;
	cout << "The address of count is " << pCount << endl;
	cout << "The value of count is " << *pCount << endl;


	const size_t n_students = 10;
	std::string* students = new std::string[n_students];
	students[0] = "Johan";
	students[1] = "Etienne";
	students[2] = "Maurice";
	students[3] = "Diederich";

	cout << "The address of students is " << students << endl;
	cout << "The address first students is " << &students[0] << endl;
	cout << "The first students is " << students[0].c_str() << endl;
	cout << "The address second students is " << &students[1] << endl;
	cout << "The address second students is " << ++students << endl;
	cout << "Sizeof String: " << sizeof(std::string) << " bytes" << endl;

	// Pointer types
	int area = 1;
	//double* pArea = &area;

	// Single line
	typedef int* intpointer;
	//int* i = 0, j = 0;
	intpointer i = 0, j = 0;
	cout << "Address of i: " << &i << endl;
	//cout << "Value of i: " << *i;
	cout << "Address of j: " << &j << endl;


	// Const pointer param
	int list[6] = { 11, 12, 13, 14, 15, 16 };
	int* p = list;

	for (int i = 0; i < 6; i++)
		cout << "address: " << (list + i) <<
		" value: " << *(list + i) << " " <<
		" value: " << list[i] << " " <<
		" value: " << *(p + i) << " " <<
		" value: " << p[i] << endl;
	//printArray(list, 6);

	// Pointer return
	int* p1 = reverse(list, 6);
	printArray(p1, 6);
	printArray(list, 6);


	std::cin.get();
	return 0;
}


void printArray(const int* list, const int size) {
	for (int i = 0; i < size; i++)
		cout << list[i] << " ";
	cout << endl;
}

int* reverse(int* list, int size) {
	for (int i = 0, j = size - 1; i < j; i++, j--) {
		// Swap list[i] with list[j]
		int temp = list[j];
		list[j] = list[i];
		list[i] = temp;
	}

	return list;
}
