//
// Created by Виктория Веселкова on 23.05.2022.
//

#pragma once
#include <iostream>

class Address {
    friend class letter;
    friend class letter1;
    friend class Box;
private:
    std::string country;
    std::string city;
    std::string building_number;
public:
    std::string show_pretty_address();
};

