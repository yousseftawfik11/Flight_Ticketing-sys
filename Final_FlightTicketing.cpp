#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#define s 20

using namespace std;
//This structure is for storing flight information
struct header{int Flight_number;
string Departure;
string Arrival;
string Date;
string Time;
float Base_Price;};
//this structure is for storing account details
struct create{
	string name, last_name, username, password, Passport_number, email;
	int phone;
};	
//this part is for plotting the seat chart
int matrix[6][6] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};
int seat_selection(){
	int seat=0;
	int i=0;
	//creating the seating chart
	cout<<"A\t\tB\t\tC\t\tD\t\tE\t\tF"<<endl;
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<6; j++){
			cout<<matrix[i][j]<<"\t\t";
			
		}
		
		cout<<endl;
	}
	//selecting the number
	cout<<"Select the seat number: ";
	cin>>seat;
	cout<<"**************************************************************************************************************"<<endl;
}
void printsummary(int,create print[],header flightfinal[],int,int);//this function i for printing the final summary at the end
int account1(create newUser[],int);//this function is for creating an new account
int selection(header flight[],int);//this function is for selecting the preffered flight
int login(create login[],int);//this function is for loging in

main(){
	
	
	int start,loginno,register1,choice1;
	int *FP,*AP;
	int FS,i,AS;
	int flight_index,seat_class,account_index;
	int finalcost;
	
	struct create account[s];
	struct header flight[s];
	
	ifstream readA;
	ifstream readF;
	
	readA.open("create.txt");//opening create.txt file
	readF.open("flight.txt");//opening flight.txt file
	if(readA.fail()){
		cout<<"File does not exist";
	}
	if(readF.fail()){
		cout<<"File does not exist";
	}		
	
		cout<<"************************************* welcome to Youssef Airways *********************************************"<<endl;
	cout<<"key in 1 to book flight "<<endl;
	cout<<"key in 2 to exit app "<<endl;
	cin>>start;
	
		if (start==2){
	
		cout<<"Thank you for choosing Youssef Airways";
		exit(0);}
		
	else if (start==1){
		
	
		cout<<"**************************************************************************************************************"<<endl;
		cout<<"Flight Number"<<"\t\t"<<"From"<<"\t\t"<<"To"<<"\t\t"<<"Date"<<"\t\t\t"<<"Time"<<"\t\t"<<"Base Price $"<<endl;
		cout<<"______________________________________________________________________________________________________________"<<endl;
		while (!readF.eof()){ // a while loop to read the file of the flights
			readF>>FS;
			FP= new int[FS];
			
				for(i=0;i<FS;i++){//reading and saving to the structure
				readF>>flight[i].Flight_number;
				readF>>flight[i].Departure;
				readF>>flight[i].Arrival;
				readF>>flight[i].Date;
				readF>>flight[i].Time;
				readF>>flight[i].Base_Price;
			}
				
		}
		
		
		
			for (i=0;i<FS;i++){//previwing the available flights table
			
			cout<<flight[i].Flight_number<<"\t\t\t"<<flight[i].Departure<<"\t\t"<<flight[i].Arrival<<"\t\t"<<flight[i].Date<<"\t\t"<<flight[i].Time<<"\t\t"<<flight[i].Base_Price<<"$"<<endl;
			cout<<"______________________________________________________________________________________________________________"<<endl;
		
	
		


			}
		}
	
	
	
	while(!readA.eof()){ //while loop to read the file of the accounts
		readA>>AS;
		readA.ignore();
		AP= new int[AS];
		
		for(i=0;i<AS;i++){//saving to structre
			readA>>account[i].name;
			readA>>account[i].last_name;
			readA>>account[i].Passport_number;
			readA>>account[i].email;
			readA>>account[i].phone;
			readA>>account[i].username;
			readA>>account[i].password;
			
			
				
				
		}
		
	}
	

	flight_index=selection(flight,FS);//caling the function to select the flight
		
	
	cout<<"Enter 1 for Business class(+500$)"<<endl;
	cout<<"Enter 2 for Economy class"<<endl;
	cin>>seat_class;
	cout<<"**************************************************************************************************************"<<endl;
	if(seat_class==1)
		finalcost=500;
	else
		finalcost=0	;
	
	cout<<"LOG IN (1)..."<<endl<<"Create account? (2)..."<<endl;
	cout<<"Your choice: ";
	cin>>choice1;
	cout<<"**************************************************************************************************************"<<endl;
	if(choice1==1){ //if the user selected 1 he will log in with his existing account
	
		loginno=login(account,AS);
		int x,seat_number;
		seat_number=seat_selection();
		printsummary(loginno,account,flight,finalcost,flight_index);
	}
	else{//if the user selected 2 he will create a new account
		account_index=account1(account,AS);
		int x,seat_number;
		seat_number=seat_selection();
		printsummary(account_index,account,flight,finalcost,flight_index);
	}
	
}

