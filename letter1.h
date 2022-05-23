//
// Created by Виктория Веселкова on 23.05.2022.
//

#pragma once
#include <iostream>
#include "common.h"
#include "Date.h"

class letter1: public common{
private:
    Date when_get;

public:
    static int count_letter1;
    letter1* letter1_array;

    void show_data1() override;
    void add_data() override;
    void new_data() override;
    void saveDataOnDisk() override;
    void readDataFromDisk() override;

    letter1& operator = (const letter1 &equal);

};


