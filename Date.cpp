//
// Created by Виктория Веселкова on 23.05.2022.
//

#include "Date.h"

std::string Date::show_pretty_date() {

    int int_day=day;
    int int_year = year;
    std::string string_day = std::to_string(int_day);
    std::string string_year = std::to_string(int_year);
    std::string beautiful_month = month;
    std::string beautiful_date, beautiful_day, beautiful_year;

    int i = 0; //сколько цифр в дне
    while( string_day[i] != '\0' ){i++;}

    if (int_day==1){beautiful_day="first";}
    else if (int_day==2){beautiful_day="second";}
    else if (int_day==3){beautiful_day="third";}
    else {beautiful_day=string_day+"th";}

    beautiful_date ="The "+ beautiful_day+" of "+beautiful_month+", "+ string_year;

    return beautiful_date;
}

