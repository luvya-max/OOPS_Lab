#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double breadth;
    int id;

public:
    Rectangle(double l = 0, double b = 0, int i = 0) {
        length = l;
        breadth = b;
        id = i;
        cout << "Constructor called for Rectangle " << id << endl;
    }

    ~Rectangle() {
        cout << "Destructor called for Rectangle " << id << endl;
    }

    double calculateArea() {
        return length * breadth;
    }

    void display() {
        cout << "Rectangle " << id << " - Length: " << length 
             << ", Breadth: " << breadth << ", Area: " << calculateArea() << endl;
    }
};

int main() {
    cout << "Creating array of 5 Rectangle objects:\n" << endl;
    
    Rectangle rectangles[5] = {
        Rectangle(5.0, 3.0, 1),
        Rectangle(7.5, 4.5, 2),
        Rectangle(6.0, 6.0, 3),
        Rectangle(8.0, 2.0, 4),
        Rectangle(10.0, 5.0, 5)
    };

    cout << "\nCalculating areas:\n" << endl;
    for (int i = 0; i < 5; i++) {
        rectangles[i].display();
    }

    cout << "\nProgram ending - destructors will be called:\n" << endl;

    return 0;
}