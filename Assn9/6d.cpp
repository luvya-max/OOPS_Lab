#include <iostream>
#include <fstream>
using namespace std;

int main(){
    char a;
    ifstream f1("AZ.txt");
    f1.seekg(-1,ios::end);
    f1.get(a);
    cout << a;
    f1.close();
    return 0;
}