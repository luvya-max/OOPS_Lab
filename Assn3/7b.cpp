#include<iostream>
using namespace std;

class Number{
	int value;
public:
	Number(int v=0){
		value=v;
		cout<<"Ctor "<<value<<endl;
	}
	Number(const Number &o){
		value=o.value;
		cout<<"Copy "<<value<<endl;
	}
	~Number(){
		cout<<"Dtor "<<value<<endl;
	}
	void show() const{
		cout<<"Val "<<value<<endl;
	}
	int get() const{return value;}
	void set(int v){value=v;}
};

Number addNumbers(const Number &a,const Number &b){
	cout<<"\nadd ref"<<endl;
	int s=a.get()+b.get();
	Number r(s);
	return r;
}

void inc(Number &n){
	cout<<"\ninc"<<endl;
	n.set(n.get()+1);
}

void byVal(Number n){
	cout<<"\nbyVal"<<endl;
	n.set(999);
}

void byRef(Number &n){
	cout<<"\nbyRef"<<endl;
	n.set(999);
}

int main(){
	cout<<"Ref demo"<<endl;

	Number n1(10),n2(20);
	Number s=addNumbers(n1,n2);
	s.show();

	Number n3(50);
	n3.show();
	inc(n3);
	n3.show();

	Number n4(100);
	n4.show();

	byVal(n4);
	n4.show();

	byRef(n4);
	n4.show();

	return 0;
}