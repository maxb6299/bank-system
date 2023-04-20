// system.cpp

#include "system.h"


System::System()
{
    users = {};
    currentUser = NULL;
}
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