#include <iostream>
using namespace std;

template <typename V>
void bubblesort(V arr, int size){
    float temp;
    for(int i=0;i<=size-1;i++){
        for(int j=i+1;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }  
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
}
int main(){
    int size = 5;
    float arr[]={9.4,6,31,34,5};
    bubblesort(arr, size);
    return 0;
}