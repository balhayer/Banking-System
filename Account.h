#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>

using namespace std;

class Account {
public:
	//Default Constructor
	Account();
	//Overload Constructor
	Account(int, char[], char[], double, string); 

	//Account functions
	//void addAc();
	void deposit(double); //deposit into account
	void withdrawal(double); //withdrawal from account
	//char getName() const; //return customer's name
	
	double getBalance() const; //return customer's balance
	string getType() const; //return account type
	int getAcno() const;
	const char* getFirst() const;
	const char* getLast() const; 
	void setAcno(int); 
	void setFirst(char[]);
	void setLast(char[]); 
	void setProduct(string); 
	void printReceipt(int, string, double); //print receipt 

private:
	double balance;
	char cfn[10];
	char cln[20];
	int acno; 
	string type; 
};

#endif 