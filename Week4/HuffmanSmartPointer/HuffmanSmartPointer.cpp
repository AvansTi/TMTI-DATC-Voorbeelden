#include <iostream>
#include "Nodes.h"
#include <iostream>
#include <queue>
#include <map>
#include <iterator>
#include <algorithm>


constexpr const int UniqueSymbols = 1 << CHAR_BIT;
constexpr const char* SampleString = "best wel veel eeeeeees";

using HuffCode = std::vector<bool>;
using HuffCodeMap = std::map<char, HuffCode>;


struct NodeCmp {
	bool operator()(std::shared_ptr<const INode> lhs, std::shared_ptr<const INode> rhs) const {
		return lhs->frequency > rhs->frequency; 
	}
};

std::shared_ptr<INode> BuildTree(const int(&frequencies)[UniqueSymbols]) {

	auto cmp = [](std::shared_ptr<const INode> lhs, std::shared_ptr<const INode> rhs)  {
		return lhs->frequency > rhs->frequency;
	};

	std::priority_queue<std::shared_ptr<INode>, std::vector<std::shared_ptr<INode>>, NodeCmp> trees;
	//std::priority_queue<std::shared_ptr<INode>, std::vector<std::shared_ptr<INode>>, decltype(cmp)> trees(cmp);

	for (int i = 0; i < UniqueSymbols; ++i) {
		if (frequencies[i] != 0)
			trees.push(std::shared_ptr<INode>(new LeafNode(frequencies[i], (char)i)));
	}


	std::cout << "\n Only leaf nodes:\n";
	std::priority_queue<std::shared_ptr<INode>, std::vector<std::shared_ptr<INode>>, NodeCmp> trees2{ trees };
	while (!trees2.empty()) { 
		trees2.top()->printNode(); 
		trees2.pop(); 
		std::cout << " "; 
	}
	std::cout << '\n';


	std::cout << "\n Connected nodes:\n";
	while (trees.size() > 1) {
		std::shared_ptr<INode> childR = trees.top();
		trees.pop();

		std::shared_ptr<INode> childL = trees.top();
		trees.pop();

		std::shared_ptr<INode> parent = std::shared_ptr<INode>(new InternalNode(childR, childL));
		trees.push(parent);

		
		std::priority_queue<std::shared_ptr<INode>, std::vector<std::shared_ptr<INode>>, NodeCmp> trees3{ trees };
		while (!trees3.empty()) {
			trees3.top()->printNode(); 
			trees3.pop(); 
			std::cout << " "; 
		}
		std::cout << '\n';

	}
	return trees.top();
}

void GenerateCodes(const std::shared_ptr<INode> node, const HuffCode& prefix, HuffCodeMap& outCodes) {
	if (auto lf = std::dynamic_pointer_cast<const LeafNode>(node)) {
		outCodes[lf->symbol] = prefix;
	} else if (auto in = std::dynamic_pointer_cast<const InternalNode>(node)) {
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


	auto root = BuildTree(frequencies);

	HuffCodeMap codes;
	GenerateCodes(root, HuffCode(), codes);

	for (auto& code : codes) {
		std::cout << code.first << " ";
		std::copy(code.second.begin(), code.second.end(),
			std::ostream_iterator<bool>(std::cout));
		std::cout << '\n';
	}

	return 0;
}


