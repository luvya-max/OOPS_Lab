#include <iostream>
#include <fstream>
using namespace std;

class Student {
    int id;
    string name;
    float marks;

public:
    void input(){
        cout<<"Enter ID : ";
        cin>>id;
        cout<<"Enter Name : ";
        cin>>name;
        cout<<"Enter Marks : ";
        cin>>marks;
    }

    void display(){
        cout<< "\nID: " <<id;
        cout<< "\nName: " <<name;
        cout<< "\nMarks: " <<marks<< endl;
    }

    void writeToFile(ofstream &fout){
        fout <<id<< " " <<name<< " " <<marks<< endl;
    }

    void readFromFile(ifstream &fin) {
        fin>> id >>name>> marks;
    }
}s;

int main() {
    ofstream fout("student.txt");
    s.input();
    s.writeToFile(fout);
    fout.close();
    ifstream fin("student.txt");

    Student s2;
    s2.readFromFile(fin);
    fin.close();


    cout<<"Data is : ";
    s2.display();

    return 0;
}