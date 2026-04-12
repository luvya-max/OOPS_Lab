//Question: Q3b - Verify there cannot be more than one destructor in a class

#include <iostream>
using namespace std;

class TestClass {
private:
    int value;

public:
    TestClass(int v = 0) {
        value = v;
        cout << "Constructor called with value: " << value << endl;
    }

    ~TestClass() {
        cout << "Destructor called for value: " << value << endl;
    }

    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    cout << "Demonstration: Only ONE destructor is allowed per class\n\n";

    TestClass obj(100);
    obj.display();

    cout << "\nNote: If you try to define multiple destructors, you will get a compilation error.\n";
    cout << "A class can have only one destructor.\n";

    return 0;
}