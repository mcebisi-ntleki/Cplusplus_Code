/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cmath>

using namespace std;

//const double tolerance = 1.0e-6;
//const int maxIterations = 100;
    
//prototype function
void computeCubeRoot(double& x, double K, 
double tolerance = 1.0e-6, 
int maxIterations = 100);

int main()
{

    double x = 1.0;
    double K = 125.0;
    
    //calculate cube root 
    computeCubeRoot(x, K);
    
    double tolerance = 0.001;
    x = 1.0;
    computeCubeRoot(x, K, tolerance);
    
    int maxIterations = 50;
    x = 1.0;
    computeCubeRoot(x, K, tolerance, maxIterations);

    return 0;
}

//compute cube root
void computeCubeRoot(double& x, double K, double tolerance, int maxIterations) {
    
    int iterations = 0;
    double residual = x * x * x - K;
    
    while( fabs( residual ) > tolerance && iterations < maxIterations ) {
        x = x - ( x * x * x - K )/( 3.0 * x * x );
        residual = x * x * x - K;
        iterations++;
    }
    
    printf("The cube root of %.1f is %.3f, ", K, x);
    printf("in %d iterations.\n", iterations);
}















