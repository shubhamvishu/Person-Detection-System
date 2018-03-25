#include<iostream>
//#include<string>
#include<bits/stdc++.h>
#include<conio.h>
//#include<math.h>
#include<windows.h>
using namespace std;

class person{
	char hair_color[20];
	char hair_type[20];
	int specs;
	int height_min;
	int height_max;
	int age_min;
	int age_max;
	char gender;
	
	public:void getp(){
		cin>>hair_color;
		cout<<hair_color;
	}
	
};
class admin:public person
{
    
	char password[20];
	const void pass(){
 	   strcpy(password,"shubham13");
 }
 public:admin(){
 	pass();
	 start();
 }
 
        void access();
        int operator ==(char pwd[])
        {
        	if(strcmpi(password,pwd)==0)
	        return 1;
	        else 
	         return 0;
		}
        const void start();
        void new_record();		
};

const void admin::start()
{   
	cout<<"\n\t\t\t***************************************************************\n\n";
	cout<<"\t\t\t\t\tWELCOME TO PERSON DETECTION SYSTEM\n\n";
	cout<<"\t\t\t***************************************************************\n";
	cout<<"\n\n\nEnter the password to login:";
	cout<<"\n\nPASSWORD:";
	
}

	
int main()
{ admin a;
char pwd[20],ch;
int i=0;
while(1)
{ ch=getch();
	if(ch==13)
	{pwd[i]='\0';
     break;
	}
	if(ch==8)
	{
	  if(i!=0)
	  {
	  	cout<<"\b \b";
	  	i--;
		  }	
	}
	if(ch!=13 && ch!=8)
	{
	 pwd[i]=ch;
     i++;
	 cout<<"*";}
	 
}
if(a==pwd)
{
	cout<<"\n\n\t\t\t\t\t-------ACCESS GRANTED!!!!!.........";
}
 else{
 	cout<<"\n\n\t\t\t\t\tIncorrect password.....ACCESS DENIED";
 } 
 getch();
 system("cls");
 cout<<"\n1.Search the person/culprit\n2."
  return 0;	
}
