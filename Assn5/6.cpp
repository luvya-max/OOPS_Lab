// Question 6: Single Inheritance - Book and Textbook
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Base class: Book
class Book {
protected:
    string title;
    string author;
    double price;
    
public:
    // Default constructor
    Book() {
        title = "Unknown";
        author = "Unknown";
        price = 0.0;
    }
    
    // Parameterized constructor
    Book(string t, string a, double p) : title(t), author(a), price(p) {
        cout << "Book object created: " << title << endl;
    }
    
    // Setter methods
    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setPrice(double p) { price = p; }
    
    // Getter methods
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    double getPrice() const { return price; }
    
    // Display book information
    void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << fixed << setprecision(2);
        cout << "Price: $" << price << endl;
    }
    
    // Virtual destructor (good practice for base classes)
    virtual ~Book() {
        cout << "Book object destroyed: " << title << endl;
    }
};

// Derived class: Textbook (Single Inheritance from Book)
class Textbook : public Book {
private:
    string subject;
    
public:
    // Default constructor
    Textbook() : Book() {
        subject = "General";
    }
    
    // Parameterized constructor
    Textbook(string t, string a, double p, string s) : Book(t, a, p), subject(s) {
        cout << "Textbook object created with subject: " << subject << endl;
    }
    
    // Setter method for subject
    void setSubject(string s) { subject = s; }
    
    // Getter method for subject
    string getSubject() const { return subject; }
    
    // Display textbook information (overriding and extending base class method)
    void displayInfo() {
        cout << "\n=== Textbook Information ===" << endl;
        Book::displayInfo();  // Call base class method
        cout << "Subject: " << subject << endl;
    }
    
    // Additional method specific to Textbook
    void displayCategory() {
        cout << "This is an educational textbook for " << subject << endl;
    }
    
    // Destructor
    ~Textbook() {
        cout << "Textbook object destroyed: " << subject << endl;
    }
};

int main() {
    cout << "===== DEMONSTRATING SINGLE INHERITANCE =====" << endl;
    cout << "\n--- Creating a General Book ---" << endl;
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", 12.99);
    cout << "\n--- Displaying General Book Information ---" << endl;
    book1.displayInfo();
    
    cout << "\n\n--- Creating Textbooks ---" << endl;
    Textbook textbook1("Introduction to C++", "Bjarne Stroustrup", 89.99, "Computer Science");
    Textbook textbook2("Calculus", "James Stewart", 149.99, "Mathematics");
    Textbook textbook3("Physics Fundamentals", "David Halliday", 119.99, "Physics");
    
    cout << "\n--- Displaying Textbook Information ---" << endl;
    textbook1.displayInfo();
    textbook1.displayCategory();
    
    textbook2.displayInfo();
    textbook2.displayCategory();
    
    textbook3.displayInfo();
    textbook3.displayCategory();
    
    // Demonstrating access to base class methods
    cout << "\n--- Using Base Class Methods on Derived Object ---" << endl;
    cout << "Textbook 1 Author: " << textbook1.getAuthor() << endl;
    cout << "Textbook 1 Price: $" << textbook1.getPrice() << endl;
    
    // Demonstrating setter methods
    cout << "\n--- Modifying Textbook Information ---" << endl;
    textbook1.setPrice(79.99);
    textbook1.setSubject("Advanced C++ Programming");
    cout << "Updated information:" << endl;
    textbook1.displayInfo();
    
    cout << "\n--- Managing Book Inventory ---" << endl;
    // Array of books (polymorphism example)
    Book* inventory[4];
    inventory[0] = &book1;
    inventory[1] = &textbook1;
    inventory[2] = &textbook2;
    inventory[3] = &textbook3;
    
    double totalValue = 0;
    for (int i = 0; i < 4; i++) {
        totalValue += inventory[i]->getPrice();
    }
    
    cout << fixed << setprecision(2);
    cout << "Total Inventory Value: $" << totalValue << endl;
    
    cout << "\n===== SINGLE INHERITANCE BENEFITS =====" << endl;
    cout << "1. Textbook inherits all properties and methods from Book" << endl;
    cout << "2. Code reusability - no need to rewrite title, author, price" << endl;
    cout << "3. Easy to maintain - changes in Book automatically apply to Textbook" << endl;
    cout << "4. Extensibility - Textbook adds 'subject' attribute specific to academic books" << endl;
    
    cout << "\n--- Program Ending - Destructors will be called ---" << endl;
    return 0;
}