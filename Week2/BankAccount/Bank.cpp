#include "Bankaccount.h"
#include <iostream>
#include  <string>
#include <vector>
#include <algorithm>



int main() {

	std::vector<Bankaccount> accounts;
	Bankaccount goossens = { "Goossens", "12345" };
	goossens.deposite(1000.34);
	accounts.push_back(goossens);
	accounts.push_back(Bankaccount("Jansen", "23456"));

	//goossens.deposite(1000.34);

	for (Bankaccount b : accounts) {
		std::cout << b.toString() << std::endl;
	}
	
}
