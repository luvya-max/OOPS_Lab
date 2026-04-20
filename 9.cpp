#include<iostream>
using namespace std;
template<class T>
class Arithmetic{
    T a, b;
public:
    void setValues(T x, T y){
        a = x;
        b = y;
    }
    void add(){
        cout << "Addition = " << a + b << endl;
    }
    void subtract(){
        cout << "Subtraction = " << a - b << endl;
    }
    void multiply(){
        cout << "Multiplication = " << a * b << endl;
    }
    void divide(){
        if(b == 0){
            cout << "Cannot divide by zero!" << endl;
        }
        else{
            cout << "Division = " << a / b << endl;
        }
    }
};
int main(){
    Arithmetic<int> obj;
    int x, y;
    cout << "Enter two integers: ";
    cin >> x >> y;
    obj.setValues(x, y);
    obj.add();
    obj.subtract();
    obj.multiply();
    obj.divide();
    return 0;
}