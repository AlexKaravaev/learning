#include <iostream>

int main()
{
    uint16_t w,h,d;
    uint32_t n;
    uint16_t  r;

    std::cin >> n >> r;


    uint64_t total_mass(0);

    for (auto i=0; i<n;i++)
    {
        std::cin >> w >> h >> d;
        total_mass += static_cast<uint64_t>(w)*h*d*r;
    }

    std::cout << total_mass << std::endl;
}
