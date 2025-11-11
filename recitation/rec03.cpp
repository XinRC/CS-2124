// Provided
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// Task 1
// Define an Account struct 
// note only structs can use {}
struct AccountInformationStruct {
    string accountName;
    int accountNumber;
};

// Task 2
// Define an Account class (use a different name than in Task 1)
// note classes should use ()
class AccountInformationClass {
     string accountName;
     int accountNumber;

public:

     // constructor
     AccountInformationClass(const string& name, const int& number) 
     :accountName(name), accountNumber(number) {}

     // getter methods: -> nonprimative so gotta make it a constant reference
     const string& getName() const {
          return accountName;
     }
     int getNumber() const {
          return accountNumber;
     }

     // friend:
     friend ostream& operator << (ostream& os, const AccountInformationClass& rhs);

};

// for outputting 
ostream& operator << (ostream& os, const AccountInformationClass& rhs){
     // os << "Account: " << rhs.getName() << ". Account #:" << rhs.getNumber();
     os << "Account:" << rhs.accountName << " Account #:" << rhs.accountNumber;
     return os;
}

// Task 3
// Define another Account class (use a different name than in Task
// 1&2) and a Transaction class. The Transaction class is to be
// defined outside of the Account class, i.e. it is not "nested".

class Transaction{
     bool isDeposit;
     double amount; 

public:
     // constructor
     Transaction(bool isDeposit, double amount)
     : isDeposit(isDeposit), amount(amount) {}
     friend ostream& operator << (ostream& os, const Transaction& rhs);
};

// output for Transaction
ostream& operator << (ostream& os, const Transaction& rhs) {
     if (rhs.isDeposit) {
          os << "Depositing: " << rhs.amount;
     } else {
          os << "Withdrawing: " << rhs.amount;
     }
     return os;
}

class TransactionAccountClass{
     string accountName;
     int accountNumber;
     double balance;
     vector <Transaction> historicalTransaction;

public:
     // contructor
     TransactionAccountClass(const string& name, int number) 
     :accountName(name), accountNumber(number), balance(0) {}

     int getAccountNumber() const {
          return accountNumber;
     }

     // depositting function
     bool deposit(double amount) {
          if (amount <= 0) {
               return false;
          }
          historicalTransaction.emplace_back(true, amount);
          balance += amount;
          return true;
     }

     // withdrawal funtion 
     bool withdrawal(double amount) {
          if (amount <= 0 || amount > balance) {
               return false;
          }
          historicalTransaction.emplace_back(false, amount);
          balance -= amount;
          return true;
     }

     // friend;
     friend ostream& operator << (ostream& os, const TransactionAccountClass& rhs);
};


ostream& operator << (ostream& os, const TransactionAccountClass& rhs) {
     // general formatting
     os << "Account " << rhs.accountName << " Account #: " 
          << rhs.accountNumber << " with the balance of $" 
          << rhs.balance << endl;

     // displays historical transactions
     for (const Transaction& historicalItem : rhs.historicalTransaction) {
          os << " " << historicalItem << endl;
     }
     return os;
}


// Task 4
// Define yet another Account class, this time with a nested public
// Transaction class. Again use a different name for the Account class
// than in the previous Tasks. Note that it is NOT necessary to rename
// the Transaction class, since it is nested.

class AccountWithNestedTransaction {
    string name;
    int number;
    double balance;
    
public:
    class NestedTransaction {
        bool isDeposit;
        double amount;
        
    public:
        NestedTransaction(bool isDeposit, double amount) : isDeposit(isDeposit), amount(amount) {}
        
        friend ostream& operator<<(ostream& os, const NestedTransaction& transaction);
    };
    
    vector<NestedTransaction> transactions;
    
    AccountWithNestedTransaction(const string& name, int number) 
        : name(name), number(number), balance(0) {}
    
    // Add getter for account number
    int getNumber() const { return number; }
    
    bool deposit(double amount) {
        if (amount <= 0) return false;
        transactions.emplace_back(true, amount);
        balance += amount;
        return true;
    }
    
    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance) return false;
        transactions.emplace_back(false, amount);
        balance -= amount;
        return true;
    }
    
    friend ostream& operator<<(ostream& os, const AccountWithNestedTransaction& account);
};

// Define output operator for nested Transaction class
ostream& operator<<(ostream& os, const AccountWithNestedTransaction::NestedTransaction& transaction) {
    os << (transaction.isDeposit ? "Deposit: " : "Withdrawal: ") << transaction.amount;
    return os;
}
// output for general AccountWithNestedTransaction
ostream& operator<<(ostream& os, const AccountWithNestedTransaction& account) {
    os << "Account: " << account.name << " #" << account.number 
       << " Balance: " << account.balance << "\nTransactions:\n";
    for (const AccountWithNestedTransaction::NestedTransaction& transaction : account.transactions) {
        os << "  " << transaction << "\n";
    }
    return os;
}


// Task 5
// Same as Task 4, but make the Transaction nested class private.
// Yes, the Account class needs a new name but, again, the Transaction
// class does not.




