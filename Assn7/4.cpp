#include <iostream>
using namespace std;

class Student{
    public:
        virtual void show() = 0;
};

class Engineering : public Student{
    public:
        void show(){
            cout << "Engineering Student" << endl; 
        }
};

class Medicine : public Student{
    public:
        void show(){
            cout << "Medicine Student" << endl; 
        }
};

class Science : public Student{
public:
    void show(){ 
        cout << "Science Student" << endl; 
    }
};

int main(){
    Engineering e;
    Medicine m;
    Science s;

    Student* arr[] = { &e, &m, &s };
    for (Student* p : arr) p->show();

    return 0;
}
