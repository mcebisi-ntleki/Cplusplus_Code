/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <limits>

using namespace std;

//prototype function
unsigned long long int recursiveFactorial(int n);// to handle very large factorials

int main(void) {
    
    int number;
    
    cout << "Enter a positive number: " << endl;
    cin >> number;
    
    while( number < 0 || cin.fail() ) {//check negative numbers and characters
        cin.clear(); //clear errors such as failbit flag
        //throw away the rest of the line
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        //alert the user of error and ask for fresh input
        cout << "\nFactorial is for positive numbers only. ";
        cout << "\nPlease, try a number >= 0.: \n";
        
        cin >> number;
        
    }
    
    cout << recursiveFactorial(number) << endl;
    

    return 0;
}

unsigned long long int recursiveFactorial(int n) {
    
    if( n == 0 || n == 1 ) {
        return 1;
    }
    else {
        return n*recursiveFactorial( n - 1 );
    }
    
}








