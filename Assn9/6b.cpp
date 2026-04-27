#include <iostream>
#include <fstream>
using namespace std;

int main(){
    char a;
    fstream f1("AZ.txt");
    f1.seekp(4, ios::beg);
    f1 << 5;
    f1.close();
    return 0;
}