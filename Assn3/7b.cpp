//QUESTION 7b: Pass Object by Reference and Return Object

#include <iostream>
using namespace std;

class Number {
private:
    int value;
public:
    // Constructor
    Number(int v = 0) {
        value = v;
        cout << "Constructor called for value: " << value << endl;
    }
    // Copy constructor
    Number(const Number &obj) {
        value = obj.value;
        cout << "Copy constructor called for value: " << value << endl;
    }
    // Destructor
    ~Number() {
        cout << "Destructor called for value: " << value << endl;
    }
    
    void display() const {
        cout << "Value: " << value << endl;
    }
    
    int getValue() const {
        return value;
    }
    
    void setValue(int v) {
        value = v;
    }
};

// PASS BY REFERENCE: No copy made, works with original object
Number addNumbers(const Number &n1, const Number &n2) {
    cout << "\n--- Inside addNumbers (reference) ---" << endl;
    int sum = n1.getValue() + n2.getValue();
    Number result(sum);
    return result;
}

// Pass by reference - can modify original
void increment(Number &n) {
    cout << "\n--- Inside increment (reference) ---" << endl;
    int newValue = n.getValue() + 1;
    n.setValue(newValue);
    cout << "Incremented inside function" << endl;
}

// Demonstration: pass by value vs reference
void modifyByValue(Number n) {
    cout << "\n--- Inside modifyByValue ---" << endl;
    n.setValue(999);
    cout << "Modified to 999 inside function (copy)" << endl;
}

void modifyByReference(Number &n) {
    cout << "\n--- Inside modifyByReference ---" << endl;
    n.setValue(999);
    cout << "Modified to 999 inside function (reference)" << endl;
}

int main() {
    cout << "=== PASS OBJECT BY REFERENCE ===" << endl;
    
    // Test 1: Addition with reference
    cout << "\n=== TEST 1: Addition (pass by reference) ===" << endl;
    Number num1(10);
    Number num2(20);
    
    cout << "\nCalling addNumbers with reference:" << endl;
    Number sum = addNumbers(num1, num2);
    
    cout << "\nResult:" << endl;
    sum.display();
    
    // Test 2: Modification with reference
    cout << "\n=== TEST 2: Increment (pass by reference) ===" << endl;
    Number num3(50);
    cout << "\nBefore increment:" << endl;
    num3.display();
    
    increment(num3);  // Modifies original
    
    cout << "\nAfter increment:" << endl;
    num3.display();
    
    // Test 3: Comparing value vs reference
    cout << "\n=== TEST 3: Value vs Reference Comparison ===" << endl;
    Number num4(100);
    
    cout << "\nOriginal value:" << endl;
    num4.display();
    
    cout << "\nTrying to modify by VALUE:" << endl;
    modifyByValue(num4);
    cout << "After modifyByValue:" << endl;
    num4.display();
    
    cout << "\nTrying to modify by REFERENCE:" << endl;
    modifyByReference(num4);
    cout << "After modifyByReference:" << endl;
    num4.display();
    
    cout << "\n=== Program ending ===" << endl;
    
    return 0;
}