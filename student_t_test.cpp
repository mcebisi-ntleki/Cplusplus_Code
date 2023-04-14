/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

void avevar(std::vector<double> &data, double &ave, double &var) {
    
    double s;
    double ep;
    
    int n = data.size();
    
    ave = 0.0;
    
    for(int j = 0; j < n; j++){
        ave += data[j];
    }
    ave /= n;
    
    var = 0.0;
    ep = 0.0;
    
    for(int j = 0; j < n; j++) {
        s = data[j] - ave;
        ep += s;
        var += s*s;
    }
    var = ( var - ep * ep/n )/( n - 1 );
    
    cout << fixed << showpoint << setprecision(3);
    cout << "The mean is: " << ave 
    << "\nThe variance is: " << var << endl;
}



float gammln( float xx ){
    double x;
    double y;
    double temp;
    double ser;
    
    static double cof[6] = {76.18009172947146, -86.50532032941677,
24.01409824083091, -1.231739572450155,
0.1208650973866179e-2, -0.5395239384953e-5};

    int j;
    
    y = x = xx;
    temp = x + 5.5;
    temp -= ( x + 0.5 ) * log( temp );
    ser = 1.000000000190015;
    
    for( j = 0; j <= 5; j++ ) {
        ser += cof[j]/++y;
    }
    
    return -temp + log( 2.5066282746310005 * ser/x );
}

struct Gauleg18 {
//Abscissas and weights for Gauss-Legendre quadrature.
    static const int ngau = 18;
    static const double y[18];
    static const double w[18];
};

const double Gauleg18::y[18] = {0.0021695375159141994,
0.011413521097787704,0.027972308950302116,0.051727015600492421,
0.082502225484340941, 0.12007019910960293,0.16415283300752470,
0.21442376986779355, 0.27051082840644336, 0.33199876341447887,
0.39843234186401943, 0.46931971407375483, 0.54413605556657973,
0.62232745288031077, 0.70331500465597174, 0.78649910768313447,
0.87126389619061517, 0.95698180152629142};

const double Gauleg18::w[18] = {0.0055657196642445571,
0.012915947284065419, 0.020181515297735382, 0.027298621498568734,
0.034213810770299537, 0.040875750923643261, 0.047235083490265582,
0.053244713977759692, 0.058860144245324798, 0.064039797355015485,
0.068745323835736408, 0.072941885005653087, 0.076598410645870640,
0.079687828912071670, 0.082187266704339706, 0.084078218979661945,
0.085346685739338721, 0.085983275670394821};

struct Beta : Gauleg18 {

    static const int SWITCH = 3000; //When to switch to quadrature method.
    static const double EPS; 
    static const double FPMIN; 
    
    double betaiapprox(double a, double b, double x) {
    //Incomplete beta by quadrature. Returns Ix .a; b/. User should not call directly.
        int j;
        double xu;
        double t;
        double sum;
        double ans;
        
        double a1 = a - 1.0; 
        double b1 = b - 1.0; 
        double mu = a/( a + b );
        double lnmu = log( mu ), lnmuc = log( 1. -mu );
        t = sqrt( a * b/( sqrt( a + b) * ( a + b + 1.0 ) ) );// SQR -> sqrt
        if ( x > a/( a + b ) ) { 
            //Set how far to integrate into the tail:
            if ( x >= 1.0 ) return 1.0;
            xu = min( 1., max( mu + 10. * t, x + 5.0 * t ) );//MIN -> min, MAX -> max
        } 
        else {
            if ( x <= 0.0 ) return 0.0;
            xu = max( 0., min( mu - 10. * t, x - 5.0 * t ) ); //MAX -> max, MIN -> min
        }
        sum = 0;
        for ( j = 0; j < 18; j++ ) { 
            //Gauss-Legendre.
            t = x + ( xu - x ) * y[j];
            sum += w[j] * exp( a1 * (log( t ) - lnmu ) + b1 * (log( 1 - t ) - lnmuc ) );
        }
        
        ans = sum * ( xu - x ) * exp(a1 * lnmu - gammln(a)+b1*lnmuc-gammln(b)+gammln(a+b));
        return ans > 0.0 ? 1.0 - ans : -ans;
    }     
    
