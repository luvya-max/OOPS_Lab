#include<iostream>
#include<string>
using namespace std;

class LibraryUser{
protected:
	string name,contact,email;
	int id,books;
public:
	LibraryUser(){
		name="Unknown";
		id=0;
		contact="NA";
		email="NA";
		books=0;
		cout<<"User default"<<endl;
	}
	LibraryUser(string n,int i,string c,string e){
		name=n;
		id=i;
		contact=c;
		email=e;
		books=0;
		cout<<"User "<<name<<endl;
	}
	void show(){
		cout<<name<<endl<<id<<endl<<contact<<endl<<email<<endl;
		cout<<"Books "<<books<<endl;
	}
	void borrow(){
		books++;
		cout<<name<<" borrow "<<books<<endl;
	}
	void ret(){
		if(books>0){
			books--;
			cout<<name<<" return "<<books<<endl;
		}else cout<<"none"<<endl;
	}
	int getBooks(){return books;}
	string getName(){return name;}
	~LibraryUser(){
		cout<<"User dtor "<<name<<endl;
	}
};

class Student:public LibraryUser{
	string grade,major,year;
	int maxB;
public:
	Student(string n,int i,string c,string e,string g,string m,string y)
	:LibraryUser(n,i,c,e){
		grade=g;
		major=m;
		year=y;
		maxB=5;
		cout<<"Student "<<grade<<endl;
	}
	void borrow(){
		if(books<maxB) LibraryUser::borrow();
		else cout<<"limit "<<maxB<<endl;
	}
	void show(){
		cout<<"\nStudent"<<endl;
		LibraryUser::show();
		cout<<grade<<endl<<major<<endl<<year<<endl;
	}
	~Student(){
		cout<<"Student dtor "<<name<<endl;
	}
};

class Teacher:public LibraryUser{
	string dept,desig;
	int exp,maxB;
	bool access;
public:
	Teacher(string n,int i,string c,string e,string d,string ds,int ex)
	:LibraryUser(n,i,c,e){
		dept=d;
		desig=ds;
		exp=ex;
		maxB=10;
		access=true;
		cout<<"Teacher "<<dept<<endl;
	}
	void borrow(){
		if(books<maxB) LibraryUser::borrow();
		else cout<<"limit "<<maxB<<endl;
	}
	void show(){
		cout<<"\nTeacher"<<endl;
		LibraryUser::show();
		cout<<dept<<endl<<desig<<endl<<exp<<endl;
	}
	void request(string m){
		if(access){
			cout<<name<<" req "<<m<<endl;
		}else cout<<"no access"<<endl;
	}
	~Teacher(){
		cout<<"Teacher dtor "<<name<<endl;
	}
};

void stats(Student s[],int ns,Teacher t[],int nt){
	int sb=0,tb=0;
	for(int i=0;i<ns;i++) sb+=s[i].getBooks();
	for(int i=0;i<nt;i++) tb+=t[i].getBooks();

	cout<<"\nStats"<<endl;
	cout<<"Students "<<ns<<endl;
	cout<<"Teachers "<<nt<<endl;
	cout<<"Books "<<sb+tb<<endl;
}

int main(){
	cout<<"Library"<<endl;

	Student s1("Alice",1001,"555","a@u","Soph","CS","2023");
	Student s2("Bob",1002,"556","b@u","Senior","Math","2021");
	Student s3("Carol",1003,"557","c@u","Fresh","Phy","2024");

	Teacher t1("David",2001,"600","d@u","CS","Prof",15);
	Teacher t2("Emma",2002,"601","e@u","Math","Assoc",8);

	s1.show();
	s2.show();
	t1.show();

	s1.borrow(); s1.borrow(); s1.borrow();
	s2.borrow(); s2.borrow();
	t1.borrow(); t1.borrow(); t1.borrow();

	for(int i=0;i<5;i++) s1.borrow();

	s1.ret(); s1.ret();

	t1.request("Algo");

	s1.show();
	t1.show();

	Student sa[]={s1,s2,s3};
	Teacher ta[]={t1,t2};
	stats(sa,3,ta,2);

	return 0;
}