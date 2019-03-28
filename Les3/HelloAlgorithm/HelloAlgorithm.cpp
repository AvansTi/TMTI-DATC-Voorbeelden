#include <iostream>
#include <algorithm>
using namespace std;

void printArray(const int* list, int size)
{
	for (int i = 0; i < size; i++)
		cout << list[i] << " ";
	cout << endl;
}

int main()
{
	int list[] = { 4, 2, 3, 6, 5, 1 };
	printArray(list, 6);

	int* min = min_element(list, list + 6);
	int* max = max_element(list, list + 6);
	cout << "The min value is " << *min << " at index " << (min - list) << endl;
	cout << "The max value is " << *max << " at index " << (max - list) << endl;

	cout << endl << "Random shuffle: " << endl;
	random_shuffle(list, list + 6);
	printArray(list, 6);

	cout << endl << "Sort: " << endl;

	sort(list, list + 6);
	printArray(list, 6);


	cout << endl << "Find : " << endl;
	int key = 4;
	int* p = find(list, list + 6, key);
	if (p != list + 6)
		cout << "The value " << *p << " is found at position " << (p - list) << endl;
	else
		cout << "The value " << key << " is not found" << endl;

	cin.get();

	return 0;
}