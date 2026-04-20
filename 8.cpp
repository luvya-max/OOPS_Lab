#include<iostream>
using namespace std;
template<class T1, class T2>
class Pair{
    T1 first;
    T2 second;
    public:
        void setValues(T1 a, T2 b){
            first = a;
            second = b;
        }

        void display(){
            cout << "First value  = " << first << endl;
            cout << "Second value = " << second << endl;
        }
};

int main(){
    Pair<string, int> p1;
    p1.setValues("Age", 21);
    cout << "--- Pair 1 ---" << endl;
    p1.display();

    Pair<int, int> p2;
    p2.setValues(10, 20);
    cout << "--- Pair 2 ---" << endl;
    p2.display();

    Pair<string, float> p3;
    p3.setValues("Marks", 87.5);
    cout << "--- Pair 3 ---" << endl;
    p3.display();

    return 0;
}