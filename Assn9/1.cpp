#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream f1("NUM.txt");
    for(int i=1; i<=200; i++){
        f1 << i << ' ';
    }
    return 0;
}