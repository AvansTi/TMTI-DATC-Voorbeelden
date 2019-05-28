#include <iostream>
#include <map>
#include "Node.h"
#include <vector>
#include <queue>
#include <xatomic.h>
#include <iterator>
#include <sstream>


using namespace std;

typedef std::vector<bool> HuffCode;
typedef std::map<char, HuffCode> HuffCodeMap;

void CreateFrequencyTable(const string& input, map<char, unsigned>& freqMap) {
	// Build the map
	for (auto c: input) {
		freqMap[c]++;
	}

	// Print the map
	cout << "Frequency Map: \n";
	for (auto pair : freqMap) {
		cout << pair.first << " : " << pair.second << '\n';
	}
}

INode* BuildTree(map<char, unsigned>& freqMap) {

	priority_queue<INode*, std::vector<INode*>, NodeCmp> trees;

	for (auto f : freqMap) {
		trees.push(new LeafNode(f.first, f.second));
	}

	while (trees.size() > 1) {
		INode* left = trees.top();
		trees.pop();

		INode* right = trees.top();
		trees.pop();

		trees.push(new InternalNode(left, right));

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

	std::string inputString{ "Heel veel ees's" };

	// Build frequency table
	map<char, unsigned> frequencyMap;
	CreateFrequencyTable(inputString, frequencyMap);

	// Build tree
	INode* rootNode = BuildTree(frequencyMap);

	// Assign code
	HuffCodeMap codes;
	GenerateCodes(rootNode, HuffCode(), codes);
	delete rootNode;


	cout << "\nCodes:\n";
	for (auto& code : codes) {
		std::stringstream intCode;
		std::cout << code.first << " ";
		std::copy(code.second.begin(), code.second.end(),
			std::ostream_iterator<bool>(intCode));

		std::cout << intCode.str() << '\n';
	}

	cin.get();
	

	return 0;
}