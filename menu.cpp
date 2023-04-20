// menu.cpp

#include "system.h"
#include <iostream>
using namespace std;


class Menu
{
public:
    Menu()
    {
        system = System();
        mainMenu();
    }
    char getInput() // accepts input and turns it uppercase (for easier boolean)
    {
        char c;
        cout << ">";
        cin >> c;
        return toupper(c);
    }
    void mainMenu() // loops options until user inputs q to quit
    {
        char input = '\0';

        while (input != 'Q')
        {
            cout << "------------------------\n";
            
            cout << "    Main Menu\n\n"
                 << "C - Create Account\n"
                 << "S - Sign In\n"
                 << "Q - Quit Program\n";

            input = getInput();
            
            if (input == 'C') {menuCreateAccount();}
            else if (input == 'S') {menuSignIn();}
            else if (input != 'Q') {cout << "Invalid Input. Please try again.\n";}
        }
    }
    void menuCreateAccount()
    {
        string u;
        string p;
        int b;

        cout << "Username: ";
        cin >> u;
        cout << "Password: ";
        cin >> p;
        cout << "Initial Deposit: ";
        cin >> b;

        if (b < 0) 
        {cout << "Error: Negative deposit. Setting deposit to $0.\n";}
        
        if (!system.createAccount(u, p, b))
        {
            cout << "Error: Username Already Taken. Please try again.\n";
            menuCreateAccount();
        }
    }
    void menuSignIn()
    {
        string u;
        string p;

        cout << "Username: ";
        cin >> u;
        cout << "Password: ";
        cin >> p;

        if (!system.signIn(u, p))
        {
            cout << "Error. Invalid Credentials.\n";
            return;
        }
        accountMenu();
    }
    void accountMenu()
    {
        cout << "------------------------";

        cout << "\n    Welcome " << system.currentUser->getUsername()
             << "\n    Your balance is $" << system.currentUser->getBalance() 
             << "\n\n";

        char input;

        while (system.currentUser != NULL) // while not signed out
        {
            viewAccountMenu();
            input = getInput();
            
            if (input == 'C') {menuCreateAccount();}
            else if (input == 'D') {menuDeposit();}
            else if (input == 'W') {menuWithdrawal();}
            else if (input == 'V') {menuViewTransactions();}
            else if (input == 'M') {viewAccountMenu();}
            else if (input == 'R') {menuDeleteAccount();}
            else if (input == 'S') {menuSignOut();}
            else {cout << "Invalid Input. Please try again.\n";}
        }
    }
    void menuDeposit()
    {
        int n;

        cout << "How much would you like to deposit? ";
        cin >> n;
        
        system.currentUser->deposit(n);
    }
    void menuWithdrawal()
    {
        int n;

        cout << "How much would you like to withdrawal? ";
        cin >> n;
        
        system.currentUser->withdrawal(n);
    }
    void menuViewTransactions() // ! NOT FUNCTIONAL
    {
        // ! use of t is inefficient because copies array
        vector<int> t = system.currentUser->getTransactions(); 


        cout << "Your transaction history is: \n";
        for (int i = 0; i < t.size(); i++)
        {
            cout << t[i] << "\n";
        }
    }
    void viewAccountMenu()
    {
        cout << "D - Deposit\n"
             << "W - Withdrawal\n"
             << "V - View Transaction History\n"
             << "M - View This Menu\n"
             << "R - Delete Account\n"
             << "S - Sign Out\n";
    }
    void menuDeleteAccount()
    {
        cout << "***WARNING***\n"
             << "This will delete your account.\n"
             << "Please type in your password to confirm: ";

        string p;
        cin >> p;

        system.deleteAccount(p);
    }
    void menuSignOut()
    {
        system.signOut();
    }

private:
    System system;
};

int main()
{
    Menu menu;
}