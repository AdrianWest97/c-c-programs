#include "account.h"
//default constructor
account::account(){
	Balance =0;
	AnnualInterestRate =0.0;
	Id = 0;
}

//set account id
void account::setId(int id){
	Id = id;
}
//get accountID
int account::getId() const{
	return Id;
}


//set account balance
void account::setBalance(double bal){
	Balance = bal;
}

//get account balance
double account::getBalance() const{
	return Balance;
}

//set annual interest rate
void account::setAnnualInterestRate(double rate){
	AnnualInterestRate = rate;
}

//get annula interest rate
double account::getAnnualInterestRate() const{
return AnnualInterestRate;
}

//get monthly interest rate
double account::getMonthlyInterestRate(){
	return (getAnnualInterestRate()/12);
}

//make a deposit
double account::deposit(int amount){
	setBalance(getBalance()+amount);
}

//withdraw x amount
double account::Withdraw(double amount){
	setBalance(getBalance()-amount);
}

//display 
void account::display(){
	cout <<endl <<endl;
	cout <<"\t***** Summary *****" <<endl;
	cout <<"\tID#: "<<getId();
	
	cout <<"\tAccount Balance($): " <<getBalance();
	
	cout <<"\tMonthly Interest rate(%): " <<getMonthlyInterestRate() <<"%" <<endl<<endl;
}

