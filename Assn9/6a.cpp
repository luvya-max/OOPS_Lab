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
    f1.close();
    ifstream f2("AZ.txt");
    f2.seekg(9);
    f2.get(a);
    cout << a;
    f2.close();
    return 0;
}