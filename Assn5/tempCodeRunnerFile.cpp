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