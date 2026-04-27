//Question: Q4d - Dynamic memory allocation for float array using new and delete

#include <iostream>
using namespace std;

int main() {
    cout << "Dynamic Memory Allocation for Float Array\n\n";

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    float* arr = new float[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nArray elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    cout << "\nMemory deallocated successfully using delete[].\n";

    return 0;
}