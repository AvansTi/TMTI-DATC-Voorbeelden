
import std.core;



void printArray(const std::vector<int> &list)
{
	for (auto v : list)
		std::cout << v << " ";
	std::cout << '\n';
}

void minMaxValue(const std::vector<int>& list) {
	auto min = min_element(list.begin(), list.end());
	auto max = max_element(list.begin(), list.end());
	std::cout << "The min value is " << *min << " at index " << std::distance(list.begin(), min) << '\n';
	std::cout << "The max value is " << *max << " at index " << std::distance(list.begin(), max) << '\n';
}

void randomList(std::vector<int>& list) {
	std::cout << "\nRandom shuffle:\n";
	// Manier vanaf C++14
	std::random_device rng;
	std::mt19937 urng(rng());
	std::shuffle(list.begin(), list.end(), urng);
	//random_shuffle(list, list + 6); <-- Vanaf C++ 17 verwijderd omdat het niet echt random is.
	printArray(list);
}

void sortVector(std::vector<int>& list) {
	std::cout << "\nSort:\n";

	std::sort(list.begin(), list.end(), std::greater<int>());
	printArray(list);
}

void findInVector(const std::vector<int>& list) {
	std::cout << "\nFind :\n";
	int key = 4;
	auto p = std::find(list.begin(), list.end(), key);
	if (p != std::end(list))
		std::cout << "The value " << *p << " is found at position " << std::distance(list.begin(), p) << '\n';
	else
		std::cout << "The value " << key << " is not found\n";
}

int main()
{
	std::vector<int> list = { 4, 2, 3, 6, 5, 1 };
	printArray(list);

	minMaxValue(list);
	
	randomList(list);

	sortVector(list);

	findInVector(list);

	return 0;
}