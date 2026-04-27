#include <iostream>
using namespace std;

class Array{
    int arr[5];
    public:
        Array(){ 
            for(int i=0;i<5;i++) arr[i]=i+1; 
        }

        int& operator[](int index){
            if(index < 0 || index >= 5){
                cout << "Index out of bounds!" << endl;
                exit(1);
            }
            return arr[index];
        }
};

int main(){
    Array a;
    cout << a[2] << endl;
    return 0;
}
