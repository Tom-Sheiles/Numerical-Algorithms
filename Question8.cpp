#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

double f(double x, double m, double b)
{
    return m * x + b;
}

double* regression(double *x, double *y)
{
    double xsum = 0, x2sum = 0, ysum = 0, xysum = 0;
    double a, b;
    double *line = (double*)malloc(2 * sizeof(double));

    for(int i = 0; i < 15; i++)
    {
        xsum += x[i];
        ysum += y[i];

        x2sum += pow(x[i],2);
        xysum += x[i] * y[i];
    }
    a = (15 * xysum - xsum * ysum) / (15 * x2sum - xsum * xsum);
    b = (x2sum * ysum - xsum * xysum) / (x2sum * 15 - xsum * xsum);
    
    line[0] = a;
    line[1] = b;
    return line;
}

int main()
{
    double time[15];
    double measured[15] = {10, 16.3, 23, 27.5, 31, 35.6, 39, 41.5, 42.9, 45, 46, 45.5, 46, 49, 50};
    double model1[15]   = {8.953,16.405,22.607,27.769,32.065,35.641,38.617,41.095,43.156,44.872,46.301,47.490,48.479,49.303,49.988};
    double model2[15]   = {11.240,18.570,23.729,27.556,30.509,32.855,34.766,36.351,37.687,38.829,39.816,40.678,41.437,42.110,42.712};

    for(int i = 0; i < 15; i++)
    {
        time[i] = i+1;
        //cout << "{" << time[i] << "," << model1[i] << "}, ";
    }

    double *model1Regression = regression(time, model1);
    double *model2Regression = regression(time, model2);

    double m1Error = 0;
    double m2Error = 0;

    for(int i = 0; i < 15; i++)
    {
        m1Error += abs(measured[i] - model1[i]);
        m2Error += abs(measured[i] - model2[i]);
    }

    cout << "Model 1: " << " y = " << model1Regression[0] << "x" << " + " << model1Regression[1] << "\nError: " << m1Error << "\n";
    cout << "Model 2: " << " y = " << model2Regression[0] << "x" << " + " << model2Regression[1] << "\nError: " << m2Error;
    
}