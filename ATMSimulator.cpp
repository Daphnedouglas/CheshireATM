/*
Created by Thomas Chase
Created on April 30, 2020
*/

//This program will simulate a ATM

#include <iostream>

using namespace std;

//Function Prototypes
void balance(const double account[20], int accountNumber);
double deposit(double amount);
double withdraw(double amount, double account[20], int accountNumber);

//Global variables
double account[]{1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};

int main()
{
    int selection, accountNumber;
    bool loggedIn = false;

    cout << "Welcome to National University Bank." << endl;
    cout << "************************************" << endl;
    cout << "************************************" << endl;

    while(true){
        cout << "1. Sign in" << endl;
        cout << "2. Balance" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Exit" << endl;
        cout << "Please enter a selection (1-5) ";
        cin >> selection;

        if(selection <=5 && selection > 0){
                cout << "You entered a vaild seclection." << endl;
                cout << endl;
                switch(selection){

                    case(1):{
                                cout << "Please enter your account number: ";
                                cin >> accountNumber;
                                if(accountNumber >=0 && accountNumber < 10){
                                    cout << "Thank you for signing in." << endl;
                                    cout << endl;
                                    loggedIn = true;
                                }else{
                                    cout << "Invalid account number." << endl;
                                    cout << endl;
                                }
                                break;
                            }
                    case(2):{
                                if(loggedIn){
                                    balance(account, accountNumber);
                                }else{
                                    cout << "Sorry you are not signed in, please sign in and try again." << endl;
                                    cout << endl;
                                }
                                break;
                            }
                    case(3):{
                                if(loggedIn){
                                    double amount = 0;
                                    account[accountNumber] += deposit(amount);
                                }else{
                                    cout << "Sorry you are not signed in, please sign in and try again." << endl;
                                    cout << endl;
                                }
                                break;
                            }
                    case(4):{
                               if(loggedIn){
                                    double amount = 0;
                                    account[accountNumber] -= withdraw(amount,account,accountNumber);
                                }else{
                                    cout << "Sorry you are not signed in, please sign in and try again." << endl;
                                    cout << endl;
                                }
                                break;
                            }
                    case(5):{
                                if(loggedIn){
                                    cout << "Thank you for using National University Bank." << endl;
                                    cout << "*********************************************" << endl;
                                    cout << "Good bye.";
                                    cout << endl;
                                    cout << endl;
                                    cout << endl;
                                    loggedIn = false;
                                }
                            }
                }
            }else{
                cout << "That is not a vaild selection." << endl;
                cout << endl;
            }

        }
    return 0;
}

void balance(const double account[20], int accountNumber){
    int i = accountNumber;
    if(account[i] <= 100){
        cout << "Low balance." << endl;
        cout << endl;
    }else{
        cout << "Current balacne is $" << account[i] << endl;
        cout << endl;
    }
}

double deposit(double amount){
    int tries = 0;
    cout << "Please enter the ammount you want to deposit: $";
    cin >> amount;

    while(tries < 2){
        if(amount <= 0){
            cout << "Invalid amount." << endl;
            cout << endl;
            tries++;
            break;
        }else{
            return amount;
            break;
        }
    }
    return 0;
}

double withdraw(double amount, double account[20], int accountNumber){
    int tries = 0;
    cout << "Please enter the ammount you want to withdraw: $";
    cin >> amount;

    while(tries < 2){
        if(amount > 0 && account[accountNumber] >= amount){
            return amount;
            break;
        }else if(account[accountNumber] < amount){
            cout << "Insufficent funds current account balance is $" << account[accountNumber] << endl;
            cout << endl;
            break;
        }else if(amount <= 0){
            cout << "Invalid selection." << endl;
            cout << endl;
            break;
        }
    }
    return 0;
}
