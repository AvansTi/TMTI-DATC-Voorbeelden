#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stddef.h>

using namespace std;

template <class T>
struct Node
{
	T value;
	Node<T> *next;
};

template <class T>
class LinkedList {
public:
	LinkedList();
	~LinkedList();

	void insertEnd(T item); // Add item to the end
	void insertFront(T item); // Insert at front
	bool removeEnd(); // Remove item at the end
	bool removeFront();
	bool isEmpty();
	size_t size();
	void clear();

	T& firstItem();

private:
	Node<T> *first;
	Node<T> *last;
};

#endif

