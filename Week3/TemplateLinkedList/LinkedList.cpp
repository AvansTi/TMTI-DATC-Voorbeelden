#include "LinkedList.h"
#include <string>

template <class T>
LinkedList<T>::LinkedList() {
	first = nullptr;
	last = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() {
	Node<T>* temp = first;
	while (temp != NULL) {
		temp = temp->next;
		delete first;
		first = temp;
	}
}

template <class T>
void LinkedList<T>::insertEnd(T item) {
	Node<T>* newNode = new Node<T>;
	newNode->value = item;
	newNode->next = NULL;
	Node<T>* temp = first;

	if (temp == NULL) {
		first = newNode;
	}
	else {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

template <class T>
void LinkedList<T>::insertFront(T item) {
	Node<T>* newNode = new Node<T>;
	newNode->value = item;

	if (first == NULL) {
		first = newNode;
	}
	else {
		newNode->next = first;
		first = newNode;
	}

}

template <class T>
bool LinkedList<T>::removeEnd() {
	// No items to be deleted
	if (isEmpty()) { return false; }

	if (first == last) {
		delete first;
		first = last = NULL;
		return true;
	}
	else {
		Node<T>* temp = first;
		int nodeCount = 0;

		while (temp != NULL) {
			nodeCount = nodeCount + 1;
			temp = temp->next;
		}

		Node<T>* temp2 = first;
		for (int i = 1; i < (nodeCount - 1); i++) {
			temp2 = temp2->next;
		}

		delete temp2->next;
		last = temp2;
		last->next = NULL;

		return true;
	}
}

template <class T>
bool LinkedList<T>::removeFront() {
	if (isEmpty()) return false;

	Node<T>* temp;
	temp = first;
	first = first->next;
	delete temp;

	return true;
}

template <class T>
bool LinkedList<T>::isEmpty() {
	// No items
	if (first == NULL && last == NULL) { return true; }
	else { return false; }
}

template <class T>
size_t LinkedList<T>::size() {
	if (isEmpty()) return 0;

	Node<T>* temp = first;
	size_t nodeSize = 0;

	while (temp != NULL) {
		nodeSize++;
		temp = temp->next;
	}
	return nodeSize;
}

template <class T>
void LinkedList<T>::clear() {
	Node<T>* temp = first;
	while (temp != NULL) {
		temp = temp->next;
		first = temp;
		delete temp;
	}
}

template <class T>
T& LinkedList<T>::firstItem() {
	return first->value;
}

// Explicit template instantiation
// https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa

template class LinkedList<int>;
template class LinkedList<double>;
template class LinkedList<std::string>;