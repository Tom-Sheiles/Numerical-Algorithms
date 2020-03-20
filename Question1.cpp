#include <iostream>
#include <math.h>

using namespace std;

float f(float x)
{
    return -0.1 * x * x * x * x - 0.15 * x * x * x - 0.5 * x * x - 0.15 * x + 1.2;
}

float df(float x)
{
    return -0.4 * x * x * x - 0.45 * x * x - x - 0.15;
}

int main()
{
  double x, h, v, error;
  x = 0.5;
  h = 0.25;

  v = (f(x+h) - f(x-h)) / (2 * h);
  error = fabs(df(x) - v) * 100 / df(x);

  cout << v <<  " error: " << error << endl;
}