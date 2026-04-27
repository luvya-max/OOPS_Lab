//Question: Q3a - Verify destructor name begins with tilde (~) and matches class name

#include <iostream>
using namespace std;

class TestClass {
private:
    int value;

public:
    TestClass(int v) {
        value = v;
        cout << "Constructor called with value: " << value << endl;
    }

    ~TestClass() {
        cout << "Destructor ~TestClass() called for value: " << value << endl;
    }

    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    cout << "Creating object t1:\n";
    TestClass t1(10);
    t1.display();

    cout << "\nCreating object t2:\n";
    TestClass t2(20);
    t2.display();

    cout << "\nProgram ending - destructors will be called automatically:\n";
    cout << "(Note: Destructor name starts with ~ and matches class name)\n";

    return 0;
}