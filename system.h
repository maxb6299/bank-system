// system.h
// 

#include "account.h"
#include <vector>

class System
{
public:
    System();    

    bool createAccount(std::string u, std::string p, int b = 0); // false if
                                                                 // username is
                                                                 // taken
    bool deleteAccount(std::string p); // false if wrong 
                                                      // credentials
    bool signIn(std::string u, std::string p); // return if credentials are 
                                               // correct and set currentUser
                                               // appropriately
    bool signOut(); // false if already signed out
    
    Account* currentUser; // address of currently signed in user 
                          // (null means signed out)
private:
    std::vector<Account> users;
};