/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string> //tolower
#include <cctype>
#include <algorithm> //transform

using namespace std;

bool isPal( string s ) {
    if( s.length() <= 1 ) {
        return true;
        }
    else {
        return s[ 0 ] == s[ s.length() - 1 ] && 
        isPal( s.substr( 1, s.length() - 2 ) );
        }
    }

string to_lower(string s) {
    
    transform(s.begin(), s.end(), s.begin(), 
    [](unsigned char c) { return ::tolower(c); });
    s.erase(remove_if(s.begin(), s.end(), ::isspace),
        s.end());
    return s;
}

int main() {
    
    string yesOrNo;
    
    string words[] = {"civic", "deleveled", "Hannah", 
    "kayak", "level", "examiron", "racecar", "radar", "refer", 
    "reviver", "revolver", "rotator", "rotor", "sagas", 
    "soros", "stats", "tenet", "Csharpstar", "Able was I ere I saw Elba",
    "Do geese see God"};

    for(int i = 0; i < sizeof( words )/sizeof( words[0] ); i++) {
        words[i] = to_lower( words[i] );
        yesOrNo = ( isPal( words[i] ) == 0 ) ? "No!" : "Yes!";
        cout << yesOrNo << endl;
    }
    
    return 0;
}











