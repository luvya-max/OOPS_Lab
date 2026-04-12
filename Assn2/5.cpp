#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    void setComplex(float r, float i) {
        real = r;
        imag = i;
    }
    void displayComplex() {
        cout << real << " + " << imag << "i" << endl;
    }
    Complex add(Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp; 
    }
}c1,c2,sum;

int main() {
    float a,b;
    cout << "Enter first complex number (real part enter imaginary part) ";
    cin >> a;
    cin >> b;
    c1.setComplex(a, b);
    cout << "Enter second complex number (real part enter imaginary part) ";
    cin >> a;
    cin >> b;
    c2.setComplex(a, b);
    sum = c1.add(c2);
    cout << "Sum of both complex numbers: ";
    sum.displayComplex();
    return 0;
}
