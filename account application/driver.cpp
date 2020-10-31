#include "account.h"


int menu(){
	int opt;
    cout <<"\t1. Withdraw   2.Deposit   3. Account Balance 0.EXIT ";
	cin >> opt;
	return opt;
}
int main(){
	
	int opt;
	int amount,id, interest;
	
    account acc;
    
	acc.setId(1122);
	
	acc.setBalance(20000);
	
	acc.setAnnualInterestRate(0.045);
	
	acc.Withdraw(2500);
		
	acc.deposit(3000);
		
	 
	cout <<"\tA deposit of $3000 was made" <<endl;
	
	cout <<"\t$2,500 was withdrawn"<<endl;
	
	acc.display();
	
	opt = menu();
	
	while(opt!=0){
	switch(opt){
		case 1:
			cout << "\tEnter your ID to withdraw: ";
			cin>>id;
		      	while(id < 0){
					if(id < 0){
						cout <<"\tId must be a positive number (Enter id): ";
						cin >>id;
				}
			}
		
			
			cout << "\tEnter amount you want to withdraw: ";
		   	cin>>amount;
		   	while(amount < 0){
		   		cout <<"\tAmount must be greater than 0 (Enter amount) ";
		   		cin>>amount;
			   }
			cout <<"\tEnter annual interest rate: ";
		   	cin >> interest;
			while(interest < 0){
			cout <<"\tInterest rate must be greater than 0 (Enter interest rate) ";
		   	cin >> interest;
			}
		   
			acc.Withdraw(amount);
			acc.setAnnualInterestRate(interest);
			acc.setId(id);

			acc.display();		   
			
			
			break;
			
			case 2:
					cout << "\tEnter your ID to deposit: ";
			cin>>id;
		      	while(id < 0){
					if(id < 0){
						cout <<"\tId must be a positive number (Enter id): ";
						cin >>id;
				}
			}
					
			cout << "\tEnter deposit amount: ";
		   	cin>>amount;
		   	while(amount < 0){
		   		cout <<"\tAmount must be greater than 0 (Enter amount) ";
		   		cin>>amount;
			   }
			//deposit the amount
			acc.deposit(amount);
			acc.setId(id);
			acc.display();
		 
		break;
		case 3:
			acc.display();
			break;
			default:
				cout <<"Invalid option";
				
	}
	opt = menu();
}
	
	 
}


