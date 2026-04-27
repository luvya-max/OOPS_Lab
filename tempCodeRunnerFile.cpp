#include <iostream>
#include <fstream>
using namespace std;

int main(){
    char a='A';
    ofstream f1("AZ.txt");
    while (a<='Z'){
        f1 << a;
        a++;
    }
    f1.seekp(4);
    f1 << 5;
    f1.close();
    return 0;
}