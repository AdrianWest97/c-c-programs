//Name: Adrian West
//ID#: 20161739

#include "mortgage.h"

//Overloaded constructor that accepts values for the amount, rate and number of years
mortgage::mortgage(double a, double r, double y){
	setAmount(a);
	setRate(r);
	setYears(y);
}

//default constructor that initialize member functions to zero
mortgage::mortgage(){
	setAmount(0);
	setRate(0);
	setYears(0);
}

//set amount 
void mortgage::setAmount(double a){
	Amount = a;
}

//set rate
void mortgage::setRate(double r){
	Rate = r/100;
}

//set years
void mortgage::setYears(double y){
	years = y;
}

//get Amount
double mortgage::getAmount()const{
	return Amount;
}

//get Rate
double mortgage::getRate()const{
	return Rate;
}

//set years
double mortgage::getYears()const{
	return years;
}

//calculate and returns the monthly payment amount.
double mortgage::getPayment()const{
	return (Amount * (Rate/12)*getTerm())/(getTerm() - 1);
}

//calcuklate the term
double mortgage::getTerm()const{
return pow((1+(Rate/12)),12*years);
}

//calculates and returns tje total ampunt to
// the bank at the end of the loan period;
double mortgage::getTotalPaid()const{
	return getPayment()+ (years*Amount);
}

