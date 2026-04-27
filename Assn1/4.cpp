#include <iostream>
using namespace std;

int main(){
    float temp,out;
    cout << "Enter temperature in degree celsius ";
    cin >> temp;
    out=(temp*9/5)+32;
    cout << out;
    return 0;
}