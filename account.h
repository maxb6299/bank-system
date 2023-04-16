// account.h
// Data: balance, username, password, transactions
// Functions: 

#include <string>
#include <vector>

class Account
{
private:
    float balance;
    std::vector<int> transactions;
    std::string username;
    std::string password;
    
public:
    Account(std::string u, std::string p, float b = 0);
    bool deposit(float n); // store transaction and return false if n <= 0
    bool withdrawal(float n); // see above & return false if n > balance
    bool checkPassword(std::string p); // return whether password is right
    std::string getUsername();
    float getBalance();
    std::vector<int> getTransactions(); // deposits are +, withdrawals are -
};