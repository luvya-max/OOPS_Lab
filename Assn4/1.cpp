//Question: Q1 - Rectangle class with three constructors

#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double breadth;

public:
    Rectangle() {
        length = 0;
        breadth = 0;
    }

    Rectangle(double l, double b) {
        length = l;
        breadth = b;
    }

    Rectangle(double side) {
        length = side;
        breadth = side;
    }

    double calculateArea() {
        return length * breadth;
    }

    void display() {
        cout << "Length: " << length << ", Breadth: " << breadth 
             << ", Area: " << calculateArea() << endl;
    }
};

int main() {
    Rectangle r1;
    Rectangle r2(10.5, 5.5);
    Rectangle r3(7.0);

    cout << "Rectangle 1 (no parameters): ";
    r1.display();

    cout << "Rectangle 2 (two parameters): ";
    r2.display();

    cout << "Rectangle 3 (one parameter): ";
    r3.display();

    return 0;
}