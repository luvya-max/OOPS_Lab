#include <iostream>
#include <fstream>
using namespace std;

int main(){
    string str;
    int count;
    char ch;
    cout << "Enter string ";
    cin >> str;
    ofstream f1("String.txt");
    f1 << str;
    f1.close();
    ifstream f2("String.txt");
    while(f2.get(ch)){
        cout << ch;
        count++;
    }
    f2.close();
    return 0;
}