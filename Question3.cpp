#include <iostream>
#include <math.h>

using namespace std;

double romberg(double values[9][9], int i, int j)
{
    return (pow(4, (i - 1)) * values[j + 1][i - 1]) / (pow(4,(i - 1)) - 1);
}

int main()
{
    double a = 0, b = 16;
    double segments = (b-a)/8;
    double values[9] = {0, 1.9, 2, 2, 2.4, 2.6, 2.25, 1.12, 0};
    double answers[9][9];

    double r = 0;
    double h = (b-a)/segments;

    for(int j = 1; j < 8; j++)
    {
        for(int i = 1; i < 8; i++)
        {
            r += 2 * (values[i]);
        }
        r *= (b-a)/ b;
        answers[j][1] = r;
    }

    for(int i = 2; i < 8; i++)
    {
        for(int j = 1; j < 8 - i + 1; j++)
        {
            answers[j][i] = romberg(answers, i, j);
        }
    }
    
    int x = 1, y = 1;
    for(int i = 1; i < 8; i++)
    {
        for(int j = 1; j < 8 - i; j++)
        {
            x = i; y = j;
        }
        
    }

    cout << "The total depth of the river is " << answers[x][y] << "m" << endl;
   
}