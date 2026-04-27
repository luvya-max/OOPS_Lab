#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Book{
protected:
	string title,author;
	double price;
public:
	Book(){
		title="Unknown";
		author="Unknown";
		price=0;
	}
	Book(string t,string a,double p){
		title=t;
		author=a;
		price=p;
		cout<<"Book "<<title<<endl;
	}
	void setTitle(string t){title=t;}
	void setAuthor(string a){author=a;}
	void setPrice(double p){price=p;}

	string getTitle(){return title;}
	string getAuthor(){return author;}
	double getPrice(){return price;}

	void show(){
		cout<<"Title: "<<title<<endl;
		cout<<"Author: "<<author<<endl;
		cout<<fixed<<setprecision(2);
		cout<<"Price: "<<price<<endl;
	}

	~Book(){
		cout<<"Book dtor "<<title<<endl;
	}
};

class Textbook:public Book{
	string subject;
public:
	Textbook():Book(){
		subject="General";
	}
	Textbook(string t,string a,double p,string s):Book(t,a,p){
		subject=s;
		cout<<"Textbook "<<subject<<endl;
	}
	void setSubject(string s){subject=s;}
	string getSubject(){return subject;}

	void show(){
		cout<<"\nTextbook"<<endl;
		Book::show();
		cout<<"Subject: "<<subject<<endl;
	}

	void category(){
		cout<<"For "<<subject<<endl;
	}

	~Textbook(){
		cout<<"Textbook dtor "<<subject<<endl;
	}
};

int main(){
	cout<<"Single Inheritance"<<endl;

	Book b("Gatsby","Fitzgerald",12.99);
	b.show();

	cout<<"\nTextbooks"<<endl;
	Textbook t1("C++","Stroustrup",89.99,"CS");
	Textbook t2("Calculus","Stewart",149.99,"Math");
	Textbook t3("Physics","Halliday",119.99,"Phy");

	t1.show(); t1.category();
	t2.show(); t2.category();
	t3.show(); t3.category();

	cout<<"\nBase methods"<<endl;
	cout<<t1.getAuthor()<<endl;
	cout<<t1.getPrice()<<endl;

	cout<<"\nModify"<<endl;
	t1.setPrice(79.99);
	t1.setSubject("Adv C++");
	t1.show();

	Book* arr[4];
	arr[0]=&b;
	arr[1]=&t1;
	arr[2]=&t2;
	arr[3]=&t3;

	double tot=0;
	for(int i=0;i<4;i++){
		tot+=arr[i]->getPrice();
	}
	cout<<fixed<<setprecision(2);
	cout<<"Total "<<tot<<endl;

	return 0;
}