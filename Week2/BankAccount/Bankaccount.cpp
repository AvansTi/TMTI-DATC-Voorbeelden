#include "Bankaccount.h"
#include <sstream>

Bankaccount::Bankaccount(std::string lastName, std::string accountNumber) :
lastName(lastName), accountNumber(accountNumber), balance(0) {
	
}

void Bankaccount::deposite(double amount) {
	this->balance += amount;
}

void Bankaccount::withdraw(double amount) {
	this->balance -= amount;
}

double Bankaccount::getBalance() {
	return balance;
}

std::string Bankaccount::getAccountNumber()  const {
	//accountNumber = "";
	return accountNumber;
}

std::string Bankaccount::toString() {
	std::ostringstream os;
	os << lastName << ": number: " << accountNumber;
	os << ", balance: " << balance;

	return os.str();
}

