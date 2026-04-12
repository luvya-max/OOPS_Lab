//Question: Q3c - Verify destructors do not allow any parameter

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
        cout << "Destructor called (no parameters allowed) for value: " << value << endl;
    }

    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    cout << "Demonstration: Destructors CANNOT have parameters\n\n";

    TestClass obj1(50);
    obj1.display();

    TestClass obj2(75);
    obj2.display();

    cout << "\nNote: Destructors cannot take any parameters.\n";
    cout << "Syntax ~ClassName(int x) would cause a compilation error.\n";

    return 0;
}