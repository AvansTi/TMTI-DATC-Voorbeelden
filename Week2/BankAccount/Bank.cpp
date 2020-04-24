#include "Bankaccount.h"
#include <iostream>
#include  <string>
#include <vector>
#include <algorithm>



void addAccount(std::vector<Bankaccount>& accounts, const std::string& name, const std::string& number, int initVal) {

	Bankaccount account{ name, number };
	account.deposite(initVal);
	accounts.push_back(account);
}


int main() {

	std::vector<Bankaccount> accounts;
	Bankaccount goossens = { "Goossens", "12345" };
	goossens.deposite(1000.34);
	accounts.emplace_back(goossens);
	//accounts.push_back(goossens);
	goossens.deposite(1000.34);
	accounts.push_back(Bankaccount("Jansen", "23456"));

	addAccount(accounts, "Jantje", "666", 2000);

	//goossens.deposite(1000.34);

	for (Bankaccount b : accounts) {
		std::cout << b.toString() << std::endl;
	}
	
}

