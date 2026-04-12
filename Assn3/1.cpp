// QUESTION 1: Pointer to Object and 'this' Pointer

#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    float marks;

public:
    Student(string n, int r, float m) {
        name = n;
        rollNo = r;
        marks = m;
    }
    void displayUsingThis() {
        cout << "\n--- Using 'this' pointer ---" << endl;
        cout << "Name: " << this->name << endl;
        cout << "Roll No: " << this->rollNo << endl;
        cout << "Marks: " << this->marks << endl;
    }
    bool hasHigherMarks(Student other) {
        return this->marks > other.marks;
    }
    void display() {
        cout << "\nName: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    cout << "=== POINTER TO OBJECT AND 'THIS' POINTER ===" << endl;
    Student s1("Rahul", 101, 85.5);
    cout << "\n1. Accessing object using DOT (.) operator:" << endl;
    s1.display();
    Student *ptr;
    ptr = &s1;
    cout << "\n2. Accessing object using ARROW (->) operator:" << endl;
    ptr->display();
    cout << "\n3. Demonstrating 'this' pointer:" << endl;
    s1.displayUsingThis();
    Student s2("Priya", 102, 90.0);
    
    cout << "\n4. Using 'this' pointer for comparison:" << endl;
    if (s1.hasHigherMarks(s2)) {
        cout << "Rahul has higher marks" << endl;
    } else {
        cout << "Priya has higher marks" << endl;
    }
    cout << "\n5. Creating object using pointer:" << endl;
    Student *s3 = new Student("Amit", 103, 88.0);
    s3->display(); 
    delete s3; 
    return 0;
}