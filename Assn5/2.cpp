// Question 2: Practice protected access specifier in inheritance. In the base class declare a variable
// which is protected and access it in the derived class.
#include <iostream>
#include <string>
using namespace std;
// Base class
class BankAccount {
protected:
    // Protected member - can be accessed by derived classes
    double balance;
    string accountNumber;
public:
    // Constructor
    BankAccount(string accNum, double initialBalance) {
        accountNumber = accNum;
        balance = initialBalance;
        cout << "Bank Account created with Account Number: " << accountNumber << endl;
    }
    void displayBalance() {
        cout << "Account Balance: $" << balance << endl;
    }
};
// Derived class
class SavingsAccount : public BankAccount {
private:
    double interestRate;
public:
    // Constructor
    SavingsAccount(string accNum, double initialBalance, double rate) 
        : BankAccount(accNum, initialBalance), interestRate(rate) {
        cout << "Savings Account created" << endl;
    }
    // Accessing protected members from base class
    void addInterest() {
        double interest = balance * interestRate / 100;  // Accessing protected 'balance'
        balance += interest;  // Modifying protected 'balance'
        cout << "Interest added: $" << interest << endl;
        cout << "New Balance: $" << balance << endl;
    }
    void deposit(double amount) {
        balance += amount;  // Accessing and modifying protected 'balance'
        cout << "Deposited: $" << amount << endl;
        cout << "Current Balance: $" << balance << endl;
    }
    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;  // Accessing and modifying protected 'balance'
            cout << "Withdrawn: $" << amount << endl;
            cout << "Remaining Balance: $" << balance << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }
    void displayAccountInfo() {
        cout << "\n--- Savings Account Information ---" << endl;
        cout << "Account Number: " << accountNumber << endl;  // Accessing protected 'accountNumber'
        cout << "Balance: $" << balance << endl;  // Accessing protected 'balance'
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};
int main() {
    // Create a savings account
    SavingsAccount myAccount("SA123456", 1000.0, 5.0);
    cout << "\n--- Initial Account Status ---" << endl;
    myAccount.displayBalance();
    cout << "\n--- Performing Transactions ---" << endl;
    myAccount.deposit(500.0);
    myAccount.withdraw(200.0);
    myAccount.addInterest();
    cout << "\n--- Final Account Status ---" << endl;
    myAccount.displayAccountInfo();
    return 0;
}