//Question: Q4e - Dynamic memory allocation for class object using new and delete

#include <iostream>
using namespace std;

class Student {
private:
    int rollNo;
    string name;

public:
    Student(int r = 0, string n = "Unknown") {
        rollNo = r;
        name = n;
        cout << "Constructor called for " << name << endl;
    }

    ~Student() {
        cout << "Destructor called for " << name << endl;
    }

    void display() {
        cout << "Roll No: " << rollNo << ", Name: " << name << endl;
    }
};

int main() {
    cout << "Dynamic Memory Allocation for Class Object\n\n";

    Student* ptr = new Student(101, "Manya");

    ptr->display();

    delete ptr;

    cout << "\nMemory deallocated successfully using delete.\n";

    return 0;
}