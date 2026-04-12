// Question 3: Different Modes of Inheritance (Public, Protected, Private)
#include <iostream>
#include <string>
using namespace std;

// Base class with different access specifiers
class Base {
private:
    int privateData;
    
protected:
    int protectedData;
    
public:
    int publicData;
    
    Base() {
        privateData = 10;
        protectedData = 20;
        publicData = 30;
    }
    
    void showBaseData() {
        cout << "Private Data: " << privateData << endl;
        cout << "Protected Data: " << protectedData << endl;
        cout << "Public Data: " << publicData << endl;
    }
};

// PUBLIC INHERITANCE - Most commonly used
class PublicDerived : public Base {
public:
    void accessBaseMembers() {
        cout << "\n=== Public Inheritance ===" << endl;
        // privateData is NOT accessible
        // cout << privateData << endl;  // ERROR!
        
        // protectedData remains protected (accessible in derived class)
        cout << "Protected Data (from base): " << protectedData << endl;
        protectedData = 25;  // Can modify
        
        // publicData remains public (accessible everywhere)
        cout << "Public Data (from base): " << publicData << endl;
        publicData = 35;  // Can modify
    }
};

// PROTECTED INHERITANCE
class ProtectedDerived : protected Base {
public:
    void accessBaseMembers() {
        cout << "\n=== Protected Inheritance ===" << endl;
        // privateData is NOT accessible
        // cout << privateData << endl;  // ERROR!
        
        // protectedData remains protected (accessible in derived class)
        cout << "Protected Data (from base): " << protectedData << endl;
        protectedData = 27;  // Can modify
        
        // publicData becomes protected (accessible in derived class but not outside)
        cout << "Public Data (from base, now protected): " << publicData << endl;
        publicData = 37;  // Can modify
    }
};

// PRIVATE INHERITANCE
class PrivateDerived : private Base {
public:
    void accessBaseMembers() {
        cout << "\n=== Private Inheritance ===" << endl;
        // privateData is NOT accessible
        // cout << privateData << endl;  // ERROR!
        
        // protectedData becomes private (accessible in derived class only)
        cout << "Protected Data (from base, now private): " << protectedData << endl;
        protectedData = 29;  // Can modify
        
        // publicData becomes private (accessible in derived class only)
        cout << "Public Data (from base, now private): " << publicData << endl;
        publicData = 39;  // Can modify
    }
};

int main() {
    cout << "===== DEMONSTRATING DIFFERENT INHERITANCE MODES =====" << endl;
    
    // PUBLIC INHERITANCE
    cout << "\n--- Testing Public Inheritance ---" << endl;
    PublicDerived pubObj;
    pubObj.accessBaseMembers();
    // Public members of base remain public
    pubObj.publicData = 100;  // Allowed
    cout << "Accessing publicData from outside: " << pubObj.publicData << endl;
    
    // PROTECTED INHERITANCE
    cout << "\n--- Testing Protected Inheritance ---" << endl;
    ProtectedDerived protObj;
    protObj.accessBaseMembers();
    // Public members of base become protected - cannot access from outside
    // protObj.publicData = 100;  // ERROR! Not accessible
    
    // PRIVATE INHERITANCE
    cout << "\n--- Testing Private Inheritance ---" << endl;
    PrivateDerived privObj;
    privObj.accessBaseMembers();
    // All base members become private - cannot access from outside
    // privObj.publicData = 100;  // ERROR! Not accessible
    
    cout << "\n===== KEY DIFFERENCES =====" << endl;
    cout << "1. PUBLIC inheritance: Base public members remain public, protected remain protected" << endl;
    cout << "2. PROTECTED inheritance: Base public members become protected, protected remain protected" << endl;
    cout << "3. PRIVATE inheritance: All accessible base members become private" << endl;
    cout << "Note: Private members of base are NEVER accessible in derived class" << endl;
    
    return 0;
}