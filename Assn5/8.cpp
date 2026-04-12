// Question 8: Hierarchical Inheritance - Library User System
#include <iostream>
#include <string>
using namespace std;

// Base class: LibraryUser
class LibraryUser {
protected:
    string name;
    int userId;
    string contactNumber;
    string email;
    int booksBorrowed;
    
public:
    // Default constructor
    LibraryUser() {
        name = "Unknown";
        userId = 0;
        contactNumber = "N/A";
        email = "N/A";
        booksBorrowed = 0;
        cout << "LibraryUser default constructor called" << endl;
    }
    
    // Parameterized constructor
    LibraryUser(string n, int id, string contact, string mail) {
        name = n;
        userId = id;
        contactNumber = contact;
        email = mail;
        booksBorrowed = 0;
        cout << "LibraryUser created: " << name << " (ID: " << userId << ")" << endl;
    }
    
    // Display general user information
    void displayUserInfo() {
        cout << "Name: " << name << endl;
        cout << "User ID: " << userId << endl;
        cout << "Contact: " << contactNumber << endl;
        cout << "Email: " << email << endl;
        cout << "Books Borrowed: " << booksBorrowed << endl;
    }
    
    // Borrow book
    void borrowBook() {
        booksBorrowed++;
        cout << name << " borrowed a book. Total books: " << booksBorrowed << endl;
    }
    
    // Return book
    void returnBook() {
        if (booksBorrowed > 0) {
            booksBorrowed--;
            cout << name << " returned a book. Remaining books: " << booksBorrowed << endl;
        } else {
            cout << name << " has no books to return." << endl;
        }
    }
    
    // Getters
    string getName() const { return name; }
    int getUserId() const { return userId; }
    int getBooksBorrowed() const { return booksBorrowed; }
    
    // Virtual destructor
    virtual ~LibraryUser() {
        cout << "LibraryUser destroyed: " << name << endl;
    }
};

// Derived class 1: Student (Hierarchical Inheritance)
class Student : public LibraryUser {
private:
    string gradeLevel;
    string major;
    string enrollmentYear;
    int maxBooksAllowed;
    
public:
    // Constructor
    Student(string n, int id, string contact, string mail, string grade, string maj, string year) 
        : LibraryUser(n, id, contact, mail) {
        gradeLevel = grade;
        major = maj;
        enrollmentYear = year;
        maxBooksAllowed = 5;  // Students can borrow max 5 books
        cout << "Student account created - Grade: " << gradeLevel << endl;
    }
    
    // Override borrow book with student-specific rules
    void borrowBook() {
        if (booksBorrowed < maxBooksAllowed) {
            LibraryUser::borrowBook();
        } else {
            cout << "Cannot borrow more books! Student limit: " << maxBooksAllowed << endl;
        }
    }
    
    // Display student-specific information
    void displayStudentInfo() {
        cout << "\n=== STUDENT INFORMATION ===" << endl;
        displayUserInfo();
        cout << "Grade Level: " << gradeLevel << endl;
        cout << "Major: " << major << endl;
        cout << "Enrollment Year: " << enrollmentYear << endl;
        cout << "Max Books Allowed: " << maxBooksAllowed << endl;
    }
    
    // Check if student can borrow more books
    bool canBorrowMore() {
        return booksBorrowed < maxBooksAllowed;
    }
    
    // Getters
    string getGradeLevel() const { return gradeLevel; }
    string getMajor() const { return major; }
    
    // Destructor
    ~Student() {
        cout << "Student account closed: " << name << " (" << gradeLevel << ")" << endl;
    }
};

// Derived class 2: Teacher (Hierarchical Inheritance)
class Teacher : public LibraryUser {
private:
    string department;
    string designation;
    int yearsOfExperience;
    int maxBooksAllowed;
    bool hasResearchAccess;
    
public:
    // Constructor
    Teacher(string n, int id, string contact, string mail, string dept, string desig, int exp) 
        : LibraryUser(n, id, contact, mail) {
        department = dept;
        designation = desig;
        yearsOfExperience = exp;
        maxBooksAllowed = 10;  // Teachers can borrow max 10 books
        hasResearchAccess = true;
        cout << "Teacher account created - Department: " << department << endl;
    }
    
    // Override borrow book with teacher-specific rules
    void borrowBook() {
        if (booksBorrowed < maxBooksAllowed) {
            LibraryUser::borrowBook();
        } else {
            cout << "Cannot borrow more books! Teacher limit: " << maxBooksAllowed << endl;
        }
    }
    
    // Display teacher-specific information
    void displayTeacherInfo() {
        cout << "\n=== TEACHER INFORMATION ===" << endl;
        displayUserInfo();
        cout << "Department: " << department << endl;
        cout << "Designation: " << designation << endl;
        cout << "Years of Experience: " << yearsOfExperience << endl;
        cout << "Max Books Allowed: " << maxBooksAllowed << endl;
        cout << "Research Access: " << (hasResearchAccess ? "Yes" : "No") << endl;
    }
    
