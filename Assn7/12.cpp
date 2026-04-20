#include <iostream>
using namespace std;

class Test{
    float value;
    public:
        Test(float v = 0){ 
            value = v; 
        }
        operator float(){ 
            return value; 
        }
};

int main(){
    Test t(7.65);
    float x = t;
    cout << "Converted value: " << x << endl;
    return 0;
}
