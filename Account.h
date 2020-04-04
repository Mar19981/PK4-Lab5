#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
class BankAccount {
	double savings;
public:
	BankAccount(double amount);
	BankAccount() = default;
	void interest();
	friend std::ostream& operator<<(std::ostream& stream, const BankAccount& acc);
};

#endif // !ACCOUNT_H
