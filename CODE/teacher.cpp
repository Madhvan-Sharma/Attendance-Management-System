#include <iostream>
#include <string>
#include<bits/stdc++.h>
#include <fstream>
#include <cstring>
#include <time.h>
#include <typeinfo>
#include <stdlib.h>
#include <sstream>

#include "Teacher_Header.h"



int Attendance();
int teacherDisplay();
int teacherlogin();

// written by Himesh
int teacherlogin()
{
	system("cls");
	cout<<endl<<" -------------------- Teacher Login ----------------------";	

        string username;
	string password;
	
	cout<<endl<<" Enter username : ";
	cin>>username;
	cout<<endl<<" Enter password : ";
	cin>>password;
	
	if(username=="Teacher" && password=="Teacher") 
	{   teacherDisplay();
	    getchar();	
       }   
       else
       {
        cout<<endl<<" Error ! Invalid Credintials..";	
        cout<<endl<<" Press any key for main menu ";
        getchar();getchar();
      }
   
   return 0;
	
}

// written by Madhvan
int Attendance()
{   ifstream read;
    read.open("db.dat");
    
    if(read)
    {     
	    string line;
    	    while(getline(read, line)) {
    	    	
    	    	char name[100];
    	    	strcpy(name, line.c_str());
    	    	string filename = name;

    int total_lines = 0;
            ifstream read1;
	read1.open(filename.c_str(), ios::app);
	string line;
	while(getline(read1,line)){
			++ total_lines;
		}
    read1.close();


	ifstream read;
	read.open(filename.c_str(), ios::app);
    cout<<"name:"<<filename<<endl;
    int c;
    cout<<"1: present:"<<"\t"<<"O : absent:"<<endl;
    cout<<"enter choice:"<<endl;
    cin>>c;
    switch(c)
    {
        case 1: 
                { string line;
                if(read)
                {	
                    int line_no = 0;
                while (line_no != total_lines && getline(read, line)) {
                ++line_no;
                }
                if (line_no == total_lines) {
                    int i;
                    istringstream(line)>>i;
                    i++;

                    ofstream out1;
                    string temp = name;
                    out1.open(temp.c_str(), ios::app);
                    out1<<i<<<<endl;

                }
                }	
                break;
                }
        case 0:
                break;

    }
	
    read.close();        
    }
     
    }
    read.close();

cout<<endl<<" Please any key to continue..";

getchar();getchar();

return 0;	
}

// written by Himesh
int teacherDisplay()
{	
    int back = 0;
    while(1)
    {
		system("cls");
		cout<<endl<<" 1 Mark Attendance";
		cout<<endl<<" 0. Go Back <- "<<endl;
		int c;
		
		cout<<endl<<" Enter you choice: ";
		cin>>c;
		
		switch(c)
		{
			case 1: Attendance();break;  
			case 0: back = 1;break;
	                default: cout<<endl<<" Invalid choice. Enter again ";
	                 getchar();           	
	   }   
	   
	   if(back == 1)
	   {
	   	break; 
           }     
    	
   }
   
   
   return 0;

}