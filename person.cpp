#include<iostream>
//#include<string>
#include<bits/stdc++.h>
#include<conio.h>
//#include<math.h>
#include<windows.h>
using namespace std;
#define GEN 7
#define H 5
#define A 4
#define HC 2
#define HT 2
#define S 1
#define T (GEN+H+A+HC+HT+S)
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
	
	public:
	        
			friend void add(person&);
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
void search(person p1)
{ 
	person p2;
    int f=1,count,ps[20],i=0;
	fstream f1;
	f1.open("stud.txt",ios::in|ios::out|ios::binary);
	while(f1.read((char*)&p2,sizeof(p2)))
	{ 
	  count=0;
	  ps[i]=0;
	   if(p1.gender==p2.gender)
	   { count++;
	     ps[i]+=GEN;
	     if(p1.height_min<=p2.height && p2.height<=p1.height_max)
	     { 
		     ps[i]+=H; 
	        if(p1.age_min>=p2.age && p2.age<=p1.age_max)
	         {
			 ps[i]+=A;
	         } 
	        if(strcmpi(p1.hair_color,p2.hair_color)==0)
	     	 {ps[i]+=HC;
	         }  
			 if(strcmpi(p1.hair_type,p2.hair_type)==0)
	     	 {ps[i]+=HT; 
	          }
			  if(p1.specs==p2.specs)
	     	  {ps[i]+=S;
	          }
		 }
	   
	   	
	   }
	   i++;
	}
	f1.close();
	int max=ps[0];
	int index=0;
	for(int j=0;j<i;j++)
	 {  cout<<"ps["<<j<<"]"<<ps[j]<<endl;
	 	if(ps[j]>max)
	 	 {
		  max=ps[j];
		  index=j;
	     }    
	 }
	 person p;
	 int k=0;
	 fstream f2;
	f2.open("stud.txt",ios::in|ios::out|ios::binary);
	 while(f2.read((char*)&p,sizeof(p)))
   {    if(k==index)
        {
		cout<<"\nRECORD"<<index;
	    cout<<"\nPerson id:"<<p.id;
	 	cout<<"\nName:"<<p.name;
	 	cout<<"\nHair color:"<<p.hair_color;
     	cout<<"\nHair type:"<<p.hair_type;
    	cout<<"\nWhether he/she wears specs(1-yes/0-no):"<<p.specs;
		cout<<"\nHeight:"<<p.height<<" "<<p.height_min<<p.height_max;
		cout<<"\nAge:"<<p.age<<" "<<p.age_min<<p.age_max;
		cout<<"\nGender(M/F):"<<p.gender;
		getch();
		cout<<endl<<endl;
	   }
	   k++;
   }
	f2.close();

}	
//------------------------------------MAIN-------------------------------------------------------------
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
	       cout<<"\n1.View particular\n2.View all\n3.Go back\n4.Exit";
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
	       	       getch();
			       break;
		    case 3:goto main; 
			       break;
		    case 4:exit(0);		      
		   }
	       //m.view();
          break;
	case 4:exit(0);   
    default:cout<<"\nWrong Choice!!!";	          
}
goto main;
}
 else{
 	cout<<"\n\n\t\t\t\t\tIncorrect password.....ACCESS DENIED";
 } 
 

  return 0;	
}
