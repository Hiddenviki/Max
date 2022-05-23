//
// Created by Виктория Веселкова on 23.05.2022.
//

#pragma once
#include <iostream>
#include "FIO.h"
#include "Address.h"

class common {
protected:
    FIO recipient_fio;
    Address recipient_address;
public:

    virtual void show_data();
    virtual void show_data1();

    virtual void new_data();
    virtual void add_data();

    virtual void saveDataOnDisk();
    virtual void readDataFromDisk();


};


