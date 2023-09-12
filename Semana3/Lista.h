#pragma once
#include <iostream>
#include <string>
using namespace std;

class Lista
{
private:
	unsigned int accountName;
	string firstName, lastName;
	double balance;

public:
	Lista(unsigned int accountName_, string firstName_, string lastName_, double balance_) {
		accountName = accountName_;
		firstName = firstName_;
		lastName = lastName_;
		balance = balance_;
	}

	void setAcna(unsigned int accountName_) {
		accountName = accountName_;
	}
	void setFirst(string firstName_) {
		firstName = firstName_;
	}
	void setLast(string lastName_) {
		lastName = lastName_;
	}
	void setBala(double balance_) {
		balance = balance_;
	}

	unsigned int getAcna() {
		return accountName;
	}
	string getFirst() {
		return firstName;
	}
	string getLast() {
		return lastName;
	}
	double getBala() {
		return balance;
	}

	void getDisplay() {

		cout << "Nombre: " << getFirst() << endl;
		cout << "Apellido: " << getLast() << endl;
		cout << "Numero de cuenta: " << getAcna() << endl;
		cout << "Balance: " << getBala() << endl;
	}
};
