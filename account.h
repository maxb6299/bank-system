// account.h
// Stores account data and allows for modification of it. Data includes 
// username, password, balance, transaction history

#include <string>
#include <vector>

class Account
{
public:
    Account(std::string u, std::string p, float b);
    bool deposit(float n); // store transaction and return false if n <= 0
    bool withdrawal(float n); // see above & return false if n > balance
    bool checkPassword(std::string p) const; // return whether password is right
    std::string getUsername() const;
    float getBalance() const;
    std::vector<int> getTransactions() const; // deposits are +, withdrawals are -

private:
    float balance;
    std::vector<int> transactions;
    std::string username;
    std::string password;
};