#include <iostream>
#include <math.h>

using namespace std;

float f(float x)
{
    return -0.1 * x * x * x * x - 0.15 * x * x * x - 0.5 * x * x - 0.15 * x + 1.2;
}


int main()
{
  double x, h, v, trunc, round;
  x = 0.5;
  h = 0.1;

for(; h <= 1; h+=0.1){
  v = (f(x+h) - f(x-h)) / (2 * h);
  trunc = (f(x+h) - f(x-h) / (2 * h)) - v;

  round = (f(x + (2*h)) - f(x - (2*h))) / (4 * h);
  round = (round - v) / 3;

}


  
    
  //error = fabs(df(x) - v) * 100 / df(x);

  
}