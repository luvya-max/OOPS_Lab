#include <iostream>
#include <cmath>
using namespace std;

class Shape{
    public:
        virtual float area() = 0;
        virtual void display() = 0;
};

class Circle : public Shape {
    float radius;
    public:
        Circle(float r) : radius(r) {}
        float area(){ 
            return 3.1416f * radius * radius; 
        }
        void display(){ 
            cout << "Circle Area: " << area() << endl; 
        }
};

class Rectangle : public Shape {
    float length, breadth;
    public:
        Rectangle(float l, float b) : length(l), breadth(b) {}
        float area(){
            return length * breadth;
        }
        void display(){ 
            cout << "Rectangle Area: " << area() << endl; 
        }
};

class Triangle : public Shape{
    float base, height;
    public:
        Triangle(float b, float h) : base(b), height(h) {}
        float area(){ 
            return 0.5f * base * height;
        }
        void display(){ 
            cout << "Triangle Area: " << area() << endl; 
            }
};

int main() {
    Circle c(5);
    Rectangle r(4, 6);
    Triangle t(5, 3);

    Shape* s[] = { &c, &r, &t };
    for (Shape* ptr : s) ptr->display();

    return 0;
}
