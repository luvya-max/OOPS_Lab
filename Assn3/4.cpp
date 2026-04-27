#include <iostream>
using namespace std;

class BankAccount {
    private:
        string accountHolder;
        int accountNumber;
        double balance;
        
    public:
        BankAccount(string name, int accNo, double bal) {
            accountHolder = name;
            accountNumber = accNo;
            balance = bal;
        }
        
        void display() {
            cout << "\nAccount Holder: " << accountHolder << endl;
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: $" << balance << endl;
        }
    friend class BankManager;
};

class BankManager {
    private:
        string managerName;
        
    public:
        BankManager(string name) {
            managerName = name;
        }
        
        void checkBalance(BankAccount &acc) {
            cout << "\n--- Manager Checking Account ---" << endl;
            cout << "Manager: " << managerName << endl;
            cout << "Account Holder: " << acc.accountHolder << endl;
            cout << "Current Balance: $" << acc.balance << endl;
        }
        
        void deposit(BankAccount &acc, double amount) {
            if (amount > 0) {
                acc.balance += amount;  
                cout << "\nDeposited: $" << amount << endl;
                cout << "New Balance: $" << acc.balance << endl;
            }
        }
        void withdraw(BankAccount &acc, double amount) {
            if (amount > 0 && amount <= acc.balance) {
                acc.balance -= amount;
                cout << "\nWithdrawn: $" << amount << endl;
                cout << "New Balance: $" << acc.balance << endl;
            } else {
                cout << "\nInsufficient balance!" << endl;
            }
        }

        void transferMoney(BankAccount &from, BankAccount &to, double amount) {
            if (amount > 0 && amount <= from.balance) {
                from.balance -= amount;
                to.balance += amount;
                cout << "\n--- Transfer Successful ---" << endl;
                cout << "From: " << from.accountHolder << endl;
                cout << "To: " << to.accountHolder << endl;
                cout << "Amount: $" << amount << endl;
            } else {
                cout << "\nTransfer failed!" << endl;
            }
        }
};

int main() {
    cout << "=== FRIEND CLASS DEMONSTRATION ===" << endl;
    
    BankAccount acc1("Rahul Kumar", 1001, 5000.0);
    BankAccount acc2("Priya Sharma", 1002, 3000.0);
    
    cout << "\nInitial Account Details:" << endl;
    acc1.display();
    acc2.display();

    BankManager manager("Mr. Anil Verma");   
    manager.checkBalance(acc1);
    manager.deposit(acc1, 1000.0);
    manager.withdraw(acc1, 500.0);
    manager.transferMoney(acc1, acc2, 2000.0);
    cout << "\nFinal Account Details:" << endl;
    acc1.display();
    acc2.display();
    
    return 0;
}