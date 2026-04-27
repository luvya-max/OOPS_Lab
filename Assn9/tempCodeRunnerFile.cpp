#include <iostream>
#include <fstream>
using namespace std;

int main(){
  ofstream fout("Helloworld.txt");
  char str[11] = "HelloWorld";
  for(int i=0; i<=9; i++){
    fout << str[i];
    cout << fout.tellp();
  }
  fout.close();
  fstream fio("Helloworld.txt");
  fio.seekp(5);
  fio << "C++";

  return 0;
}