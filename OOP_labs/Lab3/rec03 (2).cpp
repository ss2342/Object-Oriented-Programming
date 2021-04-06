/*
//Programmer: Ariaki Dandawate
  rec03-base.cpp
 */

 // Provided
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//
// Task 1: The Account struct. Call it AccountS
//
struct AccountS {
    string accountName;
    int accountNumber;
};

// Task 3
//
// Transaction class definition
class TransactionC {
public:
    TransactionC(const string& aDepWith, const int& anAmount) : theDepWith(aDepWith), theAmount(anAmount) {};
    string getDepWith() const { return theDepWith; }
    int getAmount() const { return theAmount; }
private:
    string theDepWith;
    int theAmount;
};

//
// Task 2: The Account class. Call it AccountC
//
class AccountC {
    // 2.2: AccountC output operator, reimplemented as a friend.
    friend ostream& operator<<(ostream& os, const AccountC& accountObj) {
        cout << "Account Name: " << accountObj.accountName << ", Account Number: " << accountObj.accountNumber << ", Account Balance: " << accountObj.accountBalance << endl;
        return os;}
public:
    AccountC(const string& aName, const int& aNumber, const int& aBalance) : accountName(aName), accountNumber(aNumber), accountBalance(aBalance) {};
    string getAccountName() const { return accountName; }
    int getAccountNumber() const { return accountNumber; }
    int getAccountBalance() const { return accountBalance;  }

    // 2.b: AccountC output operator, not a friend.
    void displayAll() const {
        cout << "Account Name: " << getAccountName() << ", Account Number: " << getAccountNumber() << ", Account Balance: " << getAccountBalance() << endl;
        for (size_t i = 0; i < transHistory.size(); i++) {
            cout << transHistory[i].getDepWith() << " $" << transHistory[i].getAmount() << endl;
            
        }
    }
    void display(ostream& os ) {
        cout << getAccountName() << "  " <<  getAccountNumber() << "  " << getAccountBalance();
    }

    //Task 3d: add deposit and withdrawal methods.
    void deposit(const int& depAmount) {
        TransactionC aTrans{ "Deposit", depAmount };
        transHistory.push_back(aTrans);
        accountBalance = accountBalance + depAmount;
        
    }
    void withdrawal(const int& withAmount) {
        TransactionC aTrans{ "Withdrawal", withAmount };
        transHistory.push_back(aTrans);
        if ((accountBalance - withAmount) < 0) {
            cerr << "Not enough balance in the account of: " << accountName << " (account #: " << accountNumber << ")" << endl;
        }
        else { accountBalance = accountBalance - withAmount; }
        
    }
private:
    vector<TransactionC> transHistory;
    string accountName;
    int accountNumber;
    int accountBalance;
    
};

//

//
// Task 4
//
// Transaction class definition with embedded Account class
class Account {
    // 2.2: AccountC output operator, reimplemented as a friend.
    friend ostream& operator<<(ostream& os, const Account& accountObj) {
        cout << "Account Name: " << accountObj.accountName << ", Account Number: " << accountObj.accountNumber << ", Account Balance: " << accountObj.accountBalance;
        return os;
    }
public:
    Account(const string& aName, const int& aNumber, const int& aBalance) : accountName(aName), accountNumber(aNumber), accountBalance(aBalance) {}
    string getAccountName() const { return accountName; }
    int getAccountNumber() const { return accountNumber; }
    int getAccountBalance() const { return accountBalance; }

    // 2.b: AccountC output operator, not a friend.
    void display() {
        cout << "Account Name: " << getAccountName() << " Account Number: " << getAccountNumber() << " Account Balance: $" << getAccountBalance() << endl;
        for (size_t i = 0; i < transHistory.size(); i++) {
            transHistory[i].displayTrans();
        }
    }

    //Task 3d: add deposit and withdrawal methods.
    void deposit(const int& depAmount) {
        TransactionE aTrans{ "deposit", depAmount };
        transHistory.push_back(aTrans);
        accountBalance = accountBalance + depAmount;
    }
    void withdrawal(const int& withAmount) {
        TransactionE aTrans{ "withdrawal", withAmount };
        transHistory.push_back(aTrans);
        if ((accountBalance - withAmount) < 0) {
            cerr << "Not enough balance in the account of: " << accountName << " (account #: " << accountNumber << ")" << endl;
        }
        else { accountBalance = accountBalance - withAmount; }
    }
private:
    class TransactionE {
    public:
        TransactionE(const string& aDepWith, const int& anAmount) : theDepWith(aDepWith), theAmount(anAmount) {}
        string getDepWith() const { return theDepWith; }
        int getAmount() const { return theAmount; }
        void displayTrans() const {
            cout << getDepWith() << " $" << getAmount() << endl;
        }

    private:
        string theDepWith;
        int theAmount;
    };
    vector<TransactionE> transHistory;
    string accountName;
    int accountNumber;
    int accountBalance;

};



