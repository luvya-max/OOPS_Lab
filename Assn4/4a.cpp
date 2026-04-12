//Question: Q4a - Dynamic memory allocation for integer variable using new and delete

#include <iostream>
using namespace std;

int main() {
    cout << "Dynamic Memory Allocation for Integer Variable\n\n";

    int* ptr = new int;

    *ptr = 42;

    cout << "Value stored: " << *ptr << endl;
    cout << "Address: " << ptr << endl;

    delete ptr;

    cout << "\nMemory deallocated successfully using delete.\n";

    return 0;
}