int main() {
     cout << endl;
    // Task 1: account as struct
    //      1a
    cout << "Task1a:\n"
         << "Filling vector of struct objects, define a local struct instance\n"
         << "and set fields explicitly:\n";

     vector <AccountInformationStruct> accountDataVector;
     ifstream accountFile("accounts.txt");

     if (!accountFile) {
          cerr << "There is an error with the file." << endl;
     }
     
     string name;
     int number;
     while (accountFile >> name >> number) { // Read/assign values
          AccountInformationStruct account;
          account.accountName = name;
          account.accountNumber = number;
          accountDataVector.push_back(account);
     }
     accountFile.close();

     // Displays data
     for (const AccountInformationStruct& account : accountDataVector) {
          cout << "Account: " << account.accountName << " Account #: " << account.accountNumber << endl;
     }

     cout << endl; 

    //      1b
    cout << "Task1b:\n"
         << "Filling vector of struct objects, using {} initialization:\n";
     
     accountDataVector.clear();
     accountFile.open("accounts.txt");

     if (!accountFile) {
          cerr << "There is an error with the file." << endl;
     }

     while (accountFile >> name >> number) {
          accountDataVector.push_back(AccountInformationStruct{name, number});
     }
     accountFile.close();

     for (const AccountInformationStruct& account : accountDataVector) {
          cout << "Account: " << account.accountName << " Account #:" << account.accountNumber << endl;
     }


 
    //==================================
    // Task 2: account as class

    //      2a
    cout << "==============\n";
    cout << "\nTask2a:"
         << "\nFilling vector of class objects, using local class object:\n";
     vector <AccountInformationClass> accountDataClass;
     accountFile.open("accounts.txt");

     while (accountFile >> name >> number) {
          accountDataClass.push_back(AccountInformationClass(name, number));
     }
     accountFile.close();

    cout << "\nTask2b:\n";
    cout << "output using output operator with getters\n";
    for (const AccountInformationClass& account : accountDataClass) {
          cout << "Account: " << account.getName() << " Account #: " << account.getNumber() << endl;
    }

    cout << "\nTask2c:\n"
         << "output using output operator as friend without getters\n";
     for (const AccountInformationClass& account : accountDataClass) {
          cout << account << endl; 
     }


    cout << "\nTask2d:\n"
         << "Filling vector of class objects, using temporary class object:\n";
          vector <AccountInformationClass> tempVector;
          accountFile.open("accounts.txt");

          while (accountFile >> name >> number) {
               tempVector.push_back(AccountInformationClass(name, number));
          }
          accountFile.close();

          for (const AccountInformationClass& account : tempVector) {
               cout << account << endl;
          }

    
    cout << "\nTask2e:\n"
         << "Filling vector of class objects, using emplace_back:\n";
          vector <AccountInformationClass> emplaceVector;
          accountFile.open("accounts.txt");

          while (accountFile >> name >> number) {
               emplaceVector.emplace_back(name, number);
          }
          accountFile.close();

          for (const AccountInformationClass& account : emplaceVector) {
               cout << account << endl;
          }
    
    cout << "==============\n"
         << "\nTask 3:\nAccounts and Transaction:\n"; // -----> FIX LATER

          vector <TransactionAccountClass> transactionAccountData;
          ifstream transactionFile("transactions.txt");
          if (!transactionFile) {
               cerr << "The file is unopenable" << endl;
          } 

          string order;
          while (transactionFile >> order) {
               if (order == "Account") {
                    string accountName;
                    int accountNumber;
                    transactionFile >> accountName >> accountNumber; 
                    transactionAccountData.emplace_back(accountName, accountNumber);
               } else if (order == "Deposit" || order == "Withdraw") {
                    int accountnumber;
                    double amount;
                    transactionFile >> accountnumber >> amount;

                    bool foundAccount = false;
                    for (TransactionAccountClass& account : transactionAccountData){
                         if (account.getAccountNumber() == accountnumber) {
                              foundAccount = true;
                              if (order == "Deposit") {
                                   if (!account.deposit(amount)) {
                                   cerr << "Invalid deposit amount: " << amount << endl;
                                   }
                              }
                              if (order == "Withdraw") {
                                   if (!account.withdrawal(amount)) {
                                        cerr << "Invalid withdrawl amount: " << amount << endl;
                                   }
                              }
                         }

                    }
                    if (!foundAccount) {
                         cerr << "Account was not found" << endl;
                    }

               }
          }
          transactionFile.close();
          for (const TransactionAccountClass& account: transactionAccountData) {
               cout << account << endl;
          }



    cout << "==============\n"
         << "\nTask 4:\nTransaction nested in public section of Account:\n";
     vector<AccountWithNestedTransaction> accountsNested;
     transactionFile.open("transactions.txt");

     while (transactionFile >> order) {
          if (order == "Account") {
            int accNumber;
            transactionFile >> name >> accNumber;
            accountsNested.emplace_back(name, accNumber);
          } 
          else if (order == "Deposit" || order == "Withdraw") {
               int accNumber;
               double amount;
               transactionFile >> accNumber >> amount;
            
               bool accountFound = false;
               for (AccountWithNestedTransaction& account : accountsNested) {
                    if (account.getNumber() == accNumber) {
                         accountFound = true;
                         if (order == "Deposit") {
                         if (!account.deposit(amount)) {
                                 cerr << "Invalid deposit amount: " << amount << endl;
                         }     
                         } else {
                         if (!account.withdraw(amount)) {
                                 cerr << "Invalid withdrawal amount: " << amount << endl;
                         }
                         }
                         break;
                    }
               }
               if (!accountFound) {
                    cerr << "Account not found: " << accNumber << endl;
               }
          }
     }
     transactionFile.close();
    
     for (const AccountWithNestedTransaction& account : accountsNested) {
          cout << account << endl;
     }


    
    cout << "==============\n"
         << "\nTask 5:\nTransaction nested in private section of Account:\n";

     }
 // main
