#define PrintOutputBuildTree

#include <iostream>
#include <queue>
#include <map>
#include <climits> // for CHAR_BIT
#include <iterator>
#include <algorithm>

constexpr const int UniqueSymbols = 1 << CHAR_BIT;
constexpr const char* SampleString = "best wel veel eeeeeees";

using HuffCode = std::vector<bool>;
using HuffCodeMap = std::map<char, HuffCode>;

class INode {
public:
	const int frequency;

	virtual ~INode() {}
	virtual void printNode() = 0;

protected:
	INode(int freq) : frequency(freq) {}
};

class InternalNode : public INode {
public:
	INode *const left;
	INode *const right;

	InternalNode(INode* c0, INode* c1)
		: INode(c0->frequency + c1->frequency), left(c0), right(c1) {}

	~InternalNode() {
		delete left;
		delete right;
	}

	virtual void printNode() {
		std::cout << frequency << "(";
		left->printNode();
		std::cout << ",";
		right->printNode();
		std::cout << ")";
	}
};

class LeafNode : public INode {
public:
	const char c;

	LeafNode(int f, char c) : INode(f), c(c) {}

	virtual void printNode() {
		std::cout << "(" << frequency << "," << c << ")";
	}
};

struct NodeCmp {
	bool operator()(const INode* lhs, const INode* rhs) const { return lhs->frequency > rhs->frequency; }
};

INode* BuildTree(const int(&frequencies)[UniqueSymbols]) {
	std::priority_queue<INode*, std::vector<INode*>, NodeCmp> trees;

	for (int i = 0; i < UniqueSymbols; ++i) {
		if (frequencies[i] != 0)
			trees.push(new LeafNode(frequencies[i], (char)i));
	}

	//		std::priority_queue<INode*, std::vector<INode*>, NodeCmp> trees2(trees);
	//		while (!trees2.empty()) { trees2.top()->printNode(); trees2.pop(); std::cout << " "; }
	//		std::cout << std::endl;

	while (trees.size() > 1) {
		INode* childR = trees.top();
		trees.pop();

		INode* childL = trees.top();
		trees.pop();

		INode* parent = new InternalNode(childR, childL);
		trees.push(parent);

		//		std::priority_queue<INode*, std::vector<INode*>, NodeCmp> trees2(trees);
		//		while (!trees2.empty()) { trees2.top()->printNode(); trees2.pop(); std::cout << " "; }
		//		std::cout << std::endl;

	}
	return trees.top();
}

void GenerateCodes(const INode* node, const HuffCode& prefix, HuffCodeMap& outCodes) {
	if (const LeafNode* lf = dynamic_cast<const LeafNode*>(node)) {
		outCodes[lf->c] = prefix;
	} else if (const InternalNode* in = dynamic_cast<const InternalNode*>(node)) {
		HuffCode leftPrefix = prefix;
		leftPrefix.push_back(false);
		GenerateCodes(in->left, leftPrefix, outCodes);

		HuffCode rightPrefix = prefix;
		rightPrefix.push_back(true);
		GenerateCodes(in->right, rightPrefix, outCodes);
	}
}

int main() {
	// Build frequency table
	int frequencies[UniqueSymbols] = { 0 };
	const char* ptr = SampleString;
	while (*ptr != '\0')
		++frequencies[*ptr++];

	for (int i = 0; i < UniqueSymbols; i++) {
		if (frequencies[i] != 0)
			std::cout << static_cast<char>(i) << " : " << frequencies[i] << std::endl;
	}
	std::cout << std::endl;

	INode* root = BuildTree(frequencies);

	HuffCodeMap codes;
	GenerateCodes(root, HuffCode(), codes);
	delete root;

	for (auto& code : codes) {
		std::cout << code.first << " ";
		std::copy(code.second.begin(), code.second.end(),
			std::ostream_iterator<bool>(std::cout));
		std::cout << std::endl;
	}

	return 0;
}


