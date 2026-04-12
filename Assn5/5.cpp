// Question 5: Constructors and Destructors in Inheritance
#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;
    
public:
    // Default constructor
    Person() {
        name = "Unknown";
        age = 0;
        cout << "Person default constructor called" << endl;
    }
    
    // Parameterized constructor
    Person(string n, int a) : name(n), age(a) {
        cout << "Person parameterized constructor called for: " << name << endl;
    }
    
    // Destructor
    ~Person() {
        cout << "Person destructor called for: " << name << endl;
    }
    
    void displayPerson() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived class
class Employee : public Person {
private:
    int employeeId;
    string department;
    
public:
    // Default constructor
    Employee() : Person() {
        employeeId = 0;
        department = "Not Assigned";
        cout << "Employee default constructor called" << endl;
    }
    
    // Parameterized constructor
    // Note: Base class constructor is called first, then derived class constructor
    Employee(string n, int a, int id, string dept) : Person(n, a) {
        employeeId = id;
        department = dept;
        cout << "Employee parameterized constructor called for ID: " << employeeId << endl;
    }
    
    // Destructor
    // Note: Derived class destructor is called first, then base class destructor
    ~Employee() {
        cout << "Employee destructor called for ID: " << employeeId << endl;
    }
    
    void displayEmployee() {
        displayPerson();
        cout << "Employee ID: " << employeeId << endl;
        cout << "Department: " << department << endl;
    }
};

// Another derived class to demonstrate multiple levels
class Manager : public Employee {
private:
    int teamSize;
    
public:
    // Default constructor
    Manager() : Employee() {
        teamSize = 0;
        cout << "Manager default constructor called" << endl;
    }
    
    // Parameterized constructor
    Manager(string n, int a, int id, string dept, int team) 
        : Employee(n, a, id, dept) {
        teamSize = team;
        cout << "Manager parameterized constructor called, Team Size: " << teamSize << endl;
    }
    
    // Destructor
    ~Manager() {
        cout << "Manager destructor called for team size: " << teamSize << endl;
    }
    
    void displayManager() {
        displayEmployee();
        cout << "Team Size: " << teamSize << endl;
    }
};

int main() {
    cout << "======================================" << endl;
    cout << "DEMONSTRATION OF CONSTRUCTOR ORDER" << endl;
    cout << "======================================\n" << endl;
    
    cout << "--- Creating Employee Object ---" << endl;
    Employee emp1("Alice Smith", 30, 1001, "IT");
    cout << "\n--- Displaying Employee Information ---" << endl;
    emp1.displayEmployee();
    
    cout << "\n\n--- Creating Manager Object ---" << endl;
    Manager mgr1("Bob Johnson", 40, 2001, "Sales", 10);
    cout << "\n--- Displaying Manager Information ---" << endl;
    mgr1.displayManager();
    
    cout << "\n\n======================================" << endl;
    cout << "DEMONSTRATION OF DESTRUCTOR ORDER" << endl;
    cout << "======================================" << endl;
    cout << "Objects will be destroyed in reverse order of creation" << endl;
    cout << "Destructors are called automatically when objects go out of scope\n" << endl;
    
    // Creating objects in a block to demonstrate destruction
    {
        cout << "--- Creating objects in a block ---" << endl;
        Person p1("Charlie", 25);
        Employee e1("Diana", 28, 3001, "HR");
        cout << "\n--- Exiting block, destructors will be called now ---" << endl;
    }
    
    cout << "\n--- Program ending, remaining objects will be destroyed ---" << endl;
    
    return 0;
}

/* 
KEY POINTS:
1. Constructor Order: Base -> Derived (Top to Bottom)
2. Destructor Order: Derived -> Base (Bottom to Top)
3. Base class constructor is always called before derived class constructor
4. Derived class destructor is always called before base class destructor
5. If base class constructor requires parameters, use initialization list in derived class
*/