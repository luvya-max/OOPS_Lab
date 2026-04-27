#include <iostream>
#include <string>
using namespace std;

class Book {
    public:
        string title, author, ISBN;
    };

class Library {
    private:
        Book books[100];
        int count = 0;

    public:
        bool addNewBook(string &title, string &author, string &ISBN) {
            if (count >= 100) return false;
            books[count].title = title;
            books[count].author = author;
            books[count].ISBN = ISBN;
            count++;
            return true;
        }

        bool removeBooks(string &ISBN);

        void displayDetails() {
            if (count == 0) {
                cout << "No books in library.\n";
                return;
            }

            cout << "\nLibrary Books:\n";
            for (int i = 0; i < count; i++) {
                cout << books[i].title << " | "
                    << books[i].author << " | "
                    << books[i].ISBN << endl;
            }
        }
};

bool Library::removeBooks(string &ISBN) {
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

int main() {
    Library lib;
    int n;
    cout << "Enter number of books to add: ";
    cin >> n;
    string title, author, ISBN;
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of book " << i + 1 << endl;
        cout << "Title: ";
        cin.ignore(); 
        getline(cin, title);
        cout << "Author: ";
        getline(cin, author);
        cout << "ISBN: ";
        cin >> ISBN;
        lib.addNewBook(title, author, ISBN);
    }
    cout << "\nEnter ISBN to remove: ";
    cin >> ISBN;
    if (lib.removeBooks(ISBN))
        cout << "Book removed successfully.\n";
    else
        cout << "Book not found.\n";
    lib.displayDetails();

    return 0;
}