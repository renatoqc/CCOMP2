#include <iostream>
#include "Account.h"

using namespace std;

int main(){
    Account account1{"Jane Green", 50};
    Account account2{"Jhon Blue", -7};

    cout << "account1: " << account1.getName() << "Balance is $" << account1.getBalance();
    cout << "account2: " << account2.getName() << "Balance is $" << account2.getBalance();

    cout <<"\n\nEnter deposit amount for account1: ";
    int depositAmount;
    cin >> depositAmount;
    cout << "adding " << depositAmount << "to account1 balance";
    account1.deposit(depositAmount);

    cout <<"\n\account1: " << account1.getName()<<"Balance is $"<< account1.getBalance();
    cout <<"\n\account2: " << account2.getName()<<"Balance is $"<< account2.getBalance();

    cout <<"\n\enter deposit amount for account 2: ";
    cin >> depositAmount;
    cout << "adding" << depositAmount << "to account2 balance";
    account2.deposit(depositAmount);

    cout <<"\naccount1: "<< account1.getName()<<"Balance is $"<<account1.getBalance();
    cout <<"\naccount2: "<< account2.getName()<<"Balance is $"<<account2.getBalance();
}