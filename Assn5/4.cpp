#include<iostream>
#include<string>
using namespace std;

class Vehicle{
protected:
	string brand;
public:
	Vehicle(string b){brand=b;}
	void displayBrand(){
		cout<<"Brand: "<<brand<<endl;
	}
};

class Car:public Vehicle{
	int numDoors;
public:
	Car(string b,int d):Vehicle(b){
		numDoors=d;
	}
	void displayCar(){
		displayBrand();
		cout<<"Doors: "<<numDoors<<endl;
	}
};

class Engine{
protected:
	int hp;
public:
	Engine(int h){hp=h;}
	void showEngine(){
		cout<<"HP: "<<hp<<endl;
	}
};

class Transmission{
protected:
	string type;
public:
	Transmission(string t){type=t;}
	void showTrans(){
		cout<<"Trans: "<<type<<endl;
	}
};

class SportsCar:public Engine,public Transmission{
	string model;
public:
	SportsCar(string m,int h,string t):Engine(h),Transmission(t){
		model=m;
	}
	void show(){
		cout<<"Model: "<<model<<endl;
		showEngine();
		showTrans();
	}
};

class LivingBeing{
protected:
	bool alive;
public:
	LivingBeing(){alive=true;}
	void breathe(){
		cout<<"Breathing"<<endl;
	}
};

class Animal:public LivingBeing{
protected:
	string sp;
public:
	Animal(string s){sp=s;}
	void eat(){
		cout<<sp<<" eating"<<endl;
	}
};

class Dog:public Animal{
	string name;
public:
	Dog(string n):Animal("Dog"){
		name=n;
	}
	void show(){
		breathe();
		eat();
		cout<<name<<" woof"<<endl;
	}
};

class Shape{
protected:
	string color;
public:
	Shape(string c){color=c;}
	void showColor(){
		cout<<"Color: "<<color<<endl;
	}
};

class Circle:public Shape{
	double r;
public:
	Circle(string c,double x):Shape(c){
		r=x;
	}
	void show(){
		cout<<"Circle ";
		showColor();
		cout<<"R="<<r<<endl;
	}
};

class Rectangle:public Shape{
	double l,w;
public:
	Rectangle(string c,double a,double b):Shape(c){
		l=a;w=b;
	}
	void show(){
		cout<<"Rect ";
		showColor();
		cout<<"L="<<l<<" W="<<w<<endl;
	}
};

class Student{
protected:
	string name;
	int roll;
public:
	Student(string n,int r){
		name=n;roll=r;
	}
};

class Sports{
protected:
	int sScore;
public:
	Sports(int s){sScore=s;}
};

class Exam:public Student{
protected:
	int eScore;
public:
	Exam(string n,int r,int e):Student(n,r){
		eScore=e;
	}
};

class Result:public Exam,public Sports{
public:
	Result(string n,int r,int e,int s):Exam(n,r,e),Sports(s){}
	void show(){
		cout<<name<<endl;
		cout<<roll<<endl;
		cout<<eScore<<endl;
		cout<<sScore<<endl;
		cout<<"Total "<<eScore+sScore<<endl;
	}
};

int main(){
	cout<<"Single"<<endl;
	Car c("Toyota",4);
	c.displayCar();

	cout<<"\nMultiple"<<endl;
	SportsCar s("Ferrari",700,"Auto");
	s.show();

	cout<<"\nMultilevel"<<endl;
	Dog d("Buddy");
	d.show();

	cout<<"\nHierarchical"<<endl;
	Circle c1("Red",5.5);
	c1.show();
	Rectangle r1("Blue",10,5);
	r1.show();

	cout<<"\nHybrid"<<endl;
	Result r("John",101,85,90);
	r.show();

	return 0;
}