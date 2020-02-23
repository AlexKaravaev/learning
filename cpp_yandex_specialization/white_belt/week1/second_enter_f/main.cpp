
#include <iostream>
#include <algorithm>

int main()
{
    std::string input;
    std::cin >> input;
    auto f_count = 0;
    auto i = 0;
    for (auto& char_: input)
    {
        if (char_=='f')
        {
            f_count += 1;
        }
        if (f_count==2)
        {
            std::cout << i;
            return 1;
        }
        
        i++;
    }
    std::cout << f_count-2;
    return 0;
}