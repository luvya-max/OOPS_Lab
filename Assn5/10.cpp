// Question 10: Hybrid Inheritance - Academic Institution System
#include <iostream>
#include <string>
using namespace std;

// Base class: Person (Top of hierarchy)
class Person {
protected:
    string name;
    string address;
    int age;
    
public:
    // Constructor
    Person() {
        name = "Unknown";
        address = "Unknown";
        age = 0;
        cout << "Person default constructor called" << endl;
    }
    
    Person(string n, string addr, int a) {
        name = n;
        address = addr;
        age = a;
        cout << "Person created: " << name << endl;
    }
    
    // Display person information
    void displayPersonInfo() {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Age: " << age << endl;
    }
    
    // Getters
    string getName() const { return name; }
    string getAddress() const { return address; }
    int getAge() const { return age; }
    
    // Virtual destructor
    virtual ~Person() {
        cout << "Person destroyed: " << name << endl;
    }
};

// Derived class 1: Staff (inherits from Person)
class Staff : virtual public Person {  // Virtual inheritance to avoid diamond problem
protected:
    int employeeId;
    string department;
    double salary;
    
public:
    // Constructor
    Staff() : Person() {
        employeeId = 0;
        department = "Not Assigned";
        salary = 0.0;
        cout << "Staff default constructor called" << endl;
    }
    
    Staff(string n, string addr, int a, int empId, string dept, double sal) 
        : Person(n, addr, a) {
        employeeId = empId;
        department = dept;
        salary = sal;
        cout << "Staff member created - Employee ID: " << employeeId << endl;
    }
    
    // Display staff information
    void displayStaffInfo() {
        cout << "\n=== STAFF INFORMATION ===" << endl;
        displayPersonInfo();
        cout << "Employee ID: " << employeeId << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: $" << salary << endl;
    }
    
    // Staff specific methods
    void conductMeeting(string topic) {
        cout << name << " is conducting a meeting on: " << topic << endl;
    }
    
    void updateSalary(double newSalary) {
        salary = newSalary;
        cout << name << "'s salary updated to: $" << salary << endl;
    }
    
    // Getters
    int getEmployeeId() const { return employeeId; }
    string getDepartment() const { return department; }
    double getSalary() const { return salary; }
    
    // Destructor
    ~Staff() {
        cout << "Staff member destroyed - ID: " << employeeId << endl;
    }
};

// Derived class 2: Student (inherits from Person)
class Student : virtual public Person {  // Virtual inheritance to avoid diamond problem
protected:
    int studentId;
    string grade;
    double gpa;
    
public:
    // Constructor
    Student() : Person() {
        studentId = 0;
        grade = "Freshman";
        gpa = 0.0;
        cout << "Student default constructor called" << endl;
    }
    
    Student(string n, string addr, int a, int studId, string gr, double g) 
        : Person(n, addr, a) {
        studentId = studId;
        grade = gr;
        gpa = g;
        cout << "Student created - Student ID: " << studentId << endl;
    }
    
    // Display student information
    void displayStudentInfo() {
        cout << "\n=== STUDENT INFORMATION ===" << endl;
        displayPersonInfo();
        cout << "Student ID: " << studentId << endl;
        cout << "Grade: " << grade << endl;
        cout << "GPA: " << gpa << endl;
    }
    
    // Student specific methods
    void attendClass(string className) {
        cout << name << " is attending class: " << className << endl;
    }
    
    void updateGPA(double newGPA) {
        gpa = newGPA;
        cout << name << "'s GPA updated to: " << gpa << endl;
    }
    
    void submitAssignment(string assignmentName) {
        cout << name << " submitted assignment: " << assignmentName << endl;
    }
    
    // Getters
    int getStudentId() const { return studentId; }
    string getGrade() const { return grade; }
    double getGPA() const { return gpa; }
    
    // Destructor
    ~Student() {
        cout << "Student destroyed - ID: " << studentId << endl;
    }
};

// Hybrid class: TeachingAssistant (inherits from both Staff and Student)
// This demonstrates HYBRID INHERITANCE (Multiple + Hierarchical)
class TeachingAssistant : public Staff, public Student {
private:
    string courseAssisting;
    int hoursPerWeek;
    double taStipend;
    
public:
    // Constructor
    TeachingAssistant() : Person(), Staff(), Student() {
        courseAssisting = "Not Assigned";
        hoursPerWeek = 0;
        taStipend = 0.0;
        cout << "TeachingAssistant default constructor called" << endl;
    }
    
    // Parameterized constructor - Note: Person constructor called once due to virtual inheritance
    TeachingAssistant(string n, string addr, int a, int empId, string dept, double sal,
                     int studId, string gr, double g, string course, int hours, double stipend)
        : Person(n, addr, a),  // Called once due to virtual inheritance
          Staff(n, addr, a, empId, dept, sal),
          Student(n, addr, a, studId, gr, g) {
        courseAssisting = course;
        hoursPerWeek = hours;
        taStipend = stipend;
        cout << "Teaching Assistant created - Course: " << courseAssisting << endl;
    }
    
    // Display complete TA information
    void displayTAInfo() {
        cout << "\n========================================" << endl;
        cout << "   TEACHING ASSISTANT INFORMATION" << endl;
        cout << "========================================" << endl;
        
        // Display person info (only once, thanks to virtual inheritance)
        displayPersonInfo();
        
        cout << "\n--- Employment Details ---" << endl;
        cout << "Employee ID: " << employeeId << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: $" << salary << endl;
        
        cout << "\n--- Academic Details ---" << endl;
        cout << "Student ID: " << studentId << endl;
        cout << "Grade: " << grade << endl;
        cout << "GPA: " << gpa << endl;
        
        cout << "\n--- TA Specific Details ---" << endl;
        cout << "Course Assisting: " << courseAssisting << endl;
        cout << "Hours Per Week: " << hoursPerWeek << endl;
        cout << "TA Stipend: $" << taStipend << endl;
        cout << "Total Income: $" << (salary + taStipend) << endl;
        cout << "========================================" << endl;
    }
    
