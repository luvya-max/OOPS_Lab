#include <iostream>
using namespace std;

class Complex {
    private:
        int real, imag;

    public:
        Complex(int r, int i) {
            real = r;
            imag = i;
        }
        Complex(const Complex &c) {
            real = c.real;
            imag = c.imag;
        }
        void display() {
            cout << real << " + " << imag << "i" << endl;
        }
        friend Complex sum(Complex, Complex);
};

Complex sum(Complex c1, Complex c2) {
    Complex temp(0, 0);
    temp.real = c1.real + c2.real;
    temp.imag = c1.imag + c2.imag;
    return temp;
}

int main() {
    Complex c1(2, 3), c2(4, 5);
    Complex result = sum(c1, c2);
    result.display();
    return 0;
}