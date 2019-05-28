#ifndef NODE_H
#define NODE_H
#include <iostream>

class INode {
public:
	const int frequency;

	virtual ~INode() {};
	virtual void printNode() = 0;

protected:
	INode(int frequency) : frequency(frequency) {
		
	}
};

class LeafNode : public INode {
public:
	const char c;

	LeafNode(char c, unsigned frequency) :
		INode(frequency), c(c) {
		
	}

	void printNode() override {
		std::cout << "Char: " << c << ", Frequency: " << frequency << '\n';
	}

};

class InternalNode : public INode {
public:
	INode* left;
	INode* right;

	InternalNode(INode* left, INode* right) : 
		INode(left->frequency + right->frequency),
		left(left), right(right) {
		
	}

	~InternalNode() {
		delete left;
		delete right;
	}

	void printNode() override {
		std::cout << "left: ";
		left->printNode();
		std::cout << "right: ";
		right->printNode();
	}
};


struct NodeCmp {
	bool operator()(const INode* lhs, const INode* rhs) const { return lhs->frequency > rhs->frequency; }
};


#endif