int main() {

    //
    // Task 1: account as struct
    //
    //      1a. Fill vector of account structs from file

    cout << "Task1a:\n";
    cout << "Filling vector of struct objects, define a local struct instance "
        << " and set fields explicitly:\n";
    ifstream accountFile("accounts.txt");
    vector<AccountS> accountsVec;
    string aName;
    int aNumber;
    AccountS anAccount;
    while (accountFile >> aName >> aNumber) {
        anAccount.accountName = aName;
        anAccount.accountNumber = aNumber;
        accountsVec.push_back(anAccount);

    }
    for (size_t i = 0; i < accountsVec.size(); i++) {
        cout << accountsVec[i].accountName << " " << accountsVec[i].accountNumber << endl;
    }

    accountFile.close();
    accountFile.open("accounts.txt");

    //      1b
    cout << "Task1b:\n";
    cout << "Filling vector of struct objects, using {} initialization:\n";
    accountsVec.clear();
    while (accountFile >> aName >> aNumber) {
        AccountS anotherAccount{ aName, aNumber };
        accountsVec.push_back(anotherAccount);
    }
    for (size_t i = 0; i < accountsVec.size(); i++) {
        cout << accountsVec[i].accountName << " " << accountsVec[i].accountNumber << endl;
    }
    accountFile.close();
    accountFile.open("accounts.txt");
    //==================================
    //
    // Task 2: account as class
    //

    //      2a
    cout << "==============\n";
    cout << "\nTask2a:";
    cout << "\nFilling vector of class objects, using local class object:\n";
    vector<AccountC> theAccounts;
    string theName;
    int theNumber;
    while (accountFile >> theName >> theNumber) {
        AccountC anAccount(theName, theNumber, 0);
        theAccounts.push_back(anAccount);
    }


    cout << "---\n";
    cout << "\nTask2b:\n";
    cout << "output using output operator with getters\n";
    for (size_t i = 0; i < theAccounts.size(); i++) {
        cout << "Account Name: " << theAccounts[i].getAccountName() << ", Account Number: " << theAccounts[i].getAccountNumber() << endl;
    }

    cout << "\nTask2c:\n";
    cout << "output using output operator as friend without getters\n";
    // Note code here will be same as above.
    for (size_t i = 0; i < theAccounts.size(); i++) {
        cout << theAccounts[i] << endl;
    }
    accountFile.close();
    accountFile.open("accounts.txt");
    theAccounts.clear();
    accountFile.close();

    cout << "\nTask2d:\n";
    cout << "Filling vector of class objects, using temporary class object:\n";
    while (accountFile >> theName >> theNumber) {
        theAccounts.push_back(AccountC(theName, theNumber, 0));
    }
    for (size_t i = 0; i < theAccounts.size(); i++) {
        cout << theAccounts[i] << endl;
    }

    cout << "\nTask2e:\n";
    cout << "\nFilling vector of class objects, using emplace_back:\n";
    theAccounts.clear();
    accountFile.close();
    accountFile.open("accounts.txt");

    while (accountFile >> theName >> theNumber) {
        theAccounts.emplace_back(theName, theNumber, 0);
    }
    for (size_t i = 0; i < theAccounts.size(); i++) {
        cout << theAccounts[i] << endl;
    }
    
    ifstream transFile("transactions.txt");
    // Task 3
    cout << "==============\n";
    cout << "\nTask 3:\n\nAccounts and Transaction:\n";
    string Command;
    string accountName;
    int accountNumber;
    int anAmount;
    vector<AccountC> accounts;
    while (transFile >> Command) {
        if (Command == "Account") {
            transFile >> accountName >> accountNumber;
            AccountC anAccount{ accountName, accountNumber, 0 };
            accounts.push_back(anAccount);
        }

        else if (Command == "Deposit") {
            transFile >> accountNumber >> anAmount;
            for (size_t i = 0; i < accountsVec.size(); i++) {
                if (accounts[i].getAccountNumber() == accountNumber) {
                    accounts[i].deposit(anAmount);
                    break;
                }
            }
        }

        else if (Command == "Withdraw") {
            transFile >> accountNumber >> anAmount;
            for (size_t i = 0; i < accountsVec.size(); i++) {
                if (accounts[i].getAccountNumber() == accountNumber) {
                    accounts[i].withdrawal(anAmount);
                    break;
                }
            }

        }

    } 
    for (size_t i = 0; i < accounts.size(); i++) {
         accounts[i].displayAll();
    }
    

    // Task 4
    cout << "==============\n";
    cout << "\nTask 4:\n\nAccounts and Transaction:\n"
        << "Account class is nested inside Transaction class.\n";
    transFile.close();
    transFile.open("transactions.txt");
    string Command2;
    string accountName2;
    int accountNumber2;
    int anAmount2;
    vector<Account> accountVec;
    while (transFile >> Command2) {
        if (Command2 == "Account") {
            transFile >> accountName2 >> accountNumber2;
            Account anAccount{ accountName2, accountNumber2, 0 };
            accountVec.push_back(anAccount);
        }

        else if (Command2 == "Deposit") {
            transFile >> accountNumber2 >> anAmount2;
            for (size_t i = 0; i < accountVec.size(); i++) {
                if (accountVec[i].getAccountNumber() == accountNumber2) {
                    accountVec[i].deposit(anAmount2);
                    break;
                }
            }
        }

        else if (Command2 == "Withdraw") {
            transFile >> accountNumber2 >> anAmount2;
            for (size_t i = 0; i < accountVec.size(); i++) {
                if (accountVec[i].getAccountNumber() == accountNumber2) {
                    accountVec[i].withdrawal(anAmount2);
                    break;
                }
            }

        }

    }
    for (size_t i = 0; i < accounts.size(); i++) {
        accountVec[i].display();
    }

}
