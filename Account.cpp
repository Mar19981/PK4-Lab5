#include "Account.h"

BankAccount::BankAccount(double amount): savings(amount)
{
}

void BankAccount::interest()
{
	savings *= 1.02;
}

std::ostream& operator<<(std::ostream& stream, const BankAccount& acc)
{
	return stream << "You've got " << acc.savings << "zl on your account.\n";
}
