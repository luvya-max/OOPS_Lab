#include <iostream>
using namespace std;

int main() {
    cout << "Dynamic Memory Allocation for Integer Array\n\n";

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int* arr = new int[n];

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