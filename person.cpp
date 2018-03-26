#include<iostream>
//#include<string>
#include<bits/stdc++.h>
#include<conio.h>
//#include<math.h>
#include<windows.h>
using namespace std;

//*****************************************CLASS PERSON**********************************************************
class person{
	
public:	
    char name[20];
    int id;
	char hair_color[20];
	char hair_type[20];
	int specs;
	int height;
	int height_min;
	int height_max;
	int age;
	int age_min;
	int age_max;
	char gender;
	
	
	
	 void get(){
		cout<<"\nHair color:";
		cin>>hair_color;
		cout<<"\nHair type:";
		cin>>hair_type;
		cout<<"\nWhether he/she wears specs(1-yes/0-no):";
		cin>>specs;
		cout<<"\nHeight range:";
		cin>>height_min>>height_max;
		cout<<"\nAge range:";
		cin>>age_min>>age_max;
		cout<<"\nGender(M/F):";
		cin>>gender;
	}
	 void getadd(){
	 	cout<<"\nEnter record id:";
	 	cin>>id;
	 	cout<<"\nName:";
	 	cin>>name;
		cout<<"\nHair color:";
		cin>>hair_color;
		cout<<"\nHair type:";
		cin>>hair_type;
		cout<<"\nWhether he/she wears specs(1-yes/0-no):";
		cin>>specs;
		cout<<"\nHeight:";
		cin>>height;
		cout<<"\nAge:";
		cin>>age;
		cout<<"\nGender(M/F):";
		cin>>gender;
	}
	
};

//****************************************CLASS MODIFY******************************************************
class modify:public person{
	
	public:friend void add(person&);
	        void view();
	        void view(char[]);
};

void add(person& p1)
{  
    int f=1;
	fstream f1;
	f1.open("stud.txt",ios::in|ios::out|ios::app|ios::binary);
	f1.write((char*)&p1,sizeof(p1));
	cout<<"\nRecord added";
	f1.close();
}
void modify::view()
{fstream f1;
f1.open("stud.txt",ios::in|ios::out|ios::binary);
person p;
int i=0;
   while(f1.read((char*)&p,sizeof(p)))
   {    cout<<"\nRECORD"<<i++;
	    cout<<"\nPerson id:"<<p.id;
	 	cout<<"\nName:"<<p.name;
	 	cout<<"\nHair color:"<<p.hair_color;
     	cout<<"\nHair type:"<<p.hair_type;
    	cout<<"\nWhether he/she wears specs(1-yes/0-no):"<<p.specs;
		cout<<"\nHeight:"<<p.height;
		cout<<"\nAge:"<<p.age;
		cout<<"\nGender(M/F):"<<p.gender;
		cout<<endl<<endl;
	
   }
   f1.close();
}
void modify::view(char nm[])
{
	fstream f1;
	f1.open("stud.txt",ios::in|ios::out|ios::binary);
	person p;
	int f=0;
	 while(f1.read((char*)&p,sizeof(p)))
   {   if(strcmp(nm,p.name)==0)
	   {f=1;
		cout<<"\nPerson id:"<<p.id;
	 	cout<<"\nName:"<<p.name;
	 	cout<<"\nHair color:"<<p.hair_color;
     	cout<<"\nHair type:"<<p.hair_type;
    	cout<<"\nWhether he/she wears specs(1-yes/0-no):"<<p.specs;
		cout<<"\nHeight:"<<p.height;
		cout<<"\nAge:"<<p.age;
		cout<<"\nGender(M/F):"<<p.gender;
		cout<<endl<<endl;
		break;
	   }
	
   }
   if(f==0)
    cout<<"\nOOPS!!...No person with name "<<nm;
   f1.close();
	
}



//******************************************CLASS ADMIN*************************************************
class admin:public person
{
    
	char password[20];
	const void pass()
	{
 	   strcpy(password,"shubham13");
    }
  
  public:friend class person;
       admin()
	   {
 	      pass();
	      start();
       }

        int operator ==(char pwd[])
        {
        	if(strcmpi(password,pwd)==0)
	        return 1;
	        else 
	         return 0;
		}
        void start() const;
        friend void search(person &);
        
     	
};

void admin::start() const
{   
	cout<<"\n\t\t\t***************************************************************\n\n";
	cout<<"\t\t\t\t\tWELCOME TO PERSON DETECTION SYSTEM\n\n";
	cout<<"\t\t\t***************************************************************\n";
	cout<<"\n\n\nEnter the password to login:";
	cout<<"\n\nPASSWORD:";
	
}
void search(person& p1)
{
	person p2;
    int f=1;
	fstream f1;
	f1.open("stud.txt",ios::in|ios::out|ios::binary);
	while(f1.read((char*)&p2,sizeof(p2)))
	{
	   if(p1.gender==p2.gender)
	   {
	   	
	   }
	}
	f1.close();

}	
int main()
{ 

admin a;
modify m;
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
 getch();
 main:
 system("cls");
 cout<<"\n\n======================================================================";
 cout<<"\n\n\t\t1.Search the person/culprit\n\t\t2.Add a new record\n\t\t3.View a record\n\t\t4.EXIT";
 cout<<"\n\n======================================================================\n\n:";
 int choice;
 cin>>choice;
 switch(choice)
{
	case 1:person p1;
	       p1.get();
	       search(p1);
	       break;
	case 2:person p2;
	       p2.getadd();
	       add(p2);
	       break;
	case 3:system("cls");
	       cout<<"\n1.View particular\n2.View all";
	       int cho;
	       cin>>cho;
	       switch(cho)
	       {
	       	case 1:char nm[20];
	       	    cout<<"\nEnter the name:";
	       	    cin>>nm;
	       	    m.view(nm);
	       	    break;
	       	case 2:m.view();
			       break;
		    case 3:goto main;    
		   }
	       //m.view();
//	       break;
	case 4:exit(0);   
    default:cout<<"\nWrong Choice!!!";	          
}
}
 else{
 	cout<<"\n\n\t\t\t\t\tIncorrect password.....ACCESS DENIED";
 } 
 

  return 0;	
}
