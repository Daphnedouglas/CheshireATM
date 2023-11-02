#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cctype>


using namespace std;

class Bank_Account{
	int account_number;
	char name[50];
	int PIN;
	int Money_Deposit;

public :
	void create_account();
	void Display_Account();
	
};

void Bank_Account :: create_account(){
	system("cls");
	cout << "\t Enter Card Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout << "\t Enter Account Number : ";
	cin >> account_number;
	cout << "\t Enter PIN Number : ";
	cin >> PIN;
	cout << "\t Enter Initial amount ( >= 500 for Saving and >= 1000 for current ) : ";
	cin >> Money_Deposit;
	// cari loading before ada account create
	

	
	
	cout << "\t Account Created..........:) \n";
}

void Bank_Account :: Display_Account(){
	
	cout << "\t Account Holder Name : " << name << endl;
	cout << "\t Account Number : " << account_number << endl;
	cout << "\t PIN Number : " << PIN << endl;
	cout << "\t Balance Amount : " << Money_Deposit << endl;
}

int main()
{
	Bank_Account B ;
	B.create_account();
	B.Display_Account();
	return 0;	
}




