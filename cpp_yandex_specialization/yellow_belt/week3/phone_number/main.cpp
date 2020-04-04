#include "phone_number.h"
#include <iostream>

int main(){
    {
        PhoneNumber pn("+7-495-111-22-33");
        std::cout << "Country: " << pn.GetCountryCode() << std::endl;
        std::cout << "City: " << pn.GetCityCode() << std::endl;
        std::cout << "Local: " << pn.GetLocalNumber() << std::endl;
        std::cout << "Full: " << pn.GetInternationalNumber() << std::endl;
    }
    {
        PhoneNumber pn("+--");
        std::cout << "Country: " << pn.GetCountryCode() << std::endl;
        std::cout << "City: " << pn.GetCityCode() << std::endl;
        std::cout << "Local: " << pn.GetLocalNumber() << std::endl;
        std::cout << "Full: " << pn.GetInternationalNumber() << std::endl;
    }
    
    return 0;
}