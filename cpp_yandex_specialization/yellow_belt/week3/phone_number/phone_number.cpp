#include "phone_number.h"
#include <exception>
#include <stdexcept>
#include <iostream>


PhoneNumber::PhoneNumber(const string& international_number){
    auto number_prefix = international_number.find("+");
    if (number_prefix != 0)
        throw std::invalid_argument("+ Not found at first position");

    auto country_delim = international_number.find("-");
    if (country_delim == std::string::npos)
        throw std::invalid_argument("Wrong country code");
    country_code_ = international_number.substr(number_prefix + 1, country_delim-number_prefix-1);
    
    auto city_delim = international_number.find("-", country_delim+1);
    if (city_delim == std::string::npos)
        throw std::invalid_argument("Wrong city code");
    city_code_ = international_number.substr(country_delim + 1, city_delim-country_delim - 1);

    local_number_  = international_number.substr(city_delim + 1, international_number.size() - city_delim);

    if(country_code_.size() == 0 || city_code_.size() == 0 || local_number_.size()==0)
        throw std::invalid_argument("Number part is empty");
}

string PhoneNumber::GetCountryCode() const{
    return country_code_;
}

string PhoneNumber::GetCityCode() const{
    return city_code_;
}

string PhoneNumber::GetLocalNumber() const{
    return local_number_;
}

string PhoneNumber::GetInternationalNumber() const{
    return "+"+country_code_+"-"+city_code_+"-"+local_number_;
}