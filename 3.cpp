#include <iostream>
using namespace std;

template <typename V>
int findmax(V arr[], int size){
    V temp=arr[0];
    for(int i=0;i<size;i++){
        if (arr[i]>temp){
            temp=arr[i];
        }
    }
    return temp;
}
int main(){
    int size = 5;
    float arr[]={5,6.4,31.2,34,5};
    cout << findmax(arr, size);
    return 0;
}