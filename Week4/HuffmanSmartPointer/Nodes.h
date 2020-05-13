#pragma once

#include <memory>
#include <iostream>

class INode {
public:
	const int frequency;

	virtual ~INode() {}
	virtual void printNode() = 0;

protected:
	INode(int frequency) : frequency(frequency) {}
};


class InternalNode : public INode {
public:
	std::shared_ptr<INode> left;
	std::shared_ptr<INode> right;

	InternalNode(std::shared_ptr<INode> c0, std::shared_ptr<INode> c1)
		: INode(c0.get()->frequency + c1.get()->frequency), left(c0), right(c1) {
	}

	~InternalNode() {
		//delete left;
		//delete right;
	}

	virtual void printNode() {
		std::cout << frequency << "(";
		left.get()->printNode();
		std::cout << ",";
		right.get()->printNode();
		std::cout << ")";
	}
};

class LeafNode : public INode {
public:
	const char symbol;

	LeafNode(int frequency, char symbol) : INode(frequency), symbol(symbol) {}

	virtual void printNode() {
		std::cout << "(" << frequency << "," << symbol << ")";
	}
};