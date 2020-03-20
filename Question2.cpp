#include <iostream>
#include <math.h>

using namespace std;

double degtorad(double x)
{
    return x * (M_PI / 180);
}


double findX(double a, double b)
{
    a = tan(a);
    b = tan(b);

    return 500 * (b / (b - a));
}


double findY(double a, double b)
{
    a = tan(a);
    b = tan(b);

    return 500 * (a * b / (b - a));
}


double CalculateSpeed(double x1, double x2, double y1, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}


double CalculateAngle(double x1, double x2, double y1, double y2)
{
    double delta = atan((y2 - y1) / (x2 - x1));
    return delta * 180/M_PI;
}


int main()
{
    double readings[3][2];
    double coords[3][2];

    readings[0][0] = 54.80;
    readings[0][1] = 65.59;
    readings[1][0] = 54.06;
    readings[1][1] = 64.59;
    readings[2][0] = 53.34;
    readings[2][1] = 63.62;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            readings[i][j] = degtorad(readings[i][j]);
        }
        coords[i][0] = findX(readings[i][0], readings[i][1]);
        coords[i][1] = findY(readings[i][0], readings[i][1]);

        //cout << "x: " << coords[i][0] << " y: " << coords[i][1] << endl;
    }

    double speed = CalculateSpeed(coords[0][0], coords[1][0], coords[0][1], coords[1][1]);
    double angle = CalculateAngle(coords[0][0], coords[1][0], coords[0][1], coords[1][1]);

    cout << endl << "Speed (v) = " << speed << " units per second, Angle(Y): " << angle << " degrees at 10s\n" << endl;
    
}