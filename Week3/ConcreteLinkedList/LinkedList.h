#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
	int value;
	Node *next;
};

class LinkedList {
public:
	LinkedList();
	~LinkedList();

	void insertEnd(int item); // Add item to the end
	void insertFront(int item); // Insert at front
	bool removeEnd(); // Remove item at the end
	bool removeFront();
	bool isEmpty();
	size_t size();
	void clear();

	int firstItem();

private:
	Node *first;
	Node *last;
};




#endif