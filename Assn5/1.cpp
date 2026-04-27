#include <iostream>
#include <string>
using namespace std;
class Animal {
    protected:
        string name;
        int age;
    public:
        Animal(string n, int a) : name(n), age(a) {
            cout << "Animal constructor called" << endl;
        }
        void displayInfo() {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << " years" << endl;
        }
        void makeSound() {
            cout << "Some generic animal sound" << endl;
        }
};
class Dog : public Animal {
    private:
        string breed;
    public:

        Dog(string n, int a, string b) : Animal(n, a), breed(b) {
            cout << "Dog constructor called" << endl;
        }
        void makeSound() {
            cout << name << " says: Woof! Woof!" << endl;
        }
        void displayDogInfo() {
            displayInfo();
            cout << "Breed: " << breed << endl;
        }
};
int main() {
    cout << "=== Creating Base Class Object ===" << endl;
    Animal animal1("Generic Animal", 5);
    animal1.displayInfo();
    animal1.makeSound();
    cout << "\n=== Creating Derived Class Object ===" << endl;
    Dog dog1("Buddy", 3, "Golden Retriever");
    dog1.displayDogInfo();
    dog1.makeSound();
    return 0;
}