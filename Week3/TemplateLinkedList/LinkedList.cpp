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
	while (temp != nullptr) {
		temp = temp->next;
		delete first;
		first = temp;
	}
}

template <class T>
void LinkedList<T>::insertEnd(T item) {
	Node<T>* newNode = new Node<T>;
	newNode->value = item;
	newNode->next = nullptr;
	Node<T>* temp = first;

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

template <class T>
void LinkedList<T>::insertFront(T item) {
	Node<T>* newNode = new Node<T>;
	newNode->value = item;

	if (first == nullptr) {
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
		first = last = nullptr;
		return true;
	}
	else {
		Node<T>* temp = first;
		int nodeCount = 0;

		while (temp != nullptr) {
			nodeCount = nodeCount + 1;
			temp = temp->next;
		}

		Node<T>* temp2 = first;
		for (int i = 1; i < (nodeCount - 1); i++) {
			temp2 = temp2->next;
		}

		delete temp2->next;
		last = temp2;
		last->next = nullptr;

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
	return (first == nullptr && last == nullptr);
}

template <class T>
size_t LinkedList<T>::size() {
	if (isEmpty()) return 0;

	Node<T>* temp = first;
	size_t nodeSize = 0;

	while (temp != nullptr) {
		nodeSize++;
		temp = temp->next;
	}
	return nodeSize;
}

template <class T>
void LinkedList<T>::clear() {
	Node<T>* temp = first;
	while (temp != nullptr) {
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

//template class LinkedList<int>;
//template class LinkedList<double>;
//template class LinkedList<std::string>;