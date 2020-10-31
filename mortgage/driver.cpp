//Name: Adrian West
//ID#: 20161739

#include "mortgage.h" //implement class
int main(){

	mortgage m; //create an object
	
	double amount;
	double rate;
	double years;

    //prompt user to enter loan information
    cout <<"\n\n\t\t------ Home mortgage calculator -------";
    cout <<"\n\n\tEnter Loan Amount ($) ";
    cin >>amount;
    cout <<"\n\tEnter Rate (%) ";
    cin >>rate;
    cout <<"\n\tEnter number of years ";
    cin >>years;
    
    m.setAmount(amount);
    m.setRate(rate);
    m.setYears(years);
    
     cout <<"\n\t----------------------------------";
	cout <<"\n\tTerm is " <<m.getTerm() <<endl;
	cout <<"\n\tMonthly payment is ($) " <<m.getPayment() <<endl;
	cout <<"\n\tTotal paid to bank ($) " <<m.getTotalPaid()<<endl <<endl;
	
	system("pause");
	
	
	return 0;
}
