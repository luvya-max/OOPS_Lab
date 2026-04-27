#include <iostream>
#include <fstream>
using namespace std;

int main(){
    char ch;
    ofstream fout("data.txt");
    fout << "This is a file that contains multiple lines\nHere is line 2 of this file\nFile ends here.";
    fout.close();
    ifstream fin("data.txt");
    fin.seekg(9,ios::cur);
    cout << fin.tellg() << endl;
    while(fin.get(ch)){
        cout<<ch;
    }
    return 0;
}