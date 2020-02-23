#include <iostream>
#include <limits>

int main()
{    
    bool flag(false);
    std::string input,min_str;
    for (auto i = 0; i < 3; i++)
    {
        std::cin>>input;
        if (input<min_str or !flag)
        {
            min_str = input;
            flag=true;
        }
    }
    std::cout << min_str;
    return 0;
}
