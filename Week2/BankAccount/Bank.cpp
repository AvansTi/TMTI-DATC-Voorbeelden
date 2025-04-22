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
	Bankaccount vissers = { "Vissers", "12345" };
	vissers.deposite(1000.34);
	accounts.emplace_back(vissers);
	//accounts.push_back(vissers);
	vissers.deposite(1000.34);
	accounts.push_back(Bankaccount("Jansen", "23456"));

	addAccount(accounts, "Jantje", "666", 2000);

	//vissers.deposite(1000.34);

	for (Bankaccount b : accounts) {
		std::cout << b.toString() << std::endl;
	}
	
}

