#include <iostream>
using namespace std;

struct students{
    char name[50];
    int rollno;
    char degree[50];
    char hostel[50];
    float cgpa;
    void addDetails();
    void updateDetails();
    void displaydetails();
    void updatecgpa();
    void updateHostel();
}s;

void students::displaydetails(){
    cout << endl;
    cout << "Name is : " << name << endl;
    cout << "Roll no is : " << rollno << endl;
    cout << "Degree is : " << degree << endl;
    cout << "Hostel is : " << hostel << endl;
    cout << "CGPA is : " << cgpa << endl;    
}

void students::updatecgpa(){
    cout << "Enter your CGPA ";
    cin >> cgpa;
}

void students::updateHostel(){
    cout << "Enter your hostel ";
    cin >> hostel;
}

void students::updateDetails(){
    updateHostel();
    updatecgpa();   
    displaydetails(); 
}

void students::addDetails(){
    cout << "Enter your name ";
    cin >> name;
    cout << "Enter your rollno ";
    cin >> rollno;
    cout << "Enter your degree ";
    cin >> degree;
    cout << "Enter your CGPA ";
    cin >> cgpa;
    cout << "Enter your hostel ";
    cin >> hostel;
    displaydetails();
}

int main(){
    s.addDetails();
    s.updateDetails();
    return 0;
}