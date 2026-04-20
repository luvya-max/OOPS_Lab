#include<iostream>
using namespace std;
template<class T>
class Stack{
    T arr[50];
    int top;
public:
    Stack(){
        top = -1; 
    }
    void push(T val){
        if(top >= 49){
            cout << "Stack is full!" << endl;
        }
        else{
            top++;
            arr[top] = val;
            cout << val << " pushed to stack." << endl;
        }
    }
    void pop(){
        if(top == -1){
            cout << "Stack is empty!" << endl;
        }
        else{
            cout << arr[top] << " popped from stack." << endl;
            top--;
        }
    }
    void display(){
        if(top == -1){
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for(int i = top; i >= 0; i--){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.display();
    return 0;
}