#include "Account.h"

//Default Constructor
Account::Account() {
	balance = 0; 
	cfn[10] = ' ';
	cln[20] = ' ';
	acno = 0;
	type = " "; 
}

//Overloaded Constructor
Account::Account(int _acno, char _cfn[10], char _cln[20], double _balance, string _type) {
	acno = _acno; 
	strcpy_s(cfn, 10, _cfn); 
	strcpy_s(cln, 20, _cln);
	balance = _balance; 
	type = _type; 
}

//void Account::addAc() {
//	int temp;
//	char first[10], last[20];
//	double amount;
//	string acType;
//	cout << "Enter the account number" << endl;
//	cin >> temp;
//	cout << "Enter the customer's first and last name" << endl;
//	cin.getline(first, 10, ' ');
//	cin.getline(last, 20, '\n');
//	cout << "Enter the initial deposit amount." << endl;
//	cin >> amount;
//	cout << "Enter the account type: Checking or Savings." << endl;
//	cin >> acType;
//}

void Account::deposit(double amnt) {
	balance += amnt;
}

void Account::withdrawal(double amnt) {
	balance += amnt;
}

double Account::getBalance() const{
	return balance; 
}

string Account::getType() const{
	return type;
}

int Account::getAcno() const{
	return acno; 
}

void Account::setAcno(int num) {
	acno = num; 
}

void Account::setFirst(char _first[10]){
	for (int i = 0; i < 10; i++){
		cfn[i] = _first[i];
	}
}

void Account::setLast(char _last[20]){
	for (int i = 0; i < 20; i++){
		cln[i] = _last[i];
	}
}

void Account::setProduct(string _type){
	type = _type;
}

const char* Account::getFirst() const {
	return cfn;
}

const char* Account::getLast() const {
	return cln; 
}