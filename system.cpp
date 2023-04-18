// system.cpp

#include "system.h"


System::System()
{
    users = {};
    currentUser = NULL;
}
bool System::createAccount(std::string u, std::string p, int b = 0)
{
    users.emplace_back(u, p, b);
}
bool System::deleteAccount(std::string p)
{
    if (!currentUser->checkPassword(p)) {return false;}

    // TODO iterate through and delete
    return true;
}
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
bool System::signOut()
{
    if (currentUser != NULL)
    {
        currentUser = NULL;
        return true;
    }
    return false;
}