int selection(header flight[],int size){
	
	int i,flightno,check=0,check2=0;
	string destination,depart;
	
	
	ifstream readF;
	readF.open("flight.txt");
	if(readF.fail()){
		cout<<"File does not exist";
	}
	
	while(check==0){
		check==0;
		cout<<"Please enter the preferred destination: ";
		cin>>destination;
		cout<<"Please enter the depauture city: ";
		cin>>depart;
		cout<<"**************************************************************************************************************"<<endl;
		
	
		while (!readF.eof()){
			
			for(i=0;i<size;i++){//checking the destination and the departure are availble in the table of flights
				if (flight[i].Arrival==destination && flight[i].Departure==depart){
					cout<<flight[i].Flight_number<<"\t"<<flight[i].Departure<<"\t"<<flight[i].Arrival<<"\t"<<flight[i].Date<<"\t"<<flight[i].Time<<"\t"<<flight[i].Base_Price<<"$"<<endl;
					check2=1;
					
				}
				
				
				
				
			}
			break;
			
				
		}
		
		if(check2==0){
			cout<<"There are no flights that match your chosen path...  "<<endl;
			
		}	
		else
			break;
		
			
		
	}
		
	
	cout<<"**************************************************************************************************************"<<endl;
	
	while (check==0){
		check=0;
		cout<<"Please enter the preferred flight number: ";
		cin>>flightno;
	cout<<"**************************************************************************************************************"<<endl;		
			
		for(i=0;i<size;i++){
			if (flight[i].Flight_number==flightno){//choose the preffered flight form available flights
				cout<<"Your Flight details..."<<endl<<endl;
				cout<<"Flight Number"<<"\t\t"<<"From"<<"\t\t"<<"To"<<"\t\t"<<"Date"<<"\t\t\t"<<"Time"<<"\t\t"<<"Base Price $"<<endl;
				cout<<"______________________________________________________________________________________________________________"<<endl;
				cout<<flight[i].Flight_number<<"\t\t\t"<<flight[i].Departure<<"\t\t"<<flight[i].Arrival<<"\t\t"<<flight[i].Date<<"\t\t"<<flight[i].Time<<"\t\t"<<flight[i].Base_Price<<"$"<<endl;
				cout<<"**************************************************************************************************************"<<endl;
				check=1;
				return i;
				
				
			}
	
	
	}
	if (check==0){
				
			cout<<"please enter a valid flight number"<<endl;
			cout<<"**************************************************************************************************************"<<endl;
			}
	
}

}

