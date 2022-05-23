//
// Created by Виктория Веселкова on 23.05.2022.
//

#pragma once
#include <iostream>
#include "Address.h"
#include "common.h"
#include "FIO.h"

//#include "FIO.h" ??

class letter: public common {
private:
    Address sender_address;
    double price;

public:
    static int count_letter;
    letter* letter_array;

    letter();
    ~letter();

    void find_by_sender(letter *Obj);
    friend void sort(letter *Obj);

    void show_data() override;
    void add_data() override;
    void new_data() override;

    void saveDataOnDisk() override;
    void readDataFromDisk() override;

    letter& operator = (const letter &equal);


};



