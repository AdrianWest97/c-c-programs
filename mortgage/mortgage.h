#ifndef MORTGAGE_H
#define MORTGAGE_H
#include <iostream>
#include <cmath>

using namespace std;

// class
class mortgage{
	private:
	double Amount;
	double Rate;
	double years;
	
	public:
		mortgage(); //default constructor
		mortgage(double a, double r, double y); //overloaded constructor
		
		//setters and getters
		void setAmount(double a);
		void setRate(double r);
		void setYears(double y);
	
	
		//getters
		double getTerm() const;
		double getAmount() const;
		double getRate() const;
		double getYears() const;
		
		double getPayment() const;
		double getTotalPaid() const;
	
};

#endif
