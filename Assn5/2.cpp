#include<iostream>
#include<string>
using namespace std;

class BankAccount{
protected:
	double balance;
	string accNo;
public:
	BankAccount(string a,double b){
		accNo=a;
		balance=b;
		cout<<"created "<<accNo<<endl;
	}
	void showBal(){
		cout<<"bal="<<balance<<endl;
	}
};

class Savings:public BankAccount{
	double rate;
public:
	Savings(string a,double b,double r):BankAccount(a,b){
		rate=r;
	}
	void dep(double x){
		balance+=x;
		cout<<"dep "<<x<<endl;
	}
	void wd(double x){
		if(balance>=x){
			balance-=x;
			cout<<"wd "<<x<<endl;
		}
		else{
			cout<<"low bal"<<endl;
		}
	}
	void addInt(){
		double t=balance*rate/100;
		balance+=t;
		cout<<"int "<<t<<endl;
	}
	void show(){
		cout<<accNo<<endl;
		cout<<balance<<endl<<rate<<endl;
	}
};

int main(){
	Savings s("S1",1000,5);
	s.showBal();
	s.dep(500);
	s.wd(200);
	s.addInt();
	s.show();
	return 0;
}