int login(create login[],int size2){
	
	string username,password;
	int status=0,i;
	
	ifstream readA;
	readA.open("create.txt");
	if(readA.fail()){
		cout<<"File does not exist";
	}
	
	while(status<=3){
		cout<<"Enter username : ";
		cin>>username;
		cout<<"Password : ";
		cin>>password;
		for(i=0;i<size2;i++){//comparing keyed in username and password to the database of usernames and passwords
			if(login[i].username==username && login[i].password==password){
				cout<< "You logged in succefully..."<<endl;
				cout<<"**************************************************************************************************************"<<endl;
				status=10;
				return i;
				break;
			}
			
			
		}
		
		if (status!=10){
			cout<<"Try again..."<<endl;}
		
		status++;
		
		
		
	}
	if(status!=11){
		cout<<"too many wrong entries "<<endl;
		cout<<"*********** Thank you for choosing YOUSSEF AIRWAY ***********"<<endl;
		cout<<"**************************************************************************************************************"<<endl;
		exit(0);
	}
		
}
int account1(create newUser[],int z){
	string username, password,testuser,testpassport;
	string inName;
	string inpass;
	int i,exist;
	int nSize;
	//calling the structure of account creation
	
	//file handling
	ifstream input;
	ofstream save;	
	input.open("create.txt");
	save.open("create.txt");
	nSize=z+1;
	
	
	cout<<"First Name: ";
	cin>>newUser[z].name;	
	cout<<"**************************************************************************************************************"<<endl;
	cout<<"Last name: ";
	cin>>newUser[z].last_name;
	cout<<"**************************************************************************************************************"<<endl;
	
	while(exist>=0){
		exist=0;
		cout<<"Username: ";
		cin>>testuser;
	
		for(int i=0;i<z;i++){
			if(newUser[i].username==testuser){//to check whether the created username is taken or not
				exist=1;
				
				cout<<"This username is already taken"<<endl;
				cout<<"please choose another one ";
				cout<<"**************************************************************************************************************"<<endl;
					
			}
		
	
		}
		if (exist==0){
			cout<<"Username availabe..."<<endl;
			cout<<"**************************************************************************************************************"<<endl;
			break;
		}
				
	}
	newUser[z].username=testuser;
	
	
	cout<<"Enter Password: ";
	cin>>newUser[z].password;
	cout<<"**************************************************************************************************************"<<endl;
	
	while(exist>=0){
		exist=0;
		cout<<"Enter Passport Number ";
		cin>>testpassport;
	
		for(int i=0;i<z;i++){
			if(newUser[i].Passport_number==testpassport){//checking the whether the passport number is already there
				exist=1;
				
				cout<<"This is an invalid Passport Number\nPlease check your passport number";
				cout<<"**************************************************************************************************************"<<endl;
					
			}
		
	
		}
		if (exist==0){
			
			cout<<"**************************************************************************************************************"<<endl;
			break;
		}
				
	}
	newUser[z].Passport_number=testpassport;

	cout<<"Enter Your Email: ";
	cin>>newUser[z].email;
	cout<<"**************************************************************************************************************"<<endl;
	
	cout<<"Enter your Phone Number: "<<endl;
	cin>>newUser[z].phone; 
	cout<<"**************************************************************************************************************"<<endl;
	
	save<<nSize<<endl;

	for(int i=0;i<nSize;i++){//saving the new information to the file
		save<<newUser[i].name<<" "<<newUser[i].last_name<<" "<<newUser[i].Passport_number<<" "<<newUser[i].email<<" "<<newUser[i].phone<<" "<<newUser[i].username<<" "<<newUser[i].password<<endl;
	}
	
	return z;
		
}
void printsummary(int index,create print[],header flightfinal[],int extras,int findex){
	
	
	cout<<"Your Ticket summary is..."<<endl;
	cout<<"*************************************"<<endl;
	cout<<"Name: "<<print[index].name<<endl;
	cout<<"_____________________________________"<<endl;
	cout<<"Flight Number: "<<flightfinal[findex].Flight_number<<endl;
	cout<<"_____________________________________"<<endl;
	cout<<"Flight Date : "<<flightfinal[findex].Date<<"\t"<<"Time: "<<flightfinal[findex].Time<<endl;
	cout<<"_____________________________________"<<endl;
	cout<<"FROM: "<<flightfinal[findex].Departure<<"\t TO: "<<flightfinal[findex].Arrival<<endl;
	cout<<"_____________________________________"<<endl;
	cout<<"Passport Number: "<<print[index].Passport_number<<endl;
	cout<<"_____________________________________"<<endl;
	cout<<"Total: "<<flightfinal[findex].Base_Price+extras<<"$"<<endl;
	cout<<"_____________________________________"<<endl;
	cout<<"You will find your ticket copy saved into your computer :) "<<endl;
	cout<<"************************************* Thank you for choosing YOUSSEF AIRWAYS *********************************************"<<endl;
	
	//
	ofstream ticket;
	ticket.open("your_ticket.txt");
	ticket<<"*********** Your Flight Summary ***********"<<endl;
	ticket<<"Name: "<<print[index].name<<endl;
	ticket<<"_____________________________________"<<endl;
	ticket<<"Flight Number: "<<flightfinal[findex].Flight_number<<endl;
	ticket<<"_____________________________________"<<endl;
	ticket<<"Flight Date : "<<flightfinal[findex].Date<<"\t"<<"Time: "<<flightfinal[findex].Time<<endl;
	ticket<<"_____________________________________"<<endl;
	ticket<<"FROM: "<<flightfinal[findex].Departure<<"\t TO: "<<flightfinal[findex].Arrival<<endl;
	ticket<<"_____________________________________"<<endl;
	ticket<<"Passport Number: "<<print[index].Passport_number<<endl;
	ticket<<"_____________________________________"<<endl;
	ticket<<"Total: "<<flightfinal[findex].Base_Price+extras<<"$"<<endl;
	ticket<<"_____________________________________"<<endl;
	ticket<<"Thank you for choosing YOUSSEF AIRWAYS :)"<<endl;
	
	
	
	
}

