#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <time.h>
#include <stdlib.h>
#include <sstream>

#include "Student_Header.h"


using namespace std;

int studentDisplay(); 
int studentLogin(); 
int checkStudentCredentials(string userName, string password); 
int adminLogin();
int teacherlogin();
int Attendance(string username);
int sendLeaveApplication(string username);

int total=30;




//student Display done by Himesh
int student::studentDisplay()
{
cout<<endl<<" Enter username : ";
cin>>username;

cout<<endl<<" Enter password : ";
cin>>password;

int res = checkStudentCredentials(username, password);

if(res  == 0)
{
   cout<<endl<<" Invalid Credentials !!";
   cout<<endl<<" Press any key for Main Menu..";
   getchar(); getchar();	
   return 0;
} 

    int goBack = 0;
	while(1)
    {
		
		system("cls");
		cout<<endl<<" 1 To count my Attendance";
		cout<<endl<<" 2 To send a leave application";
		cout<<endl<<" 0. Go Back <- "<<endl;
		int choice;
		
		cout<<endl<<" Enter you choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1: Attendance(username); break;
			case 2: sendLeaveApplication(username);break;
			case 0: goBack = 1;break;
	                default: cout<<endl<<"Invalid choice. Enter again ";
	                getchar();           	
	   }   
	   
	   if(goBack == 1)
	   {
	   	break;
           }     
    	
   }
   
}


// made by Himesh
int studentLogin()
{   student s;  
    system("cls");
    cout<<endl<<" -------------------- Student Login ----------------------";	
    s.studentDisplay();
    return 0; 
}
// made by Madhvan
int student::checkStudentCredentials(string username, string password)
{
	
	ifstream read;
	read.open("db.dat");
	int recordFound = 0;
	if (read) {
  		string line;
        string temp = username +".dat";
        while(getline(read, line)) {
        	if(line == temp)
        	{
        		recordFound = 1;
		}
        }
	}
    read.close();   
        if(recordFound == 1)
            {
				ifstream read;
				string filename = username+".dat";
				read.open(filename.c_str(), ios::app);
				int line_number = 0;
				string line;
				while (line_number != 3 && getline(read, line)) {
                ++line_number;
                }
				if(password == line)
					return 1;
				else
					return 0;
			}
		else
			return 0;
       	
}


// made by Madhvan
int student::Attendance(string username)		
{		int TotalLines = 0;
	string filename = username+".dat";


	ifstream read;
	read.open(filename.c_str(), ios::app);
	string line;
	while(getline(read,line)){
			++ TotalLines;
		}

	read.close();


	ifstream read_file;
	 read_file.open(filename.c_str(), ios::app);
	if(read_file)
	{	
		int curr_line = 0;

	while (curr_line != TotalLines && getline(read_file, line)) {
    ++curr_line;
	}
	if (curr_line == TotalLines) {
		
		cout<<endl<<"Total days  present: "<<line;
		int i;
		istringstream(line) >> i;
		cout<<endl<<"Percentage of attendance in ONE month :\t"<< (i*100/total)<<"%";
	}
	}
	
cout<<endl;	
cout<<" Please any key to continue..";

getchar();getchar();

return 0;	
} 



// file handling done by Madhvan, other parts done by Himesh
int student::sendLeaveApplication(string username)
{	
	char add[100];
	cout<<endl;
	cout<<"Write Reason for applying for leave: ";
	getchar();
	cin.getline(add, 100);

	time_t now = time(0);
	tm *ltm = localtime(&now);
	
	ofstream out;
	out.open("application.dat", ios::app);
	out<<add<<" -> "<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/"<<1900+ltm->tm_year<<" -> "<<username<<endl;
	out.close();
	cout<<endl<<" Application has been registered!!";
	cout<<endl<<" Please any key to continue..";
	getchar();
	return 0;
}

// main() written by Himesh
int main() {
	
	while(1)
	{
		system("cls");
		
		cout<<"\t\t\t\t\t Attendance Management System "<<endl;
		cout<<"-------------------------------------------------------------------------"<<endl<<endl;
		
		cout<<"1. Student Login"<<endl;
		cout<<"2. Admin Login"<<endl;
		cout<<"3. teacher Login"<<endl;
		cout<<"0. Exit"<<endl;
		int choice;
		
		cout<<"\n Enter you choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1: studentLogin(); break;
			case 2: adminLogin(); break;
			case 3: teacherlogin();break;
			case 0: 
			        while(1)
			        {
					    system("cls");
			        	cout<<endl<<" Are you sure, you want to exit? y | n "<<endl;
			        	char ex;
			        	cin>>ex;
			        	if(ex == 'y' || ex == 'Y')
			        		exit(0);
			        	else if(ex == 'n' || ex == 'N')
	                     {
	                     	 break;
	                     }
	                     else{
						 
	                     	cout<<endl<<" Invalid choice !!!";
	                     	getchar();
	                     }
	                    
	
                 	 }	break;
                 	 
            default: cout<<endl<<" Invalid choice :( ";
                     getchar();
                 	
		}   		        

	}
		
	return 0;
}  
