//QUESTION 5: Array of Objects - Display Area of Multiple Rectangles

#include <iostream>
using namespace std;

class Rectangle {
private:
    int length;
    int width;
    
public:
    
    Rectangle() {
        length = 0;
        width = 0;
    }
    Rectangle(int l, int w) {
        length = l;
        width = w;
    }
    void input() {
        cout << "Enter length: ";
        cin >> length;
        cout << "Enter width: ";
        cin >> width;
    }
    int area() {
        return length * width;
    }
    void display() {
        cout << "Length: " << length << ", Width: " << width;
        cout << ", Area: " << area() << endl;
    }
};

int main() {
    cout << "=== ARRAY OF OBJECTS - RECTANGLES ===" << endl;
    
    int n;
    cout << "\nHow many rectangles? ";
    cin >> n;
    
    Rectangle rectangles[n];
    
    cout << "\nEnter details for " << n << " rectangles:\n" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Rectangle " << (i + 1) << ":" << endl;
        rectangles[i].input();
        cout << endl;
    }
    
    cout << "\n--- Rectangle Details ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Rectangle " << (i + 1) << ": ";
        rectangles[i].display();
    }
    
    int maxIndex = 0;
    int maxArea = rectangles[0].area();
    
    for (int i = 1; i < n; i++) {
        if (rectangles[i].area() > maxArea) {
            maxArea = rectangles[i].area();
            maxIndex = i;
        }
    }
    
    cout << "\nRectangle with maximum area is Rectangle " << (maxIndex + 1);
    cout << " with area: " << maxArea << endl;
    
    int totalArea = 0;
    for (int i = 0; i < n; i++) {
        totalArea += rectangles[i].area();
    }
    cout << "\nTotal area of all rectangles: " << totalArea << endl;
    
    return 0;
}