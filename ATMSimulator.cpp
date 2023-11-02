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
	char ch;
	int num; 
	
	cout << "\t\t -------------------------------------------" << endl;
	cout << "\t\t | Welcome to the Cheshire Bank Management |" << endl;
	cout << "\t\t -------------------------------------------" << endl
	
	cout << endl;
	cout << "\t-----Main Menu-----";
	cout << "\t 1. Create Account" << endl;
	cout << "\t 2. Deposit Money" << endl;
	cout << "\t 3. Withdraw Money" << endl;
	cout << "\t 4. Balance Enquiry" << endl;
	cout << "\t 5. All Account Holder List" << endl;
	cout << "\t 6. Close an Account" << endl;
	cout << "\t 7. Modify an Account" << endl;
	cout << "\t 8. Exit" << endl;
	cout << endl;
	
	cout << "\t Enter your choice : ";
	cin >> ch;
	
	switch(ch){
		case '1':
			
			break;
		case '2':
			system("cls");
			cout << "\t Enter Account Number : ";
			cin >> num;
			// deposit function
			break;
		case '3':
			system("cls");
			cout << "\t Enter Account Number : ";
			cin >> num;
			// withdraw function
			break;
		case '4':
			system("cls");
			cout << "\t Enter Account Number : ";
			cin >> num;
			//  balance enquiry function
			break;
		case '5':
			//display_all(); //display all function
			break;		
		case '6':
			system("cls");
			cout << "\t Enter Account Number : ";
			cin >> num;
			//  close enquiry function
			break;
		case '7':
			system("cls");
			cout << "\t Enter Account Number : ";
			cin >> num;
			//  modify account function
			break;
		case '8':
			cout << "\t Thanks for using Cheshire Bank Management" << endl;
			break ;
	}
	Bank_Account B ;
	B.create_account();
	B.Display_Account();
	return 0;	
}




