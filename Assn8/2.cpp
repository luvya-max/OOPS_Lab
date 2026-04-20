#include <iostream>
using namespace std;

template <typename V>
int findmin(V arr[], int size){
    V temp=arr[0];
    for(int i=0;i<size;i++){
        if (arr[i]<temp){
            temp=arr[i];
        }
    }
    return temp;
}
int main(){
    int size = 5;
    int arr[]={9,6,31,34,5};
    cout << findmin(arr, size);
    return 0;
}