#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<bits/stdc++.h>
#include<conio.h>
#include<math.h>
#include<windows.h>
#include<ctype.h>
using namespace std;

#define GEN 7
#define H 5
#define A 4
#define HC 2
#define HT 2
#define S 1
#define T (GEN+H+A+HC+HT+S)

vector<int>v1;
map<string,int>m1;

int invec(vector<int>v2,int k)
{
	for(int i=0;i<v2.size();i++)
	{
		if(v2[i]==k)
		 return 1;
	}
	return 0;
}


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
cout<<"\n";

 try{
 	cout<<"--------------------------------------------------------------------------------------------------------------------\n";
 	cout<<setw(6)<<"RECORD"<<setw(15)<<"Person ID"<<setw(20)<<"NAME"<<setw(2)<<" "<<setw(15)<<"Hair color"<<setw(15)<<"Hair type"<<setw(10)<<"Specs"<<setw(10)<<"Height"<<setw(10)<<"Age"<<setw(10)
	 <<"Gender"<<endl;
	 cout<<"----------------------------------------------------------------------------------------------------------------------";
	 m1.clear();
    
	while(f1.read((char*)&p,sizeof(p)))
   {   
	   string str=p.name;
	   m1[str]++;
	   cout<<endl<<setw(6)<<(i++)+1;
	    cout<<setw(15)<<p.id;
	 	cout<<setw(20)<<p.name;
	 	if(m1[str]>1)
	 	{cout<<setw(2)<<m1[str];
		 }
		 else{
		 	cout<<setw(2)<<" ";
		 }
	 	cout<<setw(15)<<p.hair_color;
     	cout<<setw(15)<<p.hair_type;
     	if(p.specs==0)
     	{ cout<<setw(10)<<"NO";
		 }
		 else{cout<<setw(10)<<"YES";
		 }
    	//cout<<setw(10)<<p.specs;
		cout<<setw(10)<<p.height;
		cout<<setw(10)<<p.age;
		cout<<setw(10)<<p.gender;
		
   }
   if(i==0)
    throw i;
  }
  catch(int a)
  {
  	cout<<"\n\n\t\tNO RECORDS......FILE IS EMPTY";
  }
   f1.close();
}
void modify::view(char nm[])
{
	fstream f1;
	f1.open("stud.txt",ios::in|ios::out|ios::binary);
	person p;
	int f=0;
	
	try
	{
	
	 while(f1.read((char*)&p,sizeof(p)))
   {   if(strcmpi(nm,p.name)==0)
	   {f=1;
	    cout<<"\n==================================================";
		cout<<"\nPerson id:"<<p.id;
	 	cout<<"\nNAME:"<<p.name;
	 	cout<<"\nHair color:"<<p.hair_color;
     	cout<<"\nHair type:"<<p.hair_type;
    	cout<<"\nWhether he/she wears specs(1-yes/0-no):"<<p.specs;
		cout<<"\nHeight:"<<p.height;
		cout<<"\nAge:"<<p.age;
		cout<<"\nGender(M/F):"<<p.gender;
		cout<<"\n==================================================";
		cout<<endl<<endl;
		break;
	   }
	
   }
   if(f==0)
    throw nm; 
   }
    catch(char *a)
    {
	cout<<"\n\n\t\tOOPS!!...No person with name "<<a;
    }
    getch();
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
	cout<<"\n\t\t\t***************************************************************\n\n\n\n";
	cout<<"\t\t\t\t\tWELCOME TO PERSON DETECTION SYSTEM\n\n\n\n";
	cout<<"\t\t\t***************************************************************\n";
	cout<<"\n\n\nEnter the password to login:";
	cout<<"\n\nPASSWORD:";
	
}
void search(person p1)
{ 
	person p2;
    int count,ps[20],i=0;
	fstream f1;
	f1.open("stud.txt",ios::in|ios::out|ios::binary);
	while(f1.read((char*)&p2,sizeof(p2)))
	{ 
	  count=0;
	  ps[i]=0;//cout<<"p["<<i<<"]";
	   if(p1.gender==p2.gender)
	   { count++;
	     ps[i]+=GEN;
	     
		 if(p1.height_min<=p2.height && p2.height<=p1.height_max)
	     { 
		        ps[i]+=H;
	        
			if(p1.age_min<=p2.age && p2.age<=p1.age_max)
	         {
			      ps[i]+=A;
	         } 
	        if(strcmpi(p1.hair_color,p2.hair_color)==0)
	     	 {    ps[i]+=HC;
	         }  
			 if(strcmpi(p1.hair_type,p2.hair_type)==0)
	     	 {    ps[i]+=HT; 
	          }
			  if(p1.specs==p2.specs)
	     	  {   ps[i]+=S;
	          }
	          cout<<endl;
		 }
	   
	   	
	   }
	   i++;
	}
	f1.close();
	int max=ps[0];
	int index=-1;
	for(int j=0;j<i;j++)
	 {  //cout<<"ps["<<j<<"]"<<ps[j]<<endl;
	 	if(ps[j]>=max )
	 	 {
		  max=ps[j];
		  index=j;
	     }    
	 }
	 //cout<<"max="<<max;
	 v1.clear();
	 if(max>=0.5*T)
	 {
	 
	 for(int j=0;j<i;j++)
	 {  
	 	if(ps[j]==max)
	 	 {
		 v1.push_back(j);
	     }    
	 }
	 
    }

	 person p;
	 int k=0,f=0;
	 fstream f2;
	f2.open("stud.txt",ios::in|ios::out|ios::binary);
	
	if(index!=-1)

   {   float per=(max*100)/T;
       m1.clear();
	   
	   while(f2.read((char*)&p,sizeof(p)))
       {   string str=p.name;
	       m1[str]++; 
	      if(invec(v1,k))
          {  f=1;
        	
        	cout<<"\n\n***************************************************************";
		    cout<<"\nRECORD"<<" "<<k+1;
		    cout<<"\n\t_________________________________________________";
		    cout<<"\n\t\tNAME:"<<p.name;
		    if(m1[str]>1)
	 	    {cout<<setw(2)<<m1[str];
		     }
		    else{
		 	cout<<setw(2)<<" ";
		    }
		    cout<<"\n\t_________________________________________________"<<endl;
	        cout<<setw(15)<<"Person id :"<<setw(15)<<p.id<<endl;
	 	    cout<<setw(15)<<"Hair color :"<<setw(15)<<p.hair_color<<endl;
     	    cout<<setw(15)<<"Hair type :"<<setw(15)<<p.hair_type<<endl;
    	    cout<<setw(15)<<"Wears specs :";
    	    if(p.specs==0)
    	     cout<<setw(15)<<"NO"<<endl;
    	     else
    	     cout<<setw(15)<<"YES"<<endl;
		    cout<<setw(15)<<"Height :"<<setw(15)<<p.height<<endl;
		    cout<<setw(15)<<"Age :"<<setw(15)<<p.age<<endl;
		    cout<<setw(15)<<"Gender(M/F) :"<<setw(15)<<p.gender<<endl;
		    cout<<endl<<endl;
	
	        cout<<"\n\n\t\tPERCENTAGE OF ACCURACY = "<<per<<"%";
	        cout<<"\n*******************************************************************\n";
	      } 
	       k++;
       }
       if(f==0)
       {
       	cout<<"\n\n\t\tRECORDS FOUND ARE LESS THAN 50% OF ACCURACY";
       	
	   }	  
   }
    
   else if(index!=1 && max==GEN)
       {
       	cout<<"\n\n\t\tRECORDS FOUND ARE LESS THAN 50% OF ACCURACY";
       	 
	   }
   else
   {
   	cout<<"\n\t\tNO SUCH RECORD EXISTS !!!!";
   }
	 getch();
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
	       cout<<"____________________________________________________________";
	       cout<<"\n\n\t1. View particular\n\t2. View all\n\t3. Go back\n\t4. Exit";
	       cout<<"\n__________________________________________________________\n\t:";
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
    default:cout<<"\nWrong Choice!!!!!";	          
}
goto main;
}
 else{
 	cout<<"\n\n\t\t\t\t\tIncorrect password.....ACCESS DENIED";
 } 
 

  return 0;	
}
