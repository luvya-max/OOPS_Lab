#include <iostream>
using namespace std;

int main(){
   int a,p=0;
   cout << "Enter the number ";
   cin >> a;
   for(int i=2;i<=a-1;i++){
      if (a==2){
        cout << "Prime";
      }  
      if(a%i==0){
        cout<<"Not prime";
        p=1;
        break;
      }
   }
   if (p==0){
      cout << "Prime";
   }
}