    // Request research material
    void requestResearchMaterial(string materialName) {
        if (hasResearchAccess) {
            cout << name << " requested research material: " << materialName << endl;
            cout << "Request approved." << endl;
        } else {
            cout << "No research access available." << endl;
        }
    }
    
    // Check if teacher can borrow more books
    bool canBorrowMore() {
        return booksBorrowed < maxBooksAllowed;
    }
    
    // Getters
    string getDepartment() const { return department; }
    string getDesignation() const { return designation; }
    
    // Destructor
    ~Teacher() {
        cout << "Teacher account closed: " << name << " (" << department << ")" << endl;
    }
};

// Library management function
void displayLibraryStats(Student students[], int numStudents, Teacher teachers[], int numTeachers) {
    cout << "\n========================================" << endl;
    cout << "      LIBRARY STATISTICS" << endl;
    cout << "========================================" << endl;
    
    int totalStudentBooks = 0;
    int totalTeacherBooks = 0;
    
    for (int i = 0; i < numStudents; i++) {
        totalStudentBooks += students[i].getBooksBorrowed();
    }
    
    for (int i = 0; i < numTeachers; i++) {
        totalTeacherBooks += teachers[i].getBooksBorrowed();
    }
    
    cout << "Total Students: " << numStudents << endl;
    cout << "Total Teachers: " << numTeachers << endl;
    cout << "Books borrowed by Students: " << totalStudentBooks << endl;
    cout << "Books borrowed by Teachers: " << totalTeacherBooks << endl;
    cout << "Total Books in Circulation: " << (totalStudentBooks + totalTeacherBooks) << endl;
    cout << "========================================" << endl;
}

int main() {
    cout << "===== LIBRARY USER MANAGEMENT SYSTEM =====" << endl;
    cout << "\n--- Creating Student Accounts ---" << endl;
    
    Student student1("Alice Johnson", 1001, "555-0101", "alice@university.edu", 
                    "Sophomore", "Computer Science", "2023");
    
    Student student2("Bob Smith", 1002, "555-0102", "bob@university.edu", 
                    "Senior", "Mathematics", "2021");
    
    Student student3("Carol White", 1003, "555-0103", "carol@university.edu", 
                    "Freshman", "Physics", "2024");
    
    cout << "\n--- Creating Teacher Accounts ---" << endl;
    
    Teacher teacher1("Dr. David Brown", 2001, "555-0201", "david.brown@university.edu", 
                    "Computer Science", "Professor", 15);
    
    Teacher teacher2("Dr. Emma Davis", 2002, "555-0202", "emma.davis@university.edu", 
                    "Mathematics", "Associate Professor", 8);
    
    // Display information
    student1.displayStudentInfo();
    student2.displayStudentInfo();
    teacher1.displayTeacherInfo();
    
    // Simulate borrowing books
    cout << "\n--- Borrowing Books ---" << endl;
    student1.borrowBook();
    student1.borrowBook();
    student1.borrowBook();
    
    student2.borrowBook();
    student2.borrowBook();
    
    teacher1.borrowBook();
    teacher1.borrowBook();
    teacher1.borrowBook();
    teacher1.borrowBook();
    
    // Test borrowing limits
    cout << "\n--- Testing Borrowing Limits ---" << endl;
    for (int i = 0; i < 5; i++) {
        student1.borrowBook();  // Will hit limit
    }
    
    // Return books
    cout << "\n--- Returning Books ---" << endl;
    student1.returnBook();
    student1.returnBook();
    
    // Teacher requesting research material
    cout << "\n--- Research Material Request ---" << endl;
    teacher1.requestResearchMaterial("Advanced Algorithms Journal");
    
    // Display updated information
    student1.displayStudentInfo();
    teacher1.displayTeacherInfo();
    
    // Display library statistics
    Student studentArray[] = {student1, student2, student3};
    Teacher teacherArray[] = {teacher1, teacher2};
    displayLibraryStats(studentArray, 3, teacherArray, 2);
    
    cout << "\n===== HIERARCHICAL INHERITANCE BENEFITS =====" << endl;
    cout << "1. LibraryUser is the common BASE class" << endl;
    cout << "2. Student and Teacher are DERIVED classes from LibraryUser" << endl;
    cout << "3. Both derived classes inherit common properties (name, ID, contact)" << endl;
    cout << "4. Each derived class adds its own specific attributes and methods" << endl;
    cout << "5. Code reusability - common functionality defined once in base class" << endl;
    cout << "6. Easy to add new user types (e.g., Staff) by inheriting from LibraryUser" << endl;
    
    cout << "\n--- Program Ending ---" << endl;
    return 0;
}