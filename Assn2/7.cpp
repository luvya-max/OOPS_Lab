#include <iostream>
using namespace std;

namespace a{
    int b=4;
    void f(){
        cout<<"Namespace a" << endl;
    }
}

namespace c{
    int b=5;
    void f(){
        cout << "Namespace c" << endl;
    }
}
int main(){
    cout << a::b << " " << c::b << endl;
    a::f();
    c::f(); 
    return 0;
}