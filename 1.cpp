#include <iostream>
using namespace std;

template <typename V>
void swap(V a, V b){
    cout << "Before " << a << ", "<< b << endl;
    V c=a;
    a=b;
    b=c;
    cout << "After " << a << ", "<< b << endl;
}
int main(){
    swap(1,2);
    swap("hi","hey");
    return 0;
}