#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<iostream>
#include<string>
using namespace std;


class account{
private:
	
int Id;
double Balance;
double AnnualInterestRate;

public:
	
account();

void setId(int id);

int getId() const;

void setBalance(double bal);

double getBalance() const;

void setAnnualInterestRate(double interestRate);

double getAnnualInterestRate() const;

double getMonthlyInterestRate();

double Withdraw(double amount);

double deposit(int amount);

void display();
};
#endif

