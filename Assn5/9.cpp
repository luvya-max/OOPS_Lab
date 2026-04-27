#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Vehicle{
protected:
	string make,model;
	int year;
	double km;
public:
	Vehicle(){
		make="Unknown";
		model="Unknown";
		year=2020;
		km=0;
		cout<<"Vehicle default"<<endl;
	}
	Vehicle(string m,string mo,int y){
		make=m;
		model=mo;
		year=y;
		km=0;
		cout<<"Vehicle "<<make<<" "<<model<<endl;
	}
	void show(){
		cout<<make<<endl<<model<<endl<<year<<endl;
		cout<<fixed<<setprecision(1);
		cout<<"Km "<<km<<endl;
	}
	void addKm(double x){
		km+=x;
		cout<<"add "<<x<<" total "<<km<<endl;
	}
	int age(){
		return 2024-year;
	}
	~Vehicle(){
		cout<<"Vehicle dtor "<<make<<endl;
	}
};

class Truck:public Vehicle{
protected:
	double cap,load;
public:
	Truck():Vehicle(){
		cap=0;load=0;
		cout<<"Truck default"<<endl;
	}
	Truck(string m,string mo,int y,double c):Vehicle(m,mo,y){
		cap=c;
		load=0;
		cout<<"Truck "<<cap<<endl;
	}
	void show(){
		cout<<"\nTruck"<<endl;
		Vehicle::show();
		cout<<"Cap "<<cap<<" Load "<<load<<endl;
	}
	void loadC(double w){
		if(load+w<=cap){
			load+=w;
			cout<<"load "<<w<<endl;
		}else{
			cout<<"exceed "<<cap-load<<endl;
		}
	}
	void unload(double w){
		if(load>=w){
			load-=w;
			cout<<"unload "<<w<<endl;
		}else cout<<"low load"<<endl;
	}
	~Truck(){
		cout<<"Truck dtor "<<cap<<endl;
	}
};

class RefTruck:public Truck{
	double temp,minT,maxT;
	bool on;
public:
	RefTruck():Truck(){
		temp=5;
		minT=-20;
		maxT=20;
		on=false;
		cout<<"Ref default"<<endl;
	}
	RefTruck(string m,string mo,int y,double c,double t):Truck(m,mo,y,c){
		temp=t;
		minT=-20;
		maxT=20;
		on=false;
		cout<<"Ref "<<temp<<endl;
	}
	void show(){
		cout<<"\nRefTruck"<<endl;
		Vehicle::show();
		cout<<"Cap "<<cap<<" Load "<<load<<endl;
		cout<<"Temp "<<temp<<" "<<(on?"ON":"OFF")<<endl;
	}
	void start(){
		if(!on){
			on=true;
			cout<<"cool on"<<endl;
		}
	}
	void stop(){
		if(on){
			on=false;
			cout<<"cool off"<<endl;
		}
	}
	void setT(double t){
		if(t>=minT && t<=maxT){
			temp=t;
			cout<<"set "<<temp<<endl;
		}else cout<<"range err"<<endl;
	}
	void loadP(double w,string type){
		if(!on) cout<<"warn off"<<endl;
		loadC(w);
		cout<<"cargo "<<type<<endl;
	}
	bool ok(string t){
		if(t=="Frozen" && temp<=0) return true;
		if(t=="Fresh" && temp>0 && temp<=10) return true;
		if(t=="Dairy" && temp>=2 && temp<=8) return true;
		return false;
	}
	~RefTruck(){
		cout<<"Ref dtor "<<temp<<endl;
	}
};

int main(){
	cout<<"Fleet"<<endl;

	Vehicle v("Honda","Civic",2022);
	v.show();
	v.addKm(5000);
	cout<<"Age "<<v.age()<<endl;

	Truck t("Ford","F150",2023,3.5);
	t.show();
	t.loadC(1.5);
	t.loadC(1);
	t.loadC(1.5);
	t.addKm(150);
	t.show();

	RefTruck r("Volvo","FH16",2024,15,5);
	r.show();
	r.start();
	r.setT(3);
	r.loadP(5,"Veg");
	r.loadP(4,"Dairy");
	r.loadP(3.5,"Fruits");
	cout<<"Dairy "<<(r.ok("Dairy")?"Yes":"No")<<endl;
	cout<<"Frozen "<<(r.ok("Frozen")?"Yes":"No")<<endl;
	r.addKm(350);
	r.show();

	r.unload(5);
	r.unload(4);
	r.stop();
	r.show();

	RefTruck r2("Merc","Actros",2024,20,-18);
	r2.start();
	r2.loadP(10,"Meat");
	r2.loadP(8,"Ice");
	r2.show();

	return 0;
}