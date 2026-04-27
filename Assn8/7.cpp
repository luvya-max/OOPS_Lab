#include<iostream>
using namespace std;
template<class T>
class Queue{
    T arr[50];
    int front, rear;
public:
    Queue(){
        front = -1;
        rear = -1;
    }
    void enqueue(T val){
        if(rear >= 49){
            cout << "Queue is full!" << endl;
        }
        else{
            if(front == -1){
                front = 0;
            }
            rear++;
            arr[rear] = val;
            cout << val << " added to queue." << endl;
        }
    }
    void dequeue(){
        if(front == -1 || front > rear){
            cout << "Queue is empty!" << endl;
        }
        else{
            cout << arr[front] << " removed from queue." << endl;
            front++;
        }
    }
    void display(){
        if(front == -1 || front > rear){
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for(int i = front; i <= rear; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}