// Question 4: Various Types of Inheritance
#include <iostream>
#include <string>
using namespace std;

// ============================================
// 1. SINGLE INHERITANCE (One Base, One Derived)
// ============================================
class Vehicle {
protected:
    string brand;
public:
    Vehicle(string b) : brand(b) {}
    void displayBrand() {
        cout << "Brand: " << brand << endl;
    }
};

class Car : public Vehicle {
private:
    int numDoors;
public:
    Car(string b, int doors) : Vehicle(b), numDoors(doors) {}
    void displayCar() {
        displayBrand();
        cout << "Number of Doors: " << numDoors << endl;
    }
};

// ============================================
// 2. MULTIPLE INHERITANCE (Multiple Bases, One Derived)
// ============================================
class Engine {
protected:
    int horsepower;
public:
    Engine(int hp) : horsepower(hp) {}
    void displayEngine() {
        cout << "Horsepower: " << horsepower << endl;
    }
};

class Transmission {
protected:
    string type;
public:
    Transmission(string t) : type(t) {}
    void displayTransmission() {
        cout << "Transmission: " << type << endl;
    }
};

class SportsCar : public Engine, public Transmission {
private:
    string model;
public:
    SportsCar(string m, int hp, string trans) 
        : Engine(hp), Transmission(trans), model(m) {}
    void displaySportsCar() {
        cout << "Model: " << model << endl;
        displayEngine();
        displayTransmission();
    }
};

// ============================================
// 3. MULTILEVEL INHERITANCE (Chain: A -> B -> C)
// ============================================
class LivingBeing {
protected:
    bool isAlive;
public:
    LivingBeing() : isAlive(true) {}
    void breathe() {
        cout << "Breathing..." << endl;
    }
};

class Animal : public LivingBeing {
protected:
    string species;
public:
    Animal(string s) : species(s) {}
    void eat() {
        cout << species << " is eating" << endl;
    }
};

class Dog : public Animal {
private:
    string name;
public:
    Dog(string n) : Animal("Canine"), name(n) {}
    void bark() {
        cout << name << " says: Woof!" << endl;
    }
    void displayDog() {
        breathe();
        eat();
        bark();
    }
};

// ============================================
// 4. HIERARCHICAL INHERITANCE (One Base, Multiple Derived)
// ============================================
class Shape {
protected:
    string color;
public:
    Shape(string c) : color(c) {}
    void displayColor() {
        cout << "Color: " << color << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(string c, double r) : Shape(c), radius(r) {}
    void displayCircle() {
        cout << "Circle - ";
        displayColor();
        cout << "Radius: " << radius << endl;
    }
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(string c, double l, double w) : Shape(c), length(l), width(w) {}
    void displayRectangle() {
        cout << "Rectangle - ";
        displayColor();
        cout << "Length: " << length << ", Width: " << width << endl;
    }
};

// ============================================
// 5. HYBRID INHERITANCE (Combination of multiple types)
// ============================================
class Student {
protected:
    string studentName;
    int rollNo;
public:
    Student(string name, int roll) : studentName(name), rollNo(roll) {}
};

class Sports {
protected:
    int sportsScore;
public:
    Sports(int score) : sportsScore(score) {}
};

class Exam : public Student {
protected:
    int examScore;
public:
    Exam(string name, int roll, int score) : Student(name, roll), examScore(score) {}
};

class Result : public Exam, public Sports {
public:
    Result(string name, int roll, int eScore, int sScore) 
        : Exam(name, roll, eScore), Sports(sScore) {}
    
    void displayResult() {
        cout << "Student: " << studentName << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Exam Score: " << examScore << endl;
        cout << "Sports Score: " << sportsScore << endl;
        cout << "Total Score: " << (examScore + sportsScore) << endl;
    }
};

// ============================================
// MAIN FUNCTION
// ============================================
int main() {
    cout << "========================================" << endl;
    cout << "1. SINGLE INHERITANCE" << endl;
    cout << "========================================" << endl;
    Car myCar("Toyota", 4);
    myCar.displayCar();
    
    cout << "\n========================================" << endl;
    cout << "2. MULTIPLE INHERITANCE" << endl;
    cout << "========================================" << endl;
    SportsCar ferrari("Ferrari F8", 710, "Automatic");
    ferrari.displaySportsCar();
    
    cout << "\n========================================" << endl;
    cout << "3. MULTILEVEL INHERITANCE" << endl;
    cout << "========================================" << endl;
    Dog myDog("Buddy");
    myDog.displayDog();
    
    cout << "\n========================================" << endl;
    cout << "4. HIERARCHICAL INHERITANCE" << endl;
    cout << "========================================" << endl;
    Circle circle1("Red", 5.5);
    circle1.displayCircle();
    Rectangle rect1("Blue", 10.0, 5.0);
    rect1.displayRectangle();
    
    cout << "\n========================================" << endl;
    cout << "5. HYBRID INHERITANCE" << endl;
    cout << "========================================" << endl;
    Result student1("John Doe", 101, 85, 90);
    student1.displayResult();
    
    return 0;
}