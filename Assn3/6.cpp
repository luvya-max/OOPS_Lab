//QUESTION 6: Inline Function - Calculate Cube of a Number

#include <iostream>
using namespace std;

// METHOD 1: Inline function defined inside class
class Calculator1 {
public:
    int cube(int num) {
        return num * num * num;
    }
};

// METHOD 2: Explicit inline keyword
class Calculator2 {
public:
    inline int cube(int num); 
};
inline int Calculator2::cube(int num) {
    return num * num * num;
}

// METHOD 3: Standalone inline function (most common for this question)
inline int cube(int num) {
    return num * num * num;
}
int cubeNormal(int num) {
    return num * num * num;
}

int main() {
    cout << "=== INLINE FUNCTION - CUBE CALCULATION ===" << endl;
    
    int number;
    cout << "\nEnter a number: ";
    cin >> number;
    
    cout << "\nUsing inline function:" << endl;
    cout << "Cube of " << number << " = " << cube(number) << endl;
    
    Calculator1 calc1;
    cout << "\nUsing Calculator1 (inline in class):" << endl;
    cout << "Cube of " << number << " = " << calc1.cube(number) << endl;
    
    Calculator2 calc2;
    cout << "\nUsing Calculator2 (explicit inline):" << endl;
    cout << "Cube of " << number << " = " << calc2.cube(number) << endl;
    
    cout << "\n--- Cube Table (using inline function) ---" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << "Cube of " << i << " = " << cube(i) << endl;
    }
    
    return 0;
}