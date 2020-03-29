#include <iostream>
#include <math.h>

using namespace std;

const double g = 9.9, c = 10, m = 80;
const int n = 8;

double f(double t)
{
    return (g * m) / c * (1 - exp( -(c/m) * t ));
}

double trapizoidRule(double a, double b, int n)
{
    double result;
    double step = (b - a) / n;
    result = f(a) + f(b);

    for(int i = 1; i < n; i++)
    {
        result += 2 * f(a + i * step);
    }
    result *= (b - a) / (2 * n);
    return result;
}

double romberg(double values[n][n], int i, int j)
{
    return (pow(4, (i - 1)) * values[j + 1][i - 1]) / (pow(4,(i - 1)) - 1);
}

int main()
{
    double values[n][n], a = 0, b = 8;
    int segments = 1;
    double actual = 230.73398;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            values[i][j] = 0;
        }
    }

    for(int i = 1; i < n; i++)
    {
        values[i][1] = trapizodRule(a, b, segments);
        segments *= 2;
    }

    for(int i = 2; i < n; i++)
    {
        for(int j = 1; j < n - i + 1; j++)
        {
            values[j][i] = romberg(values, i, j);
        }
    }

    int x = 1, y = 1;
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < n - i; j++)
        {
            //cout << i << " " << j << " " << values[i][j] << " ";
            x = i; y = j;
        }
        //cout << endl;
    }

    double error = abs(values[x][y] - actual)/actual * 100;

    cout << endl << "The body falls approximately " << values[x][y] << " m in 8 seconds with an error of " << error << "%\n" << endl;

    
}