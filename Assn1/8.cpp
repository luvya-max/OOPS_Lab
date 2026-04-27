#include <iostream>
using namespace std;

int main(){
   int a;
   cout << "Enter the number of days the book is late ";
   cin >> a;
   if (a<6){
    cout << "Fine is 50 paise";
   }
   else if(a<11){
    cout << "Fine is 1 rupee";
   }
   else if (a<=30) {
    cout << "Fine is 5 rupees";
   }
   else {
    cout << "Membership is cancelled";
   }
   return 0;
}