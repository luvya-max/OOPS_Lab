#include <iostream>
#include <fstream>
using namespace std;

int main(){
    char a;
    int b;
    ifstream f1("AZ.txt");
    while (f1.get(a)){
        b=f1.tellg();
    }
    cout << "File size is " << b;
    f1.close();
    return 0;
}