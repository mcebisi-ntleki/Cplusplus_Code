/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<int, int> FiboDict = {{1, 1}, {2, 2}};
int numFC = 0;

int computeFibonacci(int n, std::map<int, int> &temp_map) {
    
    numFC++;
    int ans;
    
    if( FiboDict.contains( n ) ) 
        return FiboDict[n];
    else {
        ans = computeFibonacci( n-1, FiboDict ) + computeFibonacci( n-2, FiboDict );
        FiboDict[n] = ans;
    }
    
    return ans;
}

int main()
{
    int n[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int fibonacci_series[sizeof( n )/sizeof( int )];
    
    for( int i = 0; i < sizeof( n )/sizeof(int); i++ ) {
        //fibonacci_series[i] = computeFibonacci( n[i], FiboDict );
        cout << computeFibonacci( n[i], FiboDict ) << endl;
    }
    
    cout << endl << "computeFibonacci visited: " << numFC << " times." << endl;
    //cout << fibonacci_series << endl;
    
    return 0;
}














