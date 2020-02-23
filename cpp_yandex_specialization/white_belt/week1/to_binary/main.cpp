#include <iostream>
#include <vector>

int main()
{
    std::vector<uint16_t> res;
    uint input;
    std::cin >> input;


    while (input>0)
    {
        res.push_back(input % 2);
        input = input / 2;

    }
    
    for (int i = res.size()-1; i >= 0; i--)
    {

        std::cout << res[i];
    }
    return 1;
}