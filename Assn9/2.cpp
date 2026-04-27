#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream f1("NOTES.txt");
    int count=0; char ch;
    while(f1.get(ch)){
        if((ch>='a' && ch<='z')|| ch>='A' && ch<='Z'){
            count++;
        }
    }
    cout << count;

    return 0;
}