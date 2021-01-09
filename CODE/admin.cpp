#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <time.h>
#include <typeinfo>
#include <stdlib.h>
#include <sstream>
#include "Admin_Header.h"

using namespace std;

int adminDisplay(); 
int deleteAll();      
int ListofStuds(); 
int adminLogin();
int registerStudent();
int m = 0;

// made by Himesh
int adminLogin()
{
	system("cls");
	cout<<endl<<" -------------------- Admin Login --------------------";	

    string username;
	string password;
	
	cout<<endl<<" Enter username : ";
	cin>>username;
	cout<<endl<<" Enter password : ";
	cin>>password;
	
	if(username=="admin" && password=="admin") 
	{
	    adminDisplay();
	    getchar();	
       }   
       else
       {
        cout<<endl<<" Error ! Invalid Credintials used..";	
        cout<<endl<<" Press any key to go back to main menu ";
        getchar();getchar();
      }
   
   return 0;
	
}
// made by himesh
int adminDisplay()
{	
    int goBack = 0;
    while(1)
    {
		system("cls");
		cout<<endl<<" 1 Register a Student";
		cout<<endl<<" 2 Delete All students name registered";
		cout<<endl<<" 3 Check List of Student registered by username";
		cout<<endl<<" 0. Go Back  "<<endl;
		int choice;
		
		cout<<endl<<" Enter you choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1: registerStudent();break;  
			case 2: deleteAll(); break;
			case 3: ListofStuds(); break;  
			case 0: goBack = 1;break;
	                default: cout<<endl<<" Invalid choice. Enter again ";
	                 getchar();           	
	   }   
	   
	   if(goBack == 1)
	   {
	   	break; 
           }     
    	
   }
   
   
   return 0;

}

// made by MAdhvan
int deleteAll()
{
	remove("db.dat");
	cout<<endl<<" Please any key to continue..";
	
	getchar(); getchar();
	return 0;
}

// made by Madhvan
int ListofStuds(){
    cout<<endl<<" ---------- Check List of Student Registered by Username----------- ";	
	
    ifstream read;
    read.open("db.dat");
    
    if(read)
    {       int record_found =0; 
	    string line;
    	    while(getline(read, line)) {
    	    	
				char name[100];
    	    	strcpy(name, line.c_str());
    	    	string Filename = name;
				cout<<endl<<Filename;

				int totalLines = 0;
            ifstream read1;
			read1.open(Filename.c_str(), ios::app);
			string line;
			while(getline(read1,line)){
				++ totalLines;
			}
    		read1.close();
			ifstream read;
			read.open(Filename.c_str(), ios::app);
			string l;
                if(read)
                {	
                    int curr_line = 0;
                while (curr_line != totalLines && getline(read, l)) {
                ++curr_line;
                }
                if (curr_line == totalLines) {
					cout<<"-> "<<l<<endl;}
				read.close();
            }
    read.close();        
    }
	}
    else
    {
    	cout<<endl<<" No Record was found :(";
    }
	
	
    cout<<endl<<" Please any key to continue..";
    getchar(); getchar();
    return 0;
}


// made by Madhvan
int registerStudent()
{
    cout<<endl<<" ----- Register Student ---- ";	

    string name, username, password, rollno, branch;
     int total;

    cout<<endl<<" Enter First Name : ";     cin>>name;
    
    cout<<endl<<" Enter Username : ";     cin>>username;
    
    
    cout<<endl<<" Enter Password : ";     cin>>password;
    
    cout<<endl<<" Enter Rollno : ";     cin>>rollno;
    getchar();
    
    cout<<endl<<" Enter Branch : ";     cin>>branch;
	cout<<endl<<" Enter Initial number of presents to be inserted :"; cin>>m;

    
    ifstream read;
    read.open("db.dat");
    
    if(read)
    {      int record_found =0; 
	   string line;
    	    while(getline(read, line)) {
        	if(line == username+".dat" )
        	{
        		record_found = 1 ;
        	    break;
			}
        }
        if(record_found == 1)
        {
        	cout<<endl<<" Username already Register. Please choose another username ";
        	getchar(); getchar();
        	read.close();
        	return 0;
		}
	}
    read.close();

    ofstream out;
	out.open("db.dat", ios::app);
	out<<username+".dat"<<endl;
	out.close();

	ofstream fout1;
	string temp = username+".dat";
	fout1.open(temp.c_str());
	fout1<<name<<endl; 	fout1<<username<<endl; 	fout1<<password<<endl;
	fout1<<rollno<<endl; 	fout1<<branch<<endl; 

	fout1<<m<<endl;  

	fout1.close();

	cout<<endl<<" Student Registered Successfully !!";
    
        cout<<endl<<" Please any key to continue..";
	getchar(); getchar();
	return 0;		
}
