/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

bool isEven(int number); //function prototype

int main(void) {
    //loop for two numbers
    for(int i = 0; i < 2; ++i) {
        printf("Enter an integer: ");
        int input; //value used by user
        scanf("%d", &input);
        
        bool valueIsEven = isEven(input); //determine if input is even
        
        //determine whether input is even
        if(valueIsEven) {
            printf("%d is even \n\n", input);
        }
        else {
            printf("%d is odd \n\n", input);
        }
    }

    return 0;
}

//isEven returns true if number is even
bool isEven(int number) {
    if(number % 2 == 0) {//is number divisible by 2?
        return true;
    }
    else {
        return false;
    }
}










