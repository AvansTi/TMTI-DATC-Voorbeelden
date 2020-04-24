#include <iostream>
#include <memory>


void printArray(const int* list, const int size);
int* reverse(int* list, int size);


// oud
// typedef int* intpointer
using intpointer = int*;

int main() {

	int count = 5;
	int* pCount = &count;

	std::cout << "The value of count is " << count << '\n';
	std::cout << "The address of count is " << &count << '\n';
	std::cout << "The address of count is " << pCount << '\n';
	std::cout << "The value of count is " << *pCount << '\n';


	const size_t n_students = 10;
	std::unique_ptr<std::string[]> students(new std::string[n_students]);
	students[0] = "Johan";
	students[1] = "Etienne";
	students[2] = "Maurice";
	students[3] = "Diederich";

	std::cout << "The address of students is " << students << '\n';
	std::cout << "The address first students is " << &students[0] << '\n';
	std::cout << "The first students is " << students[0].c_str() << '\n';
	std::cout << "The address second students is " << &students[1] << '\n';
	std::cout << "Sizeof String: " << sizeof(std::string) << " bytes" << '\n';

	// Pointer types
	int area = 1;
	//double* pArea = &area;

	//int* i = 0, j = 0;
	intpointer i = 0, j = 0;
	std::cout << "Address of i: " << &i << '\n';
	//cout << "Value of i: " << *i;
	std::cout << "Address of j: " << &j << '\n';


	// Const pointer param
	int list[6] = { 11, 12, 13, 14, 15, 16 };
	int* p = list;

	for (int i = 0; i < 6; i++)
		std::cout << "address: " << (list + i) <<
		" value: " << *(list + i) << " " <<
		" value: " << list[i] << " " <<
		" value: " << *(p + i) << " " <<
		" value: " << p[i] << '\n';
	//printArray(list, 6);

	// Pointer return
	int* p1 = reverse(list, 6);
	printArray(p1, 6);
	printArray(list, 6);

	return 0;
}


void printArray(const int* list, const int size) {
	for (int i = 0; i < size; i++)
		std::cout << list[i] << " ";
	std::cout << '\n';
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
