#include <iostream>
using namespace std;

class ClassB;
class ClassA {
    private:
        int valueA;
    public:
        ClassA(int val) {
            valueA = val;
        }
        
        void display() {
            cout << "ClassA value: " << valueA << endl;
        }
    friend void swapValues(ClassA &a, ClassB &b);
};
class ClassB {
    private:
        int valueB;
    public:
        ClassB(int val) {
            valueB = val;
        }
        
        void display() {
            cout << "ClassB value: " << valueB << endl;
        }
    friend void swapValues(ClassA &a, ClassB &b);
};
void swapValues(ClassA &a, ClassB &b) {
    int temp;
    temp = a.valueA;       
    a.valueA = b.valueB;    
    b.valueB = temp;
}

int main() {
    cout << "=== FRIEND FUNCTION TO SWAP VALUES ===" << endl;
    
    ClassA objA(10);
    ClassB objB(20);
    
    cout << "\nBefore swapping:" << endl;
    objA.display();
    objB.display();
    swapValues(objA, objB);
    cout << "\nAfter swapping:" << endl;
    objA.display();
    objB.display();
    
    return 0;
}