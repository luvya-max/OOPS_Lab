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
	void show(){
		cout<<"Val "<<value<<endl;
	}
	int get(){return value;}
};

Number addNumbers(Number a,Number b){
	cout<<"\nadd fn"<<endl;
	int s=a.get()+b.get();
	Number r(s);
	return r;
}

Number multiply(Number n,int f){
	cout<<"\nmul fn"<<endl;
	int p=n.get()*f;
	Number r(p);
	return r;
}

int main(){
	cout<<"Pass by value"<<endl;

	Number n1(10);
	Number n2(20);

	Number s=addNumbers(n1,n2);
	s.show();

	n1.show();
	n2.show();

	Number p=multiply(n1,3);
	p.show();

	return 0;
}