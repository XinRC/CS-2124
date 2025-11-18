/*
bank_account_manager.cpp focuses on the use of pointers to grant access to transfer of money 
from one account to another. 
*/
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    private:
        string name;
        double balance;
        void transfering_money(int amount) { balance += amount; }
    public:
        BankAccount(const string& name, double balance) 
            : name(name), balance(balance) {}
        void transferTo(BankAccount* person, double transfer_money_amount) {
            if (this->balance >= transfer_money_amount) {
                person->transfering_money(transfer_money_amount);
                this->balance -= transfer_money_amount;
            } else {
                cout << "You do not have enough money to transfer " << transfer_money_amount << endl;
            }
        }
        void display() const {
            cout << name << "'s  balance: $" << balance << endl; 
        }
};

int main() {
    BankAccount account1("Alice", 1000);
    BankAccount account2("Bob", 500);
    
    // Must pass by pointer
    account1.transferTo(&account2, 300);
    
    account1.display();
    account2.display();
    
    return 0;
}
