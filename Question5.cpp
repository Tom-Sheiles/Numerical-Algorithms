#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double y)
{
    return x - (0.225/90) * (y * y);
}


double romberg(double values[5][5], int i, int j)
{
    return (pow(4, (i - 1)) * values[j + 1][i - 1]) / (pow(4,(i - 1)) - 1);
}


int main()
{
    double x = 0.0, step = 0.25, y, y1 = f(0,0), s, max = 1.0;

    int n = 5;
    double values[n];
    int i = 0;

    /*
    // Eulers Method
    for(;x <= max; x+= step)
    {
        s = f(x, y1);
        y = y1 + s * step;
        values[i] = y;
        i++;
        y1 = y;
    }*/
    
    // RK4 Method
    double k1, k2, k3, k4;
    for(;x <= max; x += step)
    {
        k1 = f(x, y1);
        k2 = f(x + step / 2, y1 + k1 * step / 2);
        k3 = f(x + step / 2, y1 + k2 * step / 2);
        k4 = f(x + step, y1 + k3 * step);
        y = y1 + (k1 + 2 * k2 + 2 * k3 + k4) * step / 6;
        values[i] = y;
        i++;
        y1 = y;
    }

    double a = 0, b = max;
    double segments = (b-a)/(max/2);
    double answers[5][5];

    double r = 0;
    double h = (b-a)/segments;

   for(int j = 1; j < n; j++)
    {
        for(int k = 1; k < n; k++)
        {
            r += 2 * (values[k]);
        }
        r *= (b-a)/ b;
        answers[j][1] = r;
    }

    for(int k = 2; k < n; k++)
    {
        for(int j = 1; j < n - k + 1; j++)
        {
            answers[j][k] = romberg(answers, k, j);
        }
    }

    int x2 = 1, y2 = 1;
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < n - i; j++)
        {
            x2 = i; y2 = j;
        }       
    }

    cout << "The speed of the object is " << answers[x2][y2] << "m/s" << endl;
    cout << "It would take " << (1/answers[x2][y2]) * 1000 << " seconds for an object to travel 1km" << endl;
}