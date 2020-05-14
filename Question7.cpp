#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
    return (1.1917535925942099587053080718604 * x) - (9.81 / ((2 * pow(25,2)) * 0.41317591116653482557414168661534)) * pow(x,2) + 1;
}

int main()
{
     
    double answer = 19.693;

    // GOLDEN SECTION SEARCH
    double a = 26, b = 36, c, d, ratio = 1.618;

    c = b - (b - a) / ratio;
    d = a + (b - a) / ratio;
    while (abs(c - d) > 0.0001)
    {
        if(f(c) < f(d))
        {
            b = d;
        }
        else
        {
            a = c;
        }   
        c = b - (b - a) / ratio;
        d = a + (b - a) / ratio;
        
    }

    double x = (a+b)/2;
    cout << "x = " << x << "\n";
    cout << "Maximum height at f(" << x << ") = " << f(x);
    cout << "\nError of " << answer - f(x) << "%";
    
}