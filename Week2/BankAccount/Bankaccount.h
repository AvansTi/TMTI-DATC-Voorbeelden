#pragma once

#include <string>

class Bankaccount {

private:
	std::string lastName;
	std::string accountNumber;
	double balance;
	
public:
	Bankaccount(std::string lastName, std::string accountNumber) noexcept;
	Bankaccount() = delete;
	~Bankaccount() = default;


	void deposite(double amount);
	void withdraw(double amount);
	double getBalance();
	std::string getAccountNumber() const;
	std::string toString() const;

};
