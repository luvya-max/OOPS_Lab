#include <iostream>
using namespace std;

class Rectangle{
    void getdata();   
    float width;
    float height;   
    public:  
        void calculatearea();
}r;

void Rectangle::getdata(){
    cout << "Enter the width ";
    cin >> width;
    cout << "Enter the height ";
    cin >> height;
}

void Rectangle::calculatearea(){
    getdata();
    cout << "Area is " << width*height;
}

int main(){
    r.calculatearea();    
    return 0;
}