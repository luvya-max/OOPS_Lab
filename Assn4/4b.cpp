//Question: Q4b - Dynamic memory allocation for float variable using new and delete

#include <iostream>
using namespace std;

int main() {
    cout << "Dynamic Memory Allocation for Float Variable\n\n";

    float* ptr = new float;

    *ptr = 3.14159;

    cout << "Value stored: " << *ptr << endl;
    cout << "Address: " << ptr << endl;

    delete ptr;

    cout << "\nMemory deallocated successfully using delete.\n";

    return 0;
}