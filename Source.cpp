#include <iostream>
#include <string>
#include <cstring>
#include "Account.h"

using namespace std;

void printOptions();

int main() {

	Account newAcc;
	Account everyone[100]; 
	int totalCustomers = 0; 
	double amount;
	char first[10], last[20]; 
	string product; 
	int accountNumber;
	bool found = false; 

	int answer; 
	
	do {
		cout << "Welcome to Johnson's Personal Banking System (JPBS).\nPlease choose one of the following options..." << endl;
		printOptions();
		cin >> answer; 
		switch (answer) {
		case 1: {
			cout << "Please enter the account number to assign to customer \n>> ";
			cin >> accountNumber;
			//Checks if account number is taken.
			for (int i = 0; i < totalCustomers; i++) {
				if (accountNumber == everyone[i].getAcno()) {
					cout << "Account number is already taken. Insert a new one. \n>> "; 
					cin >> accountNumber;
					//Resets count to 0 to check whole list again. 
					i = 0; 
				}
			}
			cout << "Enter the customers name in this format..." << endl;
			cout << "firstname lastname \n>> ";
			cin.getline(first, 10, ' ');
			cin.getline(last, 20, '\n');
			cout << "Enter the initial deposit amount" << endl;
			cout << ">> "; 
			cin >> amount;
			cout << "Enter the account type (checking / savings). \n>> ";
			cin >> product;
			newAcc.setAcno(accountNumber); 
			newAcc.setFirst(first);
			newAcc.setLast(last); 
			newAcc.setProduct(product); 
			newAcc.deposit(amount); 
			everyone[totalCustomers] = newAcc; 
			totalCustomers++; 
			cout << "Customer added." << endl << endl;
			break;
		}
		case 2:{
			cout << "Deposit Function" << endl; 
			cout << "Enter the customer's account number." << endl; 
			cin >> accountNumber;
			//Looks for account
			for (int i = 0; i < totalCustomers; i++) {
				if (accountNumber == everyone[i].getAcno()) {
					cout << "Account found. \n\n";
					cout << "Enter the amount of deposit. \n>> ";
					cin >> amount;
					everyone[i].deposit(amount);
					found = true; 
					break; 
				}
			}
			if (found == false){
				cout << "Could not find the account." << endl; 
			}

			//Changed back to false so system does not think it found an account in a future function
			found = false; 
			cout << endl; 
			break;

		}
		case 3: {
			cout << "Withdrawal function." << endl; 
			cout << "Enter the customer's account number." << endl; 
			cin >> accountNumber;
			//Looks for account
			for (int i = 0; i < totalCustomers; i++) {
				if (accountNumber == everyone[i].getAcno()) {
					cout << "Account found. \n\n";
					cout << "Enter the amount to withdraw. \n>> ";
					cin >> amount;
					everyone[i].withdrawal(amount);
					found = true;
					break;
				}
			}
			if (found == false){
				cout << "Could not find the account." << endl;
			}

			found = false;
			cout << endl; 
			break;
		}
		case 4: {
			cout << "Checking account information." << endl;
			cout << "Enter the customer's account number." << endl; 
			cin >> accountNumber;
			for (int i = 0; i < totalCustomers; i++) {
				if (accountNumber == everyone[i].getAcno()) {
					cout << "Account found. \n\n";
					cout << "Account number: " << everyone[i].getAcno() << endl;
					cout << "Account type: " << everyone[i].getType() << endl; 
					cout << "Name: " << everyone[i].getFirst() << " " << everyone[i].getLast() << endl; 
					cout << "Current balance: " << everyone[i].getBalance();
					found = true;
					break;
				}
			}
			if (found == false){
				cout << "Could not find the account." << endl;
			}

			found = false;
			cout << endl;
			break; 
		}
		case 5:{
			cout << "Exiting the program..." << endl; 
			break;
		}
		default:
			cout << "Please enter in an answer" << endl; 
			break; 
		}


	} while (answer != 5);


	return 0; 
}

void printOptions(){
	cout << "1. Add account." << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdrawal" << endl;
	cout << "4. Check balance" << endl;
	cout << "5. Quit" << endl;
}