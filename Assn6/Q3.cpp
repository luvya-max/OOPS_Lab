#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    const long accountNumber;
    long transactionID;
    string transactionType;
    double balance;

public:
    Account(long accNo, double bal) : accountNumber(accNo) {
        balance = bal;
        transactionID = 0;
    }

    long depositAmount(const long &to, const long &from, const double &amount) {
        if (to == accountNumber) {
            balance += amount;
            transactionID++;
            transactionType = "Credit";
            return transactionID;
        }
        return -1;
    }

    long creditAmount(const long &to, const long &from, const double &amount) {
        if (from == accountNumber) {
            balance -= amount;
            transactionID++;
            transactionType = "Debit";
            return transactionID;
        }
        return -1;
    }

    void displayDetails() const {
        cout << "Account: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Last Transaction: " << transactionType << endl;
    }
};

int main() {
    Account a1(101, 1000), a2(102, 2000);

    a1.depositAmount(101, 102, 500);
    a1.creditAmount(102, 101, 200);

    a1.displayDetails();

    return 0;
}