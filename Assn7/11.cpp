#include <iostream>
using namespace std;

class Test{
    float val;
    public:
        Test(float x = 0){
            val = x; 
        }
        void show(){ 
            cout << "Value = " << val << endl; 
        }
};

int main(){
    float x = 5.67;
    Test t = x;
    t.show();
    return 0;
}
