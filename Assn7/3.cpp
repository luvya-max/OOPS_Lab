#include <iostream>
#include <cmath>
using namespace std;

class Triangle{
public:
    float area(float base, float height){ 
        return 0.5 * base * height;
    }
    float area(float side){
        return (sqrt(3) / 4) * side * side;
    }
    float area(float a, float b, float c){ 
        float s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

int main(){
    Triangle t;
    cout << "Right angle: " << t.area(4, 8) << endl;
    cout << "Equilateral: " << t.area(5) << endl;
    cout << "Isosceles: " << t.area(5, 5, 8) << endl;
    return 0;
}

