//Question: Q3d - Verify destructors do not have any return type

#include <iostream>
using namespace std;

class TestClass {
private:
    int value;

public:
    TestClass(int v = 0) {
        value = v;
        cout << "Constructor called (no return type) with value: " << value << endl;
    }

    ~TestClass() {
        cout << "Destructor called (no return type) for value: " << value << endl;
    }

    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    cout << "Demonstration: Destructors have NO return type (just like constructors)\n\n";

    TestClass obj(200);
    obj.display();

    cout << "\nNote: Destructors do not have return type, not even void.\n";
    cout << "Syntax like 'void ~ClassName()' or 'int ~ClassName()' would be invalid.\n";

    return 0;
}