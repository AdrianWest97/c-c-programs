/*
Programmer : Adrian West
Date: January 4, 2016
School: Spalding High
Teacher:

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include  <string.h>
#include <windows.h>
#include <ctype.h>
#include <dos.h>

#define date __DATE__
#define time __TIME__


/*
Description

This c program simulates a student registration program for CAPE students
the program takes the following inputs:
Applicant ID, Applicant first and Last name ,Applicant D.O.B,Applicant Address,Applicant Sex,Applicant previous school and cxc subjects
The program then filter out the applicants meeting the right criteria and display them.
The program also features a search function where the user inputs the Applicant ID and 
the program then prints on screen information based on the particular ID
The user password and username are not predefined and ca be changed in the setings function

*/


char userName[20],userPass[20];//stores the login username and password

//structure of variables to store applicant information
struct apllicantData{
char fn[10],ln[10];
char phone[8];
char appID[4];
char address[100];
int numofsub;
char sex[7],prevSchool[20];
int day,year,month;
char regDate[15];
char math[3],english[3];
char grdMath,grdEng;
}applicant;


//for setting up the program
struct setupProgram{
	char user_name[20];
	char user_pass[20];
}set;

//gotoxy statement
COORD coord = {0,0};
void gotoxy(int x,int y){
	coord.X=x;coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


//system clear screen
void clrscr(){
	system("cls");
}


//A loder animation to display on screen
void loader(char display[20]){
	int i;int j;
	clrscr();
	system("COLOR e5");
    char sign[3]="%";
	gotoxy(30,6);
	printf("%s",display);
	for(i=0;i<20;i++){
	Sleep(100);
	gotoxy(30,8);
	for(j=0;j<i;j++){
		printf("\xDB");
	 }//endfor
	 printf(" %d%c ",i+71,37);
	}//endfor	
//	printf("Complete");
	Sleep(200);
}

//define functions
void login(char Lmsg[50]);
void setup_check();
void loader(char display[20]);
void setup_user(int flag,char msg[30]);
void mainScreen(void);
void welcomeScreen(void);
void settings(void);

//main program functions
void processApp(void);//create a new application 
void searchID(void);//search for an applicant 
void viewApp(void);//view all applications
void AccepApp(void);//applications that are accepted
void Settings(void);//program settings
void Display_App(void);
  
  
//check to see if program is setup;  
void setup_check(){
FILE * f1;
int flag=0;
f1=fopen("setup.txt","r");
//check if setup file exits
while(fread(&set,sizeof(set),1,f1)==0){
	char msg[30]="SETUP LOGIN INFORMATION";
	setup_user(flag=1,msg);
	break;
}
//if the file doesnt exits then goto the login function
char Lmsg[50]="LOGIN WITH USERNAME AND PASSWORD";
login(Lmsg);
}

//setup user login information
void setup_user(int flag,char msg[30]){
	FILE * s1;
	char pass1[20],pass2[20];
	clrscr();
    if(flag == 1){
    clrscr();
    gotoxy(20,2);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB %s \xDB\xDB\xDB",msg);
	s1=fopen("setup.txt","wb");
	gotoxy(10,5);
	printf("ENTER USERNAME\t |  ");
	scanf("%s",&set.user_name);
		gotoxy(10,7);
				printf("ENTER PASSWORD\t |  ");
				scanf("%s",&set.user_pass);	
				//write to file now
    		fwrite(&set,sizeof(set),1,s1);
         }
	       fclose(s1);
				char Lmsg[50]="AH! :-) NOW LOGIN FOR THE FIRST TIME....";
					login(Lmsg);
	}



    //program main
	int main(){
		clrscr();
		system("COLOR 3f");
		//main function to call first
		setup_check();
		getch();
	}

	

	void login(char Lmsg[50]){
		FILE *fts;
		int count=0;
		int c=5;
		
		//display loader function
		char display[40]="CAPE REGISTRATION SYSTEM";
		loader(display);
		char un[20],up[20];
		// a goto statemant to repeat a block of code
		repeatLogin :{
		//clears the screen
		
		clrscr();
		system("COLOR 3f");
		gotoxy(20,1);
		printf("[%s]",date);
		gotoxy(8,3);
		//prints the login message
		printf("%s (5 attempts)[%d remain]",Lmsg,c);
		
	//Now we get the login username and password from file
		fts=fopen("setup.txt","r");
		while(fread(&set,sizeof(set),1,fts)==1){
		//we copy the login username and passwords to the userName and userPass variables
		strcpy(userName,set.user_name);
		strcpy(userPass,set.user_pass);
		//now we exit the loop
		break;
		//close the file we opened
	   }fclose(fts);
	   //now we let the user login with their login informaton
	   printf("\n\t(CAsE sEnSiTive)");
	  gotoxy(10,6);
	  printf("LOGIN USERNAME \t| ");
	  scanf("%s",&un);
	  gotoxy(10,8);
	  printf("LOGIN PASSWORD \t| ");
	  scanf("%s",&up);
}//end goto statement


     //now we verify the login information
	   strcpy(display,"VERIFYING LOGIN .....");
	    	loader(display);
	    	//check to see if information match
	    	//alternative username:admin, password:adminpass
	    	if(strcmp(un,userName)==0 && strcmp(up,userPass)==0 || strcmp(un,"admin")==0 && strcmp(up,"adminpass")==0){
	    		gotoxy(30,6);
	    		//if true we go to the mainScreen
	    		mainScreen();
			}else{
				//else we repeat the block of code by going to the goto statement
			  count=count+1;
			  c = c-1;
		      goto label2;
		    
		}
		
	    label2: {
		if(count == 5){
		clrscr();
		gotoxy(10,2);
		printf("YOU HAVE EXEEDED INPUT...");
		gotoxy(20,4);
		printf("PLEASE CONTACT ADMINISTRATOR... \n \t\t\t(Delete Setup File)");
		if(getch())
		exit(0);
     	}else{
     		goto repeatLogin;
		 }
	}
}
	
	//mainScreen we=here we display the menu
	void welcomeScreen(){
		char swt;//variable of operation
		clrscr();
		system("COLOR 3f");
		gotoxy(25,1);
		//function header
		printf("CAPE STUDENT REGUSTRATION SYSTEM");
		gotoxy(30,3);
		//prints out the date
		printf("Date: %s",date);
		gotoxy(30,6);
		//ask user weather they want t login or exit the program
		printf("1. LOGIN\t 2.EXIT PROGRAM	");
	    scanf("%s",&swt);
		//message to display on login screen
		char Lmsg[50]="LOGIN WITH USERNAME AND PASSWORDE";
		
		switch(swt){
			case '1':login(Lmsg);//goto login screen
			break;
			case '2':exit(0);//exit the program
			break;
			default:{
				printf(" Incorrect option ...");
				if(getch())
				welcomeScreen();//show back the same screen
				break;
			}
		}//end swtich
	}
	
	
	//SEARCH FOR APPLICANTS BY ID;
void searchID(){
	FILE * fp;//points to a specific file
  char id[4];
  int c=0;
  char cont;//variable for decission
  //do while loop starts
 		 do{
  		clrscr();
  			gotoxy(20,2);
  				printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Search for an applicant by ID \xDB\xDB\xDB");
  						//opens the file storing applications
  					fp=fopen("applicant.txt","rb+");
 				 rewind(fp);
 				 //prompt for the ID to search for
 			 printf("\n\n\t Enter Applicant ID to search: ");
 		 scanf("%s",&id);
 		 //search for it in the file
  				while(fread(&applicant,sizeof(applicant),1,fp)==1)
 					 {
  						  if(strcmp(applicant.appID,id)==0){
  						  	//display information based on the ID given
    							Display_App();
    							c=1;
    							break;
 					 }
	    	}fclose(fp);
			//if no file is found we display the error message
			 if(c==0)
 			 printf("\n\n\tNo record found");
  				
		//ask user if they want to search again
    	 printf("\n\n\t\tSEARCH AGAIN?(Y/N): ");
    	 printf("\n\t_____________________________________________________________\n");
    			cont=getch();
    			c=0;
 					}while(cont == 'y');
 					//return to main screen if not
						mainScreen();
	}
							
	//main screen to display menu and stuff					
	void mainScreen(){
	clrscr();
	system("COLOR 3f");
	gotoxy(20,1);
	printf("SPALDING HIGH CAPE STUDENT REGUSTRATION SYSTEM");
	gotoxy(30,3);
	printf("[Date: %s, %s]",date,time);
	gotoxy(30,4);	
	//a 2D array that stores the menu
	char menu[6][100]={"PROCESS APPLICANT","SEARCH BY ID","VIEW ALL APPLICATIONS",
	                     "ACCEPTED APPLICANTS","SETTINGS","LOGOUT"};
	int i,j;//variables to print out the menu

	//prints the first three options from menu
	for(i=0;i<3;i++){
		gotoxy(10,i+6);
		printf("\xDB\xDB %d %s",i+1,menu[i]);
	}
	//prints the second set
	for(j=3;j<6;j++){
		gotoxy(40,j+3);
		printf("\xDB\xDB %d %s",j+1,menu[j]);
	}
	gotoxy(10,10);
	printf("Select a # ");
	char opt;
	scanf("%c",&opt);
	switch(opt){
		case '1':{
			//if number 1 is selected
			processApp();
	break;		
     	}
     	case '2':{
     			//if number 2 is selected
     			searchID();
     		break;
     	}
     	case '3':{
     			//if number 3 is selected
     				viewApp();
     		break;
     	}
     	case '4':{
     			//if number 4 is selected
     			AccepApp();
     		break;
		 }
		 case '5':{
		 		settings();
		 	break;
		 }
		 case '6':{
		 		//if number 6 is selected we logout user and clear variables
		 		char Lmsg[50]="Logging out....";
		 		loader(Lmsg);
		 		strcpy(userName,"");
		 		welcomeScreen();
		 break;
		 }
		 default :{
		 	printf("Incorrect option..");
		 	if(getch()){
		 		mainScreen();
			 }
			break;
		 }
	}
}
	
	
	//create an application
   void processApp(){
   	
    FILE * proc;
    char k[3], res;
    char cont;
    char id[4];
    bool flag;

    clrscr();
    gotoxy(10,2);
     //copy registration date
     strcpy(applicant.regDate,date);
     //prompt user for applicant infomration
    printf("Enter details to create application");
         	//gotoxy(10,4);
         	
        while(flag == false){
       
         	flag = true;
     			printf("\n\n\tAPPLICANT ID[4]        -->\t");
     				scanf("%s",&id);
     				
     			if(strlen(id)!=4){
     					printf("\n\tMust be 4 digits");
     				flag = false;
					 }
					 		
     }
     	strcpy(id,applicant.appID);
   
     	
    				    
    					 printf("\n\tAPPLICANT FIRST NAME -->\t");
    						 scanf("%s",&applicant.fn);
    			 printf("\n\tAPPLICANT LAST NAME  -->\t");
    			 scanf("%s",&applicant.ln);
    				 gets(k);
    			 printf("\n\tGENDER[MALE/FEMALE]  --> \t");
    			 gets(applicant.sex);
	 				printf("\n\tAPPLICANT ADDRESS    -->   \t");
	 					gets(applicant.address);
	
	 			char num[7];
	 			
	 			    do{					 
	 				printf("\n\n\tAPPLICANT PHONE      -->[000-0000]  \t");
	 					scanf("%s",&num);
						 //we verify that the values entered are numbers	
	 					if(!isdigit(num[7])){
	 						printf("\n\tINCORRECT FORMAT");
						 }
				}while(!isdigit(num[7]));
				strcpy(applicant.phone,num);
	
	 						//applicant date of birth
	 					
							 
							printf("\n\tAPPLICANT D.O.B");
							do{	
						printf("\n\tYEAR [YYYY]\t");
							scanf("%d",&applicant.year);
								if(isalpha(applicant.year)){
	 						printf("\n\tINCORRECT FORMAT");
	 					}
						 }while(isalpha(applicant.year));
												
									printf("\tMONTH [MM]\t");
							scanf("%d",&applicant.month);
					printf("\tDAY [DD]\t");
							scanf("%d",&applicant.day);
								printf("\n");
				
								
								gets(k);
								printf("\n\tAPPLICANT PREVIOUS SCHOOL --> \t");
									gets(applicant.prevSchool);
								printf("\n\tNUMBER OR CXC SUBJECTS     --> \t");
							scanf("%d",&applicant.numofsub);
					if(applicant.numofsub > 1){
	   			 printf("\n\tMATHEMATICS INCLUDE[Y/N]   --> \t");
	   			 scanf("%s",&applicant.math);
	   					 if(strcmp(applicant.math,"y")==0 || strcmp(applicant.math,"Y")==0 ){
	   							 printf("\n\tGRADE IN MATHEMATICS              -->\t");
	    							scanf("%d",&applicant.grdMath);
	    									strcpy(applicant.math,"y");
												}else{
									applicant.grdMath=0;
							strcpy(applicant.math,"n");
						}
	   				 printf("\n\tENGLISH INCLUDE[Y/N]       -->\t");
	   				scanf("%s",&applicant.english);
	    				if(strcmp(applicant.english,"y")==0 || strcmp(applicant.english,"Y")==0 ){
	   				 printf("\n\tGRADE IN ENGLISH          -->\t");
	    			scanf("%d",&applicant.grdEng);
	    			strcpy(applicant.english,"y");
					}else{
					applicant.grdEng=0;
						strcpy(applicant.english,"n");
		}
}

		//prompt user to save the application
		printf("\n\n\t'S -> SAVE APPLICATION' 'E -> EXIT '\n ");
		scanf("%s",&res);
		if(res == 'S' || res == 's'){
			//safe information to file
		char display[20]="saving ....";
		loader(display);
		 proc=fopen("applicant.txt","ab");
		fwrite(&applicant,sizeof(applicant),1,proc);
		fclose(proc);
	
		//prompt to repeat
		clrscr();
		gotoxy(20,2);
		printf("Application saved successfully!!");
		gotoxy(10,6);
		printf("Enter another ?   '1 -> Exit' | 'Any other key -> Continue'");
		cont=getch();
		switch(cont){
			case '1': {
		 		 mainScreen();
			break;
			}
					default :{
		   if(getch())
		   mainScreen();
		break;
	}
		}

		//if user wishes not to save, then we break out of the loop and return to main screen
		}else if(res == 'E' || res == 'e'){
		  mainScreen();
		}//end if
	//return to main menu if break of loop
			mainScreen();
	}
		
		
		
		//view all applications
void viewApp(){
//clrs the previous screen
int j=0;
clrscr();
gotoxy(20,2);
//printf("Registered Applicants for CAPE program\n\n");
FILE * view;
    //we first open the file to see if it exits
	view=fopen("applicant.txt","r");
		while(fread(&applicant,sizeof(applicant),1,view)==1){
			//calls the display function to print out information on applicants
           Display_App();
		    j++;
			}	
			gotoxy(30,2);
			printf("%d Applicants found ..",j);
			gotoxy(20,3);
			printf("______________________________________________");
		fclose(view);
		if(getch()){
			//if a key is pressed we return to mainScreen function
			return mainScreen();
		   }
		}
		

void AccepApp(){
	//this function basically filers applicants meeting the right
	//criteria to qualify for the CAPE progran
	//Criteria: at least 5 cxc subjects including maths and english
	
	//get the list of applicants
    clrscr();
    FILE * appl;
    appl=fopen("applicant.txt","rb");
    gotoxy(10,2);
    printf("Applicants that match the following criteria");
    printf("\n\n\t > 5 or more CXC subjects");
    printf("\n\t > Mathematics and English with grades between 1-3 \n\n");
    while(fread(&applicant,sizeof(applicant),1,appl)==1){
    	//a very long if statement to test critria of applicants
    			if(applicant.numofsub >= 5 && strcmp(applicant.math,"y")==0 && applicant.grdMath <= 3 && strcmp(applicant.english,"y")==0 && applicant.grdEng <= 3 || 	applicant.numofsub >= 5 &&strcmp(applicant.math,"y")==0 && applicant.grdMath <= 3 || applicant.numofsub >= 5 && strcmp(applicant.english,"y")==0 && applicant.grdEng <= 3)
	{
    	
    		Display_App();
		  
     	}
	}fclose(appl);
	if(getch())
	mainScreen();
}



	//layout of what is stored in file
void Display_App(){
	printf("\n\n\n\tApplicant ID       -->  %s",applicant.appID);
	
	printf("\n\tApplicant Name     -->  %s %s",applicant.fn,applicant.ln);
	
	printf("\n\tGender             --> \t%s",applicant.sex);
	printf("\n\tAddress            --> \t%s",applicant.address);
	printf("\n\tPhone #            --> \t%s",applicant.phone);
	printf("\n\tD.O.B              --> \t%d/%d/%d",applicant.day,applicant.month,applicant.year);
	
	printf("\n\tPrevious School    --> \t%s",applicant.prevSchool);
	printf("\n\t# of CXC subjects  --> \t %d",applicant.numofsub);
						
	//check if the applicant have maths or english
	if(strcmp("n",applicant.math)==0){
	printf("\n\tMathematics        --> \t -");
		}else{
		  printf("\n\tMathematics        --> \t Grade[%d]",applicant.grdMath);
			}//endif
		      if(strcmp("n",applicant.english)==0){
					printf("\n\tEnglish            --> \t -");
						}else{
						printf("\n\tEnglish            --> \t Grade[%d]",applicant.grdEng);
				     	}//endif
				     	//print date of registration
						printf("\n\tRegistration date  --> \t%s\n\n",applicant.regDate);
}



void settings(void){
	clrscr();
	FILE * f1;


   gotoxy(20,3);
   printf("PRESS A KEY TO NAVIGATE ...");
   
   gotoxy(20,5);
   printf("1. CHANGE LOGIN INFORMATION ...");
   gotoxy(20,7);
   printf("2. ABOUT PROGRAM....");
   gotoxy(20,9);
   printf("3. <- MAIN MENU");
   gotoxy(20,11);
    char key=getch();
   switch(key){
   	case '1':{
   		clrscr();
   		f1=fopen("setup.txt","wb");
   		printf("\n\n\t ENTER NEW USERNAME\t | ");
   		scanf("%s",&set.user_name);
   		printf("\n\tENTER NEW PASSWORD\t | ");
   		scanf("%s",&set.user_pass);

   		
		fwrite(&set,sizeof(set),1,f1);
		
		fclose(f1);
		char display[40]="UPDATING...";
		loader(display);
		clrscr();
		gotoxy(20,5);
		printf("LOGIN INFORMATION CHANGED SUCCESSFULLY ...");
	
		if(getch())
	    return welcomeScreen();
		break;
	   }
	   case '2':{
	   	//About software
	   	clrscr();
	   	gotoxy(20,1);
	   	printf("NAME\t| ADRIAN WEST");
	   	gotoxy(20,2);
	   	printf("SCHOOCL\t| SPALDING HIGH");
	   	gotoxy(20,3);
	   	printf("EMAIL\t| WESTSPARTA@GMAIL.COM");
	   	gotoxy(20,4);
	   	printf("PROGRAM\t|  CAPE REGISTRATION SYSTEM V1.0");
	   	if(getch())
	   	return settings();
		break;
	   }
	   case '3':{
	   	return mainScreen();
		break;
	   }
	   default:{
	   	printf("Incorrect option ..");
	   		if(getch())
	    return settings();
		break;
	   }
   }
   
	
}



