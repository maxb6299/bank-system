// account.h
// Data: balance, username, password, transactions
// Functions: 

#include <string>

class Account
{
private:
    float balance;
    float* transactions; // TODO make this a vector
    std::string username;
    std::string password;
    
public:
    Account(std::string u, std::string p, float b = 0);
    bool deposit(float n); // returns false if n <= 0
    bool withdrawal(float n); // see above & returns false if n > balance
    bool checkPassword(std::string p); // returns whether password is right
    std::string getUsername();
    float getBalance();
    float* getTransactions(); 
};