// account.cpp

#include "account.h"

Account::Account(std::string u, std::string p, float b = 0)
{
    username = u;
    password = p;
    balance = b;
    transactions.reserve(5); // set array to capacity of 5
}
bool Account::deposit(float n)
// store transaction and return false if n <= 0
{
    balance += n;
    transactions.push_back(n);
}
bool Account::withdrawal(float n)
// see above & return false if n > balance
{
    balance += n;
    n += -1; // so withdrawal shows as negative
    transactions.push_back(n);
}
bool Account::checkPassword(std::string p)
// return whether password is right
{
    return p == password;
}
std::string Account::getUsername()
{
    return username;
}
float Account::getBalance()
{
    return balance;
}
std::vector<int> Account::getTransactions()
// deposits are +, withdrawals are -
{
    return transactions;
}