    double betai(const double a, const double b, const double x) {

        double bt;
        
        if ( a <= 0.0 || b <= 0.0 ) throw( "Bad a or b in routine betai" );
        if ( x < 0.0 || x > 1.0 ) throw( "Bad x in routine betai" );
        
        if ( x == 0.0 || x == 1.0 ) return x;
        if ( a > SWITCH && b > SWITCH ) return betaiapprox( a, b, x );
        
        bt = exp(gammln(a + b) - gammln(a) - gammln(b) + a * log(x) + b * log(1.0 - x));
        
        if ( x < (a + 1.0)/(a + b + 2.0)) return bt * betacf( a, b, x )/a;
        else return 1.0 - bt * betacf(b, a, 1.0 - x)/b;
    }
    
    double betacf(const double a, const double b, const double x) {
        //Evaluates continued fraction for incomplete beta function by modified Lentz’s method
        // User should not call directly.
        int m, m2;
        
        double aa;
        double c;
        double d, del;
        double h;
        double qab, qam, qap;
        
        qab = a + b; //These q’s will be used in factors that
        //occur in the coefficients, qap=a+1.0;
        qam = a - 1.0;
        c = 1.0; //First step of Lentz’s method.
        d = 1.0 - qab * x/qap;
        if (fabs( d ) < FPMIN ) d = FPMIN;
        d = 1.0/d;
        h = d;
        for ( m = 1; m < 10000; m++ ) {
            m2 = 2 * m;
            aa = m * ( b - m ) * x/( ( qam + m2 ) * ( a + m2 ) );
            d = 1.0 + aa * d; //One step (the even one) of the recur-
            //rence.
            if ( fabs( d ) < FPMIN ) d = FPMIN;
            c = 1.0 + aa/c;
            if ( fabs( c ) < FPMIN ) c = FPMIN;
            d = 1.0/d;
            h *= d * c;
            aa = -(a + m) * (qab + m) * x/((a + m2) * (qap + m2));
            d = 1.0 + aa * d; //Next step of the recurrence (the odd
            //one).
            if ( fabs( d ) < FPMIN ) d = FPMIN;
            c = 1.0 + aa/c;
            if ( fabs( c ) < FPMIN ) c = FPMIN;
            d = 1.0/d;
            del = d * c;
            h *= del;
            if ( fabs( del - 1.0 ) <= EPS ) break; //Are we done?
        }
        
    return h;
    
    }

};

const double Beta::EPS = numeric_limits<double>::epsilon();
const double Beta::FPMIN = numeric_limits<double>::min()/EPS;


double student_t_test(vector<double> &data1, vector<double> &data2) {
    Beta beta;

    double var1;
    double var2;
    double svar;
    double df;
    double t;
    double ave1;
    double ave2;
    double prob;
    
    int n1 = data1.size();
    int n2 = data2.size();
    
    avevar( data1, ave1, var1 );
    avevar( data2, ave2, var2 );
    df = n1 + n2 - 2; //Degrees of freedom.
    svar = ( ( n1 - 1 ) * var1 + ( n2 - 1 ) * var2 )/df; 
    t = ( ave1 - ave2 )/sqrt( svar * ( 1.0/n1 + 1.0/n2 ) );
    prob = beta.betai( 0.5 * df, 0.5, df/( df + t * t ) ); 
    cout << "The p-value is " << prob << endl;
    return t;
}

int main()
{
    vector<double> data1{4, 49, 10, 4, 15, 6, 7};
    vector<double> data2{17, 25, 19, 97, 23, 46};
    
    double ave = 2.00;
    double var = 0.01;
    
    cout << endl;
    cout << "The t value is: " 
    << student_t_test( data1, data2 ) << endl;
    avevar( data1, ave, var);
    

    return 0;
}






