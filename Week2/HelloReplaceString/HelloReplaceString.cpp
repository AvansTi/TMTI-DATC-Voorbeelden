/*#include <iostream>
#include <string>*/

import std.core;


using namespace std;

// Replace oldSubStr in s with newSubStr
bool replaceString(string& s, const string& oldSubStr, const string& newSubStr);

int main() {
	// Prompt the user to enter s, oldSubStr, and newSubStr
	cout << "Enter string s, oldSubStr, and newSubStr: ";
	string s, oldSubStr, newSubStr;
	cin >> s >> oldSubStr >> newSubStr;

	bool isReplaced = replaceString(s, oldSubStr, newSubStr);

	if (isReplaced)
		cout << "The replaced string is " << s << endl;
	else
		cout << "No matches" << endl;

	return 0;
}

bool replaceString(string& s, const string& oldSubStr, const string& newSubStr) {
	bool isReplaced = false;
	int currentPosition = 0;
	while (currentPosition < s.length()) {
		int position = (int)s.find(oldSubStr, currentPosition);
		if (position == string::npos) // Mo more matches
			return isReplaced;
		
		s.replace(position, oldSubStr.length(), newSubStr);
		currentPosition = position + (int)newSubStr.length();
		isReplaced = true; // At least one match
	
	}

	return isReplaced;
}