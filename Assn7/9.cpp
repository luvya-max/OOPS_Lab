#include <iostream>
using namespace std;

class Print{
    public:
        void operator()(int a) { 
            cout << "One arg: " << a << endl; 
        }
        void operator()(int a, int b) { 
            cout << "Two args: " << a << ", " << b << endl; 
        }
        void operator()(string s) { 
            cout << "String: " << s << endl;
        }
};

int main(){
    Print p;
    p(5);
    p(3, 7);
    p("Hello");
    return 0;
}
