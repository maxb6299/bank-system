// account.h

// stores bank account data (transaction history, balance, username, password)
// allows for deposit/withdrawal and password check

#include <string>
#include <vector>

class Account
{
public:
    Account(std::string u, std::string p, float b);
    bool deposit(float n); // saves transaction and returns false if n <= 0
    bool withdrawal(float n); // saves transaction & returns false if n <= 0 
                              // or n > balance
    bool checkPassword(std::string p) const; // returns if password is right
    std::string getUsername() const;
    float getBalance() const;
    std::vector<int> getTransactions() const; // array of transaction history

private:
    float balance;
    std::vector<int> transactions; // history of deposits (positive num) and
                                   // withdrawals (negative num)
    std::string username;
    std::string password;
};