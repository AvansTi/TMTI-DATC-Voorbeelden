#include <iostream>
#include <functional>
#include <string>
#include <queue>
#include <deque>
#include <vector>
using namespace std;

template<typename T>
void printQueue(T& pQueue) {

	while (!pQueue.empty()) {
		cout << pQueue.top() << " ";
		pQueue.pop();
	}
}

int main() {

	auto cmp = [](const int lhs, const int rhs) {
		return (lhs % 3) > (rhs % 3);
	};

	priority_queue<int> queue1;
	priority_queue<int, vector<int>, greater<>> queue2;
	priority_queue<int, vector<int>, decltype(cmp)> queue3(cmp);


	for (auto v : { 7,4,9,2,1 }) {
		queue1.push(v);
		queue2.push(v);
		queue3.push(v);
	}


	cout << "Contents in queue1: ";
	printQueue(queue1);

	cout << "\nContents in queue2: ";
	printQueue(queue2);

	cout << "\nContents in queue3: ";
	printQueue(queue3);


	return 0;
}

/*
int main() {
	std::priority_queue<std::pair<int, std::string> > pq;
	pq.push(std::make_pair(3, "Start visual studio"));
	pq.push(std::make_pair(4, "plug laptop in"));
	pq.push(std::make_pair(5, "Haal koffie"));
	pq.push(std::make_pair(1, "Test, test en ... debug"));
	pq.push(std::make_pair(2, "Start coding..."));

	while (!pq.empty()) {
		std::pair<int, std::string> top = pq.top();
		std::cout << top.first << ", " << top.second << std::endl;
		pq.pop();
	}

	std::cin.get();
	return 0;
}
*/