#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string title, author, ISBN;

    // Default constructor
    Book() {
        title = "NA";
        author = "NA";
        ISBN = "0";
    }

    // Parameterized constructor
    Book(string title, string author, string ISBN) {
        this->title = title;
        this->author = author;
        this->ISBN = ISBN;
    }

    // Copy constructor
    Book(const Book &b) {
        this->title = b.title;
        this->author = b.author;
        this->ISBN = b.ISBN;
    }
};

class Library {
private:
    Book books[100];
    int count = 0;

public:
    bool addNewBook(string &title, string &author, string &ISBN) {
        if (count >= 100) return false;

        books[count] = Book(title, author, ISBN);
        count++;
        return true;
    }

    bool removeBooks(string &ISBN) {
        for (int i = 0; i < count; i++) {
            if (books[i].ISBN == ISBN) {
                for (int j = i; j < count - 1; j++) {
                    books[j] = books[j + 1];
                }
                count--;
                return true;
            }
        }
        return false;
    }

    void displayDetails() {
        for (int i = 0; i < count; i++) {
            cout << books[i].title << " | "
                 << books[i].author << " | "
                 << books[i].ISBN << endl;
        }
    }
};

int main() {
    Library lib;

    string t="A", a="AA", i="1";
    lib.addNewBook(t,a,i);

    t="B"; a="BB"; i="2";
    lib.addNewBook(t,a,i);

    string rem = "1";
    lib.removeBooks(rem);

    lib.displayDetails();

    return 0;
}