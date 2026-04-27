#include <iostream>
using namespace std;

template <typename V>
int linearsearch(V arr[], int size, V element){
    for(int i=0;i<size;i++){
        if(arr[i]==element){
            return i+1;
        }
    }
}
int main(){
    int size = 5;
    float element=5, arr[]={9.4,6,31,34,5};
    cout << linearsearch(arr, size, element) << "th element";
    return 0;
}