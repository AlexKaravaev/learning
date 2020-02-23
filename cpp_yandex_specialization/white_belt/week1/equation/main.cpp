#include <iostream>
#include <cmath>
#include <array>

int main()
{
    std::array<double, 3> k;

    for (auto i = 0; i < 3; i++)
    {
        std::cin >> k[i];
    }

    double D,x1,x2;
    D = std::pow(k[1], 2) - 4*k[0]*k[2];
    if (D < 0)
    {
        return 1;
    }
    else
    {
        if (k[0]==0 && k[1]!=0)
        {
            std::cout << -k[2]/k[1];
            return 1;
        }
        if (k[0]==0 && k[1]==0)
        {
            return 1;
        }
        x1 = (-k[1] + std::sqrt(D))/(2*k[0]);
        x2 = (-k[1] - std::sqrt(D))/(2*k[0]);
        if (x1==x2)
        {
            std::cout << x1;
        }
        else
            std::cout << x1 << ' ' << x2;
    }
    return 1;

}