#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // y at x = 3.5
    double x[7] = {0, 1,      2.5,    3,      4.5,    5,      6};
    double y[7] = {2, 5.4375, 7.3516, 7.5625, 8.4453, 9.1875, 12};

    double difference[7][7];
    double value = 3.5;

    for(int i = 0; i < 7; i++)
    {
        difference[0][i] = y[i];
    }

    for(int i = 1; i < 7; i++)
    {
        for(int j = 0; j < 7 - i; j++)
        {
            difference[i][j] = (difference[i - 1][j + 1] - difference[i - 1][j]) / (x[i + j] - x[j]);
        }
    }

    double ans = 0;
    for(int i = 0; i < 7; i++)
    {
        double prod = 1;
        for(int j = 0; j < i; j++)
        {
            prod *= (value - x[j]);
        }
        ans += prod * difference[i][0];
    }

    cout << "x = 3.5 y = " << ans << "\n";

}