#include<iostream>
#include<string>
using namespace std;

class Person{
protected:
	string name,addr;
	int age;
public:
	Person(){
		name="Unknown";
		addr="Unknown";
		age=0;
		cout<<"Person default"<<endl;
	}
	Person(string n,string a,int x){
		name=n;
		addr=a;
		age=x;
		cout<<"Person "<<name<<endl;
	}
	void show(){
		cout<<name<<endl<<addr<<endl<<age<<endl;
	}
	~Person(){
		cout<<"Person dtor "<<name<<endl;
	}
};

class Staff:virtual public Person{
protected:
	int id;
	string dept;
	double sal;
public:
	Staff():Person(){
		id=0;
		dept="NA";
		sal=0;
		cout<<"Staff default"<<endl;
	}
	Staff(string n,string a,int x,int i,string d,double s):Person(n,a,x){
		id=i;
		dept=d;
		sal=s;
		cout<<"Staff "<<id<<endl;
	}
	void show(){
		cout<<"\nStaff"<<endl;
		Person::show();
		cout<<id<<endl<<dept<<endl<<sal<<endl;
	}
	void meet(string t){
		cout<<name<<" meet "<<t<<endl;
	}
	void setSal(double s){
		sal=s;
		cout<<"sal "<<sal<<endl;
	}
	~Staff(){
		cout<<"Staff dtor "<<id<<endl;
	}
};

class Student:virtual public Person{
protected:
	int sid;
	string grade;
	double gpa;
public:
	Student():Person(){
		sid=0;
		grade="Fresh";
		gpa=0;
		cout<<"Student default"<<endl;
	}
	Student(string n,string a,int x,int i,string g,double gp):Person(n,a,x){
		sid=i;
		grade=g;
		gpa=gp;
		cout<<"Student "<<sid<<endl;
	}
	void show(){
		cout<<"\nStudent"<<endl;
		Person::show();
		cout<<sid<<endl<<grade<<endl<<gpa<<endl;
	}
	void attend(string c){
		cout<<name<<" class "<<c<<endl;
	}
	void setGpa(double g){
		gpa=g;
		cout<<"gpa "<<gpa<<endl;
	}
	void submit(string a){
		cout<<name<<" sub "<<a<<endl;
	}
	~Student(){
		cout<<"Student dtor "<<sid<<endl;
	}
};

class TA:public Staff,public Student{
	string course;
	int hrs;
	double stipend;
public:
	TA():Person(),Staff(),Student(){
		course="NA";
		hrs=0;
		stipend=0;
		cout<<"TA default"<<endl;
	}
	TA(string n,string a,int x,int eid,string d,double s,int sid,string g,double gp,string c,int h,double st)
	:Person(n,a,x),Staff(n,a,x,eid,d,s),Student(n,a,x,sid,g,gp){
		course=c;
		hrs=h;
		stipend=st;
		cout<<"TA "<<course<<endl;
	}
	void show(){
		cout<<"\nTA"<<endl;
		Person::show();
		cout<<id<<endl<<dept<<endl<<sal<<endl;
		cout<<sid<<endl<<grade<<endl<<gpa<<endl;
		cout<<course<<endl<<hrs<<endl<<stipend<<endl;
		cout<<"Total "<<sal+stipend<<endl;
	}
	void work(){
		attend(course);
		meet("TA meet");
		cout<<"grade"<<endl;
		cout<<"hrs "<<hrs<<endl;
		submit("paper");
	}
	int load(){
		return hrs+15;
	}
	~TA(){
		cout<<"TA dtor "<<course<<endl;
	}
};

int main(){
	cout<<"Hybrid"<<endl;

	Staff s("Emily","Uni",45,5001,"CS",85000);
	s.show();
	s.meet("Plan");

	Student st("Mike","Campus",20,2001,"Junior",3.7);
	st.show();
	st.attend("DS");
	st.submit("Report");

	TA t("Sarah","College",24,6001,"CS",25000,3001,"Grad",3.9,"C++",20,15000);
	t.show();
	t.work();

	t.setGpa(4.0);
	t.setSal(27000);
	t.show();

	cout<<"Load "<<t.load()<<endl;

	TA t2("James","Way",23,6002,"Math",24000,3002,"Grad",3.8,"Calc",18,14000);
	t2.show();

	return 0;
}