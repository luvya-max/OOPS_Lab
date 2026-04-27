#include<iostream>
#include<string>
using namespace std;

class Person{
protected:
	string name;
	int age;
public:
	Person(){
		name="Unknown";
		age=0;
		cout<<"Person default"<<endl;
	}
	Person(string n,int a){
		name=n;
		age=a;
		cout<<"Person param "<<name<<endl;
	}
	~Person(){
		cout<<"Person dtor "<<name<<endl;
	}
	void show(){
		cout<<name<<" "<<age<<endl;
	}
};

class Employee:public Person{
	int id;
	string dept;
public:
	Employee():Person(){
		id=0;
		dept="NA";
		cout<<"Emp default"<<endl;
	}
	Employee(string n,int a,int i,string d):Person(n,a){
		id=i;
		dept=d;
		cout<<"Emp param "<<id<<endl;
	}
	~Employee(){
		cout<<"Emp dtor "<<id<<endl;
	}
	void show(){
		Person::show();
		cout<<id<<endl<<dept<<endl;
	}
};

class Manager:public Employee{
	int team;
public:
	Manager():Employee(){
		team=0;
		cout<<"Mgr default"<<endl;
	}
	Manager(string n,int a,int i,string d,int t):Employee(n,a,i,d){
		team=t;
		cout<<"Mgr param "<<team<<endl;
	}
	~Manager(){
		cout<<"Mgr dtor "<<team<<endl;
	}
	void show(){
		Employee::show();
		cout<<team<<endl;
	}
};

int main(){
	cout<<"Constructors"<<endl;

	Employee e("Alice",30,1001,"IT");
	e.show();

	cout<<"\nManager"<<endl;
	Manager m("Bob",40,2001,"Sales",10);
	m.show();

	cout<<"\nBlock"<<endl;
	{
		Person p("Charlie",25);
		Employee e2("Diana",28,3001,"HR");
	}

	cout<<"\nEnd"<<endl;
	return 0;
}