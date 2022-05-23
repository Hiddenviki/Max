//
// Created by Виктория Веселкова on 23.05.2022.
//

#include "FIO.h"

std::string FIO::show_full_fio() {
    std::string full_fio = person_surname + " " + person_name + " " + person_patronymic;
    return full_fio;
}
