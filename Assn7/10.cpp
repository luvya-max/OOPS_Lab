#include <iostream>
using namespace std;

class Student{
    string name;
    int age;
    public:
        friend istream& operator>>(istream& in, Student& s);
        friend ostream& operator<<(ostream& out, const Student& s);
};

istream& operator>>(istream& in, Student& s){
    cout << "Enter name and age: ";
    in >> s.name >> s.age;
    return in;
}

ostream& operator<<(ostream& out, const Student& s){
    out << "Name: " << s.name << ", Age: " << s.age << endl;
    return out;
}

int main(){
    Student s;
    cin >> s;
    cout << s;
    return 0;
}