    // TA specific methods
    void gradeAssignments(int numAssignments) {
        cout << name << " is grading " << numAssignments << " assignments for " 
             << courseAssisting << endl;
    }
    
    void holdOfficeHours(int hours) {
        cout << name << " is holding office hours for " << hours << " hours" << endl;
    }
    
    void assistInLab(string labName) {
        cout << name << " is assisting in lab: " << labName << endl;
    }
    
    // Can use methods from both Staff and Student
    void performDuties() {
        cout << "\n--- " << name << "'s Daily Activities as TA ---" << endl;
        attendClass(courseAssisting);  // From Student
        conductMeeting("TA Meeting");  // From Staff
        gradeAssignments(15);
        holdOfficeHours(2);
        submitAssignment("Research Paper");  // Still a student!
    }
    
    // Calculate total workload
    int getTotalWorkload() {
        return hoursPerWeek + 15;  // TA hours + average study hours
    }
    
    // Destructor
    ~TeachingAssistant() {
        cout << "Teaching Assistant destroyed: " << courseAssisting << endl;
    }
};

int main() {
    cout << "===== ACADEMIC INSTITUTION MANAGEMENT SYSTEM =====" << endl;
    cout << "\n--- HYBRID INHERITANCE DEMONSTRATION ---" << endl;
    
    // Create a regular Staff member
    cout << "\n--- Creating Staff Member ---" << endl;
    Staff staff1("Dr. Emily Johnson", "123 University Ave", 45, 5001, "Computer Science", 85000);
    staff1.displayStaffInfo();
    staff1.conductMeeting("Curriculum Planning");
    
    // Create a regular Student
    cout << "\n--- Creating Student ---" << endl;
    Student student1("Michael Brown", "456 Campus Dr", 20, 2001, "Junior", 3.7);
    student1.displayStudentInfo();
    student1.attendClass("Data Structures");
    student1.submitAssignment("Project Report");
    
    // Create a Teaching Assistant (HYBRID INHERITANCE)
    cout << "\n--- Creating Teaching Assistant (Hybrid Inheritance) ---" << endl;
    TeachingAssistant ta1("Sarah Williams", "789 College Blvd", 24, 
                         6001, "Computer Science", 25000,    // Staff attributes
                         3001, "Graduate", 3.9,               // Student attributes
                         "Introduction to Programming", 20, 15000);  // TA attributes
    
    ta1.displayTAInfo();
    
    // Demonstrate TA performing various duties
    ta1.performDuties();
    
    cout << "\n--- TA Specific Activities ---" << endl;
    ta1.gradeAssignments(25);
    ta1.holdOfficeHours(3);
    ta1.assistInLab("Programming Lab");
    
    // Using inherited methods
    cout << "\n--- Using Inherited Methods ---" << endl;
    ta1.updateGPA(4.0);  // From Student
    ta1.updateSalary(27000);  // From Staff
    
    // Display updated info
    ta1.displayTAInfo();
    
    cout << "\n--- Workload Analysis ---" << endl;
    cout << "Total workload hours per week: " << ta1.getTotalWorkload() << endl;
    
    // Creating another TA
    cout << "\n--- Creating Another Teaching Assistant ---" << endl;
    TeachingAssistant ta2("James Davis", "321 Academic Way", 23,
                         6002, "Mathematics", 24000,
                         3002, "Graduate", 3.8,
                         "Calculus II", 18, 14000);
    
    ta2.displayTAInfo();
    
    cout << "\n===== HYBRID INHERITANCE STRUCTURE =====" << endl;
    cout << "                  Person" << endl;
    cout << "                 /      \\" << endl;
    cout << "                /        \\" << endl;
    cout << "             Staff      Student" << endl;
    cout << "                \\        /" << endl;
    cout << "                 \\      /" << endl;
    cout << "              TeachingAssistant" << endl;
    
    cout << "\n===== KEY POINTS =====" << endl;
    cout << "1. Hybrid Inheritance combines Multiple and Hierarchical inheritance" << endl;
    cout << "2. TeachingAssistant inherits from BOTH Staff and Student" << endl;
    cout << "3. Staff and Student both inherit from Person" << endl;
    cout << "4. VIRTUAL inheritance prevents the diamond problem" << endl;
    cout << "5. Without virtual inheritance, TA would have TWO copies of Person" << endl;
    cout << "6. Virtual inheritance ensures only ONE copy of Person exists" << endl;
    cout << "7. TA has access to all methods from Person, Staff, and Student" << endl;
    
    cout << "\n===== REAL-WORLD BENEFITS =====" << endl;
    cout << "1. Models complex relationships (TA is both employee and student)" << endl;
    cout << "2. Avoids code duplication" << endl;
    cout << "3. Maintains consistency (single person identity)" << endl;
    cout << "4. Flexible and extensible design" << endl;
    
    cout << "\n--- Program Ending ---" << endl;
    return 0;
}

/*
IMPORTANT NOTE ON DIAMOND PROBLEM:
Without 'virtual' inheritance, TeachingAssistant would have:
- One 'name', 'address', 'age' from Staff's Person
- Another 'name', 'address', 'age' from Student's Person
This creates ambiguity!

With 'virtual' inheritance:
- Only ONE set of 'name', 'address', 'age' exists
- Both Staff and Student share the same Person base
- No ambiguity, no duplication
*/