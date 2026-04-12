//Question: Q3e - Verify compiler generates default destructor when not specified

#include <iostream>
using namespace std;

class WithDestructor {
private:
    int value;

public:
    WithDestructor(int v = 0) {
        value = v;
        cout << "WithDestructor: Constructor called with value: " << value << endl;
    }

    ~WithDestructor() {
        cout << "WithDestructor: Explicit destructor called for value: " << value << endl;
    }
};

class WithoutDestructor {
private:
    int value;

public:
    WithoutDestructor(int v = 0) {
        value = v;
        cout << "WithoutDestructor: Constructor called with value: " << value << endl;
    }
};

int main() {
    cout << "Demonstration: Compiler provides default destructor if not specified\n\n";

    cout << "Creating object with explicit destructor:\n";
    WithDestructor obj1(100);

    cout << "\nCreating object without explicit destructor:\n";
    WithoutDestructor obj2(200);

    cout << "\nNote: obj2 uses compiler-generated default destructor.\n";
    cout << "Program ending - both destructors will be called:\n\n";

    return 0;
}