//Q4f - Dynamic memory allocation for array of class objects using new and delete

#include <iostream>
using namespace std;

class Student {
private:
    int rollNo;
    string name;

public:
    Student() {
        rollNo = 0;
        name = "Unknown";
    }

    Student(int r, string n) {
        rollNo = r;
        name = n;
        cout << "Constructor called for " << name << endl;
    }

    ~Student() {
        if (rollNo != 0) {
            cout << "Destructor called for " << name << endl;
        }
    }

    void setData(int r, string n) {
        rollNo = r;
        name = n;
    }

    void display() {
        cout << "Roll No: " << rollNo << ", Name: " << name << endl;
    }
};

int main() {
    cout << "Dynamic Memory Allocation for Array of Objects\n\n";

    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student* students = new Student[n];

    for (int i = 0; i < n; i++) {
        int roll;
        string name;
        cout << "\nEnter roll number for student " << i + 1 << ": ";
        cin >> roll;
        cout << "Enter name for student " << i + 1 << ": ";
        cin.ignore();
        getline(cin, name);
        students[i].setData(roll, name);
    }

    cout << "\nStudent Details:\n";
    for (int i = 0; i < n; i++) {
        students[i].display();
    }

    delete[] students;

    cout << "\nMemory deallocated successfully using delete[].\n";

    return 0;
}