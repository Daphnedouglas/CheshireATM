#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

struct Bank {
    string f_name, l_name, ph_no, address, cnic;
    int amount;

    Bank() : f_name(""), l_name(""), ph_no(""), address(""), cnic(""), amount(0) {}

    void welcome() {
        cout << "\t\t\t\t\t\tMy Banking System!\t\t\t\t\t\t" << endl;
    }

    void info() {
        cout << "Please enter your first name: "; cin >> f_name;
        cout << "Please enter your last name: "; cin >> l_name;
        cout << "Please enter your phone no.: "; cin >> ph_no;
        //cout << "Please enter your address: "; cin >> address;
        cout << "Please enter your CNIC: "; cin >> cnic;
    }

    void display() {
        cout << "Your first name: " << f_name << endl;
        cout << "Your last name: " << l_name << endl;
        cout << "Your phone no.: " << ph_no << endl;
        cout << "Your address: " << address << endl;
        cout << "Your CNIC: " << cnic << endl;
        cout << "Your current amount is: " << amount << endl;
    }
};

int main() {
    int key;
    Bank b;
    do {
        b.welcome();
        cout << "Please select one option from the menu:\n";
        cout << "1. Account Open\n2. Deposit Amount\n3. Withdraw Amount\n4. Check Balance\n";
        cout << "5. Update Record\n6. Delete Record\n7. Search Record\n8. Exit\n";
        cin >> key;
        if (key == 1) {
            b.info();
            ofstream file("BankData.txt", ios::app);
            file << b.f_name << " " << b.l_name << " " << b.ph_no << " " << b.address << " " << b.cnic << " " << b.amount << endl;
            file.close();
            b.display();
            Sleep(3000);
            system("cls");
        }
        else if (key == 2) {
            string nam;
            int am = 0, count = 0;
            cout << "Please enter your first name: "; cin >> nam;
            ifstream file("BankData.txt");
            ofstream tempFile("temp.txt", ios::out);
            while (file >> b.f_name >> b.l_name >> b.ph_no >> b.address >> b.cnic >> b.amount) {
                if (nam == b.f_name) {
                    cout << "Name of account holder is: " << b.f_name << " " << b.l_name << endl;
                    cout << "Current amount is: " << b.amount << endl;
                    cout << "Please enter new amount: "; cin >> am;
                    b.amount += am;
                    cout << "Name of account holder is: " << b.f_name << " " << b.l_name << endl;
                    cout << "Current amount is: " << b.amount << endl;
                    tempFile << b.f_name << " " << b.l_name << " " << b.ph_no << " " << b.address << " " << b.cnic << " " << b.amount << endl;
                    count += 1;
                }
                else {
                    tempFile << b.f_name << " " << b.l_name << " " << b.ph_no << " " << b.address << " " << b.cnic << " " << b.amount << endl;
                }
            }
            tempFile.close();
            file.close();
            if (count >= 1) {
                remove("BankData.txt");
                rename("temp.txt", "BankData.txt");
            }
            Sleep(3000);
            system("cls");
        }
        else if (key == 3) {
            string nam;
            int am = 0, count = 0;
            cout << "Please enter your first name: "; cin >> nam;
            ifstream file("BankData.txt");
            ofstream tempFile("temp.txt", ios::out);
            while (file >> b.f_name >> b.l_name >> b.ph_no >> b.address >> b.cnic >> b.amount) {
                if (nam == b.f_name) {
                    cout << "Name of account holder is: " << b.f_name << " " << b.l_name << endl;
                    cout << "Current amount is: " << b.amount << endl;
                retry:
                    cout << "Please enter amount to withdraw: ";
                    cin >> am;
                    if (am <= b.amount) {
                        b.amount -= am;
                    }
                    else {
                        cout << "Amount being withdrawn is more than the available balance.\n";
                        goto retry;
                    }
                    cout << "Name of account holder is: " << b.f_name << " " << b.l_name << endl;
                    cout << "Updated amount is: " << b.amount << endl;
                    tempFile << b.f_name << " " << b.l_name << " " << b.ph_no << " " << b.address << " " << b.cnic << " " << b.amount << endl;
                    count += 1;
                }
                else {
                    tempFile << b.f_name << " " << b.l_name << " " << b.ph_no << " " << b.address << " " << b.cnic << " " << b.amount << endl;
                }
            }
            tempFile.close();
            file.close();
            if (count >= 1) {
                remove("BankData.txt");
                rename("temp.txt", "BankData.txt");
            }
            Sleep(3000);
            system("cls");
        }
        else if (key == 4) {
            string nam;
            cout << "Please enter your first name: "; cin >> nam;
            ifstream file("BankData.txt");
            bool found = false;
            while (file >> b.f_name >> b.l_name >> b.ph_no >> b.address >> b.cnic >> b.amount) {
                if (nam == b.f_name) {
                    cout << "Name of account holder is: " << b.f_name << " " << b.l_name << endl;
                    cout << "Current amount is: " << b.amount << endl;
                    found = true;
                    break;
                }
            }
            file.close();
            if (!found) {
                cout << "Computer is either searching or wasn't able to find your record.\n";
            }
            Sleep(3000);
            system("cls");
        }
        else if (key == 5) {
            string nam;
            int count = 0;
            char ke, opt;
            cout << "Please enter your first name: "; cin >> nam;
            ifstream file("BankData.txt");
            ofstream tempFile("temp.txt", ios::out);
            while (file >> b.f_name >> b.l_name >> b.ph_no >> b.address >> b.cnic >> b.amount) {
                if (nam == b.f_name) {
                    b.display();
                    cout << "=================================================================\n";
                    tempFile << b.f_name << " " << b.l_name << " " << b.ph_no << " " << b.address << " " << b.cnic << " " << b.amount << endl;
                choose_option:
                    cout << "To update first name (Press f).\nTo update last name (Press l).\n";
                    cout << "To update phone no. (Press p).\nTo update address (Press a).\nTo update CNIC (Press c).\n";
                    cin >> ke;
                    if (ke == 'f') {
                        cout << "Please enter your new first name: "; cin >> b.f_name;
                    }
                    else if (ke == 'l') {
                        cout << "Please enter your new last name: "; cin >> b.l_name;
                    }
                    else if (ke == 'p') {
                        cout << "Please enter your new phone number: "; cin >> b.ph_no;
                    }
                    else if (ke == 'a') {
                        cout << "Please enter your new address: "; cin >> b.address;
                    }
                    else if (ke == 'c') {
                        cout << "Please enter your new CNIC: "; cin >> b.cnic;
                    }
                    else {
                        cout << "Invalid option. Try again.\n";
                        goto choose_option;
                    }
                    tempFile << b.f_name << " " << b.l_name << " " << b.ph_no << " " << b.address << " " << b.cnic << " " << b.amount << endl;
                    cout << "Do you want to update another record? (y/n) ";
                    cin >> opt;
                    if (opt == 'n') {
                        count += 1;
                    }
                }
                else {
                    tempFile << b.f_name << " " << b.l_name << " " << b.ph_no << " " << b.address << " " << b.cnic << " " << b.amount << endl;
                }
            }
            tempFile.close();
            file.close();
            if (count >= 1) {
                remove("BankData.txt");
                rename("temp.txt", "BankData.txt");
            }
            Sleep(3000);
            system("cls");
        }
        else if (key == 6) {
            string nam;
            int count = 0;
            char ke;
            cout << "Please enter your first name: "; cin >> nam;
            ifstream file("BankData.txt");
            ofstream tempFile("temp.txt", ios::out);
            while (file >> b.f_name >> b.l_name >> b.ph_no >> b.address >> b.cnic >> b.amount) {
                if (nam == b.f_name) {
                    cout << "Name of account holder is: " << b.f_name << " " << b.l_name << endl;
                    cout << "Current amount is: " << b.amount << endl;
                    cout << "Do you really want to delete the record? (y/n) ";
                    cin >> ke;
                    if (ke == 'y') {
                        count += 1;
                    }
                    else {
                        tempFile << b.f_name << " " << b.l_name << " " << b.ph_no << " " << b.address << " " << b.cnic << " " << b.amount << endl;
                    }
                }
                else {
                    tempFile << b.f_name << " " << b.l_name << " " << b.ph_no << " " << b.address << " " << b.cnic << " " << b.amount << endl;
                }
            }
            tempFile.close();
            file.close();
            if (count >= 1) {
                remove("BankData.txt");
                rename("temp.txt", "BankData.txt");
            }
            Sleep(3000);
            system("cls");
        }
        else if (key == 7) {
            string nam;
            cout << "Please enter your first name: "; cin >> nam;
            ifstream file("BankData.txt");
            bool found = false;
            while (file >> b.f_name >> b.l_name >> b.ph_no >> b.address >> b.cnic >> b.amount) {
                if (nam == b.f_name) {
                    b.display();
                    found = true;
                    break;
                }
            }
            file.close();
            if (!found) {
                cout << "Computer is either searching or wasn't able to find your record.\n";
            }
            Sleep(3000);
            system("cls");
        }
    } while (key != 8);

    system("cls");
    b.welcome();
    cout << "\t\t\t\t\t Thank You for visiting our bank.\n\t\t\t\t\t";

    return 0;
}
