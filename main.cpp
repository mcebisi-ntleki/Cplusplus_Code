/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class DebitAccount {
     
    private:   
        double currentBalance; 
        double interest; 
        double interestRate;
        
        int transactions;
        
    public:
        DebitAccount(double intRate = 0.018, double balance = 300.00) {
            
            currentBalance = balance;
            interest = balance * intRate;
            interestRate = intRate;
            transactions = 0;
            
            }
    
        char selectService(char min, char max) {
            
            char option = cin.get();
            cin.ignore();
            
            while (option < min || option > max) {
                cout << "Number selected out of bounds. "
                << "Selection must be between " 
                << min << " and "
                << max << ".\n"
                << "Please, re-enter option: ";
                
                option = cin.get();
                cin.ignore();
            }
            
            return option;
        }
        
        void makeDeposit(double amount) {
            
            currentBalance += amount;
            transactions++;
            }
    
        void withdraw(double amount) {
            
            if(!validateWithdrawal(amount)) {
                cout << "ERROR: Not enough funds.\n";
            }
            
        }
        
        bool validateWithdrawal(double amount) {
        
            if(currentBalance < amount) {
                return false;
            }
            else {
                currentBalance -= amount;
                transactions++;
                return true;
                }
            }
    
        void calculateInterest() {
            
            interest = currentBalance * interestRate;
            currentBalance += interest;
            }
    
        double getBalance() const {
            
            return currentBalance;
            }
    
        double getInterest() const {
            
            return interest;
            }
    
        int getTransactions() const {
        
            return transactions;
            }
    
    };

void showMenu() {
    
    cout << "**********MAIN MENU**********" << endl;
    cout << "1. Balance" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Number of transactions" << endl;
    cout << "5. Check interest" << endl;
    cout << "6. Add interest" << endl;
    cout << "7. Exit" << endl;
    cout << "*****************************\n";
    
}

int main()
{
    DebitAccount Account;
    
    const char MIN_OPTION = '1';
    const char MAX_OPTION = '7';
    
    char serviceOption;
    double amount;
    
    cout << fixed << showpoint << setprecision(2);
    
    
    do {
    showMenu();
    cout << "Please, select a service ";
    serviceOption = Account.selectService(MIN_OPTION, MAX_OPTION);
    
    switch(serviceOption) {
        case '1': 
            cout << "Your current balance is: £" 
            << Account.getBalance() 
            << endl; 
            break; 
        case '2': 
            cout << "Enter amount to deposit ";
            cin >> amount;
            cin.ignore();
            Account.makeDeposit(amount);
            break;
        case '3': 
            cout << "Enter amount to withdraw ";
            cin >> amount;
            cin.ignore();
            Account.withdraw(amount);
            break;
        case '4':
            cout << "There have been ";
            cout << Account.getTransactions() << " transactions.\n";
            break;
        case '5':
            cout << "Interest earned so far: £";
            cout << Account.getInterest() << endl;
            break;
        case '6':
            cout << "Interest added.\n";
            Account.calculateInterest();
            }       
    }while(serviceOption != MAX_OPTION);
    

    return 0;
}









