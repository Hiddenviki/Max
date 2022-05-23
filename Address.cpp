//
// Created by Виктория Веселкова on 23.05.2022.
//

#include "Address.h"

std::string Address::show_pretty_address() {
    std::string full_address = "Country: "+country+"; "+"City: "+city+"; "+"Building: "+building_number;
    return full_address;
}
