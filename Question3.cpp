#include <iostream>
#include <math.h>

using namespace std;

/* rhomberg answer
#include <iostream>
#include <math.h>

using namespace std;

double func(double x) {
    return pow((2*x + (3/x)), 2);
// return 0.2 + 25 * x - 200 * x * x + 675 * x * x * x - 900 * pow(x, 4) + 400 * pow(x, 5); 
// Function in lecture slides
}

double multiple_trapezoid_rule(double a, double b, double (* func)(double), int n) {
    double result;
    double step = (b - a) / n;

    result = func(a) + func(b);

    for (int i = 1; i < n; i++) {
        result += 2 * func(a + i * step);
    }
    result *= (b - a) / (2 * n);
    
    return result;
}

double rhomberg(double a, double b, double (* func)(double)) {
    int n = 8;
    int segments = 1;
    double I[n][n];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        I[i][j] = 0.0;

    for (int i = 1; i < n; i++) {
        I[i][1] = multiple_trapezoid_rule(a, b, func, segments);
        segments *= 2;
    }

    for (int k = 2; k < n; k++) {
        for (int j = 1; j < n - k + 1; j++) {
            I[j][k] = (pow(4, (k-1)) * I[j+1][k-1] - I[j][k-1]) / (pow(4,(k-1)) - 1);
        }
    }

    for (int i = 1; i < n; i++)
      {for (int j = 1; j < n - i; j++)
         cout << I[i][j] << " ";
       cout << endl;
      }
    return I[1][n-1];
}

int main() {
    double a = 1.0; 
    double b = 2.0; 
// double a = 0.0; // Function in lecture slides
// double b = 0.8; // Function in lecture slides    
    double result = rhomberg(a, b, func);

    cout << "Result: " << result << endl;
    

    return 0;
}*/

double trapizoidRule(double a, double b, int n)
{
    double answer;
    double steps = (b - a) / n;
}

int main()
{
    int n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; i++)
        {
            //zero array
        }
    }

    for(int i = 1; i < n; i++)
    {
        //multi zoid rule on array
        //segments *= 2
    }


}