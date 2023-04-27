// account.cpp

// stores bank account data (transaction history, balance, username, password)
// allows for deposit/withdrawal and password check


#include "account.h"

Account::Account(std::string u, std::string p, float b)
{
    username = u;
    password = p;
    balance = b > 0 ? b : 0; // set balance to 0 if b is negative
    transactions.reserve(5); // set array to capacity of 5
}
// saves transaction and returns false if n <= 0
bool Account::deposit(float n)
{
    if (n <= 0)
    {
        return false;
    }
    
    balance += n;
    transactions.push_back(n);
    return true;
}
// saves transaction & returns false if n <= 0 or n > balance
bool Account::withdrawal(float n)
{
    if (n <= 0 || n > balance)
    {
        return false;
    }
    
    n += -1; // so withdrawal shows as negative
    balance += n;
    transactions.push_back(n);

    return true;
}
// returns if password is right
bool Account::checkPassword(std::string p) const
{
    return p == password;
}
std::string Account::getUsername() const
{
    return username;
}
float Account::getBalance() const
{
    return balance;
}
// returns array of transaction history
std::vector<int> Account::getTransactions() const
{
    return transactions;
}