#include<iostream>
#include<string>
using namespace std;

class Base{
private:
	int privateData;
protected:
	int protectedData;
public:
	int publicData;

	Base(){
		privateData=10;
		protectedData=20;
		publicData=30;
	}

	void showBaseData(){
		cout<<"Private Data: "<<privateData<<endl;
		cout<<"Protected Data: "<<protectedData<<endl;
		cout<<"Public Data: "<<publicData<<endl;
	}
};

class PublicDerived:public Base{
public:
	void accessBaseMembers(){
		cout<<"\nPublic Inheritance"<<endl;
		cout<<"Protected: "<<protectedData<<endl;
		protectedData=25;
		cout<<"Public: "<<publicData<<endl;
		publicData=35;
	}
};

class ProtectedDerived:protected Base{
public:
	void accessBaseMembers(){
		cout<<"\nProtected Inheritance"<<endl;
		cout<<"Protected: "<<protectedData<<endl;
		protectedData=27;
		cout<<"Public->Protected: "<<publicData<<endl;
		publicData=37;
	}
};

class PrivateDerived:private Base{
public:
	void accessBaseMembers(){
		cout<<"\nPrivate Inheritance"<<endl;
		cout<<"Protected->Private: "<<protectedData<<endl;
		protectedData=29;
		cout<<"Public->Private: "<<publicData<<endl;
		publicData=39;
	}
};

int main(){
	cout<<"Inheritance modes"<<endl;

	PublicDerived p;
	p.accessBaseMembers();
	p.publicData=100;
	cout<<"Outside access: "<<p.publicData<<endl;

	ProtectedDerived pr;
	pr.accessBaseMembers();

	PrivateDerived pv;
	pv.accessBaseMembers();

	return 0;
}