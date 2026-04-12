// QUESTION 3: Friend Function to Add Objects of Different Classes

#include <iostream>
using namespace std;

class Distance2;

class Distance1 {
private:
    int meters;
    int centimeters;
    
public:
    Distance1(int m, int cm) {
        meters = m;
        centimeters = cm;
    }
    
    void display() {
        cout << meters << " meters " << centimeters << " centimeters" << endl;
    }
    friend Distance1 addDistances(Distance1 d1, Distance2 d2);
};

class Distance2 {
private:
    int feet;
    int inches;
    
public:
    Distance2(int f, int i) {
        feet = f;
        inches = i;
    }
    
    void display() {
        cout << feet << " feet " << inches << " inches" << endl;
    }
    friend Distance1 addDistances(Distance1 d1, Distance2 d2);
};

Distance1 addDistances(Distance1 d1, Distance2 d2) {
    int totalCm2 = (d2.feet * 30.48) + (d2.inches * 2.54);
    int meters2 = totalCm2 / 100;
    int cm2 = totalCm2 % 100;
    int totalMeters = d1.meters + meters2;
    int totalCm = d1.centimeters + cm2;
    if (totalCm >= 100) {
        totalMeters += totalCm / 100;
        totalCm = totalCm % 100;
    }
    return Distance1(totalMeters, totalCm);
}

int main() {
    cout << "=== FRIEND FUNCTION TO ADD DIFFERENT CLASS OBJECTS ===" << endl;
    
    Distance1 d1(5, 50);  
    Distance2 d2(10, 6);   
    
    cout << "\nDistance 1: ";
    d1.display();
    
    cout << "Distance 2: ";
    d2.display();

    Distance1 result = addDistances(d1, d2);
    
    cout << "\nTotal distance: ";
    result.display();
    
    return 0;
}