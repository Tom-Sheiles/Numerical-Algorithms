#include <iostream>
#include <cmath>

using namespace std;

float f(float x)
{
    return 2510 * log( (2.8*pow(10, 6)) / ((2.8*pow(10, 6) - (13.3*pow(10, 3)*x)) )) - 9.81*x;
}

int main()
{
    // BISECTION METHOD
    float x0 = 69.0f, x1 = 71.0f;
    float speed1 = f(x0);
    float speed2 = f(x1);
    float x2, speed3;

    do{

        x2 = (x0 + x1) / 2.0f;
        speed3 = f(x2);
        if(speed1 * speed3  < 335)
        {
            x1 = x2;
            speed2 = speed3;
        }else{
            x0 = x2;
            speed1 = speed3;
        }
    }while (speed3 - 335 <= 0.00001);

    cout << "The rocket reaches the speed of sound (335 m/s) at " << x2 << " seconds.\n";
    

     //SECANT METHOD
     /*
    float x0 = 71, x1 = 71.5;
    float answer;

    double speed0 = f(x0);
    double speed1 = f(x1);

    do
    {   
        answer = (speed1 * x0 - speed0 * x1) / (speed1 - speed0);
        x0 = x1;
        speed0 = speed1;
        x1 = answer;
        speed1 = f(x1);
    }while(answer - 335 <= 0.0001);*/ 
    
}