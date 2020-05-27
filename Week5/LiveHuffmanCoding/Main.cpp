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

void CreateFrequencyMap(const string& input, map<char, unsigned>& freqMap) {
	
	for (auto c : input) {
		freqMap[c]++;
	}

	for (auto p : freqMap) {
		cout << "Char: " << p.first << " : " << p.second << " times\n";
	}
}

INode* BuildHuffmanTree(map<char, unsigned>& freqMap) {
	priority_queue<INode*, std::vector<INode*>, NodeCmp> trees;

	for (auto p : freqMap) {
		trees.push(new LeafNode(p.first, p.second));
	}

	while (trees.size() > 1) {
		
		INode* left = trees.top();
		trees.pop();

		INode* right = trees.top();
		trees.pop();

		INode* internalNode = new InternalNode(left, right);
		trees.push(internalNode);
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

	// Create Frequency Map
	map<char, unsigned> freqMap;
	CreateFrequencyMap(inputString, freqMap);

	// Build Huffman Tree
	INode* root = BuildHuffmanTree(freqMap);

	// Generate Codes
	HuffCodeMap codes;
	GenerateCodes(root, HuffCode(), codes);
	delete root;

	// print codes 
	cout << "\nCodes:\n";
	for (auto& code : codes) {
		stringstream intCode;
		cout << code.first << " ";
		std::copy(code.second.begin(), code.second.end(), ostream_iterator<bool>(intCode));
		cout << intCode.str() << '\n';
	}

	cin.get();
	

	return 0;
}