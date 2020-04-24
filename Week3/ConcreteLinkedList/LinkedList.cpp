#include "LinkedList.h"
#include <cstddef>

LinkedList::LinkedList() noexcept {
	first = nullptr;
	last = nullptr;
}

LinkedList::~LinkedList() {
	Node* temp = first;
	while (temp != nullptr) {
		temp = temp->next;
		delete first;
		first = temp;
	}
}

void LinkedList::insertEnd(int item) {
	Node* newNode = new Node;
	newNode->value = item;
	newNode->next = nullptr;
	Node* temp = first;

	if (temp == nullptr) {
		first = newNode;
	}
	else {
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void LinkedList::insertFront(int item) {
	Node* newNode = new Node;
	newNode->value = item;

	if (first == nullptr) {
		first = newNode;
	} else {
		newNode->next = first;
		first = newNode;
	}

}

bool LinkedList::removeEnd() {
	// No items to be deleted
	if (isEmpty()) { return false; }

	if (first == last) {
		delete first;
		first = last = nullptr;
		return true;
	}


	Node* temp = first;
	int nodeCount = 0;

	while (temp != nullptr) {
		nodeCount++;
		temp = temp->next;
	}

	Node* temp2 = first;
	for (int i = 1; i < (nodeCount - 1); i++) {
		temp2 = temp2->next;
	}

	delete temp2->next;
	last = temp2;
	last->next = nullptr;

	return true;
}

bool LinkedList::removeFront() {
	if (isEmpty()) return false;

	Node* temp = first;
	first = first->next;
	delete temp;

	return true;
}

bool LinkedList::isEmpty() {
	return (first == nullptr && last == nullptr);
}

size_t LinkedList::size() {
	if (isEmpty()) return 0;

	Node* temp = first;
	size_t nodeSize = 0;

	while (temp != nullptr) {
		nodeSize++;
		temp = temp->next;
	}
	return nodeSize;
}

void LinkedList::clear() {
	Node* temp = first;
	while (temp != nullptr) {
		temp = temp->next;
		first = temp;
		delete temp;
	}
}

int LinkedList::firstItem() {
	return first->value;
}