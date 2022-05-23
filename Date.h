//
// Created by Виктория Веселкова on 23.05.2022.
//

#pragma once
#include <iostream>

class Date {
    friend class letter1;
//    friend class Box; //у тебя нет коробки
private:
    int day;
    std::string month;
    int year;
public:
    std::string show_pretty_date();

};


