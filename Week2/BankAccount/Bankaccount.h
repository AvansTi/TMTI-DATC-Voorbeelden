#pragma once

#include <string>

class Bankaccount {

private:
	std::string lastName;
	std::string accountNumber;
	double balance;
	
public:
	Bankaccount(std::string lastName, std::string accountNumber);
	void deposite(double amount);
	void withdraw(double amount);
	double getBalance();
	std::string getAccountNumber() const;
	std::string toString();

};
