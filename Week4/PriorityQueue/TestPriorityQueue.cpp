#include <iostream>
#include <functional>
#include <string>
#include <queue>
#include <deque>
using namespace std;

template<typename T>
void printQueue(T& pQueue) {

	while (!pQueue.empty()) {
		cout << pQueue.top() << " ";
		pQueue.pop();
	}
}

int main() {
	priority_queue<int> queue1;
	priority_queue<int, deque<int>, greater<int>> queue2;

	queue1.push(7); queue2.push(7);
	queue1.push(4); queue2.push(4);
	queue1.push(9); queue2.push(9);
	queue1.push(2); queue2.push(2);
	queue1.push(1); queue2.push(1);

	cout << "Contents in queue1: ";
	printQueue(queue1);

	cout << "\nContents in queue2: ";
	printQueue(queue2);

	cin.get();

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