#include<iostream>
#include<iomanip>
using namespace std;

class Speedometer{
protected:
	double speed,maxSpeed;
public:
	Speedometer(){
		speed=0;
		maxSpeed=200;
		cout<<"Speedo init"<<endl;
	}
	void setSpeed(double s){
		if(s>=0 && s<=maxSpeed) speed=s;
		else if(s>maxSpeed){
			speed=maxSpeed;
			cout<<"limit "<<maxSpeed<<endl;
		}
		else speed=0;
	}
	double getSpeed(){return speed;}
	void showSpeed(){
		cout<<fixed<<setprecision(1);
		cout<<"Speed "<<speed;
		if(speed>120) cout<<" high";
		cout<<endl;
	}
	~Speedometer(){
		cout<<"Speedo dtor"<<endl;
	}
};

class FuelGauge{
protected:
	double fuel,cap;
public:
	FuelGauge(){
		fuel=50;
		cap=60;
		cout<<"Fuel init"<<endl;
	}
	void setFuel(double f){
		if(f>=0 && f<=cap) fuel=f;
		else if(f>cap) fuel=cap;
		else fuel=0;
	}
	void useFuel(double x){
		if(fuel>=x) fuel-=x;
		else fuel=0;
	}
	void refuel(double x){
		if(fuel+x<=cap){
			fuel+=x;
			cout<<"refuel "<<x<<endl;
		}else{
			cout<<"full "<<cap-fuel<<endl;
			fuel=cap;
		}
	}
	double getFuel(){return fuel;}
	void showFuel(){
		cout<<fixed<<setprecision(1);
		cout<<"Fuel "<<fuel<<"/"<<cap;
		double p=(fuel/cap)*100;
		if(p<15) cout<<" low";
		cout<<" ("<<p<<"%)"<<endl;
	}
	~FuelGauge(){
		cout<<"Fuel dtor"<<endl;
	}
};

class Thermometer{
protected:
	double temp,norm,maxT;
public:
	Thermometer(){
		temp=90;
		norm=90;
		maxT=120;
		cout<<"Temp init"<<endl;
	}
	void setTemp(double t){temp=t;}
	void update(double s){
		temp=norm+(s*0.15);
		if(temp>maxT) temp=maxT;
	}
	double getTemp(){return temp;}
	void showTemp(){
		cout<<fixed<<setprecision(1);
		cout<<"Temp "<<temp;
		if(temp>110) cout<<" over";
		else if(temp>100) cout<<" hot";
		cout<<endl;
	}
	~Thermometer(){
		cout<<"Temp dtor"<<endl;
	}
};

class CarDash:public Speedometer,public FuelGauge,public Thermometer{
	string model;
	bool on;
public:
	CarDash(string m){
		model=m;
		on=false;
		cout<<"Dash "<<model<<endl;
	}
	void start(){
		if(!on){
			on=true;
			cout<<"start"<<endl;
		}else cout<<"already"<<endl;
	}
	void stop(){
		if(on){
			on=false;
			setSpeed(0);
			cout<<"stop"<<endl;
		}
	}
	void drive(double sp,double t){
		if(!on){
			cout<<"start first"<<endl;
			return;
		}
		setSpeed(sp);
		double dist=(sp*t)/60.0;
		double used=dist*0.08;
		useFuel(used);
		update(sp);
		cout<<"drive "<<sp<<" "<<t<<endl;
		cout<<"dist "<<dist<<" fuel "<<used<<endl;
	}
	void show(){
		cout<<"\n"<<model<<endl;
		cout<<(on?"ON":"OFF")<<endl;
		showSpeed();
		showFuel();
		showTemp();
	}
	~CarDash(){
		cout<<"Dash dtor "<<model<<endl;
	}
};

int main(){
	cout<<"Dashboard"<<endl;

	CarDash c("Tesla");
	c.show();

	c.start();
	c.show();

	c.drive(60,15);
	c.show();

	c.drive(120,30);
	c.show();

	c.drive(180,10);
	c.show();

	c.refuel(30);
	c.show();

	c.stop();
	c.show();

	return 0;
}