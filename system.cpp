// system.cpp

// stores array of users (Account objects)
// allows signing in/out and creation/deletion of accounts

// signs in through setting pointer currentUser to signed in account and 
// accesses account functions through a getter to ensure currentUser can't be
// inappropriately changed


#include "system.h"


System::System()
{
    users = {};
    currentUser = NULL;
}
// false if username is taken
bool System::createAccount(std::string u, std::string p, int b)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (u == users[i].getUsername()) // ensures username is unique
        {
            return false;
        }
    }
    users.emplace_back(u, p, b); 
    return true;
}
// false if wrong credentials
bool System::deleteAccount(std::string p)
{
    if (!currentUser->checkPassword(p)) {return false;}

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getUsername() == (currentUser->getUsername()))
        {
            users.erase(users.begin()+i);
            currentUser = NULL; // signs out
            return true;
        }
    }

    return false;
}
// return if credentials are correct and set currentUser appropriately
bool System::signIn(std::string u, std::string p)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (u == users[i].getUsername() && users[i].checkPassword(p)) 
        // if username and password are right
        {
            currentUser = &users[i]; 
            return true;
        }
    }
    return false;
}
// false if already signed out
bool System::signOut()
{
    if (currentUser != NULL)
    {
        currentUser = NULL;
        return true;
    }
    return false;
}

Account* System::getCurrentUser()
{
    return currentUser;
}
