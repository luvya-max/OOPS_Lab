#include <iostream>
#include <fstream>
using namespace std;

int main(){
    char ch;
    ifstream f1("Original.txt");
    ofstream f2("Copy.txt");
    while(f1.get(ch)){
        f2 << ch;
    }
    